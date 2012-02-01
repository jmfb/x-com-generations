#pragma once
#include "../Graphics/IGraphicsObject.h"
#include "../Screens/BaseScreen.h"
#include "../Graphics/Image.h"

namespace XCom
{

class ControlImage : public IGraphicsObject
{
public:
	ControlImage();
	~ControlImage();
	
	void Init(
		BaseScreen* parent,
		unsigned long x, unsigned long y,
		ImageType image);
		
	void SetImage(ImageType image);
	
	virtual void Render() const;
	
private:
	unsigned long mX;
	unsigned long mY;
	ImageType mImage;
	
private:
	ControlImage(const ControlImage& rhs);
	ControlImage& operator=(const ControlImage& rhs);
};

}
