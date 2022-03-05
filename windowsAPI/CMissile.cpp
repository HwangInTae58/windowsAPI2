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
	//x�� cos y�� sin
	fPos.x += 30.f * m_vDir.x * (float)DT;
	fPos.y += 30.f * m_vDir.y * (float)DT;

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
// normalize�� �̿��� �������� ����
void CMissile::SetDir(fvec _fvec)
{
	// �̵����� ���� �� �� normalize�� ���� ����
	m_vDir = _fvec.Normalize();
}


