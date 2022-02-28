#pragma once
#include "CGameObject.h"

class CMonster : public CGameObject
{
private:
	float f_mSpeed;

	//왓다갔다 할때의 범위를 구하는것
	fPoint f_CenterPos;
	float f_repeat;
	int iDir; //왼쪽일지 오른쪽일지의 진행방향

public:
	CMonster();
	virtual ~CMonster();

	float GetSpeed();
	void SetSpeed(float _mSpeed);

	void SetCenterPos(fPoint _center);

	virtual void update();

};