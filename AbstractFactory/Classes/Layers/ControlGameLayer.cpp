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
#include "ControlGameLayer.h"

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
ControlGameLayer::~ControlGameLayer()
{
    
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
ControlGameLayer* ControlGameLayer::create()
{
    ControlGameLayer* layer = new ControlGameLayer();
    layer->init();
    return layer;
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
bool ControlGameLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    
    CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
    
	// Configure joystick
	CCRect joystickBaseDimensions;
	joystickBaseDimensions = CCRectMake(0, 0, 160.0f, 160.0f);    

	CCPoint joystickBasePosition;
	joystickBasePosition = ccp(screenSize.width * 0.2f, screenSize.height*0.2f);

	SneakyJoystickSkinnedBase *joystickBase = new SneakyJoystickSkinnedBase();
	joystickBase->init();
	joystickBase->setPosition(joystickBasePosition);
	joystickBase->setBackgroundSprite(CCSprite::createWithSpriteFrameName("flatDark06.png"));
	joystickBase->setThumbSprite(CCSprite::createWithSpriteFrameName("shadedDark01.png"));
    
	SneakyJoystick *aJoystick = new SneakyJoystick();
	aJoystick->initWithRect(joystickBaseDimensions);
	aJoystick->autorelease();
	joystickBase->setJoystick(aJoystick);
	joystickBase->setPosition(joystickBasePosition);

	leftJoystick = joystickBase->getJoystick();
	leftJoystick->retain();
	this->addChild(joystickBase);	

    //Create Attack Button
    CCRect attackButtonDimensions = CCRectMake(0, 0, 64.0f, 64.0f);
    CCPoint attackButtonPosition;
	attackButtonPosition = ccp(screenSize.width * 0.9f, screenSize.height * 0.2f);
    
	SneakyButtonSkinnedBase *attackButtonBase = new SneakyButtonSkinnedBase();
    attackButtonBase->init();
	attackButtonBase->setPosition(attackButtonPosition);
    
    attackButtonBase->setDefaultSprite(CCSprite::createWithSpriteFrameName("attackBtn.png"));
    attackButtonBase->setActivatedSprite(CCSprite::createWithSpriteFrameName("attackBtn.png"));
    attackButtonBase->setDisabledSprite(CCSprite::createWithSpriteFrameName("attackBtn.png"));
    attackButtonBase->setPressSprite(CCSprite::createWithSpriteFrameName("attackBtn.png"));
    
	SneakyButton *aAttackButton = new SneakyButton();
	aAttackButton->initWithRect(attackButtonDimensions);
	aAttackButton->autorelease();
    
	attackButtonBase->setButton(aAttackButton);
    attackButtonBase->setPosition(attackButtonPosition);
    
	attackButton = attackButtonBase->getButton();
    attackButton->retain();
	this->addChild(attackButtonBase);
    
	// Enable scheduler
    scheduleUpdate();
    this->setTouchEnabled(true);

    return true;
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void ControlGameLayer::update(float dt)
{
	stickPosition = leftJoystick->getStickPosition();
    attackButtonValue = attackButton->getValue();
}