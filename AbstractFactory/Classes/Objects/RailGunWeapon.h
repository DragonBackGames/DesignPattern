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
#include "Weapon.h"

#ifndef __RAIL_GUN_WEAPON_H__
#define __RAIL_GUN_WEAPON_H__

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class RailGunWeapon : public Weapon
{
public:
	// constructure 
	RailGunWeapon(GameLayer* game);
	// creates a weapon object
	static Weapon* create(GameLayer* game);
	// shoot the object
	void shootBullet();
};

#endif // __MISSILE_WEAPON_H__