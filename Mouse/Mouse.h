#pragma once
#include "IMouse.h"
#include <UnitTest/UnitTest.h>

namespace XCom
{

class Mouse : public IMouse
{
public:
	Mouse(UnitTest::IFactoryPtr factory);
	Mouse(const Mouse& rhs) = delete;
	~Mouse();

	Mouse& operator=(const Mouse& rhs) = delete;
	
	virtual void Show(bool visible);
	virtual void Render();
	virtual Position GetPosition() const;

	bool GetVisible() const;
	void SetVisible(bool visible);
	Position GetPreviousPosition() const;
	void SetPreviousPosition(const Position& position);
	
private:
	UnitTest::IFactoryPtr mFactory;
	bool mVisible;
	Position mPreviousPosition;
};

}
