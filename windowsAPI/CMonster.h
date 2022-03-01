#pragma once
#include "CGameObject.h"

class CMonster : public CGameObject
{
private:
	float m_fSpeed;

	//�Ӵٰ��� �Ҷ��� ������ ���ϴ°�
	fPoint m_fCenterPos;
	float m_fMaxrepeat;
	int iDir; //�������� ������������ �������

public:
	CMonster();
	virtual ~CMonster();

	float GetSpeed();
	void SetSpeed(float _mSpeed);

	void SetCenterPos(fPoint _center);

	virtual void update();

};