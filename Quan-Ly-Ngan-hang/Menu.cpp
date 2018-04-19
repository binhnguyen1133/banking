#include"stdafx.h"
#include"Menu.h"
#include<iostream>
#include<fstream>
using namespace std;

void Menu(Thong_tin *a)
{
	int dem = 0;
	int luachon;
	fstream IN("DATA.txt", ios::in, ios::binary);
	while (IN.read(reinterpret_cast<char *>(&a[dem]), sizeof(Thong_tin)))
	{
		dem++;
		cout << "\n";
	}
	IN.close();
	while (true)
	{
		system("cls");
		cout << "====================Menu====================\n";
		cout << "\n\t1.Lap so tiet kiem.";				//
		cout << "\n\t2.Xuat danh sach so tiet kiem.";	//
		cout << "\n\t3.Tra cuu thong tin.";				//
		cout << "\n\t4.Xem danh sach so tiet kiem theo so tien.";	//
		cout << "\n\t5.Rut tien.";
		cout << "\n\t6.Thay doi lai suat.";				//
		cout << "\n\t7.Thong ke so lieu.";				//
		cout << "\n\t8.Huy so tiet kiem.";				//
		cout << "\n\t9.Thoat chuong trinh.";			//
		cout << "\n\n====================End====================";
		cout << "\n\n-Nhap vao thao tac muon su dung: ";
		cin >> luachon;
		cout << "\n";
		if (luachon <= 0 || luachon > 9)
		{
			cout << "Nhap sai moi nhap lai!\n";
			system("pause");
		}
		else if (luachon == 1)
		{
			Nhap(a, dem);
			dem++;
			cout << "\n";
		}
		else if (luachon == 2)
		{
			for (int i = 0; i < dem; i++)
			{
				Xuat(a, i);
				cout << "\n";
			}
			system("pause");
		}
		else if (luachon == 3)
		{
			char Ten[50];
			cout << "Nhap vao chu cai ban muon tra cuu: ";
			cin >> Ten;
			cout << endl;
			_strlwr_s(Ten);
			TraCuu(a, dem, Ten);
			system("pause");
		}
		else if (luachon == 4)
		{
			cout << "Danh sach cac so la:" << endl;
			Thong_tin *b = new Thong_tin[100];
			for (int i = 0; i < dem; i++)
			{
				b[i] = a[i];
			}
			for (int i = 0; i < dem - 1; i++)
				for (int j = i + 1; j < dem; j++)
					if (a[j].SoTienGui >a[i].SoTienGui)
						swap(a[i], a[j]);
			for (int i = 0; i < dem; i++)
			{
				Xuat(a, i);
				cout << endl;
			}
			system("pause");
		}
		else if (luachon == 5)
		{
			RutTien(a, dem);
			system("pause");
		}
		else if (luachon == 6)
		{
			int kihan;
			cout << "Nhap loai ki han moi: ";
			cout << "\nCo cac loai ki han la (0;1;3;6;12): ";
			cin >> kihan;
			float laisuat;
			cout << "Nhap lai suat moi: ";
			cin >> laisuat;
			for (int i = 0; i < dem; i++)
			{
				if (a[i].kihan == kihan)
					a[i].LaiSuat = laisuat;
			}
			system("pause");
		}
		else if (luachon == 7)
		{
			int thang, nam;
			cout << "Nhap thang: ";
			cin >> thang;
			cout << "Nhap nam: ";
			cin >> nam;
			if (thang > 12 || thang <= 0 || nam <= 0)
				cout << "khong co yeu cau\n";
			int S = 0;
			int count = 0;
			for (int i = 0; i < dem; i++)
				if (a[i].NTN.thang == thang)
				{
					count++;
					S += a[i].SoTienGui;
				}
			cout << "So so tiet kiem duoc lap trong thang " << thang << " la: " << count;
			cout << "\nTong so tien nhan duoc trong thang " << thang << " la: " << S;
			cout << "\n";
			system("pause"); 
		}
		else if (luachon == 8)
		{
			int maso;
			int flag = 0;
			int i = 0;
			cout << "Nhap vao ma so so muon xoa: ";
			cin >> maso;
			for (int i = 0; i < dem; i++)
				if (a[i].MaSo == maso)
					for (int j = i; j < dem; j++)
						a[j] = a[j + 1];
			dem--;
		}
		else
			break;
	}
	ofstream OUT("DATA.txt", ios::binary);
	for (int i = 0; i < dem; i++)
		OUT.write(reinterpret_cast<char *>(&a[i]), sizeof(Thong_tin));
	OUT.close();
}