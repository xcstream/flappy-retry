//
//  BmobParams.h
//  BmobSDK
//
//  Created by Jike on 14-3-20.
//
//

#ifndef __BmobSDK__BmobParams__
#define __BmobSDK__BmobParams__

#include <iostream>
#include "BmobModel.h"
#include "BmobConstant.h"

class BmobParams : public BmobModel{
public:
    virtual std::string getType() = 0;
    virtual void enJson(Json::Value* value)=0;
    virtual void deJson(Json::Value* value)=0;
};

/**
 *
 */
class BmobObject:public BmobParams{
public:
    BmobObject();
    BmobObject(std::string objectId);
    virtual std::string getType(){
        return kTagParamTypeObject;
    }
    void addParams(std::string key,cocos2d::CCObject *object);
    CCObject *getParams(std::string key);
    int getCount(){
        return m_mapData.size();
    }
    virtual void enJson(Json::Value* value);
    virtual void deJson(Json::Value* value);
private:
    CC_SYNTHESIZE(std::string, m_oid, ObjectId);
    std::map<std::string, cocos2d::CCObject *> m_mapData;
};


/**
 *
 */
class BmobUser:public BmobObject{
public:
    BmobUser();
    virtual std::string getType(){
        return kTagParamTypeObject;
    }
    virtual void enJson(Json::Value* value);
    virtual void deJson(Json::Value* value);
protected:
    CC_SYNTHESIZE(std::string, m_email, Email);
    CC_SYNTHESIZE(std::string, m_username, UserName);
    CC_SYNTHESIZE(std::string, m_password, PassWord);
};


/**
 *
 */
class BmobArray:public BmobParams{
public:
    BmobArray();
    virtual std::string getType(){
        return kTagParamTypeArray;
    }
    void addParams(cocos2d::CCObject *object);
    cocos2d::CCObject* getParams(int index);
    int getCount(){
        return m_list.size();
    }
    virtual void enJson(Json::Value* value);
    virtual void deJson(Json::Value* value);
private:
    std::vector<cocos2d::CCObject *> m_list;
};


/**
 *
 */
class BmobDate:public BmobParams{
public:
    BmobDate();
    virtual std::string getType(){
        return kTagParamTypeDate;
    }
    virtual void enJson(Json::Value* value);
    virtual void deJson(Json::Value* value);
    void setDate(std::string date){
        m_date = date;
    }
    
    std::string getDate(){
        return m_date;
    }
protected:
    std::string m_date;
};


/**
 *
 */
class BmobGeopoint:public BmobParams{
public:
    BmobGeopoint(double lon,double lat);
    virtual std::string getType(){
        return kTagParamTypeGeopoint;
    }
    virtual void enJson(Json::Value* value);
    virtual void deJson(Json::Value* value);
    
    double getLongitude(){
        return m_lon;
    }
    
    double getLatitude(){
        return m_lat;
    }
    
protected:
    double m_lon;
    double m_lat;
};


/**
 *
 */
class BmobFile:public BmobParams{
public:
    BmobFile();
    virtual std::string getType(){
        return kTagParamTypeFile;
    }
    virtual void enJson(Json::Value* value);
    virtual void deJson(Json::Value* value);
    void setGroup(std::string group){
        m_group = group;
    }
    
    std::string getGroup(){
        return m_group;
    }
    
    void setFileName(std::string filename){
        m_fileName = filename;
    }
    
    std::string getFileName(){
        return m_fileName;
    }
    
    void setFileUrl(std::string url){
        m_fileUrl = url;
    }
    
    std::string getFileUrl(){
        return m_fileUrl;
    }
    
protected:
    std::string m_group;
    std::string m_fileName;
    std::string m_fileUrl;
};


/**
 *查找
 */
typedef enum {
	BmobQueryAll, BmobQueryEqual,BmobQueryNotEqual, BmobQueryGreater, BmobQueryLess,BmobQueryGreaterEqual,BmobQueryLessEqual,
    BmobQueryContainedIn,BmobQueryNotContainedIn,
    BmobQueryExistValue
} BmobQueryType;

typedef enum {
	BmobQueryOr,BmobQueryAnd,BmobQueryNotOr
} BmobQueryGroupType;

typedef enum {
	BmobQueryWhereNear,BmobQueryWithinKilometers,BmobQueryWithinMiles,BmobQueryWithinRadians,BmobQueryWithinGeoBox
} BmobQueryWhereType;


/**
 *查找所需的参数
 */
class BmobQuery:public BmobModel{
protected:
    CC_SYNTHESIZE(Json::Value, m_data,Data);
};


class BmobQuerySimple:public BmobQuery{
public:
    //简单条件
    void addCondition(BmobQueryType type,std::string key,cocos2d::CCObject *condition);
    //复合条件
    void addCondition(BmobQueryType type,std::string key,std::vector<CCObject *> list);
};

/**
 *组合查找
 */
class BmobQueryGroup:public BmobQuery{
public:
    void setCondition(BmobQueryGroupType type,std::vector<BmobQuery *> queryGroup);
};

/**
 *根据地点查找所需的参数
 */
class BmobQueryWithGeoPoint:public BmobQuery{
public:
    void addCondition(BmobQueryWhereType type,std::string key,BmobGeopoint *geopoint);
    void addCondition(BmobQueryWhereType type,std::string key,BmobGeopoint *geopoint,double maxDistance);
    void addCondition(BmobQueryWhereType type,std::string key,BmobGeopoint *geopoint1,BmobGeopoint *geopoint2);
};


/**
 *查找结果显示的条件
 */
class BmobQueryShow:public BmobModel{
public:
    BmobQueryShow();
    virtual void enJson(Json::Value* value);
    void setSkip(int skip){
        m_skip = skip;
    }
    
    void setLimit(int limit){
        m_limit = limit;
    }
    
    void showCount(bool show){
        m_count = show;
    }
    
    void addOrder(std::string order){
        m_orders.push_back(order);
    }
    
    void addKey(std::string key){
        m_keys.push_back(key);
    }
    
protected:
    int m_skip;
    int m_limit;
    bool m_count;
    std::vector<std::string> m_orders;
    std::vector<std::string> m_keys;
};

#endif /* defined(__BmobSDK__BmobParams__) */
