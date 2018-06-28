#ifndef Intro_HEADER
#define Intro_HEADER

#include "cocos2d.h"
#include "Menu.h"





namespace game
{
	using cocos2d::Vec2;
	using cocos2d::Sprite;
	class Intro : public cocos2d::Scene
	{
	private:

		// ...

	public:

		// Esta macro crea la implementación de un método create() predefinido que sirve para
		// crear instancias de esta clase:
		CREATE_FUNC(Intro);

		/// Este método se llamará automáticamente para inicializar la escena.
		bool init() override;
		void update(float delta) override;

		Sprite * Logo;
		int timer;
	};

}

#endif
