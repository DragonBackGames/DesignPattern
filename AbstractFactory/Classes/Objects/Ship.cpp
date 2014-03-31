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
#include "Ship.h"
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
Ship::Ship(GameLayer* game) : b2Sprite(game, kShip)
{
	CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
	// Configure the ship sprites and physics
	this->initWithSpriteFrameName("playerShip1_blue.png");
    
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(screenSize.width * 0.5 / PTM_RATIO, screenSize.height * 0.5 / PTM_RATIO);
	bodyDef.angle = 0;
	this->m_body = m_game->getWorld()->CreateBody(&bodyDef);

	this->m_body->SetUserData((void*)this);

	GB2ShapeCache::sharedGB2ShapeCache()->addFixturesToBody(this->m_body, "playerShip1_blue");
    this->setAnchorPoint(GB2ShapeCache::sharedGB2ShapeCache()->anchorPointForShape("playerShip1_blue"));
}
