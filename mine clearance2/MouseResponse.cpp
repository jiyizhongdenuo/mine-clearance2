#ifndef _MOUSERESPONSE_H
#define _MOUSERESPONSE_H

/*与程序中鼠标响应相关*/

#include<graphics.h>
#include<iostream>
#include"MouseResponse.h"
#include"Wds.h"
#include"Algorithm.h"

using std::cout;
using std::endl;

int bnumb = 0;
Cr cr;
gamexy SXY;//左上坐标
gamexy LXY;//右下坐标
extern  cradd s1, s2, s3, o1, o2;
extern bool YON;
extern int addmultiple;
extern int total;
extern int Tflags;
extern int displaysum;
extern int total;


/*建立按钮区，把给定的坐标点区分为不同按钮。*/
template <class T, class T1, typename ...Args>
bool button(T b1, T1 b2, Args...args)
{
	bnumb++;
	if (b1.x1<b2.x&&b1.x2>b2.x&&b1.y1<b2.y&&b1.y2>b2.y)
		return true;
	if (button(args...))
		return true;
	else
	{
		return false;
		bnumb = 0;
	}
}
template <class T, class T1>
bool button(T b1, T1 b2)
{
	bnumb++;
	if (b1.x1<b2.x&&b1.x2>b2.x&&b1.y1<b2.y&&b1.y2>b2.y)
		return true;
	else
		return false;
}

/*游戏过程中，对相应的点击做出反应。*/
void GMouseResponse(clearanceInfo ** ci)
{
	bool island = false;
	MOUSEMSG mmsg = GetMouseMsg();// 3
	do
	{
		if (MouseHit())
		{
			mmsg = GetMouseMsg();
			if (mmsg.mkLButton || mmsg.mkRButton)
			{

				if (SXY.x < mmsg.x && mmsg.x < LXY.x && SXY.y < mmsg.y && mmsg.y < LXY.y)
				{
					island = judgeland(ci, mmsg);
				}
			}
		}
	} while (!island);
	Sleep(100);
}

/*辅助选择按钮，获取鼠标信息。*/
void MKLMouseMSG(MOUSEMSG & mmsg)
{
	do
	{
		if (MouseHit())
			mmsg = GetMouseMsg();
	} while (!mmsg.mkLButton);
}

/*难度选项*/
void Select()
{
	MOUSEMSG mmsg = GetMouseMsg();
	while (!bnumb)// 0
	{
		do
		{
			MKLMouseMSG(mmsg);
		} while (!button(s1, mmsg, s2, mmsg, s3, mmsg));
		switch (bnumb)
		{
		case 1:
			cr.x = 10;
			cr.y = 5;
			cr.s = 10;
			displaysum = 10;
			total = 10;
			Tflags = 10;
			SXY.x = (1280 - cr.x*addmultiple)/2;
			SXY.y = (720 - cr.y*addmultiple) / 2+50;
			LXY.x = 1280 - SXY.x;
			LXY.y = SXY.y + cr.y*addmultiple;
			break;
		case 2:
			cr.x = 20;
			cr.y = 10;
			cr.s = 40;
			displaysum = 40;
			total = 40;
			Tflags = 40;
			SXY.x = (1280 - cr.x*addmultiple) / 2;
			SXY.y = (720 - cr.y*addmultiple) / 2+50;
			LXY.x = 1280 - SXY.x;
			LXY.y = SXY.y + cr.y*addmultiple;
			break;
		case 3:
			cr.x = 30;
			cr.y = 16;
			cr.s = 99; 
			displaysum = 99;
			total = 99;
			Tflags = 99;
			SXY.x = (1280 - cr.x*addmultiple) / 2;
			SXY.y = (720 - cr.y*addmultiple) / 2+50;
			LXY.x = 1280 - SXY.x;
			LXY.y = SXY.y + cr.y*addmultiple;
			break;
		}
	}
	bnumb = 0;
}

/*重开或者结束*/
void OverSelect()
{
	MOUSEMSG mmsg = GetMouseMsg();
	while (!bnumb)
	{
		do
		{
			MKLMouseMSG(mmsg);
		} while (!button(o1, mmsg, o2, mmsg));
		switch (bnumb)
		{
		case 1:
			YON = true;
			break;
		case 2:
			YON = false;
			break;
		}
	}
	bnumb = 0;
	mciSendString(L"close ./Fake.mp3", nullptr, 0, nullptr);
}

/*游戏开始时白块背景贴图*/
void Gamegraph(clearanceInfo ** ci)
{
	for (int i = 0; i < cr.x; i++)
	{
		for (int j = 0; j < cr.y; j++)
		{
			putimage(SXY.x + i * addmultiple, SXY.y + j * addmultiple, &ci[i][j].origin);
		}
	}
}


#endif // !_MOUSERESPONSE_H
