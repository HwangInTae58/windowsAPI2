#include "framework.h"
#include "CMissile.h"

CMissile::CMissile()
{
	m_fTheta = (PHI);
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	fPoint fPos = GetPos();
	//x�� cos y�� sin
	fPos.x -= 300.f * cos(m_fTheta)* (float)DT;
	fPos.y += 300.f * sin(m_fTheta) * (float)DT;

	SetPos(fPos);
}

void CMissile::render(HDC hDC)
{
	//�θ�Ŭ������ ������ ���� ���̵��Ͽ��� �׸� ���׶�̷� �ٲ� ���
	fPoint m_fptPos = GetPos();
	fPoint m_fptScale = GetScale();
	Ellipse(hDC, (int)(m_fptPos.x - m_fptScale.x / 2.f), (int)(m_fptPos.y - m_fptScale.y / 2.f)
			, (int)(m_fptPos.x + m_fptScale.x / 2.f), (int)(m_fptPos.y + m_fptScale.y / 2.f));
}

void CMissile::SetDir(bool fTheta)
{
	m_fTheta = fTheta;
}
