#pragma once
#include "../System/ISystem.h"
#include <memory>

namespace XCom
{

class IMouse
{
public:
	virtual void Show(bool visible) = 0;
	virtual void Render() = 0;
	virtual Position GetPosition() const = 0;
};

typedef std::shared_ptr<IMouse> IMousePtr;

}
