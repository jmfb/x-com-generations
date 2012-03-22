#pragma once
#include "../WindowsInclude.h"
#include "IMouse.h"
#include "../System/ISystem.h"

namespace XCom
{

class Mouse : public IMouse
{
public:
	Mouse(ISystemPtr system);
	Mouse(const Mouse& rhs) = delete;
	~Mouse();

	Mouse& operator=(const Mouse& rhs) = delete;
	
	virtual void Show(bool visible);
	virtual void Render();
	virtual Position GetPosition() const;

	bool GetVisible() const;
	Position GetPreviousPosition() const;
	
private:
	ISystemPtr mSystem;
	bool mVisible;
	Position mPreviousPosition;
};

}
