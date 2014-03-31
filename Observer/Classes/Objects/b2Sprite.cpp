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
#include "GameScene.h"

b2Sprite::b2Sprite(GameScene* game, int type)
{
	m_game = game;
    m_type = type;
	m_health = 1000;
    m_mana = 0;
	scheduleUpdate();
}

void b2Sprite::setSpritePosition (Point position)
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

void b2Sprite::attach(b2SpriteObserver* observer)
{
	m_views.push_back(observer);
}

void b2Sprite::notify()
{
    std::vector<b2SpriteObserver*>::iterator it;
	for (it = m_views.begin(); it != m_views.end(); ++it)
	{
		b2SpriteObserver* view = (b2SpriteObserver*)(*it);
		view->update();
	}
    
    m_views.clear();
}