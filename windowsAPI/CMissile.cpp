#include "framework.h"
#include "CMissile.h"

CMissile::CMissile()
{
	
	m_vDir.x = 0.f;
	m_vDir.y = 0.f;
	
	
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	fPoint fPos = GetPos();
	//x에 cos y에 sin
	fPos.x += 30.f * m_vDir.x * (float)DT;
	fPos.y += 30.f * m_vDir.y * (float)DT;

	SetPos(fPos);
}

void CMissile::render(HDC hDC)
{
	//부모클래스의 랜더를 오버 라이딩하여서 네모를 동그라미로 바꿔 사용
	fPoint m_fptPos = GetPos();
	fPoint m_fptScale = GetScale();
	Ellipse(hDC, (int)(m_fptPos.x - m_fptScale.x / 2.f), (int)(m_fptPos.y - m_fptScale.y / 2.f)
			, (int)(m_fptPos.x + m_fptScale.x / 2.f), (int)(m_fptPos.y + m_fptScale.y / 2.f));
}
// normalize를 이용한 방향정보 갱신
void CMissile::SetDir(fvec _fvec)
{
	// 이동방향 가져 올 때 normalize도 같이 적용
	m_vDir = _fvec.Normalize();
}


