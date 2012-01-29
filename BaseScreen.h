#pragma once
#include "IGraphicsObject.h"
#include "IMouseTarget.h"
#include <list>

namespace XCom
{

class BaseScreen : public IGraphicsObject, public IMouseTarget
{
public:
	BaseScreen();
	~BaseScreen();
	
	virtual void Render() const;
	virtual void OnButton(unsigned long id);
	virtual void OnMouseMove(unsigned long x, unsigned long y, bool leftButton, bool rightButton);
	virtual void OnLeftButtonDown(unsigned long x, unsigned long y);
	virtual void OnLeftButtonUp(unsigned long x, unsigned long y);
	virtual void OnRightButtonDown(unsigned long x, unsigned long y);
	virtual void OnRightButtonUp(unsigned long x, unsigned long y);
	virtual void OnSetFocus(unsigned long param);
	virtual void OnKillFocus();
	
	void DoModal(BaseScreen* parent, long param = 0);
	void EndModal(long param = 0);
	
	void AddObject(const IGraphicsObject* object);
	void RemoveObject(const IGraphicsObject* object);
	
	void AddTarget(IMouseTarget* target);
	void RemoveTarget(IMouseTarget* target);
	IMouseTarget* FindTarget(unsigned long x, unsigned long y);
	virtual bool IsChild(const IMouseTarget* target) const;
	
private:
	//Drawn from first added to last added
	typedef std::list<const IGraphicsObject*> GraphicsList;
	GraphicsList mGraphics;
	
	//Hit tests performed from last added to first added
	typedef std::list<IMouseTarget*> TargetList;
	TargetList mTargets;
	
protected:
	BaseScreen* mParent;
	
private:
	BaseScreen(const BaseScreen& rhs);
	BaseScreen& operator=(const BaseScreen& rhs);
};

}
