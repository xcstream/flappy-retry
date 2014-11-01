//
//  BmobFileUtil.h
//  BmobSDK
//
//  Created by Jike on 14-3-26.
//
//

#ifndef __BmobSDK__BmobFileUtil__
#define __BmobSDK__BmobFileUtil__

#include <iostream>
#include "cocos2d.h"
#include "BmobDelegate.h"
class BmobDelegate;
class BmobFileUtil{
public:   
    static void uploadFile(std::string path,std::string filename,BmobDelegate* delegate);
        
    static size_t write_data(uint8_t *dataBack, size_t size, size_t nmemb, void *userp);
private:
    static BmobDelegate *m_pDelegate;
};

#endif /* defined(__BmobSDK__BmobFileUtil__) */
