#pragma once

#include <Geode/Geode.hpp>
#include <string>

class Checkbox {
public:
    static cocos2d::CCMenu* create(cocos2d::CCObject* target, const std::string& text, cocos2d::SEL_MenuHandler selector);
    static cocos2d::CCMenu* create(cocos2d::CCObject* target, const std::string& text, cocos2d::SEL_MenuHandler selector, bool toggled);
};
