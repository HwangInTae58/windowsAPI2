#pragma once
#include "CRes.h"
class CTexture : public CRes
{
private:
	HDC			m_hDC;  // 이미지 파일
	HBITMAP		m_hBit;
	BITMAP		m_bitInfo; //픽셀 이미지
public:
	CTexture();
	virtual ~CTexture();
	HDC GetDC();
	void Load(const wstring& strFilePath);
	UINT Width();
	UINT Height();

};

