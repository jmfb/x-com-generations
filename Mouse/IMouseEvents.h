#pragma once
#include "ArrowKey.h"
#include "IMouseTarget.h"
#include <memory>

namespace XCom
{

class IMouseEvents
{
public:
	virtual ~IMouseEvents()
	{
	}
	
	virtual void OnKeyDown(char ch) = 0;
	virtual void OnArrowKey(ArrowKey key) = 0;
	virtual void OnMouseMove(bool leftButton, bool rightButton) = 0;
	virtual void OnLButtonDown() = 0;
	virtual void OnLButtonUp() = 0;
	virtual void OnRButtonDown() = 0;
	virtual void OnRButtonUp() = 0;

	virtual void CaptureFocus(IMouseTarget* target) = 0;
	virtual void ReleaseFocus() = 0;
	virtual bool HasFocus(const IMouseTarget* target) const = 0;
};

typedef std::shared_ptr<IMouseEvents> IMouseEventsPtr;

}
