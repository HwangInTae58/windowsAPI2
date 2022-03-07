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


	/*���� ���̵� : ���� �����Լ�(virtual)�� �����ʿ�� ������
������ ��ӹ����� ��Ȯ�ϰ� �˱� ���� ����� ����*/
	virtual void update();
	virtual void render(HDC hDC);
private:
	

	void CreateMissile();
	void CreateGrenade();
};

