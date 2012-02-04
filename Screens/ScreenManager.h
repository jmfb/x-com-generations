#pragma once
#include "../Singleton.h"
#include "BaseScreen.h"
#include "ScreenType.h"

namespace XCom
{

class ScreenManager : public Singleton<ScreenManager>
{
private:
	ScreenManager();
	~ScreenManager();
	
	friend class Singleton<ScreenManager>;
	
public:
	void Render() const;
	void Set(ScreenType type, long param = 0);
	
private:
	static BaseScreen* FindScreen(ScreenType type);

private:	
	BaseScreen* mActiveScreen;

private:
	ScreenManager(const ScreenManager& rhs);
	ScreenManager& operator=(const ScreenManager& rhs);
};

}
