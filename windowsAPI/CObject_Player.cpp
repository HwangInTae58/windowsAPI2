#include "framework.h"
#include "CObject_Player.h"


void CObject_Player::update()
{
	//GetPos�� �����ͼ� ����
	fPoint fpt = GetPos();
	if (CKeyManager::getInst()->GetButton(VK_LEFT))
	{
		fpt.x -= 300.f * (float)DT;
	}

	if (CKeyManager::getInst()->GetButton(VK_RIGHT))
	{
		fpt.x += 300.f * (float)DT;
	}

	if (CKeyManager::getInst()->GetButton(VK_UP))
	{
		fpt.y -= 300.f * (float)DT;
	}

	if (CKeyManager::getInst()->GetButton(VK_DOWN))
	{
		fpt.y += 300.f * (float)DT;
	}
	// GetPos ���������̹Ƿ� SetPos�� ������ ���� ��������
	SetPos(fpt);

}
