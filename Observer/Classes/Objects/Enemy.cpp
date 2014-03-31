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
#include "Enemy.h"
#include "GameScene.h"
#include "b2SpriteFactory.h"

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
Enemy::Enemy(GameScene* game) : b2Sprite(game, kEnemy)
{
	// Configure the ship sprites and physics
	this->initWithSpriteFrameName("enemy.png");
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.angle = 0;
	this->m_body = m_game->getWorld()->CreateBody(&bodyDef);
	this->m_body->SetUserData((void*)this);  

	GB2ShapeCache::sharedGB2ShapeCache()->addFixturesToBody(this->m_body, "enemy");
    this->setAnchorPoint(GB2ShapeCache::sharedGB2ShapeCache()->anchorPointForShape("enemy"));
}
