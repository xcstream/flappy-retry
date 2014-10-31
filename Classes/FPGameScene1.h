//
//  FPGameScene1.h
//  flappyplane
//
//  Created by xcstream on 10/30/14.
//
//

#ifndef __flappyplane__FPGameScene1__
#define __flappyplane__FPGameScene1__

#include <stdio.h>

class GameScene1 : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene1);
    
private:
    void menu1click(Ref* pSender);
    void levelclick(cocos2d::Ref* pSender);

};


#endif /* defined(__flappyplane__FPGameScene1__) */
