#pragma once

#include <Engine\Math\Vector4D.h>
#include <list>

namespace Engine
{
	namespace Asset
	{
		class SpriteObject;
		class TextObject;
	}
}

namespace Gameplay
{
	class CharacterAttr;

	class ICharacter
	{
	public:
		ICharacter();
		virtual ~ICharacter();

		virtual void _Init();
		virtual void _Update();
		virtual void _Release();

		void _MoveTo(const Engine::Math::Vector4D<float>& i_Position);
		void _UpdateAI(const std::list<ICharacter*>& i_Target);
		bool _IsKilled();

		int  _GetATK();
		Engine::Asset::SpriteObject* _GetGameObject();
		Engine::Asset::TextObject*	 _GetTextObject_HP();

	protected:
		Engine::Asset::SpriteObject* m_pGameObject;
		Engine::Asset::TextObject*   m_pTextObject_HP;

		CharacterAttr*				 m_pAttribute;

	private:
		bool m_bKilled;
	};
}