#ifndef Khach-Hang

#include"stdafx.h"
#include<string>
struct Ngay
{
	int ngay;
	int thang;
	int nam;
};

struct Thong_tin
{
	long long int MaSo;
	char HoTen[50];
	long long int CMND;
	Ngay NTN;
	long int SoTienGui;
	float LaiSuat;
	int kihan;
	long int TongTien;
	
};

void Nhap(Thong_tin *a,int i);
void Swap(Thong_tin *a, Thong_tin *b);
void Xuat(Thong_tin *a, int i);
void TraCuu(Thong_tin *a, int dem, char ten[]);
int LaiSuat(float Ls, long int TienGui, int thang);
void RutTien(Thong_tin *a, int dem);
#endif
