#include "StageSystem.h"

#include <Engine\GameEngine\Includes.h>
#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\EnemyTowerAttackedObserverUI.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\SoldierTowerAttackedObserverUI.h>

#include <iostream>

Gameplay::StageSystem::StageSystem(TowerDefenseGame * i_pTDGame) : IGameSystem(i_pTDGame), PLAYER_HP(10), AI_HP(10)
{
	m_pTDGame->_RegisterGameEvent(ENUM_GameEvent::EnemyTowerUnderAttack, new Gameplay::EnemyTowerAttackedObserverUI(m_pTDGame, this));
	m_pTDGame->_RegisterGameEvent(ENUM_GameEvent::SoldierTowerUnderAttack, new Gameplay::SoldierTowerAttackedObserverUI(m_pTDGame, this));
}

void Gameplay::StageSystem::_Init()
{
	m_pTower_Soldier = new Engine::Asset::GameObject();
	m_pTower_Enemy	 = new Engine::Asset::GameObject();


	m_AttackPos_Soldier = Engine::Math::Vector4D<float>(550, 300, 0);
	m_AttackPos_Enemy   = Engine::Math::Vector4D<float>(250, 300, 0);

	*(m_pTower_Soldier->Transform->Position) = m_AttackPos_Enemy;
	*(m_pTower_Enemy->Transform->Position)   = m_AttackPos_Soldier;

	{
		m_pTower_Soldier->_AddComponent<Engine::Asset::Sprite>();
		Engine::Asset::Sprite* pSprite = m_pTower_Soldier->_GetComponent<Engine::Asset::Sprite>();
		pSprite->_Create("Textures/Star_Green.png");
	}

	{
		m_pTower_Enemy->_AddComponent<Engine::Asset::Sprite>();
		Engine::Asset::Sprite* pSprite = m_pTower_Enemy->_GetComponent<Engine::Asset::Sprite>();
		pSprite->_Create("Textures/Star_Red.png");
	}
}

void Gameplay::StageSystem::_Update()
{

}

void Gameplay::StageSystem::_Release()
{
	delete m_pTower_Soldier;
	delete m_pTower_Enemy;
}

void Gameplay::StageSystem::_RenderObjects(Engine::IGameScene * i_pScene) const
{
	Engine::SubmitGameObject(i_pScene, m_pTower_Soldier);
	Engine::SubmitGameObject(i_pScene, m_pTower_Enemy);
}