//
//  BmobDelegate.h
//  BmobSDK
//
//  Created by Jike on 14-3-19.
//
//

#ifndef __BmobSDK__BmobDelegate__
#define __BmobSDK__BmobDelegate__

#include <iostream>
class BmobError;
class BmobDelegate{
public:
    virtual void onRequestSuccess(std::string tag,void *data) = 0;
    virtual void onRequestError(std::string tag,BmobError *bmobError) = 0;
};

#endif /* defined(__BmobSDK__BmobDelegate__) */
