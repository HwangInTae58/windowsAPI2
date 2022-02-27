#include "framework.h"
#include "CTimeManager.h"

CTimeManager::CTimeManager()
{

}

CTimeManager::~CTimeManager()
{

}

void CTimeManager::update()
{
	static unsigned int updateCount = 0;	// update�� �߻��� ī��Ʈ ����
	static double updateOneSecond = 0;		// update�� 1�ʰ� �Ǿ����� �Ǵ��ϱ� ���� ����

	// �ð� ����
	// ���� ī��Ʈ - ���� ī��Ʈ => ���� ������Ʈ���� ���� ������Ʈ�� ȣ��Ǳ� ���� ī��Ʈ ��
	// (���� ī��Ʈ - ���� ī��Ʈ) / �ʴ� ī��Ʈ �� => 1update�� �߻��� �������� �ð�

	// ex)
	// �ӷ��� 100km/h �� �ڵ����� 10km�������� 20km �������� ���µ� �ɸ��� �ð��� ���Ϸ���
	// (20km - 10km) / 100km/h = 0.1h

	// ���� ī��Ʈ ���� Ȯ��
	QueryPerformanceCounter(&m_llCurCount);
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / m_llFrequency.QuadPart;
	// ���� ī��Ʈ�� ���� ī��Ʈ ������ �ִ´�.
	m_llPrevCount = m_llCurCount;

	// update �Լ��� ȣ��ɶ����� �����ϴ� updateCount
	++updateCount;
	// ���� �ð���ŭ 1�ʰ� �Ǿ����� Ȯ���ϴ� updateOneSecond�� �߰�
	updateOneSecond += m_dDT;
	if (updateOneSecond >= 1.0)	// ���� updateOneSecond�� 1�� �̻��� �Ǿ��ٸ�
	{
		m_uiFPS = updateCount;	// �ʴ� update Ƚ�� == FPS

		updateOneSecond = 0;	// updateOneSecond�� �ʱ�ȭ
		updateCount = 0;		// updateCount�� �ʱ�ȭ
	}
}

void CTimeManager::init()
{
	// GetTickCount				: �����ϰ� ������ ī��Ʈ ���� �Լ�
	// QueryPerformanceCount	: �� �� ������ ī��Ʈ ���� �Լ�

	// ���� ī��Ʈ ���� Ȯ��
	QueryPerformanceCounter(&m_llPrevCount);
	// �ʴ� ī��Ʈ ���� Ȯ��
	QueryPerformanceFrequency(&m_llFrequency);
}

unsigned int CTimeManager::GetFPS()
{
	return m_uiFPS;
}

double CTimeManager::GetDT()
{
	return m_dDT;
}
