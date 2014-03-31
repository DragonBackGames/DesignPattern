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

#ifndef __B2SPRITE_FACTORY_H__
#define __B2SPRITE_FACTORY_H__

class b2SpriteFactory
{
 
public:
    // Object creator
    static b2Sprite* createB2Sprite(GameScene* game, int sprite_type, int object_type);
};

#endif // __B2SPRITE_FACTORY_H__