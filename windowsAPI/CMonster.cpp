#include "framework.h"
#include "CMonster.h"

CMonster::CMonster()
{
	f_CenterPos.x = 0.f;
	f_CenterPos.y = 0.f;
	f_repeat = 0.f;
	f_mSpeed = 100.f;
	iDir = 1;

}

CMonster::~CMonster()
{
}

float CMonster::GetSpeed()
{
	return f_mSpeed;
}

void CMonster::SetSpeed(float _mSpeed)
{
	f_mSpeed = _mSpeed;
}

void CMonster::SetCenterPos(fPoint _center)
{
	f_CenterPos = _center;
}

void CMonster::update()
{
	fPoint fCurPos = GetPos(); //���� ��ġ �ҷ�����
	//�������(iDir)���� �ð��� f_mSpeed��ŭ �̵�
	fCurPos.x += f_mSpeed * iDir * (float)DT;

	f_CenterPos;

	SetPos(fCurPos);
}
