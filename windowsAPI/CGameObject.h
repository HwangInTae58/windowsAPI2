#pragma once
class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;
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
};

