#pragma once
#ifndef WINDOWS_H
#define WINDOWS_H

#include<graphics.h>

// 选择难度后返回的游戏方块数量,及雷的总数。
struct Cr        
{
	int x;
	int y;
	int s;//不需要static，s会变化。类的static一般加const。并且使用时类名::变量名。 2错误
};
//开始和结束时按钮的对角坐标
struct cradd
{
	int x1;
	int y1;
	int x2;
	int y2;
	cradd(int a1 = 0, int b1 = 0, int a2 = 0, int b2 = 0) :x1(a1), y1(b1), x2(a2), y2(b2) {}
	//不给a1等值赋值，该结构缺少默认构造函数，意味着所有cradd创建的对象必须初始化，包括继承时候。   1错误   
};


void StartWin();
void LDisplay();
void InquiryWindow();


#endif // !WINDOWS_H
