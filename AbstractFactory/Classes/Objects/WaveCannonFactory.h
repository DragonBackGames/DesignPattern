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
#include "WeaponFactory.h"

#ifndef __WAVE_CANNON_FACTORY_H__
#define __WAVE_CANNON_FACTORY_H__

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class WaveCannonFactory : public WeaponFactory
{
public:
	static Weapon* create(GameLayer* game);
};

#endif // __WAVE_CANNON_FACTORY_H__