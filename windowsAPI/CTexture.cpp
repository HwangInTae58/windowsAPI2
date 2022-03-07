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
	//���Ϸ� ���� �ε��ϴ� �����͸� ��Ʈ������ ����
	m_hBit = (HBITMAP)LoadImage(nullptr,			// hInstance. nullptr�� �ص� ��.
		strFilePath.c_str(),						// ���� ��θ� C style ���ڿ��� ��ȯ
		IMAGE_BITMAP,								// �̹��� Ÿ��, ��Ʈ�� �̹����� ����
		0,0,										// �̹����� X, Y ũ��, 0�� �ָ� �̹��� ũ��� ����
		LR_CREATEDIBSECTION | LR_LOADFROMFILE		// �̹��� �ε� Ÿ��.
		);
	assert(m_hBit);
	//bit�ʰ� ������ DC
	m_hDC = CreateCompatibleDC(CCore::getInst()->GetMainDC());

	//��Ʈ�ʰ� DC����
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_hDC, m_hBit);
	DeleteObject(hPrevBit);

	// ���� ���� ����
	// ��Ʈ�� ����
	GetObject(m_hBit,sizeof(BITMAP), &m_bitInfo);

}

UINT CTexture::Width()
{
	//��Ʈ�� ������ ����
	return m_bitInfo.bmWidth;
}

UINT CTexture::Height()
{
	//��Ʈ�� ������ ����
	return m_bitInfo.bmHeight;
}
