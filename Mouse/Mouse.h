#pragma once
#include "../WindowsInclude.h"
#include "../Singleton.h"
#include <utility>
#include <array>

namespace XCom
{

class Mouse : public Singleton<Mouse>
{
private:
	Mouse();
	~Mouse();

	friend class Singleton<Mouse>;

public:
	void Show(bool visible);
	void Render();
	std::pair<unsigned long, unsigned long> GetPosition() const;

private:
	bool mVisible;
	unsigned long mX;
	unsigned long mY;

private:	
	Mouse(const Mouse& rhs);
	Mouse& operator=(const Mouse& rhs);
};

}
