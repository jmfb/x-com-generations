#pragma once
#include <functional>

namespace XCom
{

class Game
{
public:
	static Game& Get();
	
	void Quit();
	
private:
	Game(const std::function<void()>& quit);
	Game(const Game& rhs);
	~Game();
	
	Game& operator=(const Game& rhs);
	
	void RenderScene();
	
	friend class Application;
	
	static Game* mThis;
	
	std::function<void()> mQuit;
};

}
