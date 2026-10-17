#include "Checkbox.hpp"

using namespace geode::prelude;

CCMenu* Checkbox::create(CCObject* target, const std::string& text, SEL_MenuHandler selector) {
    auto menu = CCMenu::create();
    menu->setContentSize({300.f, 40.f});
    menu->setAnchorPoint({0.f, 0.f});

    auto checkbox = CCMenuItemToggler::create(
        CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png"),
        CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png"),
        target,
        selector
    );
    checkbox->setPosition({20.f, 20.f});
    menu->addChild(checkbox);

    auto label = CCLabelBMFont::create(text.c_str(), "bigFont.fnt");
    label->setScale(0.5f);
    label->setAnchorPoint({0.f, 0.5f});
    label->setPosition({42.f, 20.f});
    menu->addChild(label);

    return menu;
}

CCMenu* Checkbox::create(CCObject* target, const std::string& text, SEL_MenuHandler selector, bool toggled) {
    auto menu = CCMenu::create();
    menu->setContentSize({300.f, 40.f});
    menu->setAnchorPoint({0.f, 0.f});

    auto checkbox = CCMenuItemToggler::create(
        CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png"),
        CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png"),
        target,
        selector
    );
    checkbox->setPosition({20.f, 20.f});
    menu->addChild(checkbox);

    auto label = CCLabelBMFont::create(text.c_str(), "bigFont.fnt");
    label->setScale(0.5f);
    label->setAnchorPoint({0.f, 0.5f});
    label->setPosition({42.f, 20.f});
    menu->addChild(label);

    checkbox->toggle(toggled);

    return menu;
}
