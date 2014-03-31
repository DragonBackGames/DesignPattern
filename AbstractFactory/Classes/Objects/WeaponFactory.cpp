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
#include "MissileFactory.h"
#include "RailGunFactory.h"
#include "WaveCannonFactory.h"
#include "BubbleCannonFactory.h"
#include "GameLayer.h"

/* ----------------------------------------------------------------------------
 *
 * Class methods
 *
 * ----------------------------------------------------------------------------
 */
/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
Weapon* WeaponFactory::createWeapon(GameLayer* game, int weapon_type)
{
	Weapon* weapon;
	switch(weapon_type)
	{
		case kMissileWeapon:
		{
			weapon = MissileFactory::create(game);
			break;
		}
		case kRailGunWeapon:
		{
			weapon = RailGunFactory::create(game);
			break;
		}
		case kWaveCannonWeapon:
		{
			weapon = WaveCannonFactory::create(game);
			break;
		}
		case kBubbleCannonWeapon:
		{
			weapon = BubbleCannonFactory::create(game);
			break;
		}
		default:
		{
			weapon = NULL;
			CCLOG("## There is an error");
			break;
		}
	}
	return weapon;
}