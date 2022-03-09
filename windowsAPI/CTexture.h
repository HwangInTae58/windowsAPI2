#pragma once
#include "CRes.h"
class CTexture : public CRes
{
private:
	HDC			m_hDC;  // 이미지 파일
	HBITMAP		m_hBit;
	BITMAP		m_bitInfo; //픽셀 이미지

	// Resourcemanager에서 텍스쳐를 만들고 저장할 수있도록 프렌드 선언을 해줌
	friend class CResManager;

	CTexture();
	~CTexture();
public:
	
	HDC GetDC();
	void Load(const wstring& strFilePath);
	UINT Width();
	UINT Height();

};

