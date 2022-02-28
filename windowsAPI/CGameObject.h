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
	//Update는 오브젝트마다 전부 자신의 기능이 있기에 순수가상함수로 만든다.
	virtual void update() = 0;
	virtual void render(HDC hDC);

	void SetPos(fPoint pos);
	void SetScale(fPoint scsle);

	fPoint GetPos();
	fPoint GetScale();
};

