#pragma once
#include <memory>
#include "../System/ISystem.h"

namespace XCom
{

class IMouse
{
public:
	virtual ~IMouse()
	{
	}
	
	virtual void Show(bool visible) = 0;
	virtual void Render() = 0;
	virtual Position GetPosition() const = 0;
};

typedef std::shared_ptr<IMouse> IMousePtr;

}
