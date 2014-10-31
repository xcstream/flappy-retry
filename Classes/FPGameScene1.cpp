//
//  FPGameScene1.cpp
//  flappyplane
//
//  Created by xcstream on 10/30/14.
//
//

#include "FPGameScene1.h"
#include "FPPlayScene.h"
USING_NS_CC;

Scene* GameScene1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene1::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene1::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto height = visibleSize.height;
    auto width = visibleSize.width;
    
    auto background = Sprite::create("res/toi.png");
    background->setPosition(width/2, height/2);
    background->setScale(2.6);
    this->addChild(background,0);
    
    auto label1 = Label::createWithTTF("Back", "fonts/comic andy.ttf", 70);
    auto item1 =MenuItemLabel::create(label1, CC_CALLBACK_1(GameScene1::menu1click, this));
    auto menu = Menu::create(item1, NULL);
    menu->setPosition(52, height-20);
    addChild(menu,100);
    
    auto label2 = Label::createWithTTF("Level Select", "fonts/comic andy.ttf", 70);
    label2->setPosition(width/2,height-50);
    addChild(label2);
    
    for (int i = 1; i<=9; i++) {
        char strbuff[20]={0};
        sprintf(strbuff, "%d",i);
        auto label1 = Label::createWithTTF(strbuff, "fonts/comic andy.ttf", 100);
        auto item1 =MenuItemLabel::create(label1, CC_CALLBACK_1(GameScene1::levelclick, this));
        item1->setPosition((i-5)*100,0);
        item1->setTag(i);
        auto menu = Menu::create(item1, NULL);
        menu->setPosition(width/2, height/2);
        addChild(menu,100);
    }
    return true;
}

void GameScene1::menu1click(Ref* pSender)
{
    Director::getInstance()->popScene();
}

void GameScene1::levelclick(Ref* pSender)
{
    CCLOG("lvclick %d",((Label*)pSender)->getTag());
    auto scene = PlayScene::createScene();
    scene->setTag(((Label*)pSender)->getTag());
    Director::getInstance()->pushScene(scene);
}

void GameScene1::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
