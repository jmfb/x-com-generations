#pragma once
#include "Singleton.h"

namespace XCom
{

class Game : public Singleton<Game>
{
public:
	void RenderScene();
	void Quit();
	
private:
	Game();
	~Game();

	friend class Singleton<Game>;
	
private:
	Game(const Game& rhs);
	Game& operator=(const Game& rhs);
};

}
