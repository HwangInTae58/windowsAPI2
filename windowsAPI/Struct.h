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

	void hypotenuse()
	{
		// return x * x + y * y;
	}
};