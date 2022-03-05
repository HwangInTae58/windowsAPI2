#include "framework.h"
#include "CObject_Player.h"
#include "CScene.h"
#include "CMissile.h"

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

	if (CKeyManager::getInst()->GetButtonDown(VK_SPACE))
	{
		CreateMissile();
	}
	// GetPos ���������̹Ƿ� SetPos�� ������ ���� ��������
	SetPos(fpt);

}

void CObject_Player::CreateMissile()
{
	//��������� �̻����� ��ġ�� �÷��̾� �������� �ϰ�
	fPoint fMissilePos = GetPos();
	// �÷��̾��� �÷��� x��ǥ�� ���뿡�� ����
	fMissilePos.x += GetScale().x / 2.f;
	//�̻��� ������Ʈ ����
	CMissile* missile1 = new CMissile;
	//������Ʈ ������ġ
	missile1->SetPos(fMissilePos);
	//������Ʈ ũ�� ����
	missile1->SetScale(fPoint(15.f, 15.f));
	//������Ʈ�� �����̴� ��ġ����
	

	CScene* pCurScene =	CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(missile1,GROUP_TYPE::Default);

}
