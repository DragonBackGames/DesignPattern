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

#ifndef __AMMUNITION_H__
#define __AMMUNITION_H__

USING_NS_CC;

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
enum
{
    kNoneAmmunition = 0,
    kMissileAmmunition,
	kRailGunAmmunition,
	kWaveCannonAmmunition,
    kBubbleCannonAmmunition
};

class Ammunition : public b2Sprite
{
public:
	// constructor
	Ammunition(GameLayer* game, int ammunitionType);
    CC_SYNTHESIZE(int, m_ammunitionType, AmmunitionType);
};

#endif //__AMMUNITION_H__