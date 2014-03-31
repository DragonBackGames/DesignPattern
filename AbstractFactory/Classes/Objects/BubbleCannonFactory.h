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

#ifndef __BUBBLE_CANNON_FACTORY_H__
#define __BUBBLE_CANNON_FACTORY_H__

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class BubbleCannonFactory : public WeaponFactory
{
public:
	static Weapon* create(GameLayer* game);
};

#endif // __BUBBLE_CANNON_FACTORY_H__