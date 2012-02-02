#pragma once
#include "BaseScreen.h"

namespace XCom
{

class ScreenTestBattle : public BaseScreen
{
private:
	ScreenTestBattle();
	ScreenTestBattle(const ScreenTestBattle& rhs);
	~ScreenTestBattle();
	
	ScreenTestBattle& operator=(const ScreenTestBattle& rhs);
	
	friend class ScreenManager;
	
	virtual void Render() const;
};

}
