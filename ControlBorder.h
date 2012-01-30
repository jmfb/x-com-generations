#pragma once
#include "IGraphicsObject.h"
#include "Background.h"
#include "ColorScheme.h"
#include "BaseScreen.h"

namespace XCom
{

class ControlBorder : public IGraphicsObject
{
public:
	ControlBorder();
	~ControlBorder();
	
	void Init(
		BaseScreen* parent,
		unsigned long x, unsigned long y,
		unsigned long width, unsigned long height,
		ColorSchemeType scheme,
		BackgroundType background,
		unsigned long paletteIndex);
	
	void SetPosition(unsigned long x, unsigned long y, unsigned long width, unsigned long height);
	void SetScheme(ColorSchemeType scheme);
	
	virtual void Render() const;
	
private:
	unsigned long mX;
	unsigned long mY;
	unsigned long mWidth;
	unsigned long mHeight;
	ColorSchemeType mScheme;
	BackgroundType mBackground;
	unsigned long mPaletteIndex;
	
private:
	ControlBorder(const ControlBorder& rhs);
	ControlBorder& operator=(const ControlBorder& rhs);
};

}
