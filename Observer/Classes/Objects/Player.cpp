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
#include "Player.h"
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
Player::Player(GameScene* game) : b2Sprite(game, kPlayer)
{
	// Set player type
	m_type = kPlayer;
	// Configure the ship sprites and physics
	this->initWithSpriteFrameName("player.png");
    // Configure additional 
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.angle = 0;
	bodyDef.fixedRotation = true;
	this->m_body = m_game->getWorld()->CreateBody(&bodyDef);

	this->m_body->SetUserData((void*)this);

	GB2ShapeCache::sharedGB2ShapeCache()->addFixturesToBody(this->m_body, "player");
    this->setAnchorPoint(GB2ShapeCache::sharedGB2ShapeCache()->anchorPointForShape("player"));
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void Player::movePlayer(Point joystickPosition)
{
	// The velocity of the ship is increase depending on the joystick position
	float maxSpeedX = 10;
	float maxSpeedY = 10;
	float maxForce = 5;

	b2Vec2 currentVelocity = this->getBody()->GetLinearVelocity();
    float forceX = 0;
	float forceY = 0;
	// Update speed X
	if((joystickPosition.x < 0) && (currentVelocity.x > -maxSpeedX))
	{
		forceX = -maxForce * abs(joystickPosition.x) / 60.0;
	}
	else if((joystickPosition.x > 0) && (currentVelocity.x < maxSpeedX))
	{
		forceX = maxForce * abs(joystickPosition.x) / 60.0;
	}
	else if(joystickPosition.x == 0)
	{
		forceX = -currentVelocity.x * maxForce * 0.5;
	}
	// Update speed Y
	if((joystickPosition.y < 0) && (currentVelocity.y > -maxSpeedY))
	{
		forceY = -maxForce * abs(joystickPosition.y) / 60.0;
	}
	else if((joystickPosition.y > 0) && (currentVelocity.y < maxSpeedY))
	{
		forceY = maxForce * abs(joystickPosition.y) / 60.0;
	}
	else if(joystickPosition.y == 0)
	{
		forceY = -currentVelocity.y * maxForce * 0.5;
	}
	this->getBody()->ApplyLinearImpulse( b2Vec2(forceX, forceY), this->getBody()->GetWorldCenter(), true );
}
