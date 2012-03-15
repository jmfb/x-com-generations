#pragma once
#include "../Graphics/IGraphicsObject.h"
#include "../Mouse/IMouseTarget.h"
#include "../IdleHandler.h"
#include "../Screens/BaseScreen.h"
#include "../Graphics/ColorScheme.h"
#include "../Fonts/FontFactory.h"
#include "../IDateTime.h"
#include <string>

namespace XCom
{

class ControlButton : public IGraphicsObject, public IMouseTarget, public IdleHandler
{
public:
	ControlButton();
	~ControlButton();
	
	void Init(
		BaseScreen* parent,
		unsigned long x,
		unsigned long y,
		unsigned long width,
		unsigned long height,
		const std::string& text,
		ColorSchemeType scheme,
		unsigned long id);
		
	void SetPosition(unsigned long x, unsigned long y, unsigned long width, unsigned long height);
	void SetText(const std::string& text);
	void SetScheme(ColorSchemeType scheme);
	void SetPushed(bool pushed);
	void SetDeep();
	void SetFont(FontType font);
	void Repeat(unsigned long interval);
	
	virtual void OnIdle();
	virtual void Render() const;
	virtual bool HitTest(unsigned long x, unsigned long y) const;
	
	virtual void OnMouseMove(unsigned long x, unsigned long y, bool leftButton, bool rightButton);
	virtual void OnLeftButtonDown(unsigned long x, unsigned long y);
	virtual void OnLeftButtonUp(unsigned long x, unsigned long y);
	
protected:
	void RenderButton() const;
	
private:
	BaseScreen* mParent;
	unsigned long mId;
	unsigned long mX;
	unsigned long mY;
	unsigned long mWidth;
	unsigned long mHeight;
	unsigned long mInterval;
	IDateTimePtr mLastRepeat;
	std::string mText;
	ColorSchemeType mScheme;
	FontType mFont;
	bool mPushed;
	bool mDeep;
	
private:
	ControlButton(const ControlButton& rhs);
	ControlButton& operator=(const ControlButton& rhs);
};

}
