//
//  FPMenuScene.h
//  flappyplane
//
//  Created by xcstream on 10/30/14.
//
//

#ifndef __flappyplane__FPMenuScene__
#define __flappyplane__FPMenuScene__

#include <stdio.h>

#endif /* defined(__flappyplane__FPMenuScene__) */
class MenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
    
private:
    void menu1click(Ref* pSender);

};