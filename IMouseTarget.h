#pragma once

namespace XCom
{

class IMouseTarget
{
public:
	virtual bool HitTest(unsigned long x, unsigned long y) const;
	virtual bool IsChild(const IMouseTarget* target) const;

	virtual void OnKeyDown(char ch);
	virtual void OnMouseMove(unsigned long x, unsigned long y, bool leftButton, bool rightButton);
	virtual void OnLeftButtonDown(unsigned long x, unsigned long y);
	virtual void OnLeftButtonUp(unsigned long x, unsigned long y);
	virtual void OnRightButtonDown(unsigned long x, unsigned long y);
	virtual void OnRightButtonUp(unsigned long x, unsigned long y);
};

}
