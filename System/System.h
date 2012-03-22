#pragma once
#include "ISystem.h"

namespace XCom
{

class System : public ISystem
{
public:
	System();
	System(const System& rhs) = delete;
	~System();
	
	System& operator=(const System& rhs) = delete;
	
	virtual Position GetCursorPosition() const;
	virtual void SetCursorPosition(const Position& position) const;
	virtual Position ConvertPositionToClient(WindowHandle handle, const Position& position) const;
	virtual Position ConvertPositionFromClient(WindowHandle handle, const Position& position) const;
};

}
