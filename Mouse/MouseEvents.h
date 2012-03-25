#pragma once
#include <stack>
#include "IMouseEvents.h"
#include "IMouseTarget.h"
#include "IMouse.h"
#include "../UnitTest/UnitTest.h"

namespace XCom
{

class MouseEvents : public IMouseEvents
{
public:
	MouseEvents(UnitTest::IFactoryPtr factory);
	MouseEvents(const MouseEvents& rhs) = delete;
	~MouseEvents();
	
	MouseEvents& operator=(const MouseEvents& rhs) = delete;

	virtual void OnKeyDown(char ch);
	virtual void OnArrowKey(ArrowKey key);
	virtual void OnMouseMove(bool leftButton, bool rightButton);
	virtual void OnLButtonDown();
	virtual void OnLButtonUp();
	virtual void OnRButtonDown();
	virtual void OnRButtonUp();

	virtual void CaptureFocus(IMouseTarget* target);
	virtual void ReleaseFocus();
	virtual bool HasFocus(const IMouseTarget* target) const;
	
	IMouseTarget* GetFocus() const;
	void SetFocus(IMouseTarget* focus);
	const std::stack<IMouseTarget*>& GetStack() const;
	std::stack<IMouseTarget*>& GetStack();
	
private:
	IMousePtr mMouse;
	IMouseTarget* mFocus;
	std::stack<IMouseTarget*> mStack;
};

}
