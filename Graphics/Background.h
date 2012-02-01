#pragma once
#include "Palette.h"
#include <string>

namespace XCom
{

enum BackgroundType
{
    BACK_TITLE,
    BACK_SOLDIER,
    BACK_TERROR,
    BACK_BATTLE,
    BACK_RESEARCH,
    BACK_INFO_SOLDIER,
    BACK_INFO_BASE,
    BACK_INFO_ITEM,
    BACK_INFO_FACILITY,
    BACK_INFO_MISSION,
    BACK_INFO_UFO,
    BACK_CRAFT,
    BACK_FUNDS,
    BACK_EQUIP_CRAFT,
    BACK_UFO,
    BACK_ASSAULT,
    BACK_WORKSHOP,
	BACK_COUNT	//The count of backgrounds, not a special background
};

class Background
{
public:
	Background();
	~Background();
	
	void Load(const std::string& file);
	
	const unsigned char* GetData() const;

private:
	unsigned char* mData;
	
private:
	Background(const Background& rhs);
	Background& operator=(const Background& rhs);
};

}
