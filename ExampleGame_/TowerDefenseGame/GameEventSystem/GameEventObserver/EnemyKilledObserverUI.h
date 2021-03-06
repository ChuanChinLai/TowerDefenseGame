#pragma once

#include "IGameEventObserver.h"

namespace Gameplay
{
	class EnemyKilledSubject;

	class EnemyKilledObserverUI : public IGameEventObserver
	{
	public:
		inline virtual void _Update() override;
		inline virtual void _SetSubject(IGameEventSubject* i_Subject) override;

	private:

		EnemyKilledSubject * m_pSubject = nullptr;
	};
}


#include "EnemyKilledObserverUI_inline.h"