#include "GameOver.h"

using namespace cocos2d;

namespace game
{
	bool GameOver::init()
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

		Gameover = Sprite::create("gameover.png");
		Gameover->setPosition(Vec2(visibleSize.width/2, visibleSize.height / 2+200));
		Gameover->setScale((float)0.5, (float)0.5);


		menu = Sprite::create("Menu.png");
		menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		menu->setScale((float)0.3, (float)0.3);

		game = Sprite::create("Play.png");
		game->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2-200));
		game->setScale((float)0.5, (float)0.5);

		this->addChild(Gameover);
		this->addChild(menu);
		this->addChild(game);
		
		//Se inicializa el metodo onTouchBegan del listener
		TouchListener->onTouchBegan = CC_CALLBACK_2(GameOver::onTouchBegan, this);
		layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(TouchListener, layer);

		return true;
	}
	bool GameOver::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
	{
		//Si es pulsado el boton de menu se crea la escena de menu
		if (menu->getBoundingBox().containsPoint(touch->getLocation())) 
		{
			auto scene = game::Menu::create();
			Director::getInstance()->replaceScene(scene);
		}
		//Si es pulsado el boton de juego se crea la escena de juego
		if(game->getBoundingBox().containsPoint(touch->getLocation()))
		{
			auto scene = game::Scene::create();
			Director::getInstance()->replaceScene(scene);
		}

		return false;
	}

}