#include "System.h"

namespace XCom
{

System::System()
{
}

System::~System()
{
}

Position System::GetCursorPosition() const
{
	POINT pt = {0};
	::GetCursorPos(&pt);
	return std::make_pair(pt.x, pt.y);
}

void System::SetCursorPosition(const Position& position) const
{
	::SetCursorPos(position.first, position.second);
}

Position System::ConvertPositionToClient(WindowHandle handle, const Position& position) const
{
	POINT point = { static_cast<long>(position.first), static_cast<long>(position.second) };
	::ScreenToClient(handle, &point);
	return std::make_pair(point.x, point.y);
}

Position System::ConvertPositionFromClient(WindowHandle handle, const Position& position) const
{
	POINT point = { static_cast<long>(position.first), static_cast<long>(position.second) };
	::ClientToScreen(handle, &point);
	return std::make_pair(point.x, point.y);
}

}
