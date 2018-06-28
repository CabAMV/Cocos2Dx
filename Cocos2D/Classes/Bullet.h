#include "cocos2d.h"
#include "Collider.h"
//#include <Vec2.h>

#ifndef Bullet_H
#define Bullet_H
namespace game
{
	using cocos2d::Vec2;
	using cocos2d::Touch;
	using cocos2d::Sprite;
	class Bullet : public Collider
	{
	private:
		int speed;
		// ... 

	public:
		Bullet();
		bool active;
		Vec2 Target;
		Vec2 direction;

		void start(Vec2 pos, Vec2 target);

		void move(float delta);

		static Bullet * create()
		{
			return Collider::re < Bullet >("bala.png");
		}


	};
}
#endif