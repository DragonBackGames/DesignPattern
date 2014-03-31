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
#include "Potion.h"
#include "GameScene.h"

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
/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
Potion::Potion(GameScene* game) : b2Sprite(game, kPotion)
{
	// Configure the ship sprites and physics
	this->initWithSpriteFrameName("potion.png");
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.angle = 0;
	this->m_body = m_game->getWorld()->CreateBody(&bodyDef);
	this->m_body->SetUserData((void*)this);

	GB2ShapeCache::sharedGB2ShapeCache()->addFixturesToBody(this->m_body, "potion");
    this->setAnchorPoint(GB2ShapeCache::sharedGB2ShapeCache()->anchorPointForShape("potion"));
}
