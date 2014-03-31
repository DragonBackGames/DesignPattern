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

#ifndef __WEAPON_H__
#define __WEAPON_H__

USING_NS_CC;

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class Weapon : public b2Sprite
{
public:
	// Constructor
	Weapon(GameLayer* game, int weaponType);
    // Type of weapon
    CC_SYNTHESIZE(int, m_weaponType, WeaponType);
};

#endif //__WEAPON_H__