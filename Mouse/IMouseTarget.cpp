#include "IMouseTarget.h"

namespace XCom
{

bool IMouseTarget::HitTest(unsigned long x, unsigned long y) const
{
	return false;
}

bool IMouseTarget::IsChild(const IMouseTarget* target) const
{
	return false;
}

void IMouseTarget::OnKeyDown(char ch)
{
	//nothing
}

void IMouseTarget::OnArrowKey(ArrowKey key)
{
	//nothing
}

void IMouseTarget::OnMouseMove(unsigned long x, unsigned long y, bool leftButton, bool rightButton)
{
	//nothing
}

void IMouseTarget::OnLeftButtonDown(unsigned long x, unsigned long y)
{
	//nothing
}

void IMouseTarget::OnLeftButtonUp(unsigned long x, unsigned long y)
{
	//nothing
}

void IMouseTarget::OnRightButtonDown(unsigned long x, unsigned long y)
{
	//nothing
}

void IMouseTarget::OnRightButtonUp(unsigned long x, unsigned long y)
{
	//nothing
}


}
