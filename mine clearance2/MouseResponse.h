#pragma once
#ifndef _MOUSERESPONSE_H
#define _MOUSERESPONSE_H

#include<graphics.h>

//��Ϊ����ʱ��������Ӧ���ֱ�Ϊ��Ϸ����ʱ����Ϸ��ʼ�����ʱ�������Ӧ


void GMouseResponse(clearanceInfo ** ci);
template <class T, class T1, typename ...Args>//�������Ӧ��Χ
bool button(T b1, T1 b2, Args...args);
template <class T, class T1>
bool button(T b1, T1 b2);
void MKLMouseMSG(MOUSEMSG & mmsg);
void Select();
void OverSelect();
void Gamegraph(clearanceInfo ** ci);

#endif // !_MOUSERESPONSE_H


