#pragma once
#include "CGameObject.h"

class CTexture;

class CObject_Player : public CGameObject
{
private:
	CTexture* m_pTex;
public:
	CObject_Player();
	~CObject_Player();


	/*오버 라이딩 : 굳이 가상함수(virtual)를 붙일필요는 없지만
무엇을 상속받은지 명확하게 알기 위해 국룰로 붙힘*/
	virtual void update();
	virtual void render(HDC hDC);
private:
	

	void CreateMissile();
	void CreateGrenade();
};

