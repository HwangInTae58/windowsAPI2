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
	fPoint fCurPos = GetPos(); //현제 위치 불러오기
	//진행방향(iDir)으로 시간당 f_mSpeed만큼 이동
	fCurPos.y += m_fSpeed * iDir * (float)DT;

	//둘의 차를 구분하기 위해 절대값으로 바꿔줌
	//Center(기준)Pos와 Cur(현재)Pos가 내가 지정한 최대치와 뺀 후
	float Diff = abs(m_fCenterPos.y - fCurPos.y) - m_fMaxrepeat;
	 // 뺀 값이 0보다 크면 즉 내가 지정한 최대치보다 더 이동했을 경우
	if (0.f < Diff)
	{
		//방향 변경
		iDir *= -1;
		//초과한 이동량 만큼 반대로 더 이동
		fCurPos.y += Diff * iDir;
	}

	SetPos(fCurPos);
}
