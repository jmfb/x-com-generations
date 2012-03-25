#pragma once
#include "../Singleton.h"
#include "IMouseTarget.h"
#include <stack>
#include "IMouseEvents.h"

namespace XCom
{

class MouseEvents : public IMouseEvents
{
public:
	MouseEvents();
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
	
private:
	IMouseTarget* mFocus;
	std::stack<IMouseTarget*> mStack;
};

}
