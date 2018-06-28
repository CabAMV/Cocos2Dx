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

		// Esta macro crea la implementación de un método create() predefinido que sirve para
		// crear instancias de esta clase:
		CREATE_FUNC(Pause);

		/// Este método se llamará automáticamente para inicializar la escena.
		bool init() override;
		bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);

		Sprite * resume;
		Sprite * menu;




	};

}

#endif