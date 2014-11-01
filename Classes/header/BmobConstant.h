//
//  Constant.h
//  BmobSDK
//
//  Created by Jike on 14-3-18.
//
//

#ifndef BmobSDK_Constant_h
#define BmobSDK_Constant_h


const int kErrorUnknown = -4;
const int kErrorServer = -3;
const int kErrorParams= -2;
const int kErrorNetwork = -1;

//http tag
const std::string kTagHttpCreate= "kTagHttpCreate";
const std::string kTagHttpQuery = "kTagHttpQuery";
const std::string kTagHttpUpdate = "kTagHttpUpdate";
const std::string kTagHttpDelete = "kTagHttpDelete";

const std::string kTagHttpUserSignUp = "kTagHttpUserSignUp";
const std::string kTagHttpUserLogin = "kTagHttpUserLogin";
const std::string kTagHttpUserReset = "kTagHttpUserReset";
const std::string kTagHttpUpload = "kTagHttpUpload";

const std::string kTagHttpEndpoint= "kTagHttpEndpoint";
const std::string kTagHttpTimestamp= "kTagHttpTimestamp";
//key
const std::string KEY_OBJECT_ID = "objectId";
const std::string KEY_CREATE_AT = "createdAt";
const std::string KEY_UPDATE_AT = "updatedAt";

//param type
const std::string kTagParamTypeObject = "Objects";
const std::string kTagParamTypeArray = "Arrays";
const std::string kTagParamTypeDate = "Date";
const std::string kTagParamTypeGeopoint = "GeoPoint";
const std::string kTagParamTypeFile = "File";
#endif
