#include "Wds.h"
#include"Algorithm.h"
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")

//为创建的窗口贴图（包括，开始选项，游戏结束及询问开始结束。）


bool YON;//是否重新开始游戏
int addmultiple = 30;//游戏两个方块之间的距离。
cradd s1(550,300,650,350);
cradd s2(550, 350, 650, 400);
cradd s3(550, 400, 650, 450);
cradd o1(500, 300, 700, 350);
cradd o2(500, 350, 700, 400);
extern Cr cr;
extern gamexy SXY;
extern gamexy LXY;
extern int total;

void StartWin()
{
	loadimage(nullptr, _T("./背景.png"));
	mciSendString(L"open ./StorySwap.mp3", nullptr, 0, nullptr);
	mciSendString(L"play ./StorySwap.mp3 repeat", nullptr, 0, nullptr);
	settextstyle(50, 0, _T("as"));
	setbkmode(TRANSPARENT);
	outtextxy(500, 140, _T("选择难度"));
	outtextxy(550, 300, _T("简单"));
	outtextxy(550, 350, _T("一般"));
	outtextxy(550, 400, _T("困难"));
}

void LDisplay()
{
	if (0==total)
	{
		settextstyle(100, 0, _T("ab"));
		outtextxy(450, 300, _T("YOU   WIN"));
		Sleep(500);
		settextstyle(50, 0, _T("as"));
		mciSendString(L"close ./StorySwap.mp3", nullptr, 0, nullptr);
		mciSendString(L"open ./Fake.mp3", nullptr, 0, nullptr);
		mciSendString(L"play ./Fake.mp3", nullptr, 0, nullptr);
	}
	else
	{
		settextstyle(100, 0, _T("ab"));
		outtextxy(450, 300, _T("GAME  OVER"));
		Sleep(500);
		settextstyle(50, 0, _T("as"));
		mciSendString(L"close ./StorySwap.mp3", nullptr, 0, nullptr);
		mciSendString(L"open ./Fake.mp3", nullptr, 0, nullptr);
		mciSendString(L"play ./Fake.mp3", nullptr, 0, nullptr);
	}
}

void InquiryWindow()
{
	outtextxy(500, 300, _T("重新开始"));
	outtextxy(500, 350, _T("结束游戏"));
}


