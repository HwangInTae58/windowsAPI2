#include "framework.h"
#include "CCollider.h"
#include "CGameObject.h"
#include "SelectGDI.h"

CCollider::CCollider()
{
	m_pOwner = nullptr;
	m_fptOffsetPos = {};
	m_fptFinalPos = {};
	m_fptScale = {};
}

CCollider::~CCollider()
{
}

fPoint CCollider::GetOffsetPos()
{
	return m_fptOffsetPos;
}

fPoint CCollider::GetFinalPos()
{
	return m_fptFinalPos;
}

fPoint CCollider::GetScale()
{
	return m_fptScale;
}

void CCollider::SetOffsetPos(fPoint offsetPos)
{
	m_fptOffsetPos = offsetPos;
}

void CCollider::SetFinalPos(fPoint finalPos)
{
	m_fptFinalPos = finalPos;
}

void CCollider::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

void CCollider::finalupdate() // 이 작업을 매프레임마다 갱신
{
	//오브젝트의 위치를 따라갈수있게 작업
	fPoint fptObjectPos = m_pOwner->GetPos(); //오브젝트의 위치를 잡고
	m_fptFinalPos = fptObjectPos + m_fptOffsetPos; //충돌체에 오프셋의 위치를 더해 
	//오브젝트가 갖는 충돌체의 정확한 위치를 FinalPos에 저장한다.
}

void CCollider::render(HDC hDC)
{
	SelectGDI brush(hDC, TYPE_BRUSH::HOLLOW);
	SelectGDI pen(hDC, TYPE_PEN::GREEN);

	Rectangle(hDC,
		(int)(m_fptFinalPos.x - m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y - m_fptScale.y / 2.f),
		(int)(m_fptFinalPos.x + m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y + m_fptScale.y / 2.f));
}
