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
#include "GameScene.h"

#ifndef __GAME_CONTACT_LISTENER_H__
#define __GAME_CONTACT_LISTENER_H__

USING_NS_CC;

/* ----------------------------------------------------------------------------
 *
 * Class definition
 *
 * ----------------------------------------------------------------------------
 */
class GameContactListener : public b2ContactListener
{
public:
    // called by Box2D during the Step function when two fixtures begin touching
	virtual void BeginContact(b2Contact* contact);
    // called by Box2D during the Step function when two fixtures finish touching
	virtual void EndContact(b2Contact* contact);
    
    class GameScene* m_layer;
};

#endif //__GAME_CONTACT_LISTENER_H__