#pragma once
#include "IMouseTarget.h"
#include <stack>

namespace XCom
{

class MouseEvents
{
public:
	static MouseEvents& Get();

	void OnKeyDown(char ch);
	void OnMouseMove(bool leftButton, bool rightButton);
	void OnLButtonDown();
	void OnLButtonUp();
	void OnRButtonDown();
	void OnRButtonUp();
	
	void CaptureFocus(IMouseTarget* target);
	void ReleaseFocus();
	bool HasFocus(const IMouseTarget* target) const;
	
private:
	MouseEvents();
	MouseEvents(const MouseEvents& rhs);
	~MouseEvents();
	
	MouseEvents& operator=(const MouseEvents& rhs);
	
	friend class Application;
	
	static MouseEvents* mThis;
	
	IMouseTarget* mFocus;
	std::stack<IMouseTarget*> mStack;
};

}
