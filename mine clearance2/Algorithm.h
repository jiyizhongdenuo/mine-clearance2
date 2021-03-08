#pragma once
#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include<graphics.h>

struct gamexy
{
	int x;
	int y;
};//贴图起始的xy
struct clearanceInfo
{
	IMAGE origin;//显示的方块或红旗图标
	IMAGE reaplace;//点击后显示的数字或空方块图标
	bool ion=0;//是否是雷
	bool judge = 0;//点击时，是蓝方块时，寻历周边方块是否寻过。
	bool redflag = 0;//判断显示的是红旗还是方块。
	gamexy add;
	int aboutland = 0;//周围雷数
};//雷的信息

void crandom(clearanceInfo ** ci);
void OIconReaplace(clearanceInfo ** ci);
void RIconReaplace(clearanceInfo ** ci);//计算设置reaplace
bool judgeland(clearanceInfo ** ci, MOUSEMSG & mmsg);
void judgebule(int x, int y, clearanceInfo ** ci);




#endif // !_ALGORITHM_H
