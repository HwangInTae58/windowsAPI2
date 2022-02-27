#pragma once
class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

public:
	CGameObject();
	virtual ~CGameObject();

	// 오브젝트의 종류를 여러게 만들기 위해 가상함수(virtual)사용
	virtual void update();
	virtual void render(HDC hDC);

	void SetPos(fPoint pos);
	void SetScale(fPoint scsle);

	fPoint GetPos();
	fPoint GetScale();
};

