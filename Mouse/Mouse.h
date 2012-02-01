#pragma once
#include "../WindowsInclude.h"
#include <utility>
#include <array>

namespace XCom
{

class Mouse
{
public:
	static Mouse& Get();
	
	void Show(bool visible);
	void Render();
	std::pair<unsigned long, unsigned long> GetPosition() const;

	enum
	{
		CURSOR_WIDTH = 9,
		CURSOR_HEIGHT = 13,
		CURSOR_SIZE = CURSOR_WIDTH * CURSOR_HEIGHT
	};
	
private:
	Mouse(unsigned long gameWidth, unsigned long gameHeight, unsigned long targetWidth, unsigned long targetHeight, HWND& windowHandle);
	Mouse(const Mouse& rhs);
	~Mouse();
	
	Mouse& operator=(const Mouse& rhs);
	
	friend class Application;
	
	static Mouse* mThis;
	
	unsigned long mGameWidth;
	unsigned long mGameHeight;
	unsigned long mTargetWidth;
	unsigned long mTargetHeight;
	HWND& mWindowHandle;
	bool mVisible;
	unsigned long mX;
	unsigned long mY;
};

}
