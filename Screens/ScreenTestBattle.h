#pragma once
#include "BaseScreen.h"
#include "../IScrollMovement.h"
#include "../IdleHandler.h"

namespace XCom
{

class ScreenTestBattle : public BaseScreen, public IdleHandler
{
private:
	ScreenTestBattle();
	ScreenTestBattle(const ScreenTestBattle& rhs);
	~ScreenTestBattle();

	ScreenTestBattle& operator=(const ScreenTestBattle& rhs);

	friend class ScreenManager;

	virtual void Render() const;

	virtual void OnLeftButtonDown(unsigned long x, unsigned long y);
	virtual void OnArrowKey(ArrowKey key);
	virtual void OnRightButtonUp(unsigned long x, unsigned long y);

	void OnIdle() override;

private:
	IScrollMovementPtr scrollX;
	IScrollMovementPtr scrollY;
};

}
