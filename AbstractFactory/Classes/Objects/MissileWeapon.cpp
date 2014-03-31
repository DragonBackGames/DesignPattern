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
#include "MissileWeapon.h"
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
MissileWeapon::MissileWeapon(GameLayer* game) : Weapon(game)
{
	// Configure the ship sprites and physics
	this->initWithSpriteFrameName("laserBlue01.png");
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.angle = 0;
	this->m_body = m_game->getWorld()->CreateBody(&bodyDef);
    
	this->m_body->SetUserData((void*)this);
	GB2ShapeCache::sharedGB2ShapeCache()->addFixturesToBody(this->m_body, "laserBlue01");
    this->setAnchorPoint(GB2ShapeCache::sharedGB2ShapeCache()->anchorPointForShape("laserBlue01"));
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
Weapon* MissileWeapon::create(GameLayer* game)
{
	MissileWeapon* missileWeapon = new MissileWeapon(game);
	return missileWeapon;
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void MissileWeapon::shootBullet()
{
	CCLOG("Shooting Missiles!!!");
}
