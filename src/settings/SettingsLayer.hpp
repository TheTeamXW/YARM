#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class SettingsLayer : public geode::Popup {
protected:
    CCMenu* m_tabsMenu = nullptr;
    CCLayer* m_contentLayer = nullptr;
    bool init();
    void switchTab(int tab);

public:
    static SettingsLayer* create();
    void onTabClicked(CCObject* sender);
    void onSafeModeCheckbox(CCObject* sender);
};
