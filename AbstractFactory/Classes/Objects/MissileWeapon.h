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

#ifndef __MISSILE_WEAPON_H__
#define __MISSILE_WEAPON_H__

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class MissileWeapon : public Weapon
{
public:
	// constructure 
	MissileWeapon(GameLayer* game);
	// creates a weapon object
	static Weapon* create(GameLayer* game);
	// shoot the object
	void shootBullet();
};

#endif // __MISSILE_WEAPON_H__