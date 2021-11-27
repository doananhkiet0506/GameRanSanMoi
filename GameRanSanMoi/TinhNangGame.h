#pragma once 
#include "myLib.h"
#include "MenuDong.h"
#define MAX 100
using namespace std;



void tuong_tren_duoi_khi_bat_dau_game(char kieutuongtren, char kieutuongduoi, int tuong_color);
void tuong_trai_phai_khi_bat_dau_game(char kieutuongtrai, char kieutuongphai, int tuong_color);
void tuong_tren_duoi_khi_an_qua(char kieutuongtren, char kieutuongduoi, int tuong_color);
void tuong_trai_phai_khi_an_qua(char kieutuongtrai, char kieutuongphai, int tuong_color);
void khoiTaoRan(int toadoXCuaRan_KhiBatDauGame, int toadoYCuaRan_KhiBatDauGame, int toadoX[], int toadoY[]);
void veRan(int toadoX[], int toadoY[]);
void xuLyRan(int toadoX[], int toadoY[], int x, int y, int &xqua, int &yqua);
void themDauMang(int arr[], int x);
void xoaCuoiMang(int arr[], int vt);

void diChuyen(int toadoX[], int toadoY[], int x, int y, int &xqua, int &yqua);

void xoaDuLieuCuKhiRanDiChuyen(int toadoX[], int toadoY[]);
bool kiemTraChamTuong(int toadoX[], int toadoY[]);
bool kiemTraChamDuoi(int toadoX[], int toadoY[]);
bool gameover(int toadoX[], int toadoY[]);
void taoQua(int &xqua, int &yqua, int mauqua, int toadoX[], int toadoY[]);
bool kiemTraRanAnQua(int xqua, int yqua, int x0, int y0);
void playGame();
void box_gameover(int x, int y, int w, int h, int box_color);

//===================== Cai dat thuoc tinh ======================================

//Ran
const int xran_macdinh = 74, yran_macdinh = 18; //Vi trí ran khi bat dau game
int soLuongDauThanRanMacDinh = 4;
int soLuongDauThanRan;
char kieuDauRan = '0';
char kieuThanRan = 'o';
int mauran = 7;
int mauqua = 7;

//Diem
int diem = 0;
int diem_tang_khi_an_qua = 10;
int diem_color = 15;
int toadoX_in_diem = 21,
	toadoY_in_diem = 3;


//Toc do
int speed_macdinh = 100; int speed;
int speed_tang_khi_an_qua = 2; // toc do cua con ran se tang len khi an qua

//Tuong
int tuong_color = 14;
int x_tuonggoctrenbentraimacdinh = 32, //32
	y_tuonggoctrenbentraimacdinh = 2;  //32
int w_tuong = 90, //100
	h_tuong = 35, //40
	h_saiso = 0; //So khi in theo chieu doc se dai hon khi in theo chieu ngang

//Khi GameOver
int toadoX_box_gameover = 52,
toadoY_box_gameOver = 14,
w_box_gameover = 50,			//Khung bao quanh
h_box_gameover = 5,
color_box_gameover = 8,

//Chu gameover
toadoX_gameover = toadoX_box_gameover + 3,
toadoY_gameover = toadoY_box_gameOver + 1,
gameover_color = 4,

//in diem khi gameover
toadoX_in_diem_gameover = toadoX_gameover + 2,
toadoY_in_diem_gameover = toadoY_gameover + 2,

toadoXquaylaisau = toadoX_gameover + 2,
toadoYquaylaisau = toadoY_gameover + 3,


sogiayquaylaimenu = 5;

//=================================================================================

void playGame()

{
	srand(time(NULL));
	showCur(0);  // ẩn con trỏ chỉ vị trong console
	speed = speed_macdinh;
	soLuongDauThanRan = soLuongDauThanRanMacDinh;
	int toadoX[MAX], toadoY[MAX];
	int soLuongDauThanRan = soLuongDauThanRanMacDinh;
	
	tuong_tren_duoi_khi_bat_dau_game('V', 'V', tuong_color);
	tuong_trai_phai_khi_bat_dau_game('>', '<', tuong_color);

	gotoXY(toadoX_in_diem, toadoY_in_diem);
	SetColor(diem_color);
	cout << "Diem: " << diem;
	SetColor(7);
	
	khoiTaoRan(xran_macdinh, yran_macdinh, toadoX, toadoY);
	veRan(toadoX, toadoY);
	
	int xqua = 0, yqua = 0;
	diChuyen(toadoX, toadoY, xran_macdinh, yran_macdinh, xqua, yqua);
	
	box_gameover(toadoX_box_gameover, toadoY_box_gameOver, w_box_gameover, h_box_gameover, color_box_gameover);
	gotoXY(toadoX_gameover, toadoY_gameover);
	textColor(gameover_color);
	cout << "           ======= GAME OVER =======\n";
	textColor(diem_color);
	gotoXY(toadoX_in_diem_gameover, toadoY_in_diem_gameover);
	cout << "Diem cua ban la: " << diem;
	textColor(7);
	
	for (int i = sogiayquaylaimenu; i >= 0; i--)
	{
		gotoXY(toadoXquaylaisau, toadoYquaylaisau);
		cout << "Quay lai Menu sau: " << 1 * i;
		Sleep(1000);
	}
}
void diChuyen(int toadoX[], int toadoY[], int xran, int yran, int &xqua, int &yqua)
{
	// 0: di xuong
	// 1: di len
	// 2: di phai
	// 3: di trai
	int check = 2;
	taoQua(xqua, yqua, mauqua, toadoX, toadoY);
	while (!gameover(toadoX, toadoY))
	{
		xoaDuLieuCuKhiRanDiChuyen(toadoX, toadoY);
		if (_kbhit()) //Tra ve true khi nguoi dung nhan phim
		{
			//Dieu khien ran bang cac phim mui ten
			char kitu = _getch();
			if (kitu == -32)
			{
				kitu = _getch();
				if (kitu == 72 && check != 0) //Len
					check = 1;
				else if (kitu == 80 && check != 1) //Xuong
					check = 0;
				else if (kitu == 77 && check != 3) //Phai
					check = 2;
				else if (kitu == 75 && check != 2) //Trai
					check = 3;
			}
		}

		//Kiem tra dieu kien de ran di chuyen theo huong nao
		if (check == 2)
			xran++;
		else if (check == 3)
			xran--;
		else if (check == 1)
		{
			yran--;
			//Sleep(1);
		}
		else if (check == 0)
		{
			yran++;
			//Sleep(1);
		}

		xuLyRan(toadoX, toadoY, xran, yran, xqua, yqua);
		Sleep(speed);
	}
}

//Them dau vao mang, xoa duoi khi ran di chuyen - tang toc do, diem, in diem, random mau tuong khi ran an qua 
void xuLyRan(int toadoX[], int toadoY[], int xran, int yran, int &xqua, int &yqua)
{
	themDauMang(toadoX, xran);
	themDauMang(toadoY, yran);
	if (kiemTraRanAnQua(xqua, yqua, toadoX[0], toadoY[0]) != true) //Khi ran chua an qua
	{
		//themDauMang(toadoX, xran);
		//themDauMang(toadoY, yran);
		xoaCuoiMang(toadoX, soLuongDauThanRan - 1);
		xoaCuoiMang(toadoY, soLuongDauThanRan - 1);
	}
	else //Khi ran an qua
	{
		soLuongDauThanRan--; // Sau khi ăn qua, vị trí của quả bi an se in ra la dau cua con ran, nhưng khi vừa thêm 0 vào đầu mảng
		//	bởi hàm themDauMang => phải giảm đi sl để khi vừa ăn 1 quả thì chỉ thêm 1 đuôi thôi 

		speed -= speed_tang_khi_an_qua; // toc do cua con ran se tang len khi an qua
		diem = diem + diem_tang_khi_an_qua;

		//Doi mau tuong khi ran an qua
		/*tuong_color = rand() % (14 - 1 + 1) + 1;
		tuong_tren_duoi_khi_an_qua('V', 'V', tuong_color);
		tuong_trai_phai_khi_an_qua('>', '<', tuong_color);*/

		//Toa do vi tri in ra diem khi ran an qua
		gotoXY(toadoX_in_diem, toadoY_in_diem);
		SetColor(diem_color);
		cout << "Diem: " << diem; //Hiển thị điểm
		SetColor(7);
		taoQua(xqua, yqua, 15, toadoX, toadoY);
	}
	veRan(toadoX, toadoY);
}
void box_gameover(int x, int y, int w, int h, int box_color)
{
	SetColor(box_color);
	//Trên, dưới
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y); //cout << '*';
		cout << (char)196;
		gotoXY(ix, y + h); //cout << '*';
		cout << (char)196;
	}

	//Trái, phải
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy); //cout << '*';
		cout << (char)179;
		gotoXY(x + w, iy); //cout << '*';
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

	SetColor(7);
}
void tuong_tren_duoi_khi_bat_dau_game(char kieutuongtren, char kieutuongduoi, int tuong_color)
{
	int x_tuong = x_tuonggoctrenbentraimacdinh;
	
	//x_tuongduoi = x_tuonggoctrenbentraimacdinh;
	SetColor(tuong_color);
	while (x_tuong <= x_tuonggoctrenbentraimacdinh + w_tuong)
	{
		//Tuong tren
		gotoXY(x_tuong, y_tuonggoctrenbentraimacdinh);
		cout << kieutuongtren;

		//Tuong duoi
		gotoXY(x_tuong, y_tuonggoctrenbentraimacdinh + h_tuong - h_saiso);
		cout << kieutuongduoi;
		x_tuong++;
	}
	SetColor(7);
}

void tuong_trai_phai_khi_bat_dau_game(char kieutuongtrai, char kieutuongphai, int tuong_color)
{
	int y_tuong = y_tuonggoctrenbentraimacdinh;
	SetColor(tuong_color);
	while (y_tuong <= y_tuonggoctrenbentraimacdinh + h_tuong - h_saiso)
	{
		//Tuong trai
		gotoXY(x_tuonggoctrenbentraimacdinh, y_tuong);
		cout << kieutuongtrai;

		//Tuong phai
		gotoXY(x_tuonggoctrenbentraimacdinh + w_tuong, y_tuong);
		cout << kieutuongphai;

		y_tuong++;
	}
	SetColor(7);

}
void tuong_tren_duoi_khi_an_qua(char kieutuongtren, char kieutuongduoi , int tuong_color)
{
	int x_tuongtren = x_tuonggoctrenbentraimacdinh;
	int x_tuongduoi = x_tuongtren + h_tuong;
	while (x_tuongtren <= x_tuonggoctrenbentraimacdinh + w_tuong)
	{
		SetColor(tuong_color);
		//Tuong tren
		gotoXY(x_tuongtren, y_tuonggoctrenbentraimacdinh);
		cout << kieutuongtren;
		x_tuongtren++;

		//Tuong duoi
		x_tuongduoi = x_tuongtren + h_tuong;
		gotoXY(x_tuongduoi, y_tuonggoctrenbentraimacdinh);
		cout << kieutuongduoi;
		x_tuongduoi++;
	}
	SetColor(7);
}

void tuong_trai_phai_khi_an_qua(char kieutuongtrai, char kieutuongphai, int tuong_color)
{
	int y_tuongtrai = y_tuonggoctrenbentraimacdinh;
	int y_tuongphai = y_tuongtrai + w_tuong;
	while (y_tuongtrai <= y_tuonggoctrenbentraimacdinh + h_tuong)
	{
		//Tuong trai
		SetColor(tuong_color);
		gotoXY(x_tuonggoctrenbentraimacdinh, y_tuongtrai);
		cout << kieutuongtrai;
		y_tuongtrai++;

		//Tuong phai
		y_tuongphai = y_tuongtrai + w_tuong;
		gotoXY(x_tuonggoctrenbentraimacdinh + w_tuong, y_tuongphai);
		cout << kieutuongphai;
		y_tuongphai++;
	}
	SetColor(7);
}



void khoiTaoRan(int toadoXCuaRan_KhiBatDauGame, int toadoYCuaRan_KhiBatDauGame, int toadoX[], int toadoY[])
{
	//int x = 60, y = 13;
	for (int i = 0; i < soLuongDauThanRan; i++)
	{
		toadoX[i] = toadoXCuaRan_KhiBatDauGame;
		toadoY[i] = toadoYCuaRan_KhiBatDauGame;
		toadoXCuaRan_KhiBatDauGame--;
	}
}

void veRan(int toadoX[], int toadoY[])
{
	for (int i = 0; i < soLuongDauThanRan; i++)
	{
		
		mauran = rand()%(15 - 1 + 1) + 1;
		SetColor(mauran);
		gotoXY(toadoX[i], toadoY[i]);
		if (i == 0)
		{
			cout << kieuDauRan; //Dau
		}
		else
		{
			cout << kieuThanRan; //Than va duoi
		}
	}
}

void xoaDuLieuCuKhiRanDiChuyen(int toadoX[], int toadoY[])
{
	for (int i = 0; i < soLuongDauThanRan; i++)
	{
		gotoXY(toadoX[i], toadoY[i]);
		cout << " ";
	}
}


void themDauMang(int arr[], int toadoran)
{
	for (int i = soLuongDauThanRan; i > 0; i--)
	{
		arr[i] = arr[i - 1];

	}
	arr[0] = toadoran;
	soLuongDauThanRan++;
}

void xoaCuoiMang(int arr[], int vt)
{
	for (int i = vt; i < soLuongDauThanRan; i++)
	{
		arr[i] = arr[i + 1];
	}
	soLuongDauThanRan--;
}

bool kiemTraChamTuong(int toadoX[], int toadoY[])
{
	if (toadoY[0] == y_tuonggoctrenbentraimacdinh && (toadoX[0] >= x_tuonggoctrenbentraimacdinh && toadoX[0] <= x_tuonggoctrenbentraimacdinh + w_tuong))
		return true;
	else if ((toadoY[0] == y_tuonggoctrenbentraimacdinh + h_tuong - h_saiso) && (toadoX[0] >= x_tuonggoctrenbentraimacdinh && toadoX[0] <= x_tuonggoctrenbentraimacdinh + w_tuong))
		return true;
	else if (toadoX[0] == x_tuonggoctrenbentraimacdinh && (toadoY[0] >= y_tuonggoctrenbentraimacdinh && toadoY[0] <= y_tuonggoctrenbentraimacdinh + h_tuong - h_saiso))
		return true;
	else if ((toadoX[0] == x_tuonggoctrenbentraimacdinh + w_tuong) && (toadoY[0] >= y_tuonggoctrenbentraimacdinh && toadoY[0] <= y_tuonggoctrenbentraimacdinh + h_tuong - h_saiso))
		return true;
	return false;
}

bool kiemTraChamDuoi(int toadoX[], int toadoY[])
{
	for (int i = 1; i < soLuongDauThanRan; i++)
	{
		if ((toadoX[0] == toadoX[i]) && (toadoY[0] == toadoY[i]))
			return true;
	}
	return false;
}

bool gameover(int toadoX[], int toadoY[])
{
	bool kiemtra1 = kiemTraChamTuong(toadoX, toadoY);
	bool kiemtra2 = kiemTraChamDuoi(toadoX, toadoY);
	if (kiemtra1 == true || kiemtra2 == true)
		return true;
	return false;
}

bool kiemTraRanDeQua(int toadoX[], int toadoY[], int xqua, int yqua)
{
	for (int i = 0; i < soLuongDauThanRan - 1; i++)
	{
		if (toadoX[i] == xqua && toadoY[i] == yqua)
		{
			return true;
		}
	}
	return false;
}
void taoQua(int &xqua, int &yqua, int mauqua, int toadoX[], int toadoY[])
{
	do
	{
		xqua = rand() % ((x_tuonggoctrenbentraimacdinh + w_tuong - 1) - (x_tuonggoctrenbentraimacdinh + 1) + 1) + (x_tuonggoctrenbentraimacdinh + 1);
		yqua = rand() % ((y_tuonggoctrenbentraimacdinh + h_tuong - h_saiso - 1) - (y_tuonggoctrenbentraimacdinh + 1) + 1) + (y_tuonggoctrenbentraimacdinh + 1);
	} while (kiemTraRanDeQua(toadoX, toadoY, xqua, yqua) == true);
	mauqua = rand()%(15 - 1 + 1) + 1;
	SetColor(mauqua);
	gotoXY(xqua, yqua);
	char qua = rand() % (90 - 65 + 1) + 65; //tao qua voi chu cai ngau nhien
	cout << qua;
	SetColor(7);
}
//x0,y0: toa do dau cua con ran
bool kiemTraRanAnQua(int xqua, int yqua, int x0, int y0)
{
	if (xqua == x0 && yqua == y0)
	{
		return true;
	}
	return false;
}


































































