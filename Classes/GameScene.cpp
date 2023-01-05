#include "GameScene.h"
#include "KeyboardScene.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    PhysicsWorld* world = scene->getPhysicsWorld();

    auto layer = GameScene::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());

    scene->addChild(layer);

    return scene;
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameScene.cpp\n");
}

bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite1 = Sprite::create("background.png");
    backgroundSprite1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    backgroundSprite1->setScale(visibleSize.width / backgroundSprite1->getContentSize().width, visibleSize.height / backgroundSprite1->getContentSize().height);
    this->addChild(backgroundSprite1);

        auto backgroundSprite2 = Sprite::create("level1-1.png");
        backgroundSprite2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        backgroundSprite2->setScale(visibleSize.width / backgroundSprite2->getContentSize().width, visibleSize.height / backgroundSprite2->getContentSize().height);
        backgroundSprite2->setName("backgroundSprite2");
        auto physicsBody = PhysicsBody::createBox(backgroundSprite2->getContentSize() / 1.5, PhysicsMaterial(1.0f, 0.0f, 20.0f));
        physicsBody->setDynamic(false);
        backgroundSprite2->setPhysicsBody(physicsBody);
        this->addChild(backgroundSprite2);

         auto caractere = Sprite::create("movein.png");
         caractere->setContentSize(Size(70, 60));
         caractere->setPosition(40,80);
         auto physicsBody2 = PhysicsBody::createBox(caractere->getContentSize(), PhysicsMaterial(100.0f, 0.0f, 20.0f));
         physicsBody2->setDynamic(false);
         physicsBody2->setContactTestBitmask(false);
         physicsBody2->setCollisionBitmask(1);
         physicsBody2->setCategoryBitmask(1);
         caractere->setRotation(0.0f);
         caractere->setPhysicsBody(physicsBody2);
         this->addChild(caractere);
        
        auto eventListener = EventListenerKeyboard::create();
        eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

        Vec2 loc = event->getCurrentTarget()->getPosition();
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            event->getCurrentTarget()->runAction(MoveBy::create(0.01, Vec2(-10, 0)));
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_D:
            event->getCurrentTarget()->runAction(MoveBy::create(0.01, Vec2(10, 0)));
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_W:
            event->getCurrentTarget()->runAction(JumpBy::create(0.5, Vec2(60, 0), 50, 1));
            break;
        case cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case cocos2d::EventKeyboard::KeyCode::KEY_S:
            event->getCurrentTarget()->runAction(JumpBy::create(0.5, Vec2(-60, 0), 50, 1));
            break;
        }
    };
        
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, caractere);
    
    
    auto obs1 = Sprite::create("obs1.png");
    obs1->setContentSize(Size(60,20));
    obs1->setPosition(165,87);
    auto physicsBody3 = PhysicsBody::createBox(obs1->getContentSize() / 1.5, PhysicsMaterial(1.0f, 0.0f, 20.0f));
    physicsBody3->setGravityEnable(false);
    physicsBody3->setDynamic(false);
    physicsBody3->setContactTestBitmask(1);
    physicsBody3->setCollisionBitmask(1);
    physicsBody3->setCategoryBitmask(1);
    obs1->setRotation(0.0f);
    obs1->setPhysicsBody(physicsBody3);
    this->addChild(obs1);

    auto obs2 = Sprite::create("obs2.png");
    obs2->setContentSize(Size(120, 25));
    obs2->setPosition(290, 120);
    auto physicsBody4 = PhysicsBody::createBox(obs2->getContentSize() / 1.5, PhysicsMaterial(1.0f, 0.0f, 20.0f));
    physicsBody4->setGravityEnable(false);
    physicsBody4->setDynamic(false);
    physicsBody4->setContactTestBitmask(1);
    physicsBody4->setCollisionBitmask(1);
    physicsBody4->setCategoryBitmask(1);
    obs2->setRotation(0.0f);
    obs2->setPhysicsBody(physicsBody4);
    this->addChild(obs2);

    auto obs3 = Sprite::create("obs3.png");
    obs3->setContentSize(Size(130, 25));
    obs3->setPosition(450, 160);
    this->addChild(obs3);

    auto door = Sprite::create("door2.png");
    door->setContentSize(Size(50, 80));
    door->setPosition(460, 213);
    this->addChild(door);

    return true;
}
