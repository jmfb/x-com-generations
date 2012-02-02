#pragma once
#include "BaseScreen.h"

namespace XCom
{

enum ScreenType
{
    //Screen code for a blank screen
    SCREEN_NONE,

    //Screen for main menu/load/save/difficult
    SCREEN_MAIN_MENU,
        SCREEN_DIFFICULTY,
        SCREEN_LOAD_GAME,
        SCREEN_SAVE_GAME,

    //Geoscape and child screens
    SCREEN_GEOSCAPE,
        SCREEN_BASE,
        SCREEN_GRAPHS,
        SCREEN_UFOPAEDIA,
        SCREEN_FUNDING,

    //Base Screens and child screens
    SCREEN_BUILD_NEW_BASE,
        SCREEN_ACCESS_LIFT,
    SCREEN_BASE_INFORMATION,
        SCREEN_STORES,
        SCREEN_MONTHLY_COSTS,
    SCREEN_SOLDIERS,
        SCREEN_SOLDIER,
    SCREEN_EQUIP_CRAFT,
        SCREEN_CRAFT,
            SCREEN_CREW,
            SCREEN_EQUIPMENT,
            SCREEN_ARMOUR,
    SCREEN_BUILD_FACILITIES,
    SCREEN_RESEARCH,
    SCREEN_MANUFACTURE,
    SCREEN_TRANSFER,
        SCREEN_TRANSFER_DATA,
    SCREEN_PURCHASE_RECRUIT,
    SCREEN_SELL_SACK,

    //Battle load screens
    SCREEN_GROUND_ASSAULT,
    SCREEN_TERROR,
    SCREEN_BASE_DEFENSE,
    SCREEN_BASE_ATTACK,

    //Battle screens
    SCREEN_EQUIP,
    SCREEN_BATTLE,
    SCREEN_BATTLE_MAP,
    SCREEN_BATTLE_OPTIONS,
    SCREEN_BATTLE_SUMMARY,
    SCREEN_PROMOTIONS,
	
	//Test screen
	SCREEN_TEST,
	SCREEN_BATTLE_TEST
};

class ScreenManager
{
public:
	static ScreenManager& Get();
	
	void Render() const;
	void Set(ScreenType type, long param = 0);
	
private:
	ScreenManager();
	ScreenManager(const ScreenManager& rhs);
	~ScreenManager();
	
	ScreenManager& operator=(const ScreenManager& rhs);
	
	friend class Application;
	
	static ScreenManager* mThis;
	
	static BaseScreen* FindScreen(ScreenType type);
	
	BaseScreen* mActiveScreen;
};

}
