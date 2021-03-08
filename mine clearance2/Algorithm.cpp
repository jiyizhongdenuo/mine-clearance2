#include "Algorithm.h"
#include"Wds.h"
#include"MouseResponse.h"
#include<cstdlib>
#include<ctime>
#include<vector>

/*与雷的制作，分布，游戏响应相关*/

using std::vector;

int total;//插旗后真实雷的总数
int displaysum;//显示插旗后剩余虚假的雷的总数
int Tflags;//可插红旗数
extern Cr cr;
extern int addmultiple;
extern gamexy SXY;

/*打乱雷的排布*/
void crandom(clearanceInfo ** ci)
{
	srand(time(nullptr));
	int count = cr.x*cr.y;
	vector<int>index(count, 0);
	for (int i = 0; i < index.size(); i++)
		index[i] = i;
	for (int i = 0; i < cr.s; i++)
	{
		int tem = rand() % (count--);
		int row = index[tem] / cr.y;
		int col = index[tem] % cr.y;
		ci[row][col].ion = 1;
		index[tem] = count;
	}
}

/*给数组换上贴图*/
void OIconReaplace(clearanceInfo ** ci)
{
	for (int i = 0; i < cr.x; i++)
	{
		for (int j = 0; j < cr.y; j++)
		{
			loadimage(&ci[i][j].origin, L"方块.png");
		}
	}
}

/*给数组换上贴图*/
void RIconReaplace(clearanceInfo ** ci)
{
	int Isum ;
	for (int i = 0; i < cr.x; i++)
	{
		for (int j = 0; j < cr.y; j++)
		{
			Isum = 0;
			ci[i][j].add.x = SXY.x + i * addmultiple;
			ci[i][j].add.y = SXY.y + j * addmultiple;
			if (ci[i][j].ion)
			{
				loadimage(&ci[i][j].reaplace, L"雷.png");
				continue;
			}
			for (int rr = i - 1; rr <= i + 1; rr++)//不能漏加1
			{
				for (int cc = j - 1; cc <= j + 1; cc++)
				{
					if (cc<0 || cc>cr.y-1 || rr<0 || rr>cr.x-1)// 1
						continue;
					if (ci[rr][cc].ion)
					{
						Isum++;
					}
				}
			}
			ci[i][j].aboutland = Isum;
			switch (Isum)
			{
			case 0:
				loadimage(&ci[i][j].reaplace, L"蓝块.png"); break;
			case 1:
				loadimage(&ci[i][j].reaplace, L"1.png"); break;
			case 2:
				loadimage(&ci[i][j].reaplace, L"2.png"); break;
			case 3:
				loadimage(&ci[i][j].reaplace, L"3.png"); break;
			case 4:
				loadimage(&ci[i][j].reaplace, L"4.png"); break;
			case 5:
				loadimage(&ci[i][j].reaplace, L"5.png"); break;
			case 6:
				loadimage(&ci[i][j].reaplace, L"6.png"); break;
			case 7:
				loadimage(&ci[i][j].reaplace, L"7.png"); break;
			case 8:
				loadimage(&ci[i][j].reaplace, L"8.png"); break;
			}
		}
	}
}

/*对游戏区的左右点击做出相应响应*/
bool judgeland(clearanceInfo ** ci, MOUSEMSG &mmsg)
{
	int i = (mmsg.x-SXY.x) / addmultiple;
	int j = (mmsg.y - SXY.y) / addmultiple;
	putimage(ci[i][j].add.x, ci[i][j].add.y, &ci[i][j].reaplace);
	if (mmsg.mkLButton)
	{
		if (ci[i][j].ion)
		{
			loadimage(&ci[i][j].reaplace, L"爆炸.png");
			putimage(ci[i][j].add.x, ci[i][j].add.y, &ci[i][j].reaplace);
			Sleep(1000);
			for (int i = 0; i < cr.x; i++)
			{
				for (int j = 0; j < cr.y; j++)
				{
					if (ci[i][j].ion)
					putimage(ci[i][j].add.x, ci[i][j].add.y, &ci[i][j].reaplace);
					Sleep(5);
				}
			}
			return true;
		}
		else
		{
			if (ci[i][j].aboutland==0)
			{
				judgebule(i, j, ci);
			}
			return false;
		}
	}
	if (mmsg.mkRButton)
	{
		if (ci[i][j].redflag == false)
		{
			displaysum--;
			ci[i][j].redflag = true;
			Tflags--;
			loadimage(&ci[i][j].origin, L"红旗.png");
			putimage(ci[i][j].add.x, ci[i][j].add.y, &ci[i][j].origin);
			if (ci[i][j].ion)
				total--;
		}
		else if (ci[i][j].redflag == true)
		{
			displaysum++;
			ci[i][j].redflag = false;
			Tflags++;
			loadimage(&ci[i][j].origin, L"方块.png");
			putimage(ci[i][j].add.x, ci[i][j].add.y, &ci[i][j].origin);
			if (ci[i][j].ion)
				total++;
		}
		if (0==total&&Tflags>=-1&&Tflags<=0)
			return true;
		else
			return false;
	}
}

/*显示空白块*/
void judgebule(int x, int y, clearanceInfo ** ci)
{
	if (x<0 || x>=cr.x || y<0 || y>=cr.y)
		return;
	if (ci[x][y].redflag)
	{
		Tflags++;
		ci[x][y].redflag = 0;
	}
	if(ci[x][y].aboutland==0 && ci[x][y].judge==0)
	{
		ci[x][y].judge = 1;
		if (ci[x][y].redflag)
			Tflags++;
		putimage(ci[x][y].add.x, ci[x][y].add.y, &ci[x][y].reaplace);
		judgebule(x + 1, y, ci);
		judgebule(x , y+1, ci);
		judgebule(x -1, y, ci);
		judgebule(x , y-1, ci);
	}
	else if(ci[x][y].judge == 0)
	{
		ci[x][y].judge = 1;
		if (ci[x][y].redflag)
			Tflags++;
		putimage(ci[x][y].add.x, ci[x][y].add.y, &ci[x][y].reaplace);
	}
}

