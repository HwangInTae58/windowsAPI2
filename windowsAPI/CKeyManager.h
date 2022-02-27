#pragma once
#include "SingleTon.h"
#define VKEY_SIZE  0xFF //Ű�� ����

class CKeyManager
{
	SINGLETON(CKeyManager);
private:
	
	bool m_arrPrevKey[VKEY_SIZE]; //���� Ű�� �Է»��¸� ����
	bool m_arrCurKey[VKEY_SIZE];  //���� Ű�� �Է»��¸� ������ �迭
public:
	void update();
	void init();

	bool GetButton(const int key);		// Ű�� ������ ���¸� true��ȯ
	bool GetButtonDown(const int key);	//Ű�� ������ ������ true��ȯ
	bool GetButtonUp(const int key);	//Ű�� �ö� ������ true��ȯ
};

