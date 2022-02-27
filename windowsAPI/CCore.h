#pragma once

class CCore
{
	SINGLETON(CCore);

private:
	//HDC : �׸��� ��������
	HDC m_hDC;			// ������ DC �ڵ� : ���� ������ â�� �׸��� DC
	HDC m_hMemDC;		// �޸� DC �ڵ� : �׸��� �۾��� �ӽ÷� ������ �޸��� DC
	HBITMAP m_hBMP;		// ��Ʈ�� �ڵ� : �׸��� ���뿡 ���� �̹��� �ڵ�

public:
	void update();
	void render();
	void init();
};

