
#include "Pause.h"

using namespace cocos2d;

namespace game
{
	bool Pause::init()
	{
		// Se intenta inicializar la clase base y, si falla, se retorna con error:
		Size visibleSize = Director::getInstance()->getVisibleSize();

		if (!cocos2d::Scene::init())
		{
			return false;
		}

		//Se crea el event listener
		auto TouchListener = EventListenerTouchOneByOne::create();
		// Se crea una capa y se a�ade a la escena:
		auto layer = Layer::create();
		this->addChild(layer);
		//Se crean los botones y se a�aden a la escena
		resume = Sprite::create("Resume.png");
		resume->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2+200));
		
		menu = Sprite::create("Menu.png");
		menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 100));
		menu->setScale((float)0.3, (float)0.3);
		this->addChild(resume);
		this->addChild(menu);
		
		//Se inicializa el metodo onTouchBegan del listener
		TouchListener->onTouchBegan = CC_CALLBACK_2(Pause::onTouchBegan, this);
		layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(TouchListener, layer);

		return true;
	}
	bool Pause::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
	{
		//Si el punto de clicado esta contenido en el boton del menu se lanza la escena del menu
		if (menu->getBoundingBox().containsPoint(touch->getLocation()))
		{
			auto scene = game::Menu::create();
			Director::getInstance()->replaceScene(scene);
		}
		//Si el punto de clicado esta contenido en el boton de resume se vuelve a la escena de juego

		if (resume->getBoundingBox().containsPoint(touch->getLocation()))
		{
			Director::getInstance()->popScene();
		}
		return false;
	}

}