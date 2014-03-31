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
/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
Weapon::Weapon(GameLayer* game, int weaponType) : b2Sprite(game, kBullet)
{
	m_weaponType = weaponType;
	char weaponName[100];
	switch(m_weaponType)
	{
		case kMissileAmmunition:
		{
			sprintf(weaponName, "laserBlue01");
			break;
		}
		case kRailGunAmmunition:
		{
			sprintf(weaponName, "laserBlue10");
			break;
		}
		case kWaveCannonAmmunition:
		{
			sprintf(weaponName, "laserGreen01");
			break;
		}
		case kBubbleCannonAmmunition:
		{
			sprintf(weaponName, "laserRed01");
			break;
		}
		default:
		{
			return;
		}
	}
	char weaponSprite[100];
	sprintf(weaponSprite,"%s.png",weaponName);
	// Configure the ship sprites and physics
	this->initWithSpriteFrameName(weaponSprite);
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.angle = 0;
	this->m_body = m_game->getWorld()->CreateBody(&bodyDef);
	this->m_body->SetUserData((void*)this);
    
	GB2ShapeCache::sharedGB2ShapeCache()->addFixturesToBody(this->m_body, weaponName);
    this->setAnchorPoint(GB2ShapeCache::sharedGB2ShapeCache()->anchorPointForShape(weaponName));
}
