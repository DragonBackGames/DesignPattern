/* ----------------------------------------------------------------------------
 *
 * (C) Copyright 2014 Gustavo E. Rangel
 * Brussels, Belgium
 *
 * ----------------------------------------------------------------------------
 */
#ifndef __CONTROL_GAME_LAYER_H__
#define __CONTROL_GAME_LAYER_H__

/* ----------------------------------------------------------------------------
 *
 * Includes
 *
 * ----------------------------------------------------------------------------
 */
#include "cocos2d.h"
#include "SneakyJoystick.h"
#include "SneakyJoystickSkinnedBase.h"
#include "SneakyButton.h"
#include "SneakyButtonSkinnedBase.h"

USING_NS_CC;

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class ControlGameLayer : public CCLayer
{
public:
    // Destructor
    ~ControlGameLayer();
    // Create a layer
    static ControlGameLayer* create();
    
    CC_SYNTHESIZE_READONLY(CCPoint, stickPosition, StickPosition);
    CC_SYNTHESIZE_READONLY(bool, attackButtonValue, AttackButtonValue);
    
private:
    // standard Cocos2d layer method
    virtual bool init();
    // standard Cocos2d layer method
    virtual void update(float dt);
	// Joystick    
	SneakyJoystick* leftJoystick;
    // Attack button
    SneakyButton *attackButton;

};

#endif // __CONTROL_GAME_LAYER_H__
