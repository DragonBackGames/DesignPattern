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
#include "GameScene.h"
#include "b2SpriteFactory.h"

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
Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

	scene->addChild(layer->setupControlGameLayer(), 1);

    // return the scene
    return scene;
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
ControlGameLayer* GameScene::setupControlGameLayer()
{
	this->controllerLayer = ControlGameLayer::create();
	return this->controllerLayer;
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    /* ------------------------------------------------------------------------
     * Initialize generic stuff
     * ------------------------------------------------------------------------
     */
	m_screenSize = Director::getInstance()->getWinSize();
    scheduleUpdate();
    setTouchEnabled(true);
    
    Sprite* bg = Sprite::create("bkg.png");
    bg->setPosition(Point(m_screenSize.width * 0.5, m_screenSize.height * 0.5));
    this->addChild(bg, -1);
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
	m_player = (Player*)b2SpriteFactory::createB2Sprite(this, kPlayer, 0);
	m_player->setSpritePosition(Point(m_screenSize.width * 0.2f, m_screenSize.height * 0.5f));
	this->addChild(m_player);

	m_enemy = (Enemy*)b2SpriteFactory::createB2Sprite(this, kEnemy, 0);
	m_enemy->setSpritePosition(Point(m_screenSize.width * 0.8f, m_screenSize.height * 0.4f));
	this->addChild(m_enemy);

	m_potion = (Potion*)b2SpriteFactory::createB2Sprite(this, kPotion, 0);
	m_potion->setSpritePosition(Point(m_screenSize.width * 0.8f, m_screenSize.height * 0.8f));
	this->addChild(m_potion);

    // Define the static container body, which will provide the collisions at screen borders. 
    b2BodyDef screenBorderDef;
	screenBorderDef.type = b2_kinematicBody;
    screenBorderDef.position.Set(0, 0);
    m_screenBorderBody = m_world->CreateBody(&screenBorderDef);
  
	//add four walls to the static body
	b2PolygonShape polygonShape;
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &polygonShape;

    float widthInMeters = m_screenSize.width / PTM_RATIO;
    float heightInMeters = m_screenSize.height / PTM_RATIO;

    polygonShape.SetAsBox( widthInMeters / 2, 1, b2Vec2(widthInMeters / 2, 0), 0); //ground
    m_screenBorderBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( widthInMeters / 2, 1, b2Vec2(widthInMeters / 2, heightInMeters), 0); //ceiling
    m_screenBorderBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 1, heightInMeters / 2, b2Vec2(0, heightInMeters / 2), 0); //left wall
    m_screenBorderBody->CreateFixture(&myFixtureDef);
    polygonShape.SetAsBox( 1, heightInMeters / 2, b2Vec2(widthInMeters, heightInMeters / 2), 0); //right wall
    m_screenBorderBody->CreateFixture(&myFixtureDef);
    
    /* ------------------------------------------------------------------------
     * Initialize labels
     * ------------------------------------------------------------------------
     */
    LabelTTF* m_healthTxt = LabelTTF::create("Health", "Marker Felt", 60);
    m_healthTxt->setPosition(Point(m_screenSize.width * 0.2, m_screenSize.height * 0.9));
    this->addChild(m_healthTxt, 1);

    LabelTTF* m_manaTxt = LabelTTF::create("Mana", "Marker Felt", 60);
    m_manaTxt->setPosition(Point(m_screenSize.width * 0.4, m_screenSize.height * 0.9));
    this->addChild(m_manaTxt, 1);
    
    m_healthLabel = LabelTTF::create("1000", "Marker Felt", 60);
    m_healthLabel->setPosition(Point(m_screenSize.width * 0.2, m_screenSize.height * 0.8));
    this->addChild(m_healthLabel, 1);

    m_manaLabel = LabelTTF::create("0", "Marker Felt", 60);
    m_manaLabel->setPosition(Point(m_screenSize.width * 0.4, m_screenSize.height * 0.8));
    this->addChild(m_manaLabel, 1);

	return true;
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameScene::update(float dt)
{
    /* ------------------------------------------------------------------------
     * Update physics stuff
     * ------------------------------------------------------------------------
     */
    if ( m_world )
    {
        m_world->Step(1/60.0, 8, 3);
    }
    
    /* ------------------------------------------------------------------------
     * Process Observer
     * ------------------------------------------------------------------------
     */
    m_player->notify();

    char score_buffer[10];
    sprintf(score_buffer,"%i", m_player->getHealth());
    m_healthLabel->setString(score_buffer);
    sprintf(score_buffer,"%i", m_player->getMana());
    m_manaLabel->setString(score_buffer);

    /* ------------------------------------------------------------------------
     * Move ship with joystick
     * ------------------------------------------------------------------------
     */
	Point joystickPosition = this->controllerLayer->getStickPosition();
	m_player->movePlayer(joystickPosition);
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameScene::draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated)
{

    // Standard Cocos2d method
    if (!m_world)
    {
        return;
    }
    
    // debug draw display will be on top of anything else
    Layer::draw(renderer, transform, transformUpdated);
    
    //ccGLEnableVertexAttribs( kCCVertexAttribFlag_Position );
    //kmGLPushMatrix();
    //m_world->DrawDebugData();
    //kmGLPopMatrix();
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameScene::onTouchesBegan(Touch* touches, Event* event)
{

}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameScene::onTouchesMoved(Touch* touches, Event* event)
{
    
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameScene::onTouchesEnded(Touch* touches, Event* event)
{
    
}
