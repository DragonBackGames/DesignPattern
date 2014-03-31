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

#ifndef __BULLET_H__
#define __BULLET_H__

USING_NS_CC;

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
enum
{
    kMissileBullet = 0,
    kLaserBullet,
    kBombBullet
};

class Potion : public b2Sprite
{
public:
	// Constructor
	Potion(GameScene* game);
};

#endif //__BULLET_H__