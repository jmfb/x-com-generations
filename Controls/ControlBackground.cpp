#include "ControlBackground.h"
#include "../Graphics/GraphicsBuffer.h"
#include "../constants.h"

namespace XCom
{

ControlBackground::ControlBackground()
	: mBackground(BACK_TITLE), mPaletteIndex(0)
{
}

ControlBackground::~ControlBackground()
{
}

void ControlBackground::Init(
	BaseScreen* parent,
	BackgroundType background,
	unsigned long paletteIndex)
{
	mBackground = background;
	mPaletteIndex = paletteIndex;
	parent->AddObject(this);
}

void ControlBackground::Render() const
{
	GraphicsBuffer::Get().DrawBackground(0, GAME_HEIGHT - 1, GAME_WIDTH, GAME_HEIGHT, mBackground, mPaletteIndex);
}

}
