#pragma once
#include "../Graphics/IGraphicsObject.h"
#include "../Mouse/IMouseTarget.h"
#include "../IdleHandler.h"
#include "../Screens/BaseScreen.h"
#include "../Graphics/ColorScheme.h"
#include "../IDateTime.h"

namespace XCom
{

enum UpDownState
{
	STATE_UP = 1,
	STATE_NONE = 0,
	STATE_DOWN = -1
};

class ControlUpDown : public IGraphicsObject, public IMouseTarget, public IdleHandler
{
public:
	ControlUpDown();
	~ControlUpDown();
	
	void Init(
		BaseScreen* parent,
		unsigned long x, unsigned long y,
		ColorSchemeType scheme,
		unsigned long id);
		
	virtual bool HitTest(unsigned long x, unsigned long y) const;
	virtual void OnMouseMove(unsigned long x, unsigned long y, bool leftButton, bool rightButton);
	virtual void OnLeftButtonDown(unsigned long x, unsigned long y);
	virtual void OnLeftButtonUp(unsigned long x, unsigned long y);
	
	virtual void Render() const;
	
	virtual void OnIdle();
	
	void Enable(bool enabled);
	UpDownState GetState() const;
	
private:
	BaseScreen* mParent;
	unsigned long mX;
	unsigned long mY;
	unsigned long mId;
	ColorScheme mScheme;
	ColorScheme mInverse;
	bool mEnabled;
	UpDownState mState;
	IDateTimePtr mLastUpdate;
	
private:
	ControlUpDown(const ControlUpDown& rhs);
	ControlUpDown& operator=(const ControlUpDown& rhs);
};

}
