// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

//library참조할때 쓰는 방법
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
#define DT							CTimeManager::getInst()->GetDT();

#define PHI 3.141592

#define Key(key)		CKeyManager::getInst()->GetButton(key)
#define KeyUP(key)		CKeyManager::getInst()->GetButtonUp(key)
#define KeyDown(key)	CKeyManager::getInst()->GetButtonDown(key)

//========================================
//## 전역변수(인스턴스, 윈도우 핸들)	##
//========================================
extern HINSTANCE hInst;
extern HWND hWnd;






