#pragma once

class CCollider;

class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

	//포인트 변수로 만들어 충돌체(Collider)가 필요 없으면 nullptr로 사용하여 자식클래스가 안쓰게 할 수있다.
	CCollider* m_pCollider;
public:
	CGameObject();
	virtual ~CGameObject();

	// 오브젝트의 종류를 여러게 만들기 위해 가상함수(virtual)사용
	//Update는 오브젝트마다 전부 자신의 기능이 있기에 순수가상함수로 만든다.
	virtual void update() = 0;
	virtual void finalupdate() final; //오버 라이딩을 막기위해 final을 붙힘
	virtual void render(HDC hDC);

	void SetPos(fPoint pos);
	void SetScale(fPoint scsle);

	fPoint GetPos();
	fPoint GetScale();

	CCollider* GetCollider();				// 충돌체 반환
	void CreateCollider();
};

