#include "ScreenTestBattle.h"
#include "../Graphics/GraphicsBuffer.h"
#include "../constants.h"

namespace XCom
{



class BattleMapSquare
{
public:
	//Load the square stuffs
	void Load(int file);
	//TODO: a single square might have an animation, thus multipls images
	//TODO: file format form square images (reuse xmg, need to recreate editor)
	//TODO: probably good to create converter
	//NOTE: I would prefer to fix the Y-axis ambiguities prior to working
	//		on further images.
};

class BattleMapSection
{
public:
	//Load a predefined section from file
	void Load(int file);
	
	//Retrieve one of the predefined map sections
	static BattleMapSection& Get(int index);
	
	//TODO: more (squares, levels, etc)
};

class BattleMap
{
public:
	//Generate a new battle map
	void Generate(int terrain);
	void GenerateAlienBase(int age);
	void GenerateXComBase(int xcombase);
	
	//Save the state of the map when saving during a battle
	void Save(int file) const;
	
	//Load the state of the file from a previous save
	void Load(int file);
	
	//TODO: more (section counts, sections, etc)
};





ScreenTestBattle::ScreenTestBattle()
{
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
}

}
