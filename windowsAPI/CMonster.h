#pragma once
#include "CGameObject.h"

class CMonster : public CGameObject
{
private:
	float m_fSpeed;

	//왓다갔다 할때의 범위를 구하는것
	fPoint m_fCenterPos;
	float m_fMaxrepeat;
	int iDir; //왼쪽일지 오른쪽일지의 진행방향

public:
	CMonster();
	virtual ~CMonster();

	float GetSpeed();
	void SetSpeed(float _mSpeed);

	void SetCenterPos(fPoint _center);

	virtual void update();

};