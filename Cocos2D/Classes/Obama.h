

#include "cocos2d.h"
#include "Collider.h"
//#include <Vec2.h>
#ifndef Obama_H
#define Obama_H
using namespace cocos2d;
namespace game
{
	using cocos2d::Vec2;
	using cocos2d::Touch;
	using cocos2d::Sprite;
	class Obama : public Collider
	{
	private:
		int speed;
		// ... 

	public:
		Obama();


		void start(Size size);

		void move(float delta,Vec2 target);

		void relocate(Size t);

		static Obama * create()
		{
			return Collider::re< Obama >("obama_face.png");
		}
		

	};
}


#endif




	


