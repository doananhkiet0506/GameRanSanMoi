#pragma once 
#include <string>
#include "myLib.h"
#include "TinhNangGame.h"

void box_luachon(int x, int y, int w, int h, string nd);
void n_boxluachon(int x, int y, int w, int h);
void thanhSang(int x, int y, int w, int h, int t_color, int b_color, string nd);
void menu();
void box_TieuDe(int x_boxtieude, int y_boxtieude, int w_boxtieude, int h_boxtieude, string nd, int t_color, int b_color);

const int x_nbox = 75,
	      y_nbox = 14;
const int w_box = 15,
		  h_box = 2;

string nd1 = "     Play",
	   nd2 = "   Tuy chon",
	   nd3 = "    Thoat",
	   tieude = "      RAN SAN MOI";

const int x_tieude = 70,
	      y_tieude = 8,
		  w_tieude = 25,
		  h_tieude = 2;
void menu()
{
	showCur(0);

	string nd_thanhsang;
	string nd_khung;
	char presskey;
	
	int xp = x_nbox, yp = y_nbox;
	int xcu = xp, ycu = yp;

	tryagain: //Quay lai menu sau khi lua chon menu hoac play
	system("cls");
	box_TieuDe(x_tieude, y_tieude, w_tieude, h_tieude, tieude, 0, 100);
	
	n_boxluachon(x_nbox, y_nbox, w_box, h_box);
	
	bool ktra = true; //Kiem tra nguoi dung co nhan phim khong
	while (true)
	{
		
		if (yp == y_nbox)
			nd_thanhsang = nd1;
		else if (yp == y_nbox + 2)
			nd_thanhsang = nd2;
		else if (yp == y_nbox + 4)
			nd_thanhsang = nd3;

		if (ktra == true)
		{
			if (ycu == y_nbox)
				nd_khung = nd1;
			else if (ycu == y_nbox + 2)
				nd_khung = nd2;
			else if (ycu == y_nbox + 4)
				nd_khung = nd3;

			thanhSang(xcu, ycu, w_box, h_box, 7, 0, nd_khung);
			xcu = xp;
			ycu = yp;
			thanhSang(xp, yp, w_box, h_box, 7, 70, nd_thanhsang);
			ktra = false;
		}

		if (_kbhit())
		{
			presskey = _getch();
			if (presskey == 13)
			{
				if (yp == y_nbox) //Play
				{
					system("color 07");
					system("cls");
					playGame(); // Khoi dong game
					system("cls");
					goto tryagain;
				}
				else if (yp == y_nbox + h_box) //Tuy chon
				{
					system("color 07");
					system("cls");
					
					//Cai dat toc do
					int *ptr_speed = &speed_macdinh;
						//*ptr_mauran = &mauran,
					gotoXY(42, 10);
					cout << "Speed(Defaut 100): ";
					cin >> *ptr_speed;
					//gotoXY(43, 10)
					//gotoXY(44, 10);
					
					goto tryagain;
				}
				else if (yp == y_nbox + h_box * 2) //Thoat
					break;
			}
			else if (presskey == 72 && yp != y_nbox)
			{
				yp = yp - h_box;
				ktra = true;

			}
			else if (presskey == 80 && yp != y_nbox + h_box * 2)
			{
				yp = yp + h_box;
				ktra = true;

			}
		}
	}
}
void n_boxluachon(int x, int y, int w, int h)
{

	box_luachon(x, y, w, h, nd1);
	box_luachon(x, y + 2, w, h, nd2);
	box_luachon(x, y + 4, w, h, nd3);

	gotoXY(x, y + h);
	cout << char(195);

	gotoXY(x, y + h * 2);
	cout << char(195);

	gotoXY(x + w, y + h);
	cout << char(180);

	gotoXY(x + w, y + h * 2);
	cout << char(180);

}
void thanhSang(int x, int y, int w, int h, int t_color, int b_color, string nd)
{
	textColor(b_color);
	int i = 0;
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			gotoXY(ix, iy);
			cout << " ";

		}
	}
	SetColor(7);
	gotoXY(x + 1, y + 1);
	cout << nd;
}
void box_luachon(int x, int y, int w, int h, string nd)
{
	//Trên, dưới
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y);
		cout << (char)196;
		gotoXY(ix, y + h);
		cout << (char)196;
	}

	//Trái, phải
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy);
		cout << (char)179;
		gotoXY(x + w, iy);
		cout << (char)179;
	}

	gotoXY(x, y);
	cout << char(218); //Goc trai tren
	gotoXY(x, y + h);
	cout << char(192); // Goc trai duoi
	gotoXY(x + w, y);
	cout << char(191);//Goc phai tren
	gotoXY(x + w, y + h);
	cout << char(217);//Goc phai duoi

	gotoXY(x + 1, y + 1);
	cout << nd;
}
void box_TieuDe(int x_boxtieude, int y_boxtieude, int w_boxtieude, int h_boxtieude, string nd, int t_color, int b_color)
{
	
	textColor(b_color);
	for (int iy = y_boxtieude; iy <= y_boxtieude + h_boxtieude; iy++)
		for (int ix = x_boxtieude; ix <= x_boxtieude + w_boxtieude; ix++)
		{
			gotoXY(ix, iy);
			cout << " ";
		}		
	
	SetColor(t_color);
	gotoXY(x_boxtieude + 1, y_boxtieude + 1);
	cout << nd;
	textColor(7);
	SetColor(7);
	
}
