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
	// GetFocus ���� Ȱ��ȭ�� �ڵ鰪(������)�� �������� �Լ�
	HWND curWnd = GetFocus();
	if (hWnd != curWnd) {
		//�����찡 ���õ� ���°� �ƴ϶�� ��� Ű�Է��� false���ش�
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
	// Ű�� ������ ���¸� true��ȯ
	return (true == m_arrPrevKey[key] && true == m_arrCurKey[key]);
}

bool CKeyManager::GetButtonDown(const int key)
{
	//Ű�� ������ ������ true��ȯ
	return (false == m_arrPrevKey[key] && true == m_arrCurKey[key]);
}

bool CKeyManager::GetButtonUp(const int key)
{
	//Ű�� �ö� ������ true��ȯ
	return (true == m_arrPrevKey[key] && false == m_arrCurKey[key]);
}
