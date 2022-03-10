#pragma once

class CCollider;

class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

	//����Ʈ ������ ����� �浹ü(Collider)�� �ʿ� ������ nullptr�� ����Ͽ� �ڽ�Ŭ������ �Ⱦ��� �� ���ִ�.
	CCollider* m_pCollider;
public:
	CGameObject();
	virtual ~CGameObject();

	// ������Ʈ�� ������ ������ ����� ���� �����Լ�(virtual)���
	//Update�� ������Ʈ���� ���� �ڽ��� ����� �ֱ⿡ ���������Լ��� �����.
	virtual void update() = 0;
	virtual void finalupdate() final; //���� ���̵��� �������� final�� ����
	virtual void render(HDC hDC);

	void SetPos(fPoint pos);
	void SetScale(fPoint scsle);

	fPoint GetPos();
	fPoint GetScale();

	CCollider* GetCollider();				// �浹ü ��ȯ
	void CreateCollider();
};

