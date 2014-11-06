//
//  FPPlayScene.cpp
//  flappyplane
//
//  Created by xcstream on 11/1/14.
//
//

#include "FPPlayScene.h"

static int distance;
USING_NS_CC;

Scene* PlayScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -200));
    scene->getPhysicsWorld()->setSpeed(1.2);
    
    // 'layer' is an autorelease object
    auto layer = PlayScene::create();
    auto layer2 = PlayMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);
    scene->addChild(layer2);

    
   
    
//    scene->addChild(menulayer);

    // return the scene
    return scene;
}

bool PlayMenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto height = visibleSize.height;
    auto width = visibleSize.width;
    auto label1 = Label::createWithTTF("Back", "fonts/comic andy.ttf", 70);
    auto item1 =MenuItemLabel::create(label1, CC_CALLBACK_1(PlayMenuScene::menu1click, this));
    auto menu = Menu::create(item1, NULL);
    menu->setPosition(52, height-20);
    addChild(menu,100);
    lbDistance=  Label::createWithTTF("--", "fonts/comic andy.ttf", 70);
    lbDistance->setPosition(280,height-20);
    addChild(lbDistance);
    scheduleUpdate();
    return true;
}
void PlayMenuScene::update(float delta){
    static char a[30] = "Velocity:   ";
    sprintf(a+10, "%d",distance);
    lbDistance->setString(a);
}

bool PlayScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto height = visibleSize.height;
    auto width = visibleSize.width;
    auto background = Sprite::create("res/scr1.png");
    background->setPosition(width/2, height/2);
    background->setScale(102.6);
    this->addChild(background,0);
    
    myplane=Sprite::create("res/plpl.png");
    myplane->setPosition(300,300);
    auto body = PhysicsBody::createBox(Size(70, 40));
    body->setMass(1000);
    myplane->setPhysicsBody(body);
    addChild(myplane);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto myListener = EventListenerTouchOneByOne::create();
    
    //如果不加入此句消息依旧会向下传递
    myListener->setSwallowTouches(true);
    
    touchdown = false;

    float playfield_width = visibleSize.width * 2.0; // make the x-boundry 2 times the screen width
    float playfield_height = visibleSize.height * 2.0; // make the y-boundry 2 times the screen height
    Point center = Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    //note : since bounddries are 2 times the screen size calculate new center point
    
    
//    this->runAction(Follow::create(myplane) );
    myplane->getPhysicsBody()->setVelocityLimit(200);
    
    fire = ParticleSun::create();
    fire->setTexture(Director::getInstance()->getTextureCache()->addImage("res/fire.png"));
    
//    fire->setGravity(Vec2(-300,0));
    addChild(fire);
    

    myplane->getPhysicsBody()->getPosition();
    
    myListener->onTouchBegan = [=](Touch* touch,Event* event)
    {
        //some check
        CCLOG("touchbegin");
        touchdown = true;

        if (1)
        {
            return true;
        }
        return false;  
    };
    
    for (int i = 0; i<0; i++) {
        auto x =  arc4random()%(int)width;
        auto y =  arc4random()%(int)height;
        Sprite* rock = Sprite::create("res/debris.png");
        rock->setPosition(x,y);
        rock->setScale(0.3);
        addChild(rock);
        
        rock->setPosition(x,y);
        
        auto rockbody = PhysicsBody::createCircle(30);
//        rockbody->setDynamic(false);
        auto vx =arc4random()%300;
        auto vy =arc4random()%300;
//        rockbody->setVelocity(Vec2(vx-150,vy-150));
        rockbody->setMass(1000);
        rock->setPhysicsBody(rockbody);
        
    }
    
    
    myListener->onTouchMoved = [=](Touch* touch,Event* event)
    {

    };
    
    myListener->onTouchEnded = [=](Touch* touch,Event* event)
    {
        touchdown = false;
        auto angle = myplane->getPhysicsBody()->getRotation();
        
        
        
        auto angle1 = (angle+0) /180*M_PI;
        auto angle2 = (angle+90) /180*M_PI;
//        myplane->getPhysicsBody()->applyForce(Vec2(-600000*cos(angle1),-600000*sin(angle1)));
//        myplane->getPhysicsBody()->applyForce(Vec2(-400000*cos(angle2),-400000*sin(angle2)));
        myplane->getPhysicsBody()->resetForces();
        
        
    };
    dispatcher->addEventListenerWithSceneGraphPriority(myListener,this);

    auto edgeSp = Sprite::create();
    auto body2 = PhysicsBody::createEdgeBox(Size(visibleSize.width*30,visibleSize.height));

    edgeSp->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    edgeSp->setPhysicsBody(body2);
    this->addChild(edgeSp);
    edgeSp->setTag(0);
    
    scheduleUpdate();
    return true;
}

void PlayScene::update(float delta){
    auto pos =myplane->getPosition();
    pos.x -=80;
    fire->setPosition(pos);
    
    if (touchdown) {
//        myplane->getPhysicsBody()->applyTorque(20000);
        auto angle = myplane->getPhysicsBody()->getRotation();
        angle = (-angle+15)*M_PI /180;
        
        myplane->getPhysicsBody()->applyImpulse(Vec2(60000*cos(angle),60000*sin(angle)), Vec2());
//        myplane->getPhysicsBody()->applyTorque(300000);
        myplane->getPhysicsBody()->setAngularVelocity(1.6);
        
    }else{
        myplane->getPhysicsBody()->getCollisionBitmask();
        auto angle = myplane->getPhysicsBody()->getRotation();

        if (sin(angle/180*M_PI) >0.5 ) {
            myplane->getPhysicsBody()->setAngularVelocity(0);

        }else{
            myplane->getPhysicsBody()->setAngularVelocity(-1);

        }

//        myplane->getPhysicsBody()->applyTorque(-20000);

//        myplane->getPhysicsBody()->applyTorque(-2000000);
//        myplane->getPhysicsBody()->resetForces();

    }
    
    Vec2 v = myplane->getPhysicsBody()->getVelocity();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto height = visibleSize.height;
    auto width = visibleSize.width;
    if (myplane->getPositionX() > width) {
        myplane->setPositionX(0);
    }
    if (myplane->getPositionX() <0) {
        myplane->setPositionX(width);
    }
    if (myplane->getPositionY() > height) {
        myplane->setPositionY(0);
    }
    if (myplane->getPositionY() <0) {
        myplane->setPositionY(height);
    }
    distance = v.x;
    
}

void PlayMenuScene::menu1click(Ref* pSender)
{
    Director::getInstance()->popScene();
}



void PlayScene::menuCloseCallback(Ref* pSender)
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
