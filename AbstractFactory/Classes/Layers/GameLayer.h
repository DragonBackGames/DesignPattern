/* ----------------------------------------------------------------------------
 *
 * (C) Copyright 2014 Gustavo E. Rangel
 * Brussels, Belgium
 *
 * ----------------------------------------------------------------------------
 */
#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

/* ----------------------------------------------------------------------------
 *
 * Includes
 *
 * ----------------------------------------------------------------------------
 */
#include "cocos2d.h"
#include "Box2D.h"
#include "GLES-Render.h"
#include "GB2ShapeCache-x.h"

#include "ControlGameLayer.h"

#include "Ship.h"
#include "Ammunition.h"
#include "Weapon.h"

#include "GameContactListener.h"

USING_NS_CC;

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class GameLayer : public CCLayer
{
public:
    // implement the "static node()" method manually
    CREATE_FUNC(GameLayer);
    // Creates the scene of the component
    static CCScene* scene();

	CC_SYNTHESIZE(b2World*, m_world, World);
	CC_SYNTHESIZE(Ship*, m_ship, Ship);
    // List of objects to process
    std::set<b2Sprite*> m_objectsToProcess;
    // List of bullets to process
    std::set<Weapon*> m_bulletsToProcess;
private:
    // Create background layer
    ControlGameLayer* setupControlGameLayer();
    
    // standard Cocos2d layer method
    virtual bool init();
    // standard Cocos2d layer method
    virtual void update(float dt);
    // standard Cocos2d layer method
    virtual void draw();
    // Touches functions
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual void ccTouchesMoved(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    // Screen size
    CCSize m_screenSize;
	// used to draw debug data
	GLESDebugDraw* m_debugDraw;
	// Controller layer object
	ControlGameLayer* controllerLayer;
	// Ammunition
	Ammunition* m_missileAmmunition;
	Ammunition* m_railGuneAmmunition;
	Ammunition* m_waveCannonAmmunition;
	Ammunition* m_bubbleCannonAmmunition;
    // Contact listener
    GameContactListener* m_gameContactListener;
};

#endif // __GAME_LAYER_H__
