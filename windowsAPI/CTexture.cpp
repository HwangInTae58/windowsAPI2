#include "framework.h"
#include "CTexture.h"

CTexture::CTexture()
{
	m_hDC = 0;
	m_hBit = 0;
	m_bitInfo = {};
}

CTexture::~CTexture()
{
	DeleteDC(m_hDC);
	DeleteObject(m_hBit);
}

HDC CTexture::GetDC()
{
	return m_hDC;
}

void CTexture::Load(const wstring& strFilePath)
{
	//파일로 부터 로딩하는 데이터를 비트맵으로 생성
	m_hBit = (HBITMAP)LoadImage(nullptr,			// hInstance. nullptr로 해도 됨.
		strFilePath.c_str(),						// 파일 경로를 C style 문자열로 변환
		IMAGE_BITMAP,								// 이미지 타입, 비트맵 이미지로 지정
		0,0,										// 이미지의 X, Y 크기, 0을 주면 이미지 크기로 설정
		LR_CREATEDIBSECTION | LR_LOADFROMFILE		// 이미지 로딩 타입.
		);
	assert(m_hBit);
	//bit맵과 연결할 DC
	m_hDC = CreateCompatibleDC(CCore::getInst()->GetMainDC());

	//비트맵과 DC연결
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_hDC, m_hBit);
	DeleteObject(hPrevBit);

	// 가로 세로 길이
	// 비트맵 정보
	GetObject(m_hBit,sizeof(BITMAP), &m_bitInfo);

}

UINT CTexture::Width()
{
	//비트맵 정보의 가로
	return m_bitInfo.bmWidth;
}

UINT CTexture::Height()
{
	//비트맵 정보의 세로
	return m_bitInfo.bmHeight;
}
