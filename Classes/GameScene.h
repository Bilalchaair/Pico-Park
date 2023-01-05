
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();


    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };
    cocos2d::PhysicsWorld* sceneWorld;
};

#endif // __GAME_SCENE_H__
