#pragma once
#include "../Singleton.h"
#include "IMouseTarget.h"
#include <stack>

namespace XCom
{

class MouseEvents : public Singleton<MouseEvents>
{
public:
	void OnKeyDown(char ch);
	void OnArrowKey(ArrowKey key);
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
	
	friend class Singleton<MouseEvents>;
	
	IMouseTarget* mFocus;
	std::stack<IMouseTarget*> mStack;
};

}
