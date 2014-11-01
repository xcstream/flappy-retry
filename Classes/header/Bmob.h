//
//  Bmob.h
//  Bmob
//
//  Created by Jike on 14-3-18.
//
//

#ifndef __Bmob__Bmob__
#define __Bmob__Bmob__

#include <iostream>
#include "cocos2d.h"
#include "BmobParams.h"
#include "BmobDelegate.h"

class Bmob{
public:
    static std::string APP_ID;
    static std::string S_ID;
public:
    //init
    static void init(std::string appid);
    static void init(std::string appid,std::string sid);
    
    //create
    static void create(std::string tableName,BmobObject* params,BmobDelegate* delegate);
    
    //update
    static void update(std::string tableName,std::string objectId, BmobObject* params,BmobDelegate* delegate);
    
    //delete
    static void remove(std::string tableName,std::string objectId,BmobDelegate* delegate);
    
    //Query
    static void query(std::string tableName,BmobDelegate* delegate);
    static void query(std::string tableName,BmobQuery *bmobQuery,BmobDelegate* delegate);
    static void query(std::string tableName,BmobQuery *bmobQuery,BmobQueryShow *bmobQueryShow,BmobDelegate* delegate);
    
    //Query with objectId
    static void queryWithObjectId(std::string tableName,std::string objectId,BmobDelegate* delegate);
    
    //Query with geopoint
    static void whereNear(std::string tableName,std::string key,BmobGeopoint *geoPoint,BmobDelegate* delegate);
    static void whereWithinKilometers(std::string tableName,std::string key,BmobGeopoint *geoPoint,double maxDistance,BmobDelegate* delegate);
    static void whereWithinMiles(std::string tableName,std::string key,BmobGeopoint *geoPoint,double maxDistance,BmobDelegate* delegate);
    static void whereWithinRadians(std::string tableName,std::string key,BmobGeopoint *geoPoint,double maxDistance,BmobDelegate* delegate);
    static void whereWithinGeoBox(std::string tableName,std::string key,BmobGeopoint *geoPoint1,BmobGeopoint *geoPoint2,BmobDelegate* delegate);

    //user signup
    static void userSignup(BmobUser *user,BmobDelegate* delegate);
    
    //user login
    static void userLogin(BmobUser *user,BmobDelegate* delegate);
    
    //user reset
    static void userReset(std::string email,BmobDelegate* delegate);
    
    //user update
    static void userUpdate(std::string objectId, BmobObject* params,BmobDelegate* delegate);
    
    //user delete
    static void userRemove(std::string objectId,BmobDelegate* delegate);
    
    //upload
    static void uploadFile(std::string path,std::string filename,BmobDelegate* delegate);
    //endpoint
    static void endPoint(std::string fuctionName,BmobDelegate* delegate);
    static void endPoint(std::string fuctionName,BmobObject* params,BmobDelegate* delegate);
    //timestamp
    static void getTimestamp(BmobDelegate* delegate);
};

#endif /* defined(__BmobSDK__BmobSDK__) */