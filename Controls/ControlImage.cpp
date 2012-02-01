#include "ControlImage.h"
#include "../Graphics/GraphicsBuffer.h"

namespace XCom
{

ControlImage::ControlImage()
	: mX(0), mY(0), mImage(static_cast<ImageType>(0))
{
}

ControlImage::~ControlImage()
{
}

void ControlImage::Init(
	BaseScreen* parent,
	unsigned long x, unsigned long y,
	ImageType image)
{
	mX = x;
	mY = y;
	SetImage(image);
	parent->AddObject(this);
}

void ControlImage::SetImage(ImageType image)
{
	mImage = image;
}

void ControlImage::Render() const
{
	GraphicsBuffer::Get().DrawImageFromFile(mX, mY, mImage);
}

}
