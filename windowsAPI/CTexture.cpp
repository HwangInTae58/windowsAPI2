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
	m_hBit = (HBITMAP)LoadImage(nullptr,			// hInstance. nullptr�� �ص� ��.
		strFilePath.c_str(),						// ���� ��θ� C style ���ڿ��� ��ȯ
		IMAGE_BITMAP,								// �̹��� Ÿ��, ��Ʈ�� �̹����� ����
		0,0,										// �̹����� X, Y ũ��, 0�� �ָ� �̹��� ũ��� ����
		LR_CREATEDIBSECTION | LR_LOADFROMFILE		// �̹��� �ε� Ÿ��.
		);
	assert(m_hBit);
}
