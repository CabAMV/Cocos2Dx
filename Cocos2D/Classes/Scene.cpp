
#include "Scene.hpp"
#include "Menu.h"
#include "Pause.h"

#include <cmath> 

#define COCOS2D_DEBUG 1

using namespace cocos2d;

namespace game
{

    bool Scene::init ()
    {
        // Se intenta inicializar la clase base y, si falla, se retorna con error:
		Size visibleSize = Director::getInstance()->getVisibleSize();

        if (!cocos2d::Scene::init ())
        {
            return false;
        }

        // Se crea el event listener
		auto TouchListener = EventListenerTouchOneByOne::create();
		// Se crea una capa y se añade a la escena:
        auto layer = Layer::create ();
		//Se establece el maximo numero de proyectiles que habra en pantalla
		maxProjectiles = 20;	
		//Se inicializan los sprites presentes en la escena. Se establece su posicion y su escala.
		Trump = Sprite::create("Face.png");
		Trump->setScale((float)0.3, (float) 0.3);
		Trump->setPosition(Vec2(visibleSize.width / 2.0,(visibleSize.width / 2 *0.4)+ (Trump->getContentSize().height/2*0.3)));
		
		Background= Sprite::create("Background.jpg");
		Background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2+20));
		Background->setScale((float)2.3,2);

		//Se establece la vida que tiene el jugador.
		life = 1000;
		
		//Se establece el punto objetivo inicial del personaje.
		TrumTarget=Trump->getPosition();
		
		//Se añaden el fondo y el personaje a la escena.
		this->addChild(Background);
		this->addChild(Trump);

		//Se inicializan los enemigos y se añaden a la escena
		for (int i = 0; i < 10; i++) 
		{
			obamasArray.insert( i,Obama::create());
			obamasArray.at(i)->start(visibleSize);
			this->addChild(obamasArray.at(i));
			
		}
		//Se inicializan los proyectiles
		for (int i = 0; i < maxProjectiles; i++) 
		{
			Projectiles.insert(i, Bullet::create());
		}
		//Se inicializa y añade a la escena el boton de pausa.
		PauseButton = Sprite::create("pause.png");
		PauseButton->setScale((float)0.1, (float)0.1);
		PauseButton->setPosition(Vec2(visibleSize.width- (PauseButton->getContentSize().width*PauseButton->getScaleX())/2, visibleSize.height-(PauseButton->getContentSize().height*PauseButton->getScaleY()) / 2));
		this->addChild(PauseButton);
		//Se añade la capa
		this->addChild (layer);

        // ...
		//Se inicializa el evento onTouchBegan del listener
		TouchListener->onTouchBegan = CC_CALLBACK_2(Scene::onTouchBegan, this);
		layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(TouchListener, layer);
		//Se ejecuta la funcion update
		scheduleUpdate();
        return true;
    }

	void Scene::update(float delta)
	{	
			//Se mueve el personaje
			MoveTrump();
			//Se mueven todos los enemigos hacia el personaje
			for (int i = 0; i < obamasArray.size(); i++)
			{
				obamasArray.at(i)->move(delta, Trump->getPosition());

			}
			//Se mueven todos los proyectiles que esten activos
			for (int j = 0; j < Projectiles.size(); j++)
			{
				Projectiles.at(j)->move(delta);
				//Desactiva los proyectiles que se salen de la pantalla
				removeLostBullets(j);
			}
			//Comprobamos si las balas o los enemigos han inpactado con algo
			checkImpacts();
			//Si la vida llega a cero cabiamos a la escena de gameover
			if (life <= 0) 
			{
				auto scene = game::GameOver::create();
				Director::getInstance()->replaceScene(scene);
			}

	}

	bool Scene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event *)
	{
		bool pauseClicked = false;

		//Si el boton de pausa es pulsado se activa la escena de pausa y se pausa la actual
		if (PauseButton->getBoundingBox().containsPoint(touch->getLocation()))
		{
			pauseClicked = true;
			auto scene = game::Pause::create();
			Director::getInstance()->pushScene(scene);



		}
		bool enemyTouched = false;
		//Si el punto de pulsado no es el boton de pausa
		if (!pauseClicked){
			//Comprobamos si un enemigo ha sido pulsado
			for (int i = 0; i < obamasArray.size(); i++)
			{
				if (obamasArray.at(i)->getBoundingBox().containsPoint(touch->getLocation()))
				{
					enemyTouched = true;
				}

			}
		//Si la comprobacion anterior es afirmativa se activa un proyectil cuyo objetivo es el punto de clicado
		if (enemyTouched) 
		{
				for (int i = 0; i < Projectiles.size(); i++)
				{
					if (!this->getChildren().contains(Projectiles.at(i)))
					{
						Projectiles.at(i)->start(Trump->getPosition(), touch->getLocation());
						this->addChild(Projectiles.at(i));
						Projectiles.at(i)->active = true;
						return false;
					}
				}
		}
		//Si la comprobacion anterior es negativa se pone como objetivo del jugador el punto de clicado
		else
		{

			TrumTarget = touch->getLocation();
			return false;

		}

	}
		return false;
	}


	void Scene::MoveTrump() 
	{
		//Creamos e inicializamos el vector de direccion del jugador
		Vec2 direction = TrumTarget - Trump->getPosition();
		direction.normalize();
		//Cambiamos la posicion de la dimension X añadiendole 10 pixels a la posicion actual en la direccion del vector
		if(std::abs(TrumTarget.x - Trump->getPosition().x) >5)
			Trump->setPosition(Vec2(Trump->getPosition().x+ 10 *direction.x, Trump->getPosition().y));
		//Cambiamos la posicion de la dimension Y añadiendole 10 pixels a la posicion actual en la direccion del vector
		if (std::abs(TrumTarget.y - Trump->getPosition().y) >5)
			Trump->setPosition(Vec2(Trump->getPosition().x, Trump->getPosition().y + 10 * direction.y));
		
		
		
	}

	void Scene::removeLostBullets(int j)
	{
		//Si el proyectil a evaluar sale de los limites de la pantalla es desactivado.
		if (Projectiles.at(j)->getPosition().x < 0 - (Projectiles.at(j)->getContentSize().width / 2 * Projectiles.at(j)->getScaleX()) ||
			Projectiles.at(j)->getPosition().x > Director::getInstance()->getVisibleSize().width + (Projectiles.at(j)->getContentSize().width / 2 * Projectiles.at(j)->getScaleX()))
		{
			this->removeChild(Projectiles.at(j), true);
			Projectiles.at(j)->active = false;

		}
		if (Projectiles.at(j)->getPosition().y < 0 - (Projectiles.at(j)->getContentSize().height / 2 * Projectiles.at(j)->getScaleY()) ||
			Projectiles.at(j)->getPosition().y > Director::getInstance()->getVisibleSize().height + (Projectiles.at(j)->getContentSize().height / 2 * Projectiles.at(j)->getScaleY()))
		{
			this->removeChild(Projectiles.at(j), true);
			Projectiles.at(j)->active = false;
		}
	}

	void Scene::checkImpacts()
	{
		//Se comprueba cada uno de los enemigos
		for (int i = 0; i < obamasArray.size(); i++) 
		{
			//Si el enemigo evaluado intersecta con el jugador se reduce su vida
			if (obamasArray.at(i)->getBoundingBox().intersectsRect(Trump->getBoundingBox())) 
			{
				life--;

			}
			
			for (int j = 0; j < Projectiles.size(); j++) 
			{
				//Si un proyectil colisiona con uno de los enemigos se desactiva dicho proyectil y se recoloca al enemigo
				if (Projectiles.at(j)->active && obamasArray.at(i)->getBoundingBox().intersectsRect(Projectiles.at(j)->getBoundingBox()))
				{
					this->removeChild(Projectiles.at(j),false);
					Projectiles.at(j)->active = false;
					obamasArray.at(i)->relocate(Director::getInstance()->getVisibleSize());
				}
				
			}
		}
	}




}
