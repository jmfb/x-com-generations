#pragma once
#include "ControlText.h"
#include "../Mouse/IMouseTarget.h"
#include "../Screens/BaseScreen.h"
#include "../Fonts/FontFactory.h"
#include "../Graphics/ColorScheme.h"
#include "../IDateTime.h"
#include <string>

namespace XCom
{

enum EditStyle
{
	EDIT_NORMAL,	//Edit begins when you call BeginEdit.
	EDIT_CLICK		//Edit begins when mouse clicks region.
};

class ControlEdit : public ControlText, public IMouseTarget
{
public:
	ControlEdit();
	~ControlEdit();
	
	void Init(
		BaseScreen* parent,
		unsigned long x, unsigned long y,
		unsigned long width,
		EditStyle style,
		const std::string& text,
		FontType font,
		ColorSchemeType scheme,
		unsigned long id);
	
	void BeginEdit();
	
	virtual bool HitTest(unsigned long x, unsigned long y) const;
	virtual void OnLeftButtonDown(unsigned long x, unsigned long y);
	virtual void OnKeyDown(char ch);
	
	virtual void Render() const;
	
private:
	BaseScreen* mParent;
	unsigned long mWidth;
	EditStyle mStyle;
	unsigned long mId;
	bool mInEdit;
	mutable IDateTimePtr mLastCursorBlink;
	mutable bool mCursorBlink;
	
private:
	ControlEdit(const ControlEdit& rhs);
	ControlEdit& operator=(const ControlEdit& rhs);
};

}
