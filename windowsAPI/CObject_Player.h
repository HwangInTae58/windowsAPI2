#pragma once
#include "CGameObject.h"

class CObject_Player : public CGameObject
{
	/*���� ���̵� : ���� �����Լ�(virtual)�� �����ʿ�� ������
	������ ��ӹ����� ��Ȯ�ϰ� �˱� ���� ����� ����*/
	virtual void update();
	
	void CreateMissile();

};

