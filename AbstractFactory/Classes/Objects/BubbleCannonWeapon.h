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

#ifndef __BUBBLE_CANNON_WEAPON_H__
#define __BUBBLE_CANNON_WEAPON_H__

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class BubbleCannonWeapon : public Weapon
{
public:
	// constructure 
	BubbleCannonWeapon(GameLayer* game);
	// creates a weapon object
	static Weapon* create(GameLayer* game);
	// shoot the object
	void shootBullet();
};

#endif // __BUBBLE_CANNON_WEAPON_H__