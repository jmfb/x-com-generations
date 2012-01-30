#pragma once
#include "IGraphicsObject.h"
#include "BaseScreen.h"
#include "ControlText.h"
#include "ColorScheme.h"

namespace XCom
{

class ControlEllipsis : public IGraphicsObject
{
public:
	ControlEllipsis();
	~ControlEllipsis();
	
	void Init(
		BaseScreen* parent,
		ControlText* buddy,
		unsigned long rightEdge,
		bool enabled,
		ColorSchemeType scheme);
		
	void Enable(bool enabled);
	
	virtual void Render() const;
	
private:
	ControlText* mBuddy;
	unsigned long mRightEdge;
	ColorSchemeType mScheme;
	bool mEnabled;
	
private:
	ControlEllipsis(const ControlEllipsis& rhs);
	ControlEllipsis& operator=(const ControlEllipsis& rhs);
};

}
