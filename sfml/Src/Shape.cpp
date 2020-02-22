#include "Shape.h"

Shape::Shape():rotate(false), colorNum(1),M(20),N(10)
{
	for (int i = 0; i < M; ++i)
	{
		std::vector<int> v(10, 0);
		field.push_back(v);
	}
	figures = { 
	{1,3,5,7},{2,4,5,7}, // Z
	{3,5,4,6},{3,5,4,7}, // T
	{2,3,5,7},{3,5,7,6}, // J
	{2,3,4,5}, // O
	};
	
}

void Shape::moveit(int axis,int dx)
{
	for (int i = 0; i < 4; ++i) b[i] = a[i];
	if (axis == 1)
	{
		for (int i = 0; i < 4; ++i)
		{
			a[i].x += dx;
		}
		if (!check()) for (int i = 0; i < 4; ++i) a[i] = b[i];
	}
	else if (axis == 2)
	{
		for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }
	}
}

void Shape::rotateit()
{
	for (int i = 0; i < 4; ++i) b[i] = a[i];
	Point p = a[1];
	for (int i = 0; i < 4; ++i)
	{
		int x = a[i].y - p.y;
		int y = a[i].x - p.x;

		a[i].x = p.x - x;
		a[i].y = p.y + y;
	}
	if (!check()) for (int i = 0; i < 4; ++i) a[i] = b[i];
}

void Shape::newShape()
{
	if (!check())
	{
		
		for (int i = 0; i < 4; i++) if(b[i].y>0)field[b[i].y][b[i].x] = colorNum;

		colorNum = 1 + rand() % 7;
		int n = rand() % 7;
		for (int i = 0; i < 4; i++)
		{
			a[i].x = figures[n][i] % 2;
			a[i].y = figures[n][i] / 2;
		}
	}
}

Point Shape::position()
{
	return Point();
}

int Shape::checkLine()
{
	int points = 0;
	int k = M - 1;
	for (int i = M - 1; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (field[i][j]) count++;
			field[k][j] = field[i][j];
		}
		if (count < N) k--;
		else ++points;
	}
	return points;
}

bool Shape::check()
{
	for (int i = 0; i < 4; i++)
		if (a[i      ].x < 0 || a[i].x >= N || a[i].y >= M) return false;
		else if (field[a[i].y][a[i].x]) return false;
	return true;
}
