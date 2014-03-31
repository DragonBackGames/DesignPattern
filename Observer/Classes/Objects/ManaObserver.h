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

#ifndef __MANA_OBSERVER__
#define __MANA_OBSERVER__

class ManaObserver : public b2SpriteObserver
{
public:
	ManaObserver(b2Sprite *model, int deltaMana)
	{
		model->attach(this);
		m_model = model;
		m_deltaMana = deltaMana;
	}

	void update()
	{
		m_model->setMana(m_model->getMana() + m_deltaMana);
	}
private:
	b2Sprite* m_model;
	int m_deltaMana;
};

#endif // __MANA_OBSERVER__