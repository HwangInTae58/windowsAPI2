#pragma once
struct fPoint
{
	//�����͸� float���·� �ٲ����ϴ� ����ü
	float x;
	float y;
	fPoint()
	{
		x = 0;
		y = 0;
	}
	fPoint(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

struct fvec
{
	//�����͸� float���·� �ٲ����ϴ� ����ü
	float x;
	float y;
	fvec()
	{
		x = 0;
		y = 0;
	}
	fvec(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	
	fvec& Normalize()
	{
		// sqrt : ��Ʈ �Լ�
		// length �� x�� y�� ���� ������ 1�� �ȴ�.
		float length = sqrt(x * x + y * y);

		//���ʿ� 0�� ������ �����ü�� �ȵǱ� ������ assert���
		// 0�� �ƴ϶�� true�� ����0�̶�� null�� �߸鼭 Ʈ����
		assert(length != 0.f);
		x /= length;
		y /= length;
		

		return *this;
	}
};