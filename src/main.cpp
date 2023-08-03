#include <Geode/loader/Mod.hpp>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
#include "PackSelectLayer.hpp"
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/IDManager.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>
#include "PackManager.hpp"

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;
        
        NodeIDs::provideFor(this);

        auto menu = this->getChildByID("right-side-menu");

        menu->addChild(CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("gj_folderBtn_001.png"),
            this, menu_selector(MyMenuLayer::onTextureLdr)
        ));
        menu->updateLayout();

        return true;
    }

    void onTextureLdr(CCObject*) {
        PackSelectLayer::scene();
    }
};

