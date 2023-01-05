
#include "SplashScene.h"
#include "MainMenuScene.h"
#include "Definition.h"



USING_NS_CC;

Scene* SplashScene::createScene()
{
    return SplashScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SplashScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->scheduleOnce(CC_SCHEDULE_SELECTOR( SplashScene::GoToMainMenuScene ), DISPLAY_TIME_SPLASH_SCENE);
   
    auto backgroundSprite = Sprite::create("HelloWorld.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 , visibleSize.height / 2 ));
    backgroundSprite->setScale(visibleSize.width / backgroundSprite->getContentSize().width, visibleSize.height / backgroundSprite->getContentSize().height);
    this->addChild(backgroundSprite);

    return true;
}
void SplashScene::GoToMainMenuScene(float dt) {
   auto scene = MainMenuScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

