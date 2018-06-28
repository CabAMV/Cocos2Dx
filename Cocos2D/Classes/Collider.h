
#include "cocos2d.h"

#ifndef Collider_H
#define Collider_H
namespace game
{
	using cocos2d::Vec2;
	using cocos2d::Touch;
	using cocos2d::Sprite;


	class Collider : public cocos2d::Sprite
	{
	public:
		
		template< class Derived_class >
		static Derived_class * re(const char * textureName)
		{
			std::unique_ptr< Derived_class > sprite(new (std::nothrow) Derived_class);

			if (sprite)
			{
				if (sprite->initWithFile(textureName))
				{
					return sprite.release();
				}
			}

			return nullptr;
		}
	
	
	};		

}
#endif