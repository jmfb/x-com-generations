#include "ScreenTestControls.h"
#include "../FactoryInject.h"
#include <sstream>

namespace XCom
{

enum
{
	ID_RETURN,
	ID_EDIT,
	ID_LIST,
	ID_UPDOWN
};

ScreenTestControls::ScreenTestControls()
	: mValue(50)
{
	mBackground.Init(this, BACK_TITLE, 0);
	mBorder.Init(this, 150, 100, 110, 80, SCHEME_YELLOW, BACK_SOLDIER, 1);
	mBar.Init(this, 150, 110, 9, Color(0, 0, 255), Color(255, 0, 0));
	mBar.SetBar(50, 101);
	mBar.SetClearColor(Color(0, 255, 0));
	mEdit.Init(this, 150, 130, 170, EDIT_CLICK, "Edit me", FONT_LARGE, SCHEME_WHITE, ID_EDIT);
	mEllipsis.Init(this, &mEdit, 319, true, SCHEME_PURPLE);
	mImage.Init(this, 156, 94, IMAGE_RANK_COMMANDER);
	mText.Init(this, 160, 60, "50", FONT_NORMAL, SCHEME_GREEN);
	mUpDown.Init(this, 190, 60, SCHEME_AQUA, ID_UPDOWN);
	mUpDown.Enable(true);

	mList.Init(this, 10, 150, 8, Color(255, 0, 255), SCHEME_GREEN, ID_LIST);
	mList.AddColumn(40, ALIGN_LEFT);
	mList.AddColumn(40, ALIGN_CENTER);
	mList.AddColumn(40, ALIGN_RIGHT);

	const char* values[][3] = {
		{ "Eat", "My", "Dick" },
		{ "Lick", "Your", "Ass" },
		{ "Not", "Your", "Son" },
		{ "Peter", "Is", "Gone" },
		{ "Trust", "No", "One" },
		{ "I", "Love", "Lamp" },
		{ "Peter", "From", "Boston" },
		{ "Long", "Road", "Out" },
		{ "I", "Like", "Your" },
		{ "Drakes", "Bay", "Motel" }
	};

	for (unsigned long row = 0; row < 10; ++row)
	{
		unsigned long index = mList.AddRow();
		mList.SetItem(index, 0, values[row][0], SCHEME_DARK_YELLOW);
		mList.SetItem(index, 1, values[row][1], SCHEME_AQUA);
		mList.SetItem(index, 2, values[row][2], SCHEME_GREEN);
	}

	mButton.Init(this, 10, 190, 40, 20, "Return", SCHEME_AQUA, ID_RETURN);
}

ScreenTestControls::~ScreenTestControls()
{
}

void ScreenTestControls::OnButton(unsigned long id)
{
	std::ostringstream out;
	switch(id)
	{
	case ID_RETURN:
		UnitTest::Inject<IScreenManager>::Resolve()->Set(SCREEN_MAIN_MENU);
		break;
	case ID_EDIT:
		mEdit.SetText("[" + mEdit.GetText() + "]");
		break;
	case ID_LIST:
		break;
	case ID_UPDOWN:
		if (mUpDown.GetState() == STATE_UP && mValue < 100)
			++mValue;
		else if (mUpDown.GetState() == STATE_DOWN && mValue > 0)
			--mValue;
		out << mValue;
		mText.SetText(out.str());
		mBar.SetBar(mValue, 101);
		break;
	}
}

}
