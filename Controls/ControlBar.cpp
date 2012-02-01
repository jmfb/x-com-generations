#include "ControlBar.h"
#include "../Graphics/GraphicsBuffer.h"

namespace XCom
{

ControlBar::ControlBar()
	: mX(0), mY(0), mWidth(1), mHeight(0), mPosition(0), mIsClear(true)
{
}

ControlBar::~ControlBar()
{
}

void ControlBar::Init(
	BaseScreen* parent,
	unsigned long x, unsigned long y,
	unsigned long height,
	const Color& fill,
	const Color& border)
{
	mX = x;
	mY = y;
	mHeight = height;
	mFill = fill;
	mBorder = border;
	parent->AddObject(this);
}

void ControlBar::SetBar(unsigned long position, unsigned long width)
{
	mPosition = position;
	mWidth = width;
}

void ControlBar::SetClearColor(const Color& clear)
{
	mIsClear = false;
	mClear = clear;
}

void ControlBar::Render() const
{
	GraphicsBuffer& graphics = GraphicsBuffer::Get();
	graphics.SetBrush(mBorder);
	graphics.DrawHorizontalLine(mX, mY, mWidth);
	graphics.DrawHorizontalLine(mX, mY - mHeight + 1, mWidth);
	graphics.DrawVerticalLine(mX + mWidth - 1, mY, mHeight);
	graphics.SetBrush(mFill);
	graphics.DrawRect(mX, mY - 1, mPosition, mHeight - 2);
	if (!mIsClear)
	{
		graphics.SetBrush(mClear);
		graphics.DrawRect(mX + mPosition, mY - 1, mWidth - mPosition - 1, mHeight - 2);
	}
}

}
