#pragma once
#ifndef WINDOWS_H
#define WINDOWS_H

#include<graphics.h>

// ѡ���ѶȺ󷵻ص���Ϸ��������,���׵�������
struct Cr        
{
	int x;
	int y;
	int s;//����Ҫstatic��s��仯�����staticһ���const������ʹ��ʱ����::�������� 2����
};
//��ʼ�ͽ���ʱ��ť�ĶԽ�����
struct cradd
{
	int x1;
	int y1;
	int x2;
	int y2;
	cradd(int a1 = 0, int b1 = 0, int a2 = 0, int b2 = 0) :x1(a1), y1(b1), x2(a2), y2(b2) {}
	//����a1��ֵ��ֵ���ýṹȱ��Ĭ�Ϲ��캯������ζ������cradd�����Ķ�������ʼ���������̳�ʱ��   1����   
};


void StartWin();
void LDisplay();
void InquiryWindow();


#endif // !WINDOWS_H
