#include "framework.h"
#include "CMonster.h"

CMonster::CMonster()
{
	m_fCenterPos.x = 0.f;
	m_fCenterPos.y = 0.f;
	m_fMaxrepeat = 200.f;
	m_fSpeed = 250.f;
	iDir = 1;

}

CMonster::~CMonster()
{
}

float CMonster::GetSpeed()
{
	return m_fSpeed;
}

void CMonster::SetSpeed(float _mSpeed)
{
	m_fSpeed = _mSpeed;
}

void CMonster::SetCenterPos(fPoint _center)
{
	m_fCenterPos = _center;
}

void CMonster::update()
{
	fPoint fCurPos = GetPos(); //���� ��ġ �ҷ�����
	//�������(iDir)���� �ð��� f_mSpeed��ŭ �̵�
	fCurPos.y += m_fSpeed * iDir * (float)DT;

	//���� ���� �����ϱ� ���� ���밪���� �ٲ���
	//Center(����)Pos�� Cur(����)Pos�� ���� ������ �ִ�ġ�� �� ��
	float Diff = abs(m_fCenterPos.y - fCurPos.y) - m_fMaxrepeat;
	 // �� ���� 0���� ũ�� �� ���� ������ �ִ�ġ���� �� �̵����� ���
	if (0.f < Diff)
	{
		//���� ����
		iDir *= -1;
		//�ʰ��� �̵��� ��ŭ �ݴ�� �� �̵�
		fCurPos.y += Diff * iDir;
	}

	SetPos(fCurPos);
}
