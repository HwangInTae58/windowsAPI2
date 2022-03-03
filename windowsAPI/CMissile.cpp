#include "framework.h"
#include "CMissile.h"

CMissile::CMissile()
{
	iDir = 1;
}

CMissile::~CMissile()
{
}

void CMissile::update()
{
	fPoint fPos = GetPos();

	fPos.x += 300.f * iDir * (float)DT;

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

void CMissile::SetDir(bool _Right)
{
	if (_Right)
	{
		iDir = 1.f;
	}
	else
	{
		iDir = -1.f;
	}
}
