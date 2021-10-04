#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include "mylib.h"
#include <time.h>
#include <string.h>
using namespace std;
int sl;
bool KT_qua_de_ran(int xqua, int yqua, int Toadox[], int Toadoy[]);
bool Ran_anqua(int xqua, int yqua, int xdau, int ydau);
void Tao_qua(int& xqua, int& yqua, int Toadox[], int Toadoy[]);
void ve_khung()
{
	setBackgroundColor(7);
	int i = 10;
	// khung tren // 10-70
	while (i < 70)
	{
		gotoXY(i++, 5);
		printf_s(" ");
	}
	i = 5;
	// khung trai 5-25
	while (i < 25)
	{
		gotoXY(10, i++);
		printf_s("  ");
	}
	i = 11;
	// khung duoi 10-70
	while (i < 70)
	{
		gotoXY(i++, 24);
		printf_s(" ");
	}
	// khung phai
	i = 5;
	while (i < 25)
	{
		gotoXY(70, i++);
		printf_s("  ");
	}
	setBackgroundColor(0);
}
void ve_conran(int Toadox[], int Toadoy[])
{

	for (int i = 0; i < sl; i++)
	{
		gotoXY(Toadox[i], Toadoy[i]);
		if (i == 0)
			printf_s("0");
		else
			printf_s("o");
	}
}
// them xoa toa do
void them(int a[], int x)
{
	for (int i = sl; i > 0; i--)
		a[i] = a[i - 1];
	a[0] = x;
	sl++;
}
void xoa(int a[])
{
	for (int i = sl - 1; i < sl; i++)
		a[i] = a[i + 1];
	sl--;
}
void xoa_DL_cu(int Toadox[], int Toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(Toadox[i], Toadoy[i]);
		printf_s(" ");
	}
}
void xuli_Ran(int Toadox[], int Toadoy[], int x, int y, int& xqua, int& yqua, int& Tocdo,int &Power,int &score,int &mau)
{
	// them toa do moi vao dau mang
	them(Toadox, x);
	them(Toadoy, y);
	if (Ran_anqua(xqua, yqua, Toadox[0], Toadoy[0]) == false)
	{
		// xoa vi tri cua mang
		xoa(Toadox);
		xoa(Toadoy);
	}
	else
	{
		if (Power != 3)
			Power++;
		Tocdo -= 10; // toc do tang 10
		score += 10;
		Tao_qua(xqua, yqua, Toadox, Toadoy);
		SetColor(7);
		gotoXY(70, 4);
		printf_s("%d", score);
		mau = rand() % (15 - 1 + 1) + 1;
	}
	SetColor(mau);
	ve_conran(Toadox, Toadoy);
}
void Khoi_tao_Mang(int Toadox[], int Toadoy[])
{
	int x = 50, y = 10;
	for (int i = 0; i < sl; i++)
	{
		Toadox[i] = x;
		Toadoy[i] = y;
		x--;
	}
}
bool KT_ran_chamtuong(int x, int y)
{
	if (x > 11 && x < 70 && y>5 && y < 24)
		return false;
	else
	{
		ve_khung();
		return true; // dung game
	}
}
bool KT_ran_chamduoi(int Toadox[], int Toadoy[])
{
	for (int i = 1; i < sl; i++)
		if (Toadox[0] == Toadox[i] && Toadoy[0] == Toadoy[i])
			return true;// dung game
	return false;
}
void Tao_qua(int& xqua, int& yqua, int Toadox[], int Toadoy[])
{
	SetColor(7);
	do {
		// tao toa do cho qua
		xqua = rand() % (67 - 13 + 1) + 13;
		yqua = rand() % (23 - 6 + 1) + 6;
	} while (KT_qua_de_ran(xqua, yqua, Toadox, Toadoy) == true);
	gotoXY(xqua, yqua);
	printf_s("?");
}
bool KT_qua_de_ran(int xqua, int yqua, int Toadox[], int Toadoy[])
{
	for (int i = 0; i < sl; i++)
		if (xqua == Toadox[i] && yqua == Toadoy[i])
			return true; // ran da de qua
	return false;
} // kiem tra ran co de qua k de tao qua moi
bool Ran_anqua(int xqua, int yqua, int xdau, int ydau)
{
	if ((xqua == xdau) && yqua == ydau)
		return true;
	return false;
}
bool Check_move(int check,int HuongCu)
{
	/*if (HuongCu == 2 && check == 5)
		return false;
	else if (HuongCu == 5 && check == 2)
		return false;
	else if (HuongCu == 1 && check == 3)
		return false;
	else if (HuongCu == 3 && check == 1)
		return false;
	return true;
	*/
	if (HuongCu == 2 && check == 5)
		return false;
	else if (HuongCu == 1 && check == 3)
		return false;
	return true;
}
void Ultimate(int Power)
{
	setBackgroundColor(7);
	gotoXY(80, 24);
	if (Power == 1)
	{
		printf_s("      ");
	}
	else if (Power == 2)
	{
		printf_s("             ");
	}
	else if (Power == 3)
	{
		Sleep(3);
		setBackgroundColor(15);
		printf_s("                     ");
		Sleep(3);
		gotoXY(80, 24);
		setBackgroundColor(10);
		printf_s("                     ");
		setBackgroundColor(0);
		gotoXY(124, 24);
		SetColor(7);
		printf_s("SPACE");
	}
	else if (Power == 0)
	{
		setBackgroundColor(0);
		printf_s("                              ");
	}
	setBackgroundColor(0);
}
void HuongDanChoi_And_HienThi()
{
	gotoXY(25, 2);
	SetColor(12);
	printf_s("======RAN_PHIEN_BAN_LOI=========");
	SetColor(7);
	SetColor(10);
	gotoXY(80, 23);
	printf_s("ULTIMATE");
	SetColor(7);
	gotoXY(80, 4);
	SetColor(12);
	printf_s("HUONG DAN CHOI");
	SetColor(7);
	char a = 17;
	char b = 31;
	char c = 16;
	gotoXY(80, 7);
	printf_s("%c %c %c", a,b,c);
	gotoXY(82, 6);
	a = 30;
	printf_s("%c", a);
	gotoXY(87, 7);
	printf_s("Dung Cac Phim De Di Chuyen Ran");
	gotoXY(80, 9);
	printf_s("ULTIMATE: Giup Ran di chuyen cham lai");
	gotoXY(80, 10);
	printf_s("trong mot khoang thoi gian ngan.");
	gotoXY(85, 12);
	printf("__TOP HIGH SCORE__");
	gotoXY(63,4);
	SetColor(7);
	printf_s("SCORE: 0");
	SetColor(7);
}
struct Top {
	char Name[32];
	int point;
};
void KT_FILE_Ghi(Top X[], int n)
{
	FILE* txt;
	errno_t err;
	if ((err = fopen_s(&txt, "D:\\Game C_C++\\RanSanMoi\\DuLieu.txt", "w")) != 0)
	{
		printf("File was not opened\n");
	}
	else
	{
		if (n > 3)
			n = 3;
		for (int i = 0; i < n; i++)
		{
			fprintf(txt, "%s", X[i].Name);
			fprintf(txt, "%d\n", X[i].point);
		}
		fclose(txt);
	}
}
void Swap(Top &X, Top &Y)
{
	Top tmp = X;
	X = Y;
	Y = tmp;
}
void KT_FILE_DOC(Top X[], int& n)
{
	FILE* txt;
	errno_t err;
	int i = 0;
	if ((err = fopen_s(&txt, "D:\\Game C_C++\\RanSanMoi\\DuLieu.txt", "r")) != 0)
	{
		printf("File was not opened\n");
	}
	else
	{

		// co the thay do dai 32 la  _countof(s)
		while(fgets(X[i].Name, 32, txt) &&fscanf_s(txt, "%d\n", &X[i].point)!=EOF)
		{ 
			
			i++;
		}
		fclose(txt);
	}

	n = i;
}
void DuLieuTop(Top Highscore[],int score,int nFile)
{	
	ShowCur(true);
	if (nFile < 3)
	{
		gotoXY(25, 25);
		printf("Chuc mung ban da lot vao TOP:");
		gets_s(Highscore[nFile].Name, 32);
		strcat_s(Highscore[nFile].Name, 32, "\n");
		Highscore[nFile].point = score;
		nFile++;
	}
	else
	{

		if (score > Highscore[nFile - 1].point)
		{
			gotoXY(25, 25);
			printf("Chuc mung ban da lot vao TOP:");
			gets_s(Highscore[nFile].Name, 32);
			strcat_s(Highscore[nFile].Name, 32, "\n");
			Highscore[nFile].point = score;
			Swap(Highscore[nFile], Highscore[nFile - 1]);
			nFile++;
		}

	}
	for (int i = 0; i < nFile; i++)
		for (int j = i + 1; j < nFile; j++)
			if (Highscore[i].point < Highscore[j].point)
				Swap(Highscore[i], Highscore[j]);
	KT_FILE_Ghi(Highscore, nFile);
	ShowCur(false);
}
void ChayChu_Diem(Top X[]) // 85 14
{
	// chay Diem
	int x1 = 25, y = 5;
	int x2 = 25, x3 = 25;
	int count1 = 1;
	int count2 = 1;
	int count3 = 1;
	int n1= strlen(X[0].Name);
	int n2 = strlen(X[1].Name);
	int n3 = strlen(X[2].Name);
	//ShowCur(false);
	gotoXY(45, 3);
	printf("___BANG XEP HANG___");
	bool ChayChu = true;
	while (ChayChu==true)
	{

		if (x1 < 50+n1)
		{
			for (int i = 0; i < count1; i++)
			{
				gotoXY(x1 - i, y);
				printf("%c", X[0].Name[n1 - i]);
			}
			gotoXY(x1 - count1, y);
			printf(" ");
			if (count1 <= n1)
				count1++;
			x1++;
		}
		if (x1 == 50 + n1)
		{
			gotoXY(x1 - n1, y + 1);
			printf("Score: %d", X[0].point);
		}
		if (count1 >= n1 / 2)
		{
			if (x2  < 50+n2)
			{
				for (int i = 0; i < count2; i++)
				{
					gotoXY(x2 - i, y + 3);
					printf("%c", X[1].Name[n2 - i]);
				}
				gotoXY(x2 - count2, y + 3);
				printf(" ");
				if (count2 <= n2)
					count2++;
				x2++;
			}
		}
		if (x2 == 50 + n2)
		{
			gotoXY(x2 - n2, y + 4);
			printf("Score: %d", X[1].point);
		}
		if (count2 >= n2 / 2)
		{
			if (x3  < 50+n3) {
				for (int i = 0; i < count3; i++)
				{
					gotoXY(x3 - i, y + 6);
					printf("%c", X[2].Name[n3 - i]);
				}
				gotoXY(x3 - count3, y + 6);
				printf(" ");
				if (count3 <= n3)
					count3++;
				x3++;
			}
		}
		if (x3 == 50 + n3)
		{
			gotoXY(x3 - n3, y + 7);
			printf("Score: %d", X[2].point);
			ChayChu = false;
		}
		Sleep(100);
	}

}
void END(Top X[])
{
	int x = 50;
	int y = 5;
	gotoXY(45, 3);
	printf("___BANG XEP HANG___");
	for (int i = 0; i < 3; i++)
	{
		gotoXY(x, y);
		printf("%s",X[i].Name);
		gotoXY(x+1,y + 1);
		printf("Score: %d", X[i].point);
		y = y+ 3;
	}
	y -= 3;
	gotoXY(45, 3);
	printf("                      ");
	while (true)
	{
		for (int i = 2; i >=0; i--)
		{
			gotoXY(x + 1, y + 1);
			printf("Score: %d", X[i].point);
			gotoXY(x, y);
			printf("%s", X[i].Name);
			y = y - 3;
		}
		Sleep(200);
		for (int i = y; i < y + 10; i++)
		{
			gotoXY(x, i);
			printf("                                  ");
		}
		if (y >16)
			break;
		y += 10;
	}
	system("cls");
	SetColor(14);
	gotoXY(50, 10);
	printf("Cam On Ban Da Choi Game Cua Toi");
	Sleep(500);
	gotoXY(0, 15);
}
int main() {
	// Tuong (11,70) - (5,24)

	bool ChoiLai = true;
	Top Highscore[4];
	int nFile = 0;
	ShowCur(false); // false an true hien
	while (ChoiLai == true)
	{
		int xFile = 85, yFile = 14;
		KT_FILE_DOC(Highscore, nFile);
		srand(time(NULL));
		sl = 4;
		int Toadox[100];
		int Toadoy[100];
		int xqua, yqua;
		HuongDanChoi_And_HienThi();
		Khoi_tao_Mang(Toadox, Toadoy);
		ve_khung();
		ve_conran(Toadox, Toadoy);
		Tao_qua(xqua, yqua, Toadox, Toadoy);
		for (int i = 0; i < nFile; i++)
		{
			gotoXY(xFile, yFile);
			printf("%s", Highscore[i].Name);
			gotoXY(xFile, yFile + 1);
			printf("Score: %d", Highscore[i].point);
			yFile = yFile + 3;
		}
		int x = 50, y = 10;
		int check = 3;
		bool gameover = false;
		int Tocdo = 250;
		int HuongCu = 3;
		int Power = 0;
		int time = 0;
		int Speed = Tocdo;
		bool Dung_Power = false;
		int score = 0;
		int mau = 7;
		// ran chay
		//ShowCur(gameover);
		while (gameover == false)
		{
			Speed = Tocdo;
			if (_kbhit()) // nhap tu ban phim len xuong qua lai
			{
				char kitu = _getch();
				if (kitu == 32 && Power == 3 && Dung_Power == false)
				{
					Dung_Power = true;
					Power = 0;
				}
				if (kitu == -32)
				{
					kitu = _getch();
					if (kitu == 72)
						check = 5;
					else if (kitu == 80)
						check = 2;
					else if (kitu == 77)
						check = 3;
					else if (kitu == 75)
						check = 1;
				}

			}
			if (Dung_Power == true)
			{
				time++;
				if (time == 5)
				{
					time = 0;
					Dung_Power = false;
				}
				Sleep(500);
				Tocdo += 2;
			}

			if (check != HuongCu)
			{
				if (Check_move(check, HuongCu) == false || Check_move(HuongCu, check) == false)
					check = HuongCu;
			}
			HuongCu = check;
			if (check == 1)
				x--;
			else if (check == 2)
				y++;
			else if (check == 3)
				x++;
			else if (check == 5)
				y--;
			xoa_DL_cu(Toadox, Toadoy);
			xuli_Ran(Toadox, Toadoy, x, y, xqua, yqua, Tocdo, Power, score, mau);
			bool kt1 = KT_ran_chamtuong(Toadox[0], Toadoy[0]);
			bool kt2 = KT_ran_chamduoi(Toadox, Toadoy);
			if (kt1 == true || kt2 == true)
				gameover = true;
			Ultimate(Power);
			if (Dung_Power == false)
				Sleep(Tocdo);
		} // dong while ran chay
		DuLieuTop(Highscore, score, nFile);
		system("cls");
		ChayChu_Diem(Highscore);
		gotoXY(25, 25);
		printf("ENTER De Choi Tiep");
		gotoXY(25, 26);
		printf("Nhan phim bat ki de thoat");
		while (1)
		{
			if (_kbhit())
			{
				char kitu = _getch();
				if (kitu == 13)
					ChoiLai = true;
				else
					ChoiLai = false;
				break;
			}
		}
		system("cls"); // xoa man hinh
	}
	END(Highscore);
	return 0;
}
