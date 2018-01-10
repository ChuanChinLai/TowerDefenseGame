#pragma once

#include <Engine\Math\Vector4D.h>
#include <External\SDL2\Includes.h>
#include <string>

namespace Engine
{
	class Color;

	namespace Asset
	{
		enum Alignment
		{
			Left,
			Right,
			Center,
			Up,
			Down,
		};

		class GameObject;

		class Component
		{
		public:
			Component(GameObject* i_GameObject) : m_GameObject(i_GameObject)
			{

			}
			virtual ~Component()
			{

			}
			GameObject* m_GameObject;
		};


		class Component_Renderable : public Component
		{
		public:
			Component_Renderable(GameObject* i_GameObject) : Component(i_GameObject), pTexture(nullptr), w(0), h(0)
			{

			}

			~Component_Renderable()
			{

			}

			SDL_Texture*  pTexture;

			int w;
			int h;
		};

		class GameObject
		{
		public:
			
			Math::Vector4D<float> m_Position;
		};


		class TextObject : public GameObject
		{
		public:

			TextObject();
			~TextObject();

			bool _Create(std::string i_Text, Engine::Color i_Color, int i_Size, std::string i_FilePath);
			void _Release();

			inline Component_Renderable* _GetComponent_Renderable();

		private:

			Component* m_pRenderComponent;
		};

		class SpriteObject : public GameObject
		{
		public:

			SpriteObject();
			~SpriteObject();

			bool _Create(std::string i_FilePath);
			void _Release();

			inline Component_Renderable* _GetComponent_Renderable();

		private:
			Component_Renderable* m_pRenderComponent;
		};

	}
}

#include "GameObject_inline.h"