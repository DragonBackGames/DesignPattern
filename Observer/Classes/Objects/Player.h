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
#include "cocos2d.h"
#include "b2Sprite.h"
#include "b2SpriteFactory.h"
#include "Potion.h"

#ifndef __PLAYER_H__
#define __PLAYER_H__

USING_NS_CC;

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class Player : public b2Sprite
{
public:
	// constructor
	Player(GameScene* game);
	// In case that player is moving, show animation
	void movePlayer(Point joystickPosition);
};

#endif //__PLAYER_H__