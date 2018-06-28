#include "Intro.h"

using namespace cocos2d;

namespace game
{
	bool Intro::init()
	{
		// Se intenta inicializar la clase base y, si falla, se retorna con error:
		Size visibleSize = Director::getInstance()->getVisibleSize();

		if (!cocos2d::Scene::init())
		{
			return false;
		}

		// Se crea una capa y se añade a la escena:

		auto layer = Layer::create();
		this->addChild(layer);
		//Se inicia el tiempo que a de estar esperando a cambiar de escena
		timer = 200;
		//Se crea el sprite del logo y se añade a la escena
		Logo = Sprite::create("logo.jpg");
		Logo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		this->addChild(Logo);
		//Se ejecuta el metodo update
		scheduleUpdate();

		return true;
	}

	void Intro::update(float delta)
	{
		//Cuando la variable timer llega a cero se crea la escena del menu
		timer--;
		if (timer <= 0)
		{
			auto scene = game::Menu::create();
			Director::getInstance()->replaceScene(scene);
		}
	}
}