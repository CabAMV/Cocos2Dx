#include "Obama.h"



namespace game
{
	Obama::Obama()
	{
	}

	void Obama::start(Size t)
	{
		//Se inicializan las variables de la clase
		int x = t.width;
		int y = t.height;
		//Se coloca en la escena y se inicializa su velocidad
		this->setPosition(Vec2(rand()%x,rand()%y));
		this->setScale((float)0.3, (float)0.3);
		speed = 1;
	}

	void Obama::move(float delta,Vec2 target)
	{
		//Se crea el vector direccion y se mueve hacia la direccion que este indica
		Vec2 direction = target - this->getPosition();
		direction.normalize();
		this->setPosition(Vec2(this->getPosition().x + speed * direction.x, this->getPosition().y + speed * direction.y));
	}

	void Obama::relocate(Size t)
	{
		//Se recoloca a este enemigo fuera de los limites de la pantalla de forma pseudoaleatoria
		srand(time(NULL));
		int first = rand() % 20;
		int second = rand() % 20;

		if (first<10) //laterales
		{
			if (second <10)	//izquierda
				this->setPosition(Vec2(-100,rand() % (int)t.height));
			else if (second >10)
				this->setPosition(Vec2(t.width+100, rand() %  (int)t.height));
		}
		else if(first>10)//arriba/abajo
		{
			if (second <10)	//izquierda
				this->setPosition(Vec2(rand() % (int)t.width,-100 ));
			else if (second >10)
				this->setPosition(Vec2(rand() % (int)t.width, (int)t.height+100) );
		}
	
	}
	
}

