#include "Bullet.h"



namespace game
{
	Bullet::Bullet()
	{
	}

	void Bullet::start(Vec2 pos,Vec2 target)
	{
		//Se inicializan las variables de la clase y se coloca en la escena
		this->setPosition(pos);
		Target = target;
		direction=Target - this->getPosition();
		direction.normalize();
		speed = 10;
		active = false;
	}

	void Bullet::move(float delta)
	{
		//En caso de estar activo se mueve en la direccion del vector dado
		if(active)
			this->setPosition(Vec2(this->getPosition().x + speed * direction.x, this->getPosition().y + speed * direction.y));
	}



}