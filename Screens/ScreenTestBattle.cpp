#include "ScreenTestBattle.h"
#include "../Graphics/GraphicsBuffer.h"
#include "../constants.h"
#include "../DateTime.h"
#include "../IdleHandler.h"
#include <vector>

namespace XCom
{



class BattleMapSquare : public IdleHandler
{
public:
	BattleMapSquare()
		: mCurrentFrame(0)
	{
	}

	//Load the square stuffs
	//TODO: a single square might have an animation, thus multipls images
	//TODO: file format form square images (reuse xmg, need to recreate editor)
	//TODO: probably good to create converter
	//NOTE: I would prefer to fix the Y-axis ambiguities prior to working
	//		on further images.
	
	virtual void OnIdle()
	{
		if (mLastFrame.TestInterval(100))
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
		GraphicsBuffer::Get().DrawImageFromFile(x, y, mFrames[mCurrentFrame]);
	}
	
private:
	DateTime mLastFrame;
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
unsigned long gdx = 100;
unsigned long gdy = 199;

ScreenTestBattle::ScreenTestBattle()
{
	testSection(0, 0).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(1, 0).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(2, 0).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(3, 0).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(4, 0).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);

	testSection(0, 1).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(1, 1).AddFrame(IMAGE_BATTLESCAPE_TEST_CORNER);
	testSection(2, 1).AddFrame(IMAGE_BATTLESCAPE_TEST_TOP);
	testSection(3, 1).AddFrame(IMAGE_BATTLESCAPE_TEST_TOP);
	testSection(4, 1).AddFrame(IMAGE_BATTLESCAPE_TEST_LEFT);

	testSection(0, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(1, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_LEFT);
	
	testSection(2, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(2, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR_1);
	testSection(2, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR_2);
	testSection(2, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR_1);
	
	testSection(3, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(4, 2).AddFrame(IMAGE_BATTLESCAPE_TEST_LEFT);

	testSection(0, 3).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(1, 3).AddFrame(IMAGE_BATTLESCAPE_TEST_LEFT);
	testSection(2, 3).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(3, 3).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(4, 3).AddFrame(IMAGE_BATTLESCAPE_TEST_LEFT);

	testSection(0, 4).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
	testSection(1, 4).AddFrame(IMAGE_BATTLESCAPE_TEST_TOP);
	testSection(2, 4).AddFrame(IMAGE_BATTLESCAPE_TEST_TOP);
	testSection(3, 4).AddFrame(IMAGE_BATTLESCAPE_TEST_TOP);
	testSection(4, 4).AddFrame(IMAGE_BATTLESCAPE_TEST_FLOOR);
}

ScreenTestBattle::~ScreenTestBattle()
{
}

void ScreenTestBattle::Render() const
{
	GraphicsBuffer& graphics = GraphicsBuffer::Get();
	graphics.SetBrush(Color(0, 0, 255));
	for (unsigned long x = 0; x < 5 * GAME_WIDTH; ++x)
	{
		graphics.DrawPoint(x % GAME_WIDTH, x % GAME_HEIGHT);
	}
	
	testSection.Render(gdx, gdy);
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
		gdx -= 8;
		break;
	case ARROW_RIGHT:
		gdx += 8;
		break;
	case ARROW_UP:
		gdy += 8;
		break;
	case ARROW_DOWN:
		gdy -= 8;
		break;
	}
}

}
