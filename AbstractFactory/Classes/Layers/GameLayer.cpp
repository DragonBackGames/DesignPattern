/* ----------------------------------------------------------------------------
 *
 * (C) Copyright 2014 Gustavo E. Rangel
 * Brussels, Belgium
 *
 * ----------------------------------------------------------------------------
 */

/* ----------------------------------------------------------------------------
 *
 * Includes
 *
 * ----------------------------------------------------------------------------
 */
#include "GameLayer.h"


/* ----------------------------------------------------------------------------
 *
 * Class methods
 *
 * ----------------------------------------------------------------------------
 */
/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
CCScene* GameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
           
	// add control layer to scene
	scene->addChild(layer->setupControlGameLayer(), 1);

    // return the scene
    return scene;
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
ControlGameLayer* GameLayer::setupControlGameLayer()
{
	this->controllerLayer = ControlGameLayer::create();
	return this->controllerLayer;
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
bool GameLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
	
    /* ------------------------------------------------------------------------
     * Initialize generic stuff
     * ------------------------------------------------------------------------
     */
	m_screenSize = CCDirector::sharedDirector()->getWinSize();
    scheduleUpdate();
    this->setTouchEnabled(true);

    /* ------------------------------------------------------------------------
     * Initialize physics
     * ------------------------------------------------------------------------
     */
    b2Vec2 gravity;
    gravity.Set(0.0f, 0.0f);
    m_world = new b2World(gravity);
    m_world->SetAllowSleeping(true);
    m_world->SetContinuousPhysics(true);
    
    // set the debug draw to show fixtures, and let the world know about it
    m_debugDraw = new GLESDebugDraw( PTM_RATIO );
    m_debugDraw->SetFlags( b2Draw::e_shapeBit | b2Draw::e_jointBit );
    m_world->SetDebugDraw(m_debugDraw);

    // Create contact listener
    m_gameContactListener = new GameContactListener();
    m_gameContactListener->m_layer = this;
    m_world->SetContactListener( m_gameContactListener );
    
    /* ------------------------------------------------------------------------
     * Initialize objects
     * ------------------------------------------------------------------------
     */
	m_ship = new Ship(this);
	m_ship->setSpritePosition(ccp(m_screenSize.width * 0.5f, m_screenSize.height * 0.5f));
    m_ship->setWeapon(kNoneAmmunition);
	this->addChild(m_ship);

	m_missileAmmunition = new Ammunition(this, kMissileAmmunition);
	m_missileAmmunition->setSpritePosition(ccp(m_screenSize.width * 0.2f, m_screenSize.height * 0.7f));
	this->addChild(m_missileAmmunition);

	m_railGuneAmmunition = new Ammunition(this, kRailGunAmmunition);
	m_railGuneAmmunition->setSpritePosition(ccp(m_screenSize.width * 0.3f, m_screenSize.height * 0.7f));
	this->addChild(m_railGuneAmmunition);

	m_waveCannonAmmunition = new Ammunition(this, kWaveCannonAmmunition);
	m_waveCannonAmmunition->setSpritePosition(ccp(m_screenSize.width * 0.4f, m_screenSize.height * 0.7f));
	this->addChild(m_waveCannonAmmunition);

	m_bubbleCannonAmmunition = new Ammunition(this, kBubbleCannonAmmunition);
	m_bubbleCannonAmmunition->setSpritePosition(ccp(m_screenSize.width * 0.5f, m_screenSize.height * 0.7f));
	this->addChild(m_bubbleCannonAmmunition);

    return true;
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameLayer::update(float dt)
{
    // Check if there is any object to erase
    for (std::set<b2Sprite*>::iterator it = m_objectsToProcess.begin(); it != m_objectsToProcess.end(); it++)
    {
        b2Sprite* fud = *it;
        // If hit with ammo, add weapon to ship
        if(fud->getType() == kAmmunition)
        {
            Ammunition* ammunition = (Ammunition*)fud;
            m_ship->setWeapon(ammunition->getAmmunitionType());
        }
        this->removeChild(fud, true);
        m_world->DestroyBody(fud->getBody());
        delete fud;
        
    }
    
    m_objectsToProcess.clear();
    
    /* ------------------------------------------------------------------------
     * Update physics stuff
     * ------------------------------------------------------------------------
     */
    if ( m_world )
    {
        m_world->Step(1/60.0, 8, 3);
    }
    
    /* ------------------------------------------------------------------------
     * Move ship with joystick
     * ------------------------------------------------------------------------
     */
	CCPoint joystickPosition = this->controllerLayer->getStickPosition();
	float maxSpeedX = 15;
	float maxSpeedY = 15;
	float maxForce = 20;

	b2Vec2 currentVelocity = m_ship->getBody()->GetLinearVelocity();
    float forceX = 0;
	float forceY = 0;
	// Update speed X
	if((joystickPosition.x < 0) && (currentVelocity.x > -maxSpeedX))
	{
		forceX = -maxForce * abs(joystickPosition.x) / 80.0;
	}
	else if((joystickPosition.x > 0) && (currentVelocity.x < maxSpeedX))
	{
		forceX = maxForce * abs(joystickPosition.x) / 80.0;
	}
	else if(joystickPosition.x == 0)
	{
		forceX = -currentVelocity.x * maxForce * 0.5;
	}
	// Update speed Y
	if((joystickPosition.y < 0) && (currentVelocity.y > -maxSpeedY))
	{
		forceY = -maxForce * abs(joystickPosition.y) / 80.0;
	}
	else if((joystickPosition.y > 0) && (currentVelocity.y < maxSpeedY))
	{
		forceY = maxForce * abs(joystickPosition.y) / 80.0;
	}
	else if(joystickPosition.y == 0)
	{
		forceY = -currentVelocity.y * maxForce * 0.5;
	}
	m_ship->getBody()->ApplyLinearImpulse( b2Vec2(forceX, forceY), m_ship->getBody()->GetWorldCenter(), true );
    
    /* ------------------------------------------------------------------------
     * Shoot some bullets
     * ------------------------------------------------------------------------
     */
    if(controllerLayer->getAttackButtonValue())
    {
        CCLOG("## Bullet ");
        float forceBullet = 10;
        Weapon* weapon = new Weapon(this, m_ship->getWeapon());
        weapon->setSpritePosition(ccp(m_ship->getPosition().x + 10, m_ship->getPosition().y + 100));
        this->addChild(weapon);
        weapon->getBody()->ApplyLinearImpulse( b2Vec2(0, forceBullet), weapon->getBody()->GetWorldCenter(), true );
        m_bulletsToProcess.insert(weapon);
    }

}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameLayer::draw()
{
    // Standard Cocos2d method
    if (!m_world)
    {
        return;
    }
    
    // debug draw display will be on top of anything else
    CCLayer::draw();
    
    ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position );
    kmGLPushMatrix();
    m_world->DrawDebugData();
    kmGLPopMatrix();
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameLayer::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{

}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameLayer::ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameLayer::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    
}
