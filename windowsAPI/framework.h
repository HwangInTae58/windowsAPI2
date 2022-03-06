// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#pragma comment(lib, "msimg32.lib")
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string.h>
#include <locale>
#include <math.h>
#include <assert.h>


#include <vector>
#include <map>


using namespace std;






#include "SingleTon.h"
#include "Struct.h"

//========================================
//##			그룹				##
//========================================

enum class GROUP_TYPE
{
	Default,	// 0
	Player,		// 1
	Missile,	// 2	
	Monster,	// 3

	Size,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE1,

	Size,
};



#include "CCore.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "PathManager.h"
//========================================
//##			디파인문				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX



//========================================
//##			메크로				##
//========================================

// TODO : 여기 키값 메크로 하나도 안먹히는 이유를 모르겠어요.
#define KEY(vk_key)					CKeyManager::getInst()->GetButton(vk_key);
#define KEYDOWN(vk_key)				CKeyManager::getInst()->GetButtonDown(vk_key);
#define KEYUP(vk_key)				CKeyManager::getInst()->GetButtonUP(vk_key);

#define DT							CTimeManager::getInst()->GetDT();

#define PHI 3.141592



//========================================
//## 전역변수(인스턴스, 윈도우 핸들)	##
//========================================
extern HINSTANCE hInst;
extern HWND hWnd;






