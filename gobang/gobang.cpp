
#include "stdafx.h"
#define initial_value 0
#define bai 1
#define hei 2
#define 棋盘边长 15
#define another_color(a) (3-a)
using namespace std;

 int x = 0, y = 0;

char qizi_color[2][3] = { "黑","白" };
char qipan[棋盘边长][棋盘边长];
inline void 绘制棋盘(void)
{
	register int i, j;
	system("cls");
	printf("五子棋游戏（控制台版）\n\n");
	for (i = 0; i < 棋盘边长; i++)
	{
		printf("%2d", 棋盘边长 - i);//输出纵坐标轴
		for (j = 0; j < 棋盘边长; j++)
		{
			switch (qipan[i][j]) {
			case 0 :printf("十"); break;
			case bai : printf("○"); break;
			case hei :  printf("●"); break;
			}
		}
		printf("\n");
	}
	for (i = 0; i <= 棋盘边长; i++)//输出横坐标轴
		printf("%2d", i);
}
inline void init(void) {
	register int i = 0, j = 0;
	for (i = 0; i < 棋盘边长; i++)
		for (j = 0; j < 棋盘边长; j++)
			qipan[i][j] = initial_value;
	绘制棋盘();
}
inline int is_win(int color)
{
	register int i,j;
	//横排
	for (i = 0; i < 棋盘边长; i++)
		for (j = 0; j < 棋盘边长 - 4; j++)
			if (qipan[i][j] == color && qipan[i][j + 1] == color && qipan[i][j + 2] == color && qipan[i][j + 3] == color && qipan[i][j + 4] == color)
				return 1;
	//竖排
	for (i = 0; i < 棋盘边长-4; i++)
		for (j = 0; j < 棋盘边长; j++)
			if (qipan[i][j] == color && qipan[i + 1][j] == color && qipan[i + 2][j] == color && qipan[i + 3][j] == color && qipan[i + 4][j] == color)
				return 1;
	//副对角线
	for (i = 0; i < 棋盘边长 - 4; i++)
		for (j = 4; j < 棋盘边长; j++)
			if (qipan[i][j] == color && qipan[i + 1][j-1] == color && qipan[i + 2][j-2] == color && qipan[i + 3][j-3] == color && qipan[i + 4][j-4] == color)
				return 1;
	//主对角线
	for (i = 0; i < 棋盘边长 - 4; i++)
		for (j = 0; j < 棋盘边长-4; j++)
			if (qipan[i][j] == color && qipan[i + 1][j+1] == color && qipan[i + 2][j+2] == color && qipan[i + 3][j+3] == color && qipan[i + 4][j+4] == color)
				return 1;
	return 0;
}
inline int is_kongde(int i, int j)
{
	if (qipan[棋盘边长 - j][i - 1] == initial_value)return 1;
	return 0;
}
inline void get_qizi(int color)
{
	register int i, j;
	while (1){
		//printf("\n请输入%s棋位置：",qizi_color[color-1]);
		printf("\n请输入%s棋的横坐标：", qizi_color[color - 1]);
		scanf_s("%d", &i);
		printf("请输入%s棋的纵坐标：", qizi_color[color - 1]);
		scanf_s("%d", &j);
		if (is_kongde(i, j) == 1&&i<=15&&j<=15&&i>0&&j>0) break;
		printf("位置有误");
	}
	x = 棋盘边长 - j;
	y = i - 1;
	qipan[x][y] = color;
}
inline void welcome(void){
	system("cls");
	cout<<"\n◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇█◇◇█◇◇◇◇█◇◇◇\n◇█████████████◇◇◇██████████◇◇◇◇◇◇█◇◇█◇◇◇◇█◇◇◇\n◇◇◇◇◇◇█◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◢██◤◇◇◇◇◇◇█◇█████████◇\n◇◇◇◇◇◇█◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◢██◤◇◇◇◇◇◇◇█◇◇█◇◇◇◇█◇◇◇\n◇◇◇◇◇◇█◇◇◇◇◇◇◇◇◇◇◇◇◇◇◢██◤◇◇◇◇◇◇████◇██████◇◇◇\n◇◇◇◇◇◇█◇◇◇◇◇◇◇◇◇◇◇◇◇◇██◤◇◇◇◇◇◇◇◇◇█◇◇█◇◇◇◇█◇◇◇\n◇◇██████████◇◇◇◇█████████████◇◇◇◢█◣◇█◇◇◇◇█◇◇◇\n◇◇◇◇◇◇█◇◇◇◇█◇◇◇◇◇◇◇◇◇◇◥█◣◇◇◇◇◇◇◢███◣██████◇◇◇\n◇◇◇◇◇◇█◇◇◇◇█◇◇◇◇◇◇◇◇◇◇◇◥█◇◇◇◇◇◢█◤█◥◤█◇◇◇◇█◇◇◇\n◇◇◇◇◇◇█◇◇◇◇█◇◇◇◇◇◇◇◇◇◇◇◇█◇◇◇◇◇█◤◇███████████◇\n◇◇◇◇◇◇█◇◇◇◇█◇◇◇◇◇◇◣◇◇◇◇◢█◇◇◇◇◇◇◇◇█◇◇◢██◇█◣◇◇◇\n◇◇◇◇◇◇█◇◇◇◇█◇◇◇◇◇◇██◣◇◢██◇◇◇◇◇◇◇◇█◇◢█◤◇◇◥█◣◇◇\n◇█████████████◇◇◇◇◥█████◤◇◇◇◇◇◇◇◇█◢█◤◇◇◇◇◥█◣◇\n◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇┏ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━┓  ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇┃ 1、单人游戏（PvAI）┃  ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇┃ 2、双人游戏（PvP） ┃  ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇┃ 0、退出            ┃  ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇┗ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━┛  ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n"<<endl;
}
inline int AI(int color) {
	register int i, j;
	//假定AI使用黑棋
	//1--己方四连A--黑黑黑黑空
	{
		//横排
		for (i = 0; i < 棋盘边长; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == color && qipan[i][j + 1] == color && qipan[i][j + 2] == color && qipan[i][j + 3] == color && qipan[i][j + 4] == initial_value)
				{
					qipan[i][j + 4] = color;
					return 1;
				}			
		//竖排
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长; j++)
				if (qipan[i][j] == color && qipan[i + 1][j] == color && qipan[i + 2][j] == color && qipan[i + 3][j] == color && qipan[i + 4][j] == initial_value)
				{
					qipan[i+4][j] = color;
					return 1;
				}
		//副对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 4; j < 棋盘边长; j++)
				if (qipan[i][j] == color && qipan[i + 1][j - 1] == color && qipan[i + 2][j - 2] == color && qipan[i + 3][j - 3] == color && qipan[i + 4][j - 4] == initial_value)
				{
					qipan[i+4][j -4] = color;
					return 1;
				}
		//主对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == color && qipan[i + 1][j + 1] == color && qipan[i + 2][j + 2] == color && qipan[i + 3][j + 3] == color && qipan[i + 4][j + 4] == initial_value)
				{
					qipan[i+4][j + 4] = color;
					return 1;
				}
	}
	//2--己方四连B--空黑黑黑黑
	{
		//横排
		for (i = 0; i < 棋盘边长; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == initial_value && qipan[i][j + 1] == color && qipan[i][j + 2] == color && qipan[i][j + 3] == color && qipan[i][j + 4] == color)
				{
					qipan[i][j] = color;
					return 2;
				}
		//竖排
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j] == color && qipan[i + 2][j] == color && qipan[i + 3][j] == color && qipan[i + 4][j] == color)
				{
					qipan[i][j] = color;
					return 2;
				}
		//副对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 4; j < 棋盘边长; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j - 1] == color && qipan[i + 2][j - 2] == color && qipan[i + 3][j - 3] == color && qipan[i + 4][j - 4] == color)
				{
					qipan[i][j] = color;
					return 2;
				}
		//主对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j + 1] == color && qipan[i + 2][j + 2] == color && qipan[i + 3][j + 3] == color && qipan[i + 4][j + 4] == color)
				{
					qipan[i][j] = color;
					return 2;
				}
	}
	//3--对方四连A--空白白白白
	{
		//横排
		for (i = 0; i < 棋盘边长; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == initial_value && qipan[i][j + 1] == another_color(color) && qipan[i][j + 2] == another_color(color) && qipan[i][j + 3] == another_color(color) && qipan[i][j + 4] == another_color(color))
				{
					qipan[i][j] = color;
					return 3;
				}
		//竖排
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j] == another_color(color) && qipan[i + 2][j] == another_color(color) && qipan[i + 3][j] == another_color(color) && qipan[i + 4][j] == another_color(color))
				{
					qipan[i][j] = color;
					return 3;
				}
		//副对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 4; j < 棋盘边长; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j - 1] == another_color(color) && qipan[i + 2][j - 2] == another_color(color) && qipan[i + 3][j - 3] == another_color(color) && qipan[i + 4][j - 4] == another_color(color))
				{
					qipan[i][j] = color;
					return 3;
				}
		//主对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j + 1] == another_color(color) && qipan[i + 2][j + 2] == another_color(color) && qipan[i + 3][j + 3] == another_color(color) && qipan[i + 4][j + 4] == another_color(color))
				{
					qipan[i][j] = color;
					return 3;
				}
	}
	//4--对方四连B--白白白白空
	{
		//横排
		for (i = 0; i < 棋盘边长; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == another_color(color) && qipan[i][j + 1] == another_color(color) && qipan[i][j + 2] == another_color(color) && qipan[i][j + 3] == another_color(color) && qipan[i][j + 4] == initial_value)
				{
					qipan[i][j+4] = color;
					return 4;
				}
		//竖排
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长; j++)
				if (qipan[i][j] == another_color(color) && qipan[i + 1][j] == another_color(color) && qipan[i + 2][j] == another_color(color) && qipan[i + 3][j] == another_color(color) && qipan[i + 4][j] == initial_value)
				{
					qipan[i+4][j] = color;
					return 4;
				}
		//副对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 4; j < 棋盘边长; j++)
				if (qipan[i][j] == another_color(color) && qipan[i + 1][j - 1] == another_color(color) && qipan[i + 2][j - 2] == another_color(color) && qipan[i + 3][j - 3] == another_color(color) && qipan[i + 4][j - 4] == initial_value)
				{
					qipan[i+4][j-4] = color;
					return 4;
				}
		//主对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == another_color(color) && qipan[i + 1][j + 1] == another_color(color) && qipan[i + 2][j + 2] == another_color(color) && qipan[i + 3][j + 3] == another_color(color) && qipan[i + 4][j + 4] == initial_value)
				{
					qipan[i+4][j+4] = color;
					return 3;
				}
	}
	//5--对方三连A--空白白白空
	{
		//横排
		for (i = 0; i < 棋盘边长; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == initial_value && qipan[i][j + 1] == another_color(color) && qipan[i][j + 2] == another_color(color) && qipan[i][j + 3] == another_color(color) && qipan[i][j + 4] == initial_value)
				{
					qipan[i][j] = color;
					return 5;
				}
		//竖排
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j] == another_color(color) && qipan[i + 2][j] == another_color(color) && qipan[i + 3][j] == another_color(color) && qipan[i + 4][j] == initial_value)
				{
					qipan[i][j] = color;
					return 5;
				}
		//副对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 4; j < 棋盘边长; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j - 1] == another_color(color) && qipan[i + 2][j - 2] == another_color(color) && qipan[i + 3][j - 3] == another_color(color) && qipan[i + 4][j - 4] == initial_value)
				{
					qipan[i][j] = color;
					return 5;
				}
		//主对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j + 1] == another_color(color) && qipan[i + 2][j + 2] == another_color(color) && qipan[i + 3][j + 3] == another_color(color) && qipan[i + 4][j + 4] == initial_value)
				{
					qipan[i][j] = color;
					return 5;
				}
	}
	//6--对方三连B--空白白白黑
	{
		//横排
		for (i = 0; i < 棋盘边长; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == initial_value && qipan[i][j + 1] == another_color(color) && qipan[i][j + 2] == another_color(color) && qipan[i][j + 3] == another_color(color) && qipan[i][j + 4] == color)
				{
					qipan[i][j] = color;
					return 6;
				}
		//竖排
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j] == another_color(color) && qipan[i + 2][j] == another_color(color) && qipan[i + 3][j] == another_color(color) && qipan[i + 4][j] == color)
				{
					qipan[i][j] = color;
					return 6;
				}
		//副对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 4; j < 棋盘边长; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j - 1] == another_color(color) && qipan[i + 2][j - 2] == another_color(color) && qipan[i + 3][j - 3] == another_color(color) && qipan[i + 4][j - 4] == color)
				{
					qipan[i][j] = color;
					return 6;
				}
		//主对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == initial_value && qipan[i + 1][j + 1] == another_color(color) && qipan[i + 2][j + 2] == another_color(color) && qipan[i + 3][j + 3] == another_color(color) && qipan[i + 4][j + 4] == color)
				{
					qipan[i][j] = color;
					return 6;
				}
	}
	//7--对方三连C--黑白白白空
	
	{
		//横排
		for (i = 0; i < 棋盘边长; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] ==color && qipan[i][j + 1] == another_color(color) && qipan[i][j + 2] == another_color(color) && qipan[i][j + 3] == another_color(color) && qipan[i][j + 4] == initial_value)
				{
					qipan[i][j+4] = color;
					return 5;
				}
		//竖排
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长; j++)
				if (qipan[i][j] == color && qipan[i + 1][j] == another_color(color) && qipan[i + 2][j] == another_color(color) && qipan[i + 3][j] == another_color(color) && qipan[i + 4][j] == initial_value)
				{
					qipan[i+4][j] = color;
					return 5;
				}
		//副对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 4; j < 棋盘边长; j++)
				if (qipan[i][j] == color && qipan[i + 1][j - 1] == another_color(color) && qipan[i + 2][j - 2] == another_color(color) && qipan[i + 3][j - 3] == another_color(color) && qipan[i + 4][j - 4] == initial_value)
				{
					qipan[i+4][j-4] = color;
					return 5;
				}
		//主对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] ==color  && qipan[i + 1][j + 1] == another_color(color) && qipan[i + 2][j + 2] == another_color(color) && qipan[i + 3][j + 3] == another_color(color) && qipan[i + 4][j + 4] == initial_value)
				{
					qipan[i+4][j+4] = color;
					return 5;
				}
	}
	//8--己方三连
	
	{		//横排
		for (i = 0; i < 棋盘边长; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == color && qipan[i][j + 1] == color && qipan[i][j + 2] == color && qipan[i][j + 3] == color && qipan[i][j + 4] == color)
					return 1;
		//竖排
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长; j++)
				if (qipan[i][j] == color && qipan[i + 1][j] == color && qipan[i + 2][j] == color && qipan[i + 3][j] == color && qipan[i + 4][j] == color)
					return 1;
		//副对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 4; j < 棋盘边长; j++)
				if (qipan[i][j] == color && qipan[i + 1][j - 1] == color && qipan[i + 2][j - 2] == color && qipan[i + 3][j - 3] == color && qipan[i + 4][j - 4] == color)
					return 1;
		//主对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == color && qipan[i + 1][j + 1] == color && qipan[i + 2][j + 2] == color && qipan[i + 3][j + 3] == color && qipan[i + 4][j + 4] == color)
					return 1;

	}
	//
	{
		//横排
		for (i = 0; i < 棋盘边长; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == color && qipan[i][j + 1] == color && qipan[i][j + 2] == color && qipan[i][j + 3] == color && qipan[i][j + 4] == color)
					return 1;
		//竖排
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长; j++)
				if (qipan[i][j] == color && qipan[i + 1][j] == color && qipan[i + 2][j] == color && qipan[i + 3][j] == color && qipan[i + 4][j] == color)
					return 1;
		//副对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 4; j < 棋盘边长; j++)
				if (qipan[i][j] == color && qipan[i + 1][j - 1] == color && qipan[i + 2][j - 2] == color && qipan[i + 3][j - 3] == color && qipan[i + 4][j - 4] == color)
					return 1;
		//主对角线
		for (i = 0; i < 棋盘边长 - 4; i++)
			for (j = 0; j < 棋盘边长 - 4; j++)
				if (qipan[i][j] == color && qipan[i + 1][j + 1] == color && qipan[i + 2][j + 2] == color && qipan[i + 3][j + 3] == color && qipan[i + 4][j + 4] == color)
					return 1;
	}
	//0--其他情况
	while (1) {
		i = rand() % 14 + 0;
		j = rand() % 14+0;
		if (is_kongde(i, j) == 1) {
			qipan[棋盘边长 - j][i - 1] = color;
			绘制棋盘();
			break;
		}
	}
	return 0;
}
inline void withdraw(int color) {
	if (x != 0 && y != 0) {
		qipan[x][y] = initial_value; 绘制棋盘();
	}
	else printf("\n悔棋失败！\n");
	get_qizi(color);
}
inline void play_double(void) {
	init();
	while (1) {
		get_qizi(bai);
		绘制棋盘();//绘制棋盘
		if (is_win(bai)==1) {
			printf("\n%s棋获胜，按回车键继续。", "白");
			//getch();
			break;
		}
		get_qizi(hei);
		绘制棋盘();//绘制棋盘
		if (is_win(hei) == 1) { 
			printf("\n%s棋获胜，按回车键继续。", "黑");
			//getch();
			break;
		}
	}
}
inline void play_single(void) {
	init();
	while (1) {
		//while (1) {
			//int a;
			//printf("\n1、悔棋\n2、下棋\n");
			//scanf_s("%d", &a);
			//if (a == 1) {
				//withdraw(bai); break;
			//}
			//else if (a == 2){
				get_qizi(bai);
				//break;
			//}
			//else printf("输入有误，请重试！");
		//}
		绘制棋盘();//绘制棋盘
		if (is_win(bai) == 1) {
			printf("\n%s棋获胜，按回车键继续。", "白");
			//getch();
			break;
		}
		AI(hei);
		绘制棋盘();//绘制棋盘
		if (is_win(hei) == 1) {
			printf("\n%s棋获胜，按回车键继续。", "黑(AI)");
			//getch();
			break;
		}
	}
}
int main()
{
	register int n;
	while (1){
		welcome();
		scanf_s("%d", &n);
		if (n == 1)play_single();
		else if (n == 2)play_double();
		else if (n == 0)break;
	}
    return 0;
}