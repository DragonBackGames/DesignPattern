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
#include "Ammunition.h"
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
Ammunition::Ammunition(GameLayer* game, int ammunitionType) : b2Sprite(game, kAmmunition)
{
	m_ammunitionType = ammunitionType;
	char ammunitionName[100];
	switch(m_ammunitionType)
	{
		case kMissileAmmunition:
		{
			sprintf(ammunitionName, "ufoBlue");
			break;
		}
		case kRailGunAmmunition:
		{
			sprintf(ammunitionName, "ufoGreen");
			break;
		}
		case kWaveCannonAmmunition:
		{
			sprintf(ammunitionName, "ufoRed");
			break;
		}
		case kBubbleCannonAmmunition:
		{
			sprintf(ammunitionName, "ufoYellow");
			break;
		}
		default:
		{
			return;
		}
	}
	char ammunitionSprite[100];
	sprintf(ammunitionSprite,"%s.png",ammunitionName);
	// Configure the ship sprites and physics
	this->initWithSpriteFrameName(ammunitionSprite);
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.angle = 0;
	this->m_body = m_game->getWorld()->CreateBody(&bodyDef);

	this->m_body->SetUserData((void*)this);
	GB2ShapeCache::sharedGB2ShapeCache()->addFixturesToBody(this->m_body, ammunitionName);
    this->setAnchorPoint(GB2ShapeCache::sharedGB2ShapeCache()->anchorPointForShape(ammunitionName));
}
