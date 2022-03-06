#include "framework.h"
#include "CCore.h"
#include "CScene.h"

#define CHAR_X_LEN 20
#define CHAR_Y_LEN 20

CCore::CCore()
{
	// 게임 화면을 그리기 위한 DC 핸들값 초기화
	m_hDC = 0;
	m_hMemDC = 0;
	m_hBMP = 0;
}

CCore::~CCore()
{
	// 게임 코어 종료 시점에 DC 핸들값 반납
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

void CCore::update()
{
	//씬 매니저 업데이트
	
	CTimeManager::getInst()->update();
	CKeyManager::getInst()->update();
	CSceneManager::getInst()->update();


}
	   

void CCore::render()
{

	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);
	//씬 매니저 렌더
	CSceneManager::getInst()->render(m_hMemDC);

	// 오른쪽 상단에 FPS 표시
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);

	// memDC에 그린 작업을 다시 윈도우 DC로 복사
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
	
}

void CCore::init()
{
	// 게임(매니저) 초기화 작업 진행
	PathManager::getInst()->init();
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->init();
	CSceneManager::getInst()->init();

	// 게임 윈도우의 DC 핸들값 가져오기
	m_hDC = GetDC(hWnd);

	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
}
