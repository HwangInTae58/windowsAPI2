#include "framework.h"
#include "CTexture.h"

CTexture::CTexture()
{
	m_hDC = 0;
	m_hBit = 0;
}

CTexture::~CTexture()
{
	DeleteDC(m_hDC);
	DeleteObject(m_hBit);
}

void CTexture::Load(const wstring& strFilePath)
{
	m_hBit = (HBITMAP)LoadImage(nullptr,			// hInstance. nullptr로 해도 됨.
		strFilePath.c_str(),						// 파일 경로를 C style 문자열로 변환
		IMAGE_BITMAP,								// 이미지 타입, 비트맵 이미지로 지정
		0,0,										// 이미지의 X, Y 크기, 0을 주면 이미지 크기로 설정
		LR_CREATEDIBSECTION | LR_LOADFROMFILE		// 이미지 로딩 타입.
		);
	assert(m_hBit);
}
