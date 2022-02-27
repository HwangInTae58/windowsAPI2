#pragma once
#include "SingleTon.h"
#define VKEY_SIZE  0xFF //키의 갯수

class CKeyManager
{
	SINGLETON(CKeyManager);
private:
	
	bool m_arrPrevKey[VKEY_SIZE]; //이전 키의 입력상태를 저장
	bool m_arrCurKey[VKEY_SIZE];  //현재 키의 입력상태를 저장할 배열
public:
	void update();
	void init();

	bool GetButton(const int key);		// 키가 눌려진 상태면 true반환
	bool GetButtonDown(const int key);	//키가 눌려진 순간만 true반환
	bool GetButtonUp(const int key);	//키가 올라간 순간만 true반환
};

