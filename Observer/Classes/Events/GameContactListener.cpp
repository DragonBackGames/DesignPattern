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
#include "HealthObserver.h"
#include "ManaObserver.h"

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
	if ( fudA && fudA->getType() == kEnemy && fB->GetBody() == m_layer->getPlayer()->getBody())
	{
        HealthObserver* healthObserver = new HealthObserver(m_layer->getPlayer(), -10);
        m_layer->getPlayer()->attach(healthObserver);
	}
	if ( fudB && fudB->getType() == kEnemy && fA->GetBody() == m_layer->getPlayer()->getBody())
	{
        HealthObserver* healthObserver = new HealthObserver(m_layer->getPlayer(), -10);
        m_layer->getPlayer()->attach(healthObserver);
	}

    if ( fudA && fudA->getType() == kPotion && fB->GetBody() == m_layer->getPlayer()->getBody())
	{
        ManaObserver* manaObserver = new ManaObserver(m_layer->getPlayer(), 10);
        m_layer->getPlayer()->attach(manaObserver);
	}
	if ( fudB && fudB->getType() == kPotion && fA->GetBody() == m_layer->getPlayer()->getBody())
	{
        ManaObserver* manaObserver = new ManaObserver(m_layer->getPlayer(), 10);
        m_layer->getPlayer()->attach(manaObserver);
	}

}

/* ----------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------
 */
void GameContactListener::EndContact(b2Contact* contact)
{
    
}