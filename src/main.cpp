#include <Geode/Geode.hpp>
#include "settings/SettingsLayer.hpp"

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		auto yarmButton = CCMenuItemSpriteExtra::create(
			CCSprite::create("button_yarm.png"_spr),
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);
		yarmButton->setScaleX(202.f / 184.f);
		yarmButton->setScaleY(215.f / 190.f);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(yarmButton);

		yarmButton->setID("yarm-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onMyButton(CCObject*) {
		SettingsLayer::create()->show();
	}
};
