#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
private:
	//�̻����� ���ư��� ������ ������ ���Ѵ�
	float m_fTheta; // �̻����� ���ư��� ����

public:
	CMissile();
	virtual ~CMissile();

	virtual void update();
	virtual void render(HDC hDC);

	void SetDir(bool _Right);

};

