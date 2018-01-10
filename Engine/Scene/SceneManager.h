#pragma once

#include <string>
#include <External\SDL2\Includes.h>

namespace Engine
{
	namespace Asset
	{
		class GameObject;
	}

	class IGameScene;

	class SceneManager
	{
	public:

		SceneManager() : m_pCurrentScene(nullptr), m_bRunBegin(false)
		{

		};

		~SceneManager();

		void _SetGameScene(IGameScene* i_Scene);
		IGameScene* _GetGameScene();

		void _Update();
		void _Render();
		void _Release();

	private:

		SDL_Rect _GetRenderPosition(Asset::GameObject* i_Object);

		IGameScene* m_pCurrentScene;
		bool 		m_bRunBegin;
	};
}

#include "SceneManager_inline.h"