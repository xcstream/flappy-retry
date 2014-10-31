//
//  FPPlayScene.h
//  flappyplane
//
//  Created by xcstream on 11/1/14.
//
//

#ifndef __flappyplane__FPPlayScene__
#define __flappyplane__FPPlayScene__

#include <stdio.h>
class PlayScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void update(float delta);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    
    cocos2d::Sprite* myplane;
    
    CREATE_FUNC(PlayScene);
    
private:
    void menu1click(Ref* pSender);
    bool touchdown;
};

class PlayMenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    // implement the "static create()" method manually
    
    CREATE_FUNC(PlayMenuScene);
    void menu1click(Ref* pSender);
    virtual void update(float delta);
    cocos2d::Label* lbDistance;
  
};


#endif /* defined(__flappyplane__FPPlayScene__) */
