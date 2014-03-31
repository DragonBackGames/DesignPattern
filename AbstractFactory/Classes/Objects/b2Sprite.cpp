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
#include "b2Sprite.h"
#include "GameLayer.h"

b2Sprite::b2Sprite(GameLayer* game, int type)
{
	m_game = game;
    m_type = type;
	scheduleUpdate();
}

void b2Sprite::setSpritePosition (CCPoint position)
{    
    setPosition(position);
   
    //update box2d body if any
    if (m_body)
	{
        m_body->SetTransform(b2Vec2(position.x / PTM_RATIO, position.y/ PTM_RATIO), m_body->GetAngle());
    }
     
}

void b2Sprite::update(float dt)
{    
    if (m_body && isVisible())
	{
        setPositionX(m_body->GetPosition().x * PTM_RATIO);
        setPositionY(m_body->GetPosition().y * PTM_RATIO);
        setRotation(CC_RADIANS_TO_DEGREES(-1 * m_body->GetAngle()));
    }
}
