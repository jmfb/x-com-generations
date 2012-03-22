#include "ControlList.h"
#include "../Graphics/GraphicsBuffer.h"
#include "../Mouse/Mouse.h"
#include "../Mouse/MouseEvents.h"
#include "../Fonts/Font.h"
#include "../FactoryInject.h"

namespace XCom
{

enum
{
	ID_UP,
	ID_DOWN
};

ControlList::ControlList()
	: mParent(0), mId(0), mX(0), mY(0), mMaxRows(0), mScheme(SCHEME_WHITE),
	mScrollPos(0), mSelRow(0)
{
}

ControlList::~ControlList()
{
}

void ControlList::Init(
	BaseScreen* parent,
	unsigned long x, unsigned long y,
	unsigned long maxRows,
	const Color& selected,
	ColorSchemeType scheme,
	unsigned long id)
{
	mParent = parent;
	mId = id;
	mX = x;
	mY = y;
	mMaxRows = maxRows;
	mScheme = scheme;
	mSelected = selected;
	
	mUp.Init(this, 0, 0, 13, 15, "U", mScheme, ID_UP);
	mUp.SetFont(FONT_ARROW);
	mUp.Repeat(100);
	mDown.Init(this, 0, 0, 13, 15, "D", mScheme, ID_DOWN);
	mDown.SetFont(FONT_ARROW);
	mDown.Repeat(100);
	
	mParent->AddObject(this);
	mParent->AddTarget(this);
	UpdateData();
}

void ControlList::AddColumn(unsigned long width, AlignType align)
{
	ListColumn column = { width, align };
	mColumns.push_back(column);
	unsigned long listWidth = GetColWidth();
	mUp.SetPosition(mX + listWidth + 3, mY, 13, 15);
	mDown.SetPosition(mX + listWidth + 3, mY - mMaxRows * 8 + 15, 13, 15);
}

unsigned long ControlList::AddRow()
{
	std::vector<ListItem> row;
	row.resize(mColumns.size());
	mList.push_back(row);
	UpdateData();
	return mList.size() - 1;
}

void ControlList::SetItem(unsigned long row, unsigned long column, const std::string& text, ColorSchemeType scheme)
{
	ListItem item = { text, scheme };
	mList[row][column] = item;
}

void ControlList::SetScrollPos(unsigned long pos)
{
	mScrollPos = pos;
}

void ControlList::ClearRows()
{
	mList.clear();
	mScrollPos = 0;
	UpdateData();
}

bool ControlList::HitTest(unsigned long x, unsigned long y) const
{
	return (x - mX) < (GetColWidth() + 16) && (mY - y) < (mMaxRows * 8);
}

void ControlList::OnMouseMove(unsigned long x, unsigned long y, bool leftButton, bool rightButton)
{
	if ((x - mX) < GetColWidth())
	{
		if (leftButton)
			OnLeftButtonDown(x, y);
	}
	else
		BaseScreen::OnMouseMove(x, y, leftButton, rightButton);
}

void ControlList::OnLeftButtonDown(unsigned long x, unsigned long y)
{
	unsigned long row = (mY - y) / 8;
	if ((x - mX) < GetColWidth() && row < mMaxRows && (row + mScrollPos) < mList.size())
	{
		mSelRow = row + mScrollPos;
		mParent->OnButton(mId);
	}
	else
		BaseScreen::OnLeftButtonDown(x, y);
}

void ControlList::Render() const
{
	GraphicsBuffer& graphics = GraphicsBuffer::Get();
	auto position = UnitTest::Inject<IMouse>::Resolve()->GetPosition();
	unsigned long row = (mY - position.second) / 8;
	if (MouseEvents::Get().HasFocus(this) && 
		(position.first - mX) < GetColWidth() &&
		row < mMaxRows &&
		(row + mScrollPos) < mList.size())
	{
		graphics.SetBrush(mSelected, GraphicsBuffer::Or);
		graphics.DrawRect(mX, mY - row * 8, GetColWidth(), 8);
	}
	
	Font font(FONT_NORMAL);
	for (row = 0; row < mMaxRows && (row + mScrollPos) < mList.size(); ++row)
	{
		auto rowData = mList[row + mScrollPos];
		unsigned long x = mX;
		for (unsigned long column = 0; column < mColumns.size(); ++column)
		{
			const ListColumn& columnData = mColumns[column];
			
			unsigned long textX = x;
			unsigned long textY = mY - row * 8;
			switch(columnData.mAlign)
			{
			case ALIGN_CENTER:
				textX += (columnData.mWidth - font.Measure(rowData[column].mText)) / 2;
				break;
			case ALIGN_RIGHT:
				textX += columnData.mWidth - font.Measure(rowData[column].mText);
				break;
			case ALIGN_LEFT:
				//nothing, already left aligned
				break;
			}
			
			font.Render(textX, textY, rowData[column].mText, ColorScheme::Get(rowData[column].mScheme));
			x += columnData.mWidth;
		}
	}
	
	BaseScreen::Render();
}

void ControlList::OnButton(unsigned long id)
{
	switch(id)
	{
	case ID_UP:
		if (mScrollPos > 0)
		{
			--mScrollPos;
			UpdateData();
		}
		break;
		
	case ID_DOWN:
		if ((mList.size() - mScrollPos) > mMaxRows)
		{
			++mScrollPos;
			UpdateData();
		}
		break;
	}
}

unsigned long ControlList::GetSelRow() const
{
	return mSelRow;
}

unsigned long ControlList::GetVisibleRowCount() const
{
	return std::min(static_cast<unsigned long>(mList.size()), mMaxRows);
}

unsigned long ControlList::GetScrollPos() const
{
	return mScrollPos;
}

unsigned long ControlList::GetColWidth() const
{
	unsigned long width = 0;
	for (auto iter = mColumns.begin(), end = mColumns.end(); iter != end; ++iter)
		width += iter->mWidth;
	return width;
}

void ControlList::UpdateData()
{
	RemoveObject(&mUp);
	RemoveTarget(&mUp);
	RemoveObject(&mDown);
	RemoveTarget(&mDown);
	
	if (mScrollPos > 0)
	{
		AddObject(&mUp);
		AddTarget(&mUp);
	}
	
	if ((mList.size() - mScrollPos) > mMaxRows)
	{
		AddObject(&mDown);
		AddTarget(&mDown);
	}
}

}
