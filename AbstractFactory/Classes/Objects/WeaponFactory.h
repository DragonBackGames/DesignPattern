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
#include "Weapon.h"

#ifndef __WEAPON_FACTORY_H__
#define __WEAPON_FACTORY_H__

enum
{
	kMissileWeapon = 0,
	kRailGunWeapon,
	kWaveCannonWeapon,
	kBubbleCannonWeapon
};

class WeaponFactory
{
 
public:
    // constructor
	Weapon(GameLayer* game, int weaponType);
    CC_SYNTHESIZE(int, m_weaponType, WeaponType);

};

#endif // __WEAPON_FACTORY_H__