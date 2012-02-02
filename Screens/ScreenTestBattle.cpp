#include "ScreenTestBattle.h"
#include "../Graphics/GraphicsBuffer.h"
#include "../constants.h"

namespace XCom
{

ScreenTestBattle::ScreenTestBattle()
{
}

ScreenTestBattle::~ScreenTestBattle()
{
}

void ScreenTestBattle::Render() const
{
	GraphicsBuffer& graphics = GraphicsBuffer::Get();
	graphics.SetBrush(Color(0, 0, 255));
	for (unsigned long x = 0; x < 5 * GAME_WIDTH; ++x)
	{
		graphics.DrawPoint(x % GAME_WIDTH, x % GAME_HEIGHT);
	}
}

}
