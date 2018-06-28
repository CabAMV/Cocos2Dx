#ifndef Pause_HEADER
#define Pause_HEADER

#include "cocos2d.h"
#include "Menu.h"




namespace game
{
	using cocos2d::Vec2;
	using cocos2d::Touch;
	using cocos2d::Sprite;
	class Pause : public cocos2d::Scene
	{
	private:

		// ...

	public:

		// Esta macro crea la implementaci�n de un m�todo create() predefinido que sirve para
		// crear instancias de esta clase:
		CREATE_FUNC(Pause);

		/// Este m�todo se llamar� autom�ticamente para inicializar la escena.
		bool init() override;
		bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);

		Sprite * resume;
		Sprite * menu;




	};

}

#endif