//
//  BmobHttpUtils.h
//  BmobSDK
//
//  Created by Jike on 14-3-20.
//
//

#ifndef __BmobSDK__BmobHttpUtils__
#define __BmobSDK__BmobHttpUtils__

#include <iostream>
#include "cocos2d.h"
#include "HttpClient.h"
#include "HttpRequest.h"
#include "json.h"
#include "BmobParams.h"
#include "BmobDelegate.h"

class BmobHttpUtils : public cocos2d::CCObject{
public:
    static void setToken(std::string token);
    
    void send();
    void send(cocos2d::extension::CCHttpRequest::HttpRequestType type);
    virtual void onHttpRequestCompleted(cocos2d::CCNode *pSender,void *data);
private:
    std::string json2String(Json::Value *value);
    std::vector<std::string> getHeader();
    std::vector<std::string> getHeader2();
    virtual Json::Value getJsonParams();
    void setDefaultParams(Json::Value *value);
    void setDefaultParams2(Json::Value *value);
    char* unGzip(std::string source);
protected:
    CC_SYNTHESIZE(std::string, m_sTableName, TableName);
    CC_SYNTHESIZE(std::string, m_sUrl, Url);
    CC_SYNTHESIZE(std::string, m_sTag, RequestTag);
    CC_SYNTHESIZE(BmobDelegate *, m_pDelegate, BmobDelegate);
};


/**
 *
 */
class BmobHttpUtilCreate : public BmobHttpUtils{
protected:
    BmobHttpUtilCreate();
public:
    BmobHttpUtilCreate(std::string tableName);
    
    virtual Json::Value getJsonParams();
    
protected:
    CC_SYNTHESIZE(BmobObject*, m_params, Params);
};


/**
 *继承BmobHttpUtilCreate
 */
class BmobHttpUtilUpdate : public BmobHttpUtilCreate{
public:
    BmobHttpUtilUpdate(std::string tableName);
    virtual Json::Value getJsonParams();
};


/**
 *
 */
class BmobHttpUtilQuery : public BmobHttpUtils{
public:
    BmobHttpUtilQuery(std::string tableName);
    
    virtual Json::Value getJsonParams();
    
protected:
    CC_SYNTHESIZE(std::string, m_oid, ObjectId);
    CC_SYNTHESIZE(BmobQuery*, m_queryParam,QueryParam);
    CC_SYNTHESIZE(BmobQueryShow*, m_queryParamShow,QueryParamShow);
};


/**
 *
 */
class BmobHttpUtilDelete : public BmobHttpUtils{
public:
    BmobHttpUtilDelete(std::string tableName);
    
    virtual Json::Value getJsonParams();
    
protected:
    CC_SYNTHESIZE(std::string, m_oid, ObjectId);
};


/**
 *
 */
class BmobHttpUtilUserSignup : public BmobHttpUtils{
public:
    BmobHttpUtilUserSignup();
    
    virtual Json::Value getJsonParams();
protected:
    CC_SYNTHESIZE(BmobUser*, m_user, User);
};


/**
 *
 */
class BmobHttpUtilUserLogin : public BmobHttpUtils{
public:
    BmobHttpUtilUserLogin();
    virtual Json::Value getJsonParams();
protected:
    CC_SYNTHESIZE(BmobUser*, m_user, User);
};


/**
 *
 */
class BmobHttpUtilUserReset : public BmobHttpUtils{
public:
    BmobHttpUtilUserReset();
    virtual Json::Value getJsonParams();
protected:
    CC_SYNTHESIZE(BmobObject*, m_params, Params);
};



/**
 *
 */
class BmobHttpUtilEndpoint : public BmobHttpUtils{
public:
    BmobHttpUtilEndpoint(std::string functionName);
    virtual Json::Value getJsonParams();
    
protected:
    CC_SYNTHESIZE(BmobObject*, m_params, Params);
    CC_SYNTHESIZE(std::string, m_functionName, FunctionName);
};


#endif /* defined(__BmobSDK__BmobHttpUtils__) */
