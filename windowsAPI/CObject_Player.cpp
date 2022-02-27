#include "framework.h"
#include "CObject_Player.h"


void CObject_Player::update()
{
	if (CKeyManager::getInst()->GetButton(VK_LEFT))
	{
		m_fptPos.x -= 300.f * DT;
	}

	if (CKeyManager::getInst()->GetButton(VK_RIGHT))
	{
		m_fptPos.x += 300.f * DT;
	}

	if (CKeyManager::getInst()->GetButton(VK_UP))
	{
		m_fptPos.y -= 300.f * DT;
	}

	if (CKeyManager::getInst()->GetButton(VK_DOWN))
	{
		m_fptPos.y += 300.f * DT;
	}
}
