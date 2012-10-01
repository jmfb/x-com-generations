#include "ScreenTestBattle.h"
#include "../Graphics/GraphicsBuffer.h"
#include "../constants.h"
#include "../IDateTime.h"
#include "../IdleHandler.h"
#include "../FactoryInject.h"
#include <vector>

namespace XCom
{



class BattleMapSquare : public IdleHandler
{
public:
	BattleMapSquare()
		: mCurrentFrame(0)
	{
		mLastFrame = UnitTest::Inject<IDateTime>::Resolve();
	}
	~BattleMapSquare()
	{
		if (mFrames.size() > 1)
			UnregisterFromIdle();
	}

	//Load the square stuffs
	//TODO: a single square might have an animation, thus multipls images
	//TODO: file format form square images (reuse xmg, need to recreate editor)
	//TODO: probably good to create converter
	//NOTE: I would prefer to fix the Y-axis ambiguities prior to working
	//		on further images.

	virtual void OnIdle()
	{
		if (mLastFrame->TestInterval(100))
			mCurrentFrame = (mCurrentFrame + 1) % mFrames.size();
	}

	void AddFrame(ImageType index)
	{
		mFrames.push_back(index);
		if (mFrames.size() == 2)
			RegisterForIdle();
	}

	void Render(unsigned long x, unsigned long y) const
	{
		UnitTest::Inject<IGraphicsBuffer>::Resolve()->DrawImageFromFile(x, y, mFrames[mCurrentFrame]);
	}

private:
	IDateTimePtr mLastFrame;
	unsigned long mCurrentFrame;
	std::vector<ImageType> mFrames;
};

static const unsigned long BATTLE_MAP_SECTION_SIZE = 5; //TODO: should be 10

class BattleMapSection
{
public:
	BattleMapSection()
	{
		std::vector<BattleMapSquare> column;
		for (unsigned long index = 0; index < BATTLE_MAP_SECTION_SIZE; ++index)
			column.push_back(BattleMapSquare());
		for (unsigned long index = 0; index < BATTLE_MAP_SECTION_SIZE; ++index)
			mData.push_back(column);
	}

	//Load a predefined section from file
	//void Load(int file);

	//Retrieve one of the predefined map sections
	//static BattleMapSection& Get(int index);

	//TODO: more (squares, levels, etc)

	BattleMapSquare& operator()(unsigned long x, unsigned long y)
	{
		return mData[x][y];
	}

	void Render(unsigned long x, unsigned long y) const
	{
		for (unsigned long iy = 0; iy < BATTLE_MAP_SECTION_SIZE; ++iy)
			for (unsigned long ix = 0; ix < BATTLE_MAP_SECTION_SIZE; ++ix)
				mData[ix][iy].Render(x + ix * 16 - iy * 16, y - ix * 8 - iy * 8);
	}

private:
	std::vector<std::vector<BattleMapSquare>> mData;
};

class BattleMap
{
public:
	//Generate a new battle map
	//void Generate(int terrain);
	//void GenerateAlienBase(int age);
	//void GenerateXComBase(int xcombase);

	//Save the state of the map when saving during a battle
	//void Save(int file) const;

	//Load the state of the file from a previous save
	//void Load(int file);

	//TODO: more (section counts, sections, etc)
};


BattleMapSection testSection;

ScreenTestBattle::ScreenTestBattle()
{
	testSection(0, 0).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(1, 0).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(2, 0).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(3, 0).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(4, 0).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);

	testSection(0, 1).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(1, 1).AddFrame(IMAGE_BATTLESCAPE_TEST_CORNER);
	testSection(2, 1).AddFrame(IMAGE_BATTLESCAPE_TEST_TOP_WINDOW);
	testSection(3, 1).AddFrame(IMAGE_BATTLESCAPE_TEST_TOP);
	testSection(4, 1).AddFrame(IMAGE_BATTLESCAPE_TEST_LEFT);

	testSection(0, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(1, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_LEFT);

	testSection(2, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(2, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR_1);
	testSection(2, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR_2);
	testSection(2, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR_1);

	testSection(3, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(4, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);

	testSection(0, 3).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(1, 3).AddFrame(IMAGE_BATTLESCAPE_TEST_LEFT);
	testSection(2, 3).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(3, 3).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(4, 3).AddFrame(IMAGE_BATTLESCAPE_TEST_LEFT);

	testSection(0, 4).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(1, 4).AddFrame(IMAGE_BATTLESCAPE_TEST_TOP);
	testSection(2, 4).AddFrame(IMAGE_BATTLESCAPE_TEST_TOP_WINDOW);
	testSection(3, 4).AddFrame(IMAGE_BATTLESCAPE_TEST_TOP);
	testSection(4, 4).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);

	scrollX = UnitTest::Inject<IScrollMovement>::Resolve();
	scrollY = UnitTest::Inject<IScrollMovement>::Resolve();
	
	scrollX->SetPeriod(std::chrono::milliseconds { 500 });
	scrollY->SetPeriod(std::chrono::milliseconds { 500 });
	scrollX->SetPosition(100);
	scrollY->SetPosition(199);

	RegisterForIdle();
}

ScreenTestBattle::~ScreenTestBattle()
{
	UnregisterFromIdle();
}

void ScreenTestBattle::Render() const
{
	auto graphics = UnitTest::Inject<IGraphicsBuffer>::Resolve();
	graphics->SetBrush(Color(0, 0, 255));
	for (unsigned long x = 0; x < 5 * GAME_WIDTH; ++x)
	{
		graphics->DrawPoint(x % GAME_WIDTH, x % GAME_HEIGHT);
	}

	testSection.Render(scrollX->GetCurrentPosition(), scrollY->GetCurrentPosition());
}

void ScreenTestBattle::OnLeftButtonDown(unsigned long x, unsigned long y)
{
	BaseScreen::OnLeftButtonDown(x, y);
	//TODO: click shit
}

void ScreenTestBattle::OnArrowKey(ArrowKey key)
{
	BaseScreen::OnArrowKey(key);
	switch(key)
	{
	case ARROW_LEFT:
		scrollX->ChangeDestination(-16);
		break;
	case ARROW_RIGHT:
		scrollX->ChangeDestination(16);
		break;
	case ARROW_UP:
		scrollY->ChangeDestination(16);
		break;
	case ARROW_DOWN:
		scrollY->ChangeDestination(-16);
		break;
	}
}

void ScreenTestBattle::OnRightButtonUp(unsigned long x, unsigned long y)
{
	BaseScreen::OnRightButtonUp(x, y);

	scrollX->ChangeDestination(GAME_WIDTH / 2 - x);
	scrollY->ChangeDestination(GAME_HEIGHT / 2 - y);
}

void ScreenTestBattle::OnIdle()
{
}

}

