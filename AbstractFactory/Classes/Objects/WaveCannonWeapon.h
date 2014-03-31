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

#ifndef __WAVE_CANNON_WEAPON_H__
#define __WAVE_CANNON_WEAPON_H__

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class WaveCannonWeapon : public Weapon
{
public:
	// constructure 
	WaveCannonWeapon(GameLayer* game);
	// creates a weapon object
	static Weapon* create(GameLayer* game);
	// shoot the object
	void shootBullet();
};

#endif // __WAVE_CANNON_WEAPON_H__