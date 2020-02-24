#pragma once
#include"Point.h"
#include<cmath>
#include<vector>

class Shape
{
public:
	Shape();
	void moveit(int i,int dx);
	void rotateit();
	void newShape();
	Point position();
	int checkLine();
	bool checkWin();
	int colorNum;
	Point a[4], b[4];
	const int M ;
	const int N ;
	std::vector<std::vector<int>> figures, field;
private:
	bool check();
	
	bool rotate;
	
};

