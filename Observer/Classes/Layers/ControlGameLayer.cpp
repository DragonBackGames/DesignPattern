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
    if (!Layer::init())
    {
        return false;
    }
    
    Size screenSize = Director::getInstance()->getWinSize();

	// Configure joystick
	Rect joystickBaseDimensions;
	joystickBaseDimensions = CCRectMake(0, 0, 160.0f, 160.0f);    

	Point joystickBasePosition;
	joystickBasePosition = Point(screenSize.width * 0.2f, screenSize.height*0.2f);

	SneakyJoystickSkinnedBase *joystickBase = new SneakyJoystickSkinnedBase();
	joystickBase->init();
	joystickBase->setPosition(joystickBasePosition);
	joystickBase->setBackgroundSprite(Sprite::createWithSpriteFrameName("backgroundJoy.png"));
	joystickBase->setThumbSprite(Sprite::createWithSpriteFrameName("thumbJoy.png"));
    
	SneakyJoystick *aJoystick = new SneakyJoystick();
	aJoystick->initWithRect(joystickBaseDimensions);
	aJoystick->autorelease();
	joystickBase->setJoystick(aJoystick);
	joystickBase->setPosition(joystickBasePosition);

	leftJoystick = joystickBase->getJoystick();
	leftJoystick->retain();
	this->addChild(joystickBase);	
   
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
}