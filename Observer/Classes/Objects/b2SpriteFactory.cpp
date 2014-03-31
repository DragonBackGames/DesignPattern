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
#include "b2SpriteFactory.h"
#include "Player.h"
#include "Enemy.h"
#include "Potion.h"

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
b2Sprite* b2SpriteFactory::createB2Sprite(GameScene* game, int sprite_type, int object_type)
{
	b2Sprite* sprite;
	switch(sprite_type)
	{
		case kPlayer:
		{
			sprite = new Player(game);
			break;
		}
		case kEnemy:
		{
			sprite = new Enemy(game);
			break;
		}
		case kPotion:
		{
			sprite = new Potion(game);
			break;
		}
		default:
		{
			sprite = NULL;
			CCLOG("## There is an error");
			break;
		}
	}
	return sprite;
}