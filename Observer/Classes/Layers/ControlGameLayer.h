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
class ControlGameLayer : public Layer
{
public:
    // Destructor
    ~ControlGameLayer();
    // Create a layer
    static ControlGameLayer* create();
    
    CC_SYNTHESIZE_READONLY(Point, stickPosition, StickPosition);
    
private:
    // standard Cocos2d layer method
    virtual bool init();
    // standard Cocos2d layer method
    virtual void update(float dt);
	// Joystick    
	SneakyJoystick* leftJoystick;
};

#endif // __CONTROL_GAME_LAYER_H__
