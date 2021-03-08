#include"Algorithm.h"
#include"Wds.h"
#include"MouseResponse.h"
#include<iostream>

extern bool YON;
extern Cr cr;
int main()
{
	initgraph(1280, 720, SHOWCONSOLE);
	do
	{
		StartWin();
		Select();
		clearanceInfo ** ci = new clearanceInfo *[cr.x];
		for (int i = 0; i < cr.x; i++)
			ci[i] = new clearanceInfo[cr.y];
		crandom(ci);
		OIconReaplace(ci);
		RIconReaplace(ci);
		loadimage(nullptr, L"./背景.png");
		Gamegraph(ci);
		Sleep(200);
		GMouseResponse(ci);
		loadimage(nullptr, L"./背景.png");
		LDisplay();
		for (int i = 0; i < cr.x; i++)
		{
			delete[]ci[i];
		}
		delete[]ci;
		Sleep(500);
		loadimage(nullptr, L"./背景.png");
		InquiryWindow();
		FlushMouseMsgBuffer();
		OverSelect();
	} while (YON);
	return 0;
}
