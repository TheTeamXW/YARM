#include "SettingsLayer.hpp"
#include "../ui/Checkbox.hpp"

#include <Geode/Geode.hpp>
#include <Geode/ui/ScrollLayer.hpp>
#include <string>

using namespace geode::prelude;

bool SettingsLayer::init() {
    if (!Popup::init(380.f, 250.f))
        return false;

    setTitle("YARM Settings");

    m_tabsMenu = CCMenu::create();
    m_tabsMenu->setPosition({0.f, 0.f});
    m_mainLayer->addChild(m_tabsMenu);

    const std::string tabNames[] = {
        "General", "Gameplay", "Safety", "About"
    };

    for (int i = 0; i < 4; i++) {
        auto button = CCMenuItemSpriteExtra::create(
            ButtonSprite::create(tabNames[i].c_str(), 70, true, 0.6f, 1.f, "goldFont.fnt", "GJ_button_01.png", 25.f),
            this,
            menu_selector(SettingsLayer::onTabClicked)
        );

        button->setTag(i);
        button->setPosition({70.f + i * 80.f, 180.f});
        m_tabsMenu->addChild(button);
    }

    m_contentLayer = CCLayer::create();
    m_contentLayer->setContentSize({340.f, 130.f});
    m_contentLayer->setPosition({20.f, 20.f});
    m_mainLayer->addChild(m_contentLayer);

    switchTab(0);

    return true;
}

void SettingsLayer::switchTab(int tab) {
    m_contentLayer->removeAllChildren();

    switch (tab) {
        case 0: {
            auto list = ScrollLayer::create(m_contentLayer->getContentSize());
            list->setAnchorPoint({0.f, 0.f});
            list->setPosition({0.f, 0.f});
            list->m_contentLayer->setLayout(ScrollLayer::createDefaultListLayout());
            list->m_contentLayer->addChild(Checkbox::create(
                this,
                "Safe mode",
                menu_selector(SettingsLayer::onSafeModeCheckbox),
                true
            ));
            list->m_contentLayer->addChild(Checkbox::create(
                this,
                "Safe mode",
                menu_selector(SettingsLayer::onSafeModeCheckbox)
            ));
            list->m_contentLayer->addChild(Checkbox::create(
                this,
                "Safe mode",
                menu_selector(SettingsLayer::onSafeModeCheckbox)
            ));
            list->m_contentLayer->addChild(Checkbox::create(
                this,
                "Safe mode",
                menu_selector(SettingsLayer::onSafeModeCheckbox)
            ));
            list->m_contentLayer->addChild(Checkbox::create(
                this,
                "Safe mode",
                menu_selector(SettingsLayer::onSafeModeCheckbox)
            ));
            list->m_contentLayer->updateLayout();
            m_contentLayer->addChild(list);

            break;
        }

        case 1: {
            break;
        }
    }
}

void SettingsLayer::onSafeModeCheckbox(CCObject* sender) {
    auto checkbox = static_cast<CCMenuItemToggler*>(sender);

    bool enabled = !checkbox->isToggled();

    if (!enabled) {
        geode::createQuickPopup(
            "Warning",
            "Are you sure you want to disable safe mode?",
            "No",
            "Yes",
            [checkbox](auto, bool btn2) {
                if (!btn2) {
                    checkbox->toggle(true);
                }
            }
        );
    }

    log::info("Checkbox enabled: {}", enabled);
}

void SettingsLayer::onTabClicked(CCObject* sender) {
    auto button = static_cast<CCNode*>(sender);
    switchTab(button->getTag());
}

SettingsLayer* SettingsLayer::create() {
    auto ret = new SettingsLayer();
    if (ret->init()) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}