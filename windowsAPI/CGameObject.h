#pragma once

class CCollider;

class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

	//����Ʈ ������ ����� �浹ü(Collider)�� �ʿ� ������ nullptr�� ����Ͽ� �ڽ�Ŭ������ �Ⱦ��� �� ���ִ�.
	CCollider* m_pClloder;
public:
	CGameObject();
	virtual ~CGameObject();

	// ������Ʈ�� ������ ������ ����� ���� �����Լ�(virtual)���
	//Update�� ������Ʈ���� ���� �ڽ��� ����� �ֱ⿡ ���������Լ��� �����.
	virtual void update() = 0;
	virtual void render(HDC hDC);

	void SetPos(fPoint pos);
	void SetScale(fPoint scsle);

	fPoint GetPos();
	fPoint GetScale();

	void CreateCollider();
};

