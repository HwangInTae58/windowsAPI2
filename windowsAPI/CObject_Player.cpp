#include "framework.h"
#include "CObject_Player.h"
#include "CScene.h"
#include "CMissile.h"
#include "PathManager.h"
#include "CTexture.h"
#include "CResManager.h"

CObject_Player::CObject_Player()
{
	// Resource Manager�� ���� Texture �ε��ϱ�
	m_pTex = CResManager::getInst()->LoadTextrue(L"PlayerTex", L"texture\\Player.bmp");
}

CObject_Player::~CObject_Player()
{
	if (nullptr != m_pTex)
	{
		delete m_pTex;
	}
}

void CObject_Player::update()
{
	//GetPos�� �����ͼ� ����
	fPoint fpt = GetPos();
	if (Key(VK_LEFT))
	{
		fpt.x -= 300.f * (float)DT;
	}

	if (Key(VK_RIGHT))
	{
		fpt.x += 300.f * (float)DT;
	}

	if (Key(VK_UP))
	{
		fpt.y -= 300.f * (float)DT;
	}

	if (Key(VK_DOWN))
	{
		fpt.y += 300.f * (float)DT;
	}
	
	if (KeyDown(VK_SPACE))
	{
		CreateMissile();
	}
	
	if (KeyDown(VK_LSHIFT))
	{
		CreateGrenade();
	}
	// GetPos ���������̹Ƿ� SetPos�� ������ ���� ��������
	SetPos(fpt);

}

void CObject_Player::render(HDC hDC)
{
	// ���� �̻������� �����Ƿ� ����(int)�� ����ȯ
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();
	
	fPoint fPos = GetPos();

	//TransparentBlt : ���� ������ ������ ����ó��
	TransparentBlt(hDC,							//�ڽ��� �׸� ������
		int(fPos.x - (float)(iWidth / 2)),		//�»��
		int(fPos.y - (float)(iHeight / 2)),		//
		iWidth, iHeight,
		m_pTex->GetDC(),						//�Ű����� ���� DC
		0, 0, 
		iWidth, iHeight,						//�ű涧�� ���� ũ��? �ڸ��� �ʰ� �����Ŷ� ��ü ����
		RGB(255, 0, 255));
}


void CObject_Player::CreateMissile()
{

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

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
	missile1->SetDir(fvec(1.f, 0.f));
	pCurScene->AddObject(missile1, GROUP_TYPE::Default);

}

void CObject_Player::CreateGrenade()
{
	//TODO : �߷��ۿ� ����� ����ź ����� 
	//TODO : Grenade ������Ʈ �����
	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

	//��������� �̻����� ��ġ�� �÷��̾� �������� �ϰ�
	fPoint fMissilePos = GetPos();
	// �÷��̾��� �÷��� x��ǥ�� ���뿡�� ����
	fMissilePos.y -= GetScale().y / 3.f;
	//�̻��� ������Ʈ ����
	CMissile* grenade1 = new CMissile;
	//������Ʈ ������ġ
	grenade1->SetPos(fMissilePos);
	//������Ʈ ũ�� ����
	grenade1->SetScale(fPoint(15.f, 15.f));
	//������Ʈ�� �����̴� ��ġ����
	grenade1->SetDir(fvec(1.f, -2.f));
	pCurScene->AddObject(grenade1, GROUP_TYPE::Default);
}

