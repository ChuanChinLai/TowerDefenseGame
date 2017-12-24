#pragma once

#include <string>
#include <iostream>

namespace Engine
{
	namespace Asset
	{
		class GameObject;
	}


	class SceneManager;

	class IGameScene
	{
	public:

		IGameScene(SceneManager* i_pSceneManager);

		void SubmitBackgroundColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A);
		void SubmitGameObject(Asset::GameObject* i_Object);

		virtual void _Init() = 0;
		virtual void _Update() = 0;
		virtual void _Release() = 0;
		virtual void _SubmitDataToBeRendered() = 0;

		inline void SetName(std::string i_Name);
		inline std::string ToString() const;

	protected:
		SceneManager * m_pSceneManager;
		std::string m_Name;
	};
}

#include "IGameScene_inline.h"