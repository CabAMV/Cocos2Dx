
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                             *
 *  Copyright (c) ...                                                          *
 *  Started on:                                                                *
 *  Author:                                                                    *
 *                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GAME_SCENE_HEADER
#define GAME_SCENE_HEADER

    #include "cocos2d.h"
	#include "Obama.h"
	#include "Bullet.h"
	#include "GameOver.h"




    namespace game
    {
		using cocos2d::Vec2;
		using cocos2d::Touch;
		using cocos2d::Sprite;
        class Scene : public cocos2d::Scene
        {
        private:

            // ...

        public:

            // Esta macro crea la implementación de un método create() predefinido que sirve para
            // crear instancias de esta clase:
            CREATE_FUNC(Scene);

            /// Este método se llamará automáticamente para inicializar la escena.
            bool init () override;
			void update(float delta) override;

			bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
			void MoveTrump();
			void removeLostBullets(int actualIndex);
			void checkImpacts();

			Sprite * Trump;
			Vec2 TrumTarget;
			Sprite * Background;
			Sprite * PauseButton;
			cocos2d::Vector <Obama *>  obamasArray;
			cocos2d::Vector <Bullet *>  Projectiles;
			Sprite * MenuButton;
			int maxProjectiles;
			int life;

			

        };

    }

#endif
