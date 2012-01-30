#pragma once
#include "BaseScreen.h"
#include "ColorScheme.h"
#include "Color.h"
#include "ControlButton.h"
#include <vector>
#include <string>

namespace XCom
{

enum AlignType
{
	ALIGN_LEFT,
	ALIGN_CENTER,
	ALIGN_RIGHT
};

struct ListColumn
{
	unsigned long mWidth;
	AlignType mAlign;
};

struct ListItem
{
	std::string mText;
	ColorSchemeType mScheme;
};

class ControlList : public BaseScreen
{
public:
	ControlList();
	~ControlList();
	
	void Init(
		BaseScreen* parent,
		unsigned long x, unsigned long y,
		unsigned long maxRows,
		const Color& selected,
		ColorSchemeType scheme,
		unsigned long id);
	
	void AddColumn(unsigned long width, AlignType align);
	unsigned long AddRow();
	void SetItem(unsigned long row, unsigned long column, const std::string& text, ColorSchemeType scheme);
	void SetScrollPos(unsigned long pos);
	void ClearRows();
	
	virtual bool HitTest(unsigned long x, unsigned long y) const;
	virtual void OnMouseMove(unsigned long x, unsigned long y, bool leftButton, bool rightButton);
	virtual void OnLeftButtonDown(unsigned long x, unsigned long y);
	
	virtual void Render() const;
	
	virtual void OnButton(unsigned long id);
	
	unsigned long GetSelRow() const;
	unsigned long GetVisibleRowCount() const;
	unsigned long GetScrollPos() const;
	
	unsigned long GetColWidth() const;
	void UpdateData();
	
private:
	BaseScreen* mParent;
	unsigned long mId;
	unsigned long mX;
	unsigned long mY;
	unsigned long mMaxRows;
	ColorSchemeType mScheme;
	Color mSelected;
	std::vector<ListColumn> mColumns;
	std::vector<std::vector<ListItem>> mList;
	unsigned long mScrollPos;
	unsigned long mSelRow;
	ControlButton mUp;
	ControlButton mDown;
	
private:
	ControlList(const ControlList& rhs);
	ControlList& operator=(const ControlList& rhs);
};

}
