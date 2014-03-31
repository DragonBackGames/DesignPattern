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
#include "GameContactListener.h"

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
void GameContactListener::BeginContact(b2Contact* contact)
{
    b2Fixture* fA = contact->GetFixtureA();
    b2Fixture* fB = contact->GetFixtureB();
    
    if( fA == NULL || fB == NULL || m_layer == NULL)
    {
        return;
    }
    
    b2Sprite* fudA = (b2Sprite*)fA->GetBody()->GetUserData();
    b2Sprite* fudB = (b2Sprite*)fB->GetBody()->GetUserData();
    
    // If pick-up destroy it and increment score
	if ( fudA && fudA->getType() == kAmmunition && fB->GetBody() == m_layer->getShip()->getBody())
	{
		m_layer->m_objectsToProcess.insert(fudA);
	}
	if ( fudB && fudB->getType() == kAmmunition && fA->GetBody() == m_layer->getShip()->getBody())
	{
		m_layer->m_objectsToProcess.insert(fudB);
	}
}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameContactListener::EndContact(b2Contact* contact)
{
    
}