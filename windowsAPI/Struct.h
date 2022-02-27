#pragma once
struct fPoint
{
	//포인터를 float형태로 바꿔사용하는 구조체
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
	//포인터를 float형태로 바꿔사용하는 구조체
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