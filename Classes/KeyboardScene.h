
/*#ifndef __KEYBOARD_SCENE_H__
#define __KEYBOARD_SCENE_H__

#include "cocos2d.h"

class KeyboardScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
    virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
    CREATE_FUNC(KeyboardScene);


private:
    cocos2d::Label* labelTouchInfo;
};
#endif*/