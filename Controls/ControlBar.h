#pragma once
#include "../Graphics/IGraphicsObject.h"
#include "../Screens/BaseScreen.h"
#include "../Graphics/Color.h"

namespace XCom
{

class ControlBar : public IGraphicsObject
{
public:
	ControlBar();
	~ControlBar();
	
	void Init(
		BaseScreen* parent,
		unsigned long x, unsigned long y,
		unsigned long height,
		const Color& fill,
		const Color& border);
		
	void SetBar(unsigned long position, unsigned long width);
	void SetClearColor(const Color& clear);
	
	virtual void Render() const;
	
private:
	unsigned long mX;
	unsigned long mY;
	unsigned long mWidth;
	unsigned long mHeight;
	unsigned long mPosition;
	Color mFill;
	Color mBorder;
	bool mIsClear;
	Color mClear;
	
private:
	ControlBar(const ControlBar& rhs);
	ControlBar& operator=(const ControlBar& rhs);
};

}
