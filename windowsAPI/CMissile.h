#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
private:
	float iDir; //미사일이 날라가는 방향

public:
	CMissile();
	virtual ~CMissile();

	virtual void update();
	virtual void render(HDC hDC);

	void SetDir(bool _Right);

};

