#pragma once
#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include<graphics.h>

struct gamexy
{
	int x;
	int y;
};//��ͼ��ʼ��xy
struct clearanceInfo
{
	IMAGE origin;//��ʾ�ķ�������ͼ��
	IMAGE reaplace;//�������ʾ�����ֻ�շ���ͼ��
	bool ion=0;//�Ƿ�����
	bool judge = 0;//���ʱ����������ʱ��Ѱ���ܱ߷����Ƿ�Ѱ����
	bool redflag = 0;//�ж���ʾ���Ǻ��컹�Ƿ��顣
	gamexy add;
	int aboutland = 0;//��Χ����
};//�׵���Ϣ

void crandom(clearanceInfo ** ci);
void OIconReaplace(clearanceInfo ** ci);
void RIconReaplace(clearanceInfo ** ci);//��������reaplace
bool judgeland(clearanceInfo ** ci, MOUSEMSG & mmsg);
void judgebule(int x, int y, clearanceInfo ** ci);




#endif // !_ALGORITHM_H
