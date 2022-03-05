#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
private:
	//�̻����� ���ư��� ������ ������ ���Ѵ�
	float m_fTheta; // �̻����� ���ư��� ����

	// ����(r)�� 1�϶� x, y�� x = cos���� / ����, y = sin���� / ���� �̴ϱ�
	//x = cos����, y = sin����
	fvec m_vDir;

public:
	CMissile();
	virtual ~CMissile();

	virtual void update();
	virtual void render(HDC hDC);
	void SetDir(fvec _fvec);



};

