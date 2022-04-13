#include<iostream>
#include<stdio.h>
using namespace std;
class HocSinh
{
private:
	char HoTen[30];
	char GT[10];
	int NamSinh;
	float GPA;
public:
	
	void XuatTT() {
		cout << "HoTen:" << HoTen << endl;
		cout << "GioiTinh:" << GT << endl;
		cout << "NamSinh:" << NamSinh << endl;
		cout << "GPA:" << GPA << endl;
	}
	friend void sx_noibotHS(HocSinh* L, int n);
	friend void sx_chonHS(HocSinh* L, int n);
	friend void sx_chenHS(HocSinh* L, int n);
	friend istream& operator >>(istream& in, HocSinh& l);
	string getTen() {
		string tenX;
		int i = sizeof(HoTen)/sizeof(char)-1;
		for (i; i >0; i--)
		{
			if (this->HoTen[i]==' ')
			{
				tenX += HoTen[i+1];
			}
		}
		return tenX;
	}
};
template<class T> void xuat_mang(T* arr, const int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
istream& operator >>(istream& in, HocSinh& l) {
	cout << "Nhap Ho Ten: "; cin.ignore(); gets_s(l.HoTen);
	cout << "Nhap Gioi Tinh: "; fflush(stdin); gets_s(l.GT);
	cout << "Nhap Nam Sinh:"; in >> l.NamSinh;
	cout << "Nhap GPA: "; in >> l.GPA;
	return in;
}
void sx_noibotHS(HocSinh *L, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if ((L[i].getTen()>L[j].getTen()))
			{
				swap(L[i], L[j]);
			}
		}
	}
}
void sx_chonHS(HocSinh* L, int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (L[j].getTen() < L[min].getTen())
				min = j;
				swap(L[min], L[i]);
	}
}
void sx_chenHS(HocSinh* L, int n) {
	int i, j;
	string key;
	for (i = 1; i < n; i++)
	{
		key = L[i].getTen();
		j = i - 1;
		while (j >= 0 && L[j].getTen() > key)
		{
			L[j + 1].getTen() = L[j].getTen();
			j = j - 1;
		}
		L[j + 1].getTen() = key;
	}
}
void sx_noibot(int arr[],int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i]<arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}
void sx_chon(int arr[], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min])
				min = j;

		swap(arr[min], arr[i]);
	}
}
void sx_chen(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
int main() {
	int arr[] = { 34,14,24,54,84,64,94,74,04 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int choice = 0;
	do
	{
		cout << "0.Thoat CT\n";
		cout << "1.Sap xep mang bang pp noi bot: \n";
		cout << "2.Sap xep mang bang pp chen: \n";
		cout << "3.Sap xep mang bang pp chon: \n";
		cout << "4.Xuat mang\n";
		cout << "5.Nhap vao 1 mang hoc sinh va tien hanh sap xep: \n";
		cout << "Nhap lua chon: \n";
		cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			sx_noibot(arr, n);
			break;
		case 2:
			sx_chen(arr, n);
			break;
		case 3:
			sx_chon(arr, n);
			break;
		case 4:
			xuat_mang(arr, n);
			break;
		case 5:
			int k;
			int x=0;
			cout << "Nhap so luong HS:"; cin >> k;
			HocSinh *L=new HocSinh[k];
			
			for (int i = 0; i < k; i++)
			{
				cout << "Nhap TT hoc sinh thu " << i + 1 << endl;
				cin>>L[i];
			}
			do
			{
				cout << "Nhap lua chon:\n";
				cout << "1.Sap xep mang HS  bang pp noi bot: \n";
				cout << "2.Sap xep mang HS bang pp chen: \n";
				cout << "3.Sap xep mang HS bang pp chon: \n";
				cout << "4.Xuat mang HS \n";
				cin >> x;
				switch (x)
				{
				case 0:
					break;
				case 1:
					sx_noibotHS(L, k);
					break;
				case 2:
					sx_chenHS(L, k);
					break;
				case 3:
					sx_chonHS(L, k);
					break;
				case 4:
					for (int i = 0; i < k; i++)
					{
						L[i].XuatTT();
					}
					break;
				default:
					break;
				}

			} while (x!=0);		
			break;
		}
	} while (choice!=0);
}
