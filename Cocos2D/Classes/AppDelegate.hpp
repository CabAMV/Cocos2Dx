
// ...

#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

/**
@brief    The cocos2d Application.
Private inheritance here hides part of interface from Director.
*/
class AppDelegate : private cocos2d::Application
{
private:

	// Design Resolution es la resolución "virtual" que tendrán todas las escenas en cualquier dispositivo:

	static const int designResolutionWidth = 1280;             ///< Ancho virtual de todas las escenas
	static const int designResolutionHeight = 720;             ///< Alto  virtual de todas las escenas

	// Assets Resolution es la resolución para la que se prepararon los assets.
	// En proyectos más elaborados normalmente conviene tener varios juegos de assets preparados para
	// diversas resoluciones reales para se tengan que escalar menos:

	static const int assetsResolutionWidth = 1280;
	static const int assetsResolutionHeight = 720;

public:

    void initGLContextAttrs () override;

    /**
    @brief    Implement Director and Scene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    bool applicationDidFinishLaunching () override;

    /**
    @brief  Called when the application moves to the background
    @param  the pointer of the application
    */
    void applicationDidEnterBackground () override;

    /**
    @brief  Called when the application reenters the foreground
    @param  the pointer of the application
    */
    void applicationWillEnterForeground () override;

};

#endif
