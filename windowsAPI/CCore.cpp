#include "framework.h"
#include "CCore.h"
#include "CScene.h"

#define CHAR_X_LEN 20
#define CHAR_Y_LEN 20

CCore::CCore()
{
	// ���� ȭ���� �׸��� ���� DC �ڵ鰪 �ʱ�ȭ
	m_hDC = 0;
	m_hMemDC = 0;
	m_hBMP = 0;
}

CCore::~CCore()
{
	// ���� �ھ� ���� ������ DC �ڵ鰪 �ݳ�
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

void CCore::update()
{
	//�� �Ŵ��� ������Ʈ
	
	CTimeManager::getInst()->update();
	CKeyManager::getInst()->update();
	CSceneManager::getInst()->update();


}
	   

void CCore::render()
{

	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);
	//�� �Ŵ��� ����
	CSceneManager::getInst()->render(m_hMemDC);

	// ������ ��ܿ� FPS ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);

	// memDC�� �׸� �۾��� �ٽ� ������ DC�� ����
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
	
}

void CCore::init()
{
	// ����(�Ŵ���) �ʱ�ȭ �۾� ����
	PathManager::getInst()->init();
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->init();
	CSceneManager::getInst()->init();

	// ���� �������� DC �ڵ鰪 ��������
	m_hDC = GetDC(hWnd);

	// ���� ���۸��� �޸� DC�� ��Ʈ�� ����
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
}
