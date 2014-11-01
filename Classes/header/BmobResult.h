//
//  BmobResult.h
//  BmobSDK
//
//  Created by Jike on 14-3-20.
//
//

#ifndef __BmobSDK__BmobResult__
#define __BmobSDK__BmobResult__

#include <iostream>
#include "BmobModel.h"
class BmobObject;
class BmobUser;

class BmobResult:public BmobModel{
public:
    virtual void parse(Json::Value* value){};
};


/**
 *
 */
class BmobResultInfo:public BmobResult{
public:
    virtual void parse(Json::Value* value);
protected:
    CC_SYNTHESIZE(std::string, m_info, ResultInfo);
};


/**
 *
 */
class BmobCreateResult:public BmobResult{
public:
    virtual void parse(Json::Value* value);
protected:
    CC_SYNTHESIZE(std::string, m_oid, ObjectId);
    CC_SYNTHESIZE(std::string, m_createTime, CreateTime);
};


/**
 *
 */
class BmobUpdateResult:public BmobResult{
public:
    virtual void parse(Json::Value* value);
protected:
    CC_SYNTHESIZE(std::string, m_updateTime, UpdateTime);
};


/**
 *
 */
class BmobQueryResult:public BmobResult{
public:
    virtual void parse(Json::Value* value);
protected:
    CC_SYNTHESIZE(int, m_count, Count);
    CC_SYNTHESIZE(std::vector<BmobObject *>, m_list, ResultList);
};


/**
 *继承BmobCreateResult
 */
class BmobUserSignUpResult : public BmobCreateResult{
public:
    virtual void parse(Json::Value* value);
};

/**
 *
 */
class BmobUserLoginResult : public BmobResult{
public:
    BmobUserLoginResult();
    virtual void parse(Json::Value* value);
protected:
    CC_SYNTHESIZE(BmobUser *, m_user, User);
};

/**
 *
 */
class BmobTimeStampResult : public BmobResult{
public:
    virtual void parse(Json::Value* value);
protected:
    CC_SYNTHESIZE(int, m_second, Second);
    CC_SYNTHESIZE(int, m_msecond, MicroSecond);
};

#endif /* defined(__BmobSDK__BmobResult__) */
