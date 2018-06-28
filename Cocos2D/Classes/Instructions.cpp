
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Copyright (c) ...                                                          *
*  Started on:                                                                *
*  Author:                                                                    *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Instructions.h"
#include "Menu.h"

#define COCOS2D_DEBUG 1

using namespace cocos2d;

namespace game
{

	bool Instructions::init()
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
		
		//Se crean los botones y sprites y se añaden a la escena

		BackButton = Sprite::create("back.png");
		BackButton->setPosition(Vec2(visibleSize.width/2, visibleSize.height / 2-200));
		BackButton->setScale((float)0.3, (float)0.3);
		this->addChild(BackButton);

		Explicacion = Sprite::create("Explicacion.png");
		Explicacion->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 200));
		this->addChild(Explicacion);
		
		//Se inicializa el metodo onTouchBegan del listener
		TouchListener->onTouchBegan = CC_CALLBACK_2(Instructions::onTouchBegan, this);
		layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(TouchListener, layer);
		return true;
	}



	bool Instructions::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event *)
	{
		//Si es pulsado el boton se crea la escena de menu

		if (BackButton->getBoundingBox().containsPoint(touch->getLocation())) 
		{
			auto scene = game::Menu::create();
			Director::getInstance()->replaceScene(scene);
		}
		return false;
	}

}