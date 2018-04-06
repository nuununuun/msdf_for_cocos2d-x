//
//  MainScene.h
//  h
//
//  Created by A on 2018. 4. 5..
//

#ifndef MainScene_h
#define MainScene_h

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class MainScene : public cocos2d::Scene {
public:
    virtual bool init() override;
    
    CREATE_FUNC(MainScene);
    
};

#endif /* MainScene_h */
