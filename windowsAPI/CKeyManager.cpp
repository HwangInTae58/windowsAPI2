#include "CKeyManager.h"
#include "framework.h"

CKeyManager::CKeyManager()
{
	for (int key = 0; key < VKEY_SIZE; key++) {
		m_arrPrevKey[key] = false;
		m_arrCurKey[key] = false;
	}
}
CKeyManager::~CKeyManager()
{

}

void CKeyManager::update()
{
	// GetFocus 지금 활성화된 핸들값(윈도우)을 가져오는 함수
	HWND curWnd = GetFocus();
	if (hWnd != curWnd) {
		//윈도우가 선택된 상태가 아니라면 모든 키입력을 false해준다
		for (int key = 0; key < VKEY_SIZE; key++)
		{
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;
		}
		return;
	}
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];
		if (GetAsyncKeyState(key) & 0x8000)
		{
			m_arrCurKey[key] = true;
		}
		else
		{
			m_arrCurKey[key] = false;
		}
	}
}

void CKeyManager::init()
{
}

bool CKeyManager::GetButton(const int key)
{
	// 키가 눌려진 상태면 true반환
	return (true == m_arrPrevKey[key] && true == m_arrCurKey[key]);
}

bool CKeyManager::GetButtonDown(const int key)
{
	//키가 눌려진 순간만 true반환
	return (false == m_arrPrevKey[key] && true == m_arrCurKey[key]);
}

bool CKeyManager::GetButtonUp(const int key)
{
	//키가 올라간 순간만 true반환
	return (true == m_arrPrevKey[key] && false == m_arrCurKey[key]);
}
