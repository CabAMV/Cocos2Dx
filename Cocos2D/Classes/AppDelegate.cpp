
// ...

#include "AppDelegate.hpp"
#include "Intro.h"


using namespace std;

using namespace cocos2d;

/*static cocos2d::Size designResolutionSize = cocos2d::Size(1280,  720);
static cocos2d::Size smallResolutionSize  = cocos2d::Size( 480,  320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024,  720);
static cocos2d::Size largeResolutionSize  = cocos2d::Size(1920, 1080);*/

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs ()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil:

    GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    auto director = Director::getInstance   ();
    auto glview   = director->getOpenGLView ();
	
	if (!glview)
	{
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
				glview = GLViewImpl::createWithRect("MyGame", Rect(0, 0, designResolutionWidth, designResolutionHeight));
		#else
				glview = GLViewImpl::create("MyGame");
		#endif

		director->setOpenGLView(glview);
	}

	// Se establece la resolución de diseño de las escenas:

	glview->setDesignResolutionSize(designResolutionWidth, designResolutionHeight, ResolutionPolicy::EXACT_FIT);

	// Se establece cuánto hay que escalar los assets para acaptarse a la resolución de diseño:

	director->setContentScaleFactor(float(assetsResolutionWidth) / designResolutionWidth);

    // create a scene. it's an autorelease object
    auto scene = game::Intro::create(); /*con el menu no funciona, no muestra nada por pantalla*/
	
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be paused:

    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here:

    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
