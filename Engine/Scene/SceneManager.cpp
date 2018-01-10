#include "SceneManager.h"
#include "IGameScene.h"

#include <Engine\GameObject\GameObject.h>
#include <Engine\GameEngine\GameEngine.h>

Engine::SceneManager::~SceneManager()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Release();
		delete m_pCurrentScene;
		m_pCurrentScene = nullptr;
	}
}

void Engine::SceneManager::_SetGameScene(IGameScene * i_Scene)
{
	m_bRunBegin = false;

	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Release();
		delete m_pCurrentScene;
	}

	m_pCurrentScene = i_Scene;
}

Engine::IGameScene * Engine::SceneManager::_GetGameScene()
{
	return m_pCurrentScene;
}


void Engine::SceneManager::_Update()
{
	if (m_pCurrentScene != nullptr && m_bRunBegin == false)
	{
		m_pCurrentScene->_Init();
		m_bRunBegin = true;
	}

	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Update();
	}
}

void Engine::SceneManager::_Render()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_SubmitDataToBeRendered();

		{
			for (size_t i = 0; i < m_pCurrentScene->m_RenderedData.SpriteObjects.size(); i++)
			{
				Asset::SpriteObject* s = m_pCurrentScene->m_RenderedData.SpriteObjects[i];

				Asset::Component_Renderable* pComponent = s->_GetComponent_Renderable();

//				SDL_Rect DestRect = { static_cast<int>(s->m_Position.x), static_cast<int>(s->m_Position.y), s->_GetComponent_Renderable()->w, s->_GetComponent_Renderable()->h };
				SDL_Rect DestRect = _GetRenderPosition(pComponent);
				SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), s->_GetComponent_Renderable()->pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
			}

			m_pCurrentScene->m_RenderedData.SpriteObjects.clear();
		}

		{
			for (size_t i = 0; i < m_pCurrentScene->m_RenderedData.TextObjects.size(); i++)
			{
				Asset::TextObject* t = m_pCurrentScene->m_RenderedData.TextObjects[i];
				Asset::Component_Renderable* pComponent = t->_GetComponent_Renderable();
	//			SDL_Rect DestRect = { static_cast<int>(t->m_Position.x), static_cast<int>(t->m_Position.y), t->_GetComponent_Renderable()->w, t->_GetComponent_Renderable()->h };
				SDL_Rect DestRect = _GetRenderPosition(pComponent);
				SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), t->_GetComponent_Renderable()->pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
			}

			m_pCurrentScene->m_RenderedData.TextObjects.clear();
		}
	}

}

void Engine::SceneManager::_Release()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Release();
	}
}

SDL_Rect Engine::SceneManager::_GetRenderPosition(Asset::Component_Renderable * i_pComponent)
{
	int x = static_cast<int>(i_pComponent->m_GameObject->m_Position.x);
	int y = static_cast<int>(i_pComponent->m_GameObject->m_Position.y);
	int w = i_pComponent->w;
	int h = i_pComponent->h;

	x -= w / 2;
	y -= h / 2;

	SDL_Rect DestRect = { x, y, w, h };

	return DestRect;
}


