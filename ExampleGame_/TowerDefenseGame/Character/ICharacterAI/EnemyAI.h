#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>

namespace Gameplay
{
	class StageSystem;

	class EnemyAI : public ICharacterAI
	{
	public:
		EnemyAI(ICharacter* i_pCharacter);
		~EnemyAI();

		virtual void ChangeAIState(IAIState* i_pNewAIState) override;
		static void _SetStageSystem(StageSystem* i_pStageSystem);

	private:
		static StageSystem*	m_pStageSystem;
		Engine::Math::Vector4D<float> m_AttackPosition;
	};
}