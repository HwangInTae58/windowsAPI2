#pragma once

class CGameObject;

class CCollider
{
	friend class CGameObject;

private:
	CGameObject* m_pOwner;		// �浹ü�� ������ ���ӿ�����Ʈ�� �ּ�
	fPoint m_fptOffsetPos;		// �浹ü�� ������(������)
	fPoint m_fptFinalPos;		// �浹ü�� ���� ��ġ
	fPoint m_fptScale;			// �浹ü�� ũ��

public:
	CCollider();
	~CCollider();

	fPoint GetOffsetPos();
	fPoint GetFinalPos();
	fPoint GetScale();

	void SetOffsetPos(fPoint offsetPos);
	void SetFinalPos(fPoint finalPos);
	void SetScale(fPoint scale);

	void finalupdate();
	void render(HDC hDC);
};

