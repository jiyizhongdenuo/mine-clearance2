#pragma once
#ifndef _MOUSERESPONSE_H
#define _MOUSERESPONSE_H

#include<graphics.h>

//分为两个时间段鼠标相应，分别为游戏运行时，游戏开始与结束时的鼠标相应


void GMouseResponse(clearanceInfo ** ci);
template <class T, class T1, typename ...Args>//鼠标点击响应范围
bool button(T b1, T1 b2, Args...args);
template <class T, class T1>
bool button(T b1, T1 b2);
void MKLMouseMSG(MOUSEMSG & mmsg);
void Select();
void OverSelect();
void Gamegraph(clearanceInfo ** ci);

#endif // !_MOUSERESPONSE_H


