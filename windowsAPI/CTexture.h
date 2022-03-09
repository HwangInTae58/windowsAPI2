#pragma once
#include "CRes.h"
class CTexture : public CRes
{
private:
	HDC			m_hDC;  // �̹��� ����
	HBITMAP		m_hBit;
	BITMAP		m_bitInfo; //�ȼ� �̹���

	// Resourcemanager���� �ؽ��ĸ� ����� ������ ���ֵ��� ������ ������ ����
	friend class CResManager;

	CTexture();
	~CTexture();
public:
	
	HDC GetDC();
	void Load(const wstring& strFilePath);
	UINT Width();
	UINT Height();

};

