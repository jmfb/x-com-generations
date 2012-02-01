#include "BaseScreen.h"
#include "../Mouse/MouseEvents.h"
#include <algorithm>

namespace XCom
{

BaseScreen::BaseScreen()
	: mParent(0)
{
}

BaseScreen::~BaseScreen()
{
}

void BaseScreen::Render() const
{
	for (auto iter = mGraphics.begin(), end = mGraphics.end(); iter != end; ++iter)
		(*iter)->Render();
}

void BaseScreen::OnButton(unsigned long id)
{
	//nothing
}

void BaseScreen::OnMouseMove(unsigned long x, unsigned long y, bool leftButton, bool rightButton)
{
	IMouseTarget* target = FindTarget(x, y);
	if (target)
		target->OnMouseMove(x, y, leftButton, rightButton);
}

void BaseScreen::OnLeftButtonDown(unsigned long x, unsigned long y)
{
	IMouseTarget* target = FindTarget(x, y);
	if (target)
		target->OnLeftButtonDown(x, y);
}

void BaseScreen::OnLeftButtonUp(unsigned long x, unsigned long y)
{
	IMouseTarget* target = FindTarget(x, y);
	if (target)
		target->OnLeftButtonUp(x, y);
}

void BaseScreen::OnRightButtonDown(unsigned long x, unsigned long y)
{
	IMouseTarget* target = FindTarget(x, y);
	if (target)
		target->OnRightButtonDown(x, y);
}

void BaseScreen::OnRightButtonUp(unsigned long x, unsigned long y)
{
	IMouseTarget* target = FindTarget(x, y);
	if (target)
		target->OnRightButtonUp(x, y);
}

void BaseScreen::OnSetFocus(unsigned long param)
{
	//nothing
}

void BaseScreen::OnKillFocus()
{
	//nothing
}

void BaseScreen::DoModal(BaseScreen* parent, long param)
{
	mParent = parent;
	mParent->OnKillFocus();
	mParent->AddObject(this);
	MouseEvents::Get().CaptureFocus(this);
	OnSetFocus(param);
}

void BaseScreen::EndModal(long param)
{
	OnKillFocus();
	MouseEvents::Get().ReleaseFocus();
	mParent->RemoveObject(this);
	mParent->OnSetFocus(param);
}

void BaseScreen::AddObject(const IGraphicsObject* object)
{
	mGraphics.push_back(object);
}

void BaseScreen::RemoveObject(const IGraphicsObject* object)
{
	auto iter = std::find(mGraphics.begin(), mGraphics.end(), object);
	if (iter != mGraphics.end())
		mGraphics.erase(iter);
}

void BaseScreen::AddTarget(IMouseTarget* target)
{
	mTargets.push_front(target);
}

void BaseScreen::RemoveTarget(IMouseTarget* target)
{
	auto iter = std::find(mTargets.begin(), mTargets.end(), target);
	if (iter != mTargets.end())
		mTargets.erase(iter);
}

IMouseTarget* BaseScreen::FindTarget(unsigned long x, unsigned long y)
{
	for (auto iter = mTargets.begin(), end = mTargets.end(); iter != end; ++iter)
		if ((*iter)->HitTest(x, y))
			return *iter;
	return 0;
}

bool BaseScreen::IsChild(const IMouseTarget* target) const
{
	for (auto iter = mTargets.begin(), end = mTargets.end(); iter != end; ++iter)
		if (*iter == target || (*iter)->IsChild(target))
			return true;
	return false;
}

}
