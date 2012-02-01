#pragma once
#include "../Graphics/Background.h"
#include "../Graphics/IGraphicsObject.h"
#include "../Screens/BaseScreen.h"

namespace XCom
{

class ControlBackground : public IGraphicsObject
{
public:
	ControlBackground();
	~ControlBackground();
	
	void Init(
		BaseScreen* parent,
		BackgroundType background,
		unsigned long paletteIndex);
		
	virtual void Render() const;
	
private:
	BackgroundType mBackground;
	unsigned long mPaletteIndex;
	
private:
	ControlBackground(const ControlBackground& rhs);
	ControlBackground& operator=(const ControlBackground& rhs);
};

}
