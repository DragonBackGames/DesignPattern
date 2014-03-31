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
#include "cocos2d.h"
#include "Box2D.h"
#include "GLES-Render.h"

#ifndef __B2SPRITE_H__
#define __B2SPRITE_H__

USING_NS_CC;

class GameLayer;

enum
{
    kShip = 0,
	kEnemy,
	kAmmunition,
    kBullet,
};

class b2Sprite : public CCSprite
{    
public:
    
    b2Sprite(GameLayer* game, int type);
	virtual void setSpritePosition (CCPoint position);
    virtual void update(float dt);

	CC_SYNTHESIZE(GameLayer*, m_game, Game);
    CC_SYNTHESIZE(b2Body*, m_body, Body);
    CC_SYNTHESIZE(int, m_type, Type);    
};

#endif /* __B2SPRITE_H__ */