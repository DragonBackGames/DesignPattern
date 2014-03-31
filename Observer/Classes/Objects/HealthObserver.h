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
#include "b2SpriteObserver.h"
#include "b2Sprite.h"

#ifndef __HEALTH_OBSERVER__
#define __HEALTH_OBSERVER__

class HealthObserver : public b2SpriteObserver
{
public:
	HealthObserver(b2Sprite *model, int deltaHealth)
	{
		model->attach(this);
		m_model = model;
		m_deltaHealth = deltaHealth;
	}

	void update()
	{
		m_model->setHealth(m_model->getHealth() + m_deltaHealth);
	}
private:
	b2Sprite* m_model;
	int m_deltaHealth;
};

#endif // __HEALTH_OBSERVER__