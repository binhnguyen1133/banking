#include"stdafx.h"
#include<iostream>
#include"Khach-Hang.h"
using namespace std;

void Nhap(Thong_tin *a,int i)
{
	cout << "Nhap ma so khach hang: ";	
	cin >> a[i].MaSo;
	cin.ignore();
	cout << "Nhap ho ten khach hang: ";	
	gets_s(a[i].HoTen);
	cout << "Nhap so CMND khach hang: "; 
	cin >> a[i].CMND;
	cout << "Nhap ngay thang nam lap so:\n";  
	do
	{
		cout << "\tNhap ngay: ";
		cin >> a[i].NTN.ngay;
	} while (a[i].NTN.ngay <= 0 || a[i].NTN.ngay > 31);
	do
	{
		cout << "\tNhap thang: ";
		cin >> a[i].NTN.thang;
	} while (a[i].NTN.thang <= 0 || a[i].NTN.thang > 12);
	cout << "\tNhap nam: ";
	cin >> a[i].NTN.nam;
	cout << "->Ngay thang nam lap the la: " << a[i].NTN.ngay << '/' << a[i].NTN.thang << '/' << a[i].NTN.nam << '.';
	cout << "\nNhap so tien gui vao: ";
	cin >> a[i].SoTienGui;
	cout << "Nhap vao ki han ban muon gui (0,1,3,6,12): ";
	cin >> a[i].kihan;
	cout << "Nhap vao lai suat: ";
	cout << "\n\t0.01 cho loai ki han '0'";
	cout << "\n\t0.02 cho loai ki han '1'";
	cout << "\n\t0.03 cho loai ki han '3'";
	cout << "\n\t0.04 cho loai ki han '6'";
	cout << "\n\t0.05 cho loai ki han '12'\n";
	cout << "Lai suat: ";
	cin >> a[i].LaiSuat;
}

void Swap(Thong_tin *a,Thong_tin *b)
{
	Thong_tin *c;
	c = a;
	a = b;
	b = c;
}

void TraCuu(Thong_tin *a, int dem, char ten[])
{
	for (int i = 0; i < dem; i++)
	{
		char s[50];
		strcpy_s(s, a[i].HoTen);
		_strlwr_s(s);
		char *p = strstr(s, ten);
		if (p != NULL)
		{
			Xuat(a, i);
			cout << endl;
		}
	}
}

void Xuat(Thong_tin *a, int i)
{
		cout << "Ma so: ";
		cout << a[i].MaSo << endl;
		cout << "Ho ten: ";
		cout << a[i].HoTen << endl;
		cout << "CMND: ";
		cout << a[i].CMND << endl;
		cout << "Ngay thang nam lap so: ";
		cout << a[i].NTN.ngay << "/" << a[i].NTN.thang << "/" << a[i].NTN.nam << endl;
		cout << "So tien gui vao: ";
		cout << a[i].SoTienGui << endl;
		cout << "Ki han la: ";
		cout << a[i].kihan << endl;
		cout << "Lai suat la: ";
		cout << a[i].LaiSuat << endl;
}

int LaiSuat(float Ls, long int TienGui, int thang)
{
	if (thang == 1)
		return TienGui * (1 + Ls);
	else
		return LaiSuat(Ls, TienGui, thang - 1)*(1 + Ls);
}

void RutTien(Thong_tin *a, int dem)
{
	int flag = 0;
	int songay;
	long long int MaSo;
	int s1, s2, s;
	cout << "Nhap vao ma so can rut: ";
	cin >> MaSo;
	for (int i = 0; i < dem; i++)
		if (a[i].MaSo == MaSo)
			flag = 1;
	if (flag == 0)
	{
		cout << "Khong co tai khoan nao co ma so da nhap\n";
		return;
	}
	else
	{
		int ngay, thang, nam;
		cout << "Nhap ngay: ";
		cin >> ngay;
		cout << "Nhap thang: ";
		cin >> thang;
		cout << "Nhap nam: ";
		cin >> nam;
		switch (thang)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			songay = 31;
			break;
		case 4: case 6: case 9: case 11:
			songay = 30;
			break;
		case 2:
			songay = 28;
			break;
		}
		s1 = nam * 365 + thang * songay + ngay;
		for (int i = 0; i < dem; i++)
			if (a[i].MaSo = MaSo)
			{
				switch (a[i].NTN.thang)
				{
				case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					songay = 31;
					break;
				case 4: case 6: case 9: case 11:
					songay = 30;
					break;
				case 2:
					songay = 28;
					break;
				}
				s2 = a[i].NTN.nam*365 + a[i].NTN.thang*songay + a[i].NTN.ngay;
				s = s1 - s2;
				if (a[i].kihan == 0)
					a[i].TongTien = LaiSuat(a[i].LaiSuat, a[i].SoTienGui, s / 30);
				else
				{
					a[i].TongTien = LaiSuat(a[i].LaiSuat, a[i].SoTienGui, a[i].kihan);
				}
				cout << "Tien lai khach hang nhan duoc: " << a[i].TongTien << " VND" << endl;
			}
	}
}