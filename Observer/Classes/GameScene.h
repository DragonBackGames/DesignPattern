/* ----------------------------------------------------------------------------
 *
 * (C) Copyright 2014 Gustavo E. Rangel
 * Brussels, Belgium
 *
 * ----------------------------------------------------------------------------
 */
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

/* ----------------------------------------------------------------------------
 *
 * Includes
 *
 * ----------------------------------------------------------------------------
 */
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"

#include "ControlGameLayer.h"

#include "Player.h"
#include "Enemy.h"
#include "Potion.h"

#include "GameContactListener.h"

USING_NS_CC;

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class GameScene : public Layer
{
public:
    // implement the "static node()" method manually
    CREATE_FUNC(GameScene);
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(); 

	CC_SYNTHESIZE(b2World*, m_world, World);
	CC_SYNTHESIZE(Player*, m_player, Player);
	CC_SYNTHESIZE(Enemy*, m_enemy, Enemy);
	CC_SYNTHESIZE(Potion*, m_potion, Potion);
    CC_SYNTHESIZE_READONLY(b2Body*, m_screenBorderBody, ScreenBorderBody);
    
private:
    // Create background layer
    ControlGameLayer* setupControlGameLayer();
    
    // standard Cocos2d layer method
    virtual void update(float dt);
    // standard Cocos2d layer method
    virtual void draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated);
    // Touches functions
    virtual void onTouchesBegan(Touch* touches, Event* event);
    virtual void onTouchesMoved(Touch* touches, Event* event);
    virtual void onTouchesEnded(Touch* touches, Event* event);
    
    // Screen size
    Size m_screenSize;
	// used to draw debug data
	GLESDebugDraw* m_debugDraw;
	// Controller layer object
	ControlGameLayer* controllerLayer;
    // Contact listener
    GameContactListener* m_gameContactListener;
    
    LabelTTF* m_healthLabel;
    LabelTTF* m_manaLabel;
};

#endif // __GAME_SCENE_H__
