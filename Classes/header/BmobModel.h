//
//  BmobModel.h
//  BmobSDK
//
//  Created by Jike on 14-3-20.
//
//

#ifndef __BmobSDK__BmobModel__
#define __BmobSDK__BmobModel__

#include <iostream>
#include "cocos2d.h"
#include "json.h"

class BmobModel : public cocos2d::CCObject{
};

class BmobError :public BmobModel{
    
public:
    CC_SYNTHESIZE(int, m_nErrorCode, ErrorCode);
    CC_SYNTHESIZE(std::string, m_nErrorInfo, ErrorInfo);
};

#endif /* defined(__BmobSDK__BmobModel__) */
