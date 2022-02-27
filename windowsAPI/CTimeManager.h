#pragma once
class CTimeManager
{
	SINGLETON(CTimeManager);

private:
	// LARGE_INTEGER : long long ������ ����ü HighPart + LowPart = QuadPart
	LARGE_INTEGER m_llCurCount;		// ���� ī��Ʈ
	LARGE_INTEGER m_llPrevCount;	// ���� ī��Ʈ
	LARGE_INTEGER m_llFrequency;	// �ʴ� ī��Ʈ Ƚ��

	unsigned int	m_uiFPS;			// FPS : �ʴ� ȣ��� ������Ʈ �� == �ʴ� �׷��� ȭ�� ��
	double			m_dDT;				// Delta Time : �����ð�, ������Ʈ�� �ҿ�� �ð� == 1�����Ӵ� �ҿ�� �ð�

public:
	void update();		// ������Ʈ
	void init();		// �ʱ�ȭ

	unsigned int GetFPS();
	double GetDT();
};

