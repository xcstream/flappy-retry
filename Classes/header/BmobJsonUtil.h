//
//  JsonUtil.h
//  BmobSDK
//
//  Created by Jike on 14-3-25.
//
//

#ifndef __BmobSDK__BmobJsonUtil__
#define __BmobSDK__BmobJsonUtil__

#include <iostream>
#include "cocos2d.h"
#include "json.h"

class BmobJsonUtil{
public:
    static void object2Json(Json::Value *value, std::string key, cocos2d::CCObject *object);
    static void dictionary2Json(Json::Value *value,std::map<std::string, cocos2d::CCObject *> *mapData);
    static void array2Json(Json::Value *jarray, std::vector<cocos2d::CCObject *> *list);
    
    static cocos2d::CCObject* json2Object(Json::Value *value, std::string key);
    static void json2Dictionary(Json::Value *value,std::map<std::string, cocos2d::CCObject *> *mapData);
    static void json2Array(Json::Value *jarray, std::vector<cocos2d::CCObject *> *list);
};
#endif /* defined(__BmobSDK__JsonUtil__) */
