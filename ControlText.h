#pragma once
#include "IGraphicsObject.h"
#include "FontFactory.h"
#include "ColorScheme.h"
#include "BaseScreen.h"
#include <string>

namespace XCom
{

static const unsigned long X_CENTER = 0xffffffff;

class ControlText : public IGraphicsObject
{
public:
	ControlText();
	~ControlText();
	
	void Init(
		BaseScreen* parent,
		unsigned long x, unsigned long y,
		const std::string& text,
		FontType font,
		ColorSchemeType scheme);
		
	void SetPosition(unsigned long x, unsigned long y);
	void SetText(const std::string& text);
	void SetFont(FontType font);
	void SetScheme(ColorSchemeType scheme);
	void Center(unsigned long y);
	void ReCenter(unsigned long width);
	
	unsigned long GetY() const;
	unsigned long GetRightEdge() const;
	FontType GetFont() const;
	const std::string& GetText() const;
	
	virtual void Render() const;
	
protected:
	unsigned long mX;
	unsigned long mY;
	std::string mText;
	FontType mFont;
	ColorSchemeType mScheme;
	
private:
	ControlText(const ControlText& rhs);
	ControlText& operator=(const ControlText& rhs);
};

}
