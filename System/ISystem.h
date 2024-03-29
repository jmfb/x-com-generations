#pragma once
#include "../WindowsInclude.h"
#include <utility>
#include <memory>
#include <iostream>

namespace XCom
{

typedef HWND WindowHandle;
typedef std::pair<unsigned long, unsigned long> Position;

class ISystem
{
public:
	virtual Position GetCursorPosition() const = 0;
	virtual void SetCursorPosition(const Position& position) const = 0;
	virtual Position ConvertPositionToClient(WindowHandle handle, const Position& position) const = 0;
	virtual Position ConvertPositionFromClient(WindowHandle handle, const Position& position) const = 0;
};

typedef std::shared_ptr<ISystem> ISystemPtr;

}

inline std::ostream& operator<<(std::ostream& out, const XCom::Position& rhs)
{
	return out << "{" << rhs.first << "," << rhs.second << "}";
}
