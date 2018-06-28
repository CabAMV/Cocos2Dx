
#include "Menu.h"
#include "Instructions.h"


#define COCOS2D_DEBUG 1

using namespace cocos2d;

namespace game
{

	bool Menu::init()
	{
		// Se intenta inicializar la clase base y, si falla, se retorna con error:
		Size visibleSize = Director::getInstance()->getVisibleSize();

		if (!cocos2d::Scene::init())
		{
			return false;
		}

		//Se crea el event listener
		auto TouchListener = EventListenerTouchOneByOne::create();
		// Se crea una capa y se añade a la escena:
		auto layer = Layer::create();
		this->addChild(layer);
		
		//Se crean los botones y se añaden a la escena

		PlayButton = Sprite::create("Play.png");
		PlayButton->setPosition(Vec2(visibleSize.width/2, visibleSize.height / 2+200));
		Instructions = Sprite::create("Instrucciones.png");
		Instructions->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2-100));
		this->addChild(PlayButton);
		this->addChild(Instructions);

		//Se inicializa el metodo onTouchBegan del listener

		TouchListener->onTouchBegan = CC_CALLBACK_2(Menu::onTouchBegan, this);
		layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(TouchListener, layer);

		
		return true;
	}



	bool Menu::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event *)
	{
		//Si es pulsado el boton de juego se crea la escena de juego
		if (PlayButton->getBoundingBox().containsPoint(touch->getLocation())) 
		{
			auto scene = game::Scene::create();
			Director::getInstance()->replaceScene(scene);
		}
		//Si es pulsado el boton de instrucciones se crea la escena de instrucciones
		if (Instructions->getBoundingBox().containsPoint(touch->getLocation()))
		{
			auto scene = game::Instructions::create();
			Director::getInstance()->replaceScene(scene);
		}
		return false;
	}

}
