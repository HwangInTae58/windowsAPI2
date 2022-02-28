#pragma once
#include "CGameObject.h"

class CMonster : public CGameObject
{
private:
	float f_mSpeed;

	//�Ӵٰ��� �Ҷ��� ������ ���ϴ°�
	fPoint f_CenterPos;
	float f_repeat;
	int iDir; //�������� ������������ �������

public:
	CMonster();
	virtual ~CMonster();

	float GetSpeed();
	void SetSpeed(float _mSpeed);

	void SetCenterPos(fPoint _center);

	virtual void update();

};