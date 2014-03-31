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
#include "Box2D/Box2D.h"
#include "GLES-Render.h"
#include "GB2ShapeCache-x.h"
#include "b2SpriteObserver.h"

#ifndef __B2SPRITE_H__
#define __B2SPRITE_H__

USING_NS_CC;

class GameScene;

enum
{
    kPlayer = 0x0001,
	kEnemy = 0x0002,
	kPotion = 0x0004
};

class b2Sprite : public Sprite
{    
public:
    
    b2Sprite(GameScene* game, int type);
	virtual void setSpritePosition(Point position);
    virtual void update(float dt);
	void attach(b2SpriteObserver* observer);
	void notify();

	CC_SYNTHESIZE(GameScene*, m_game, Game);
    CC_SYNTHESIZE(b2Body*, m_body, Body);
    CC_SYNTHESIZE(int, m_type, Type);
	CC_SYNTHESIZE(int, m_health, Health);
	CC_SYNTHESIZE(int, m_mana, Mana);
private:
    std::vector<b2SpriteObserver*> m_views;
};

#endif /* __B2SPRITE_H__ */