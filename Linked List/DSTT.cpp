#include <iostream>
#include<stdio.h>
#include<iomanip>
#include<string>
#define MAX 100
using namespace std;
class SINHVIEN {
	char MaSV[10];
	char HoDem[20];
	char Ten[10];
	char GioiTinh[10];
	int NamSinh;
	float GPA;
public:
	void Nhap() {
		cout << "Nhap ma sinh vien:"; fflush(stdin); gets_s(MaSV);
		if (strcmp(MaSV,"***") == 0) {
			return;
		}
		cout << "Nhap ho deghm: "; fflush(stdin); gets_s(HoDem);
		cout << "Nhap ten: ";  fflush(stdin); gets_s(Ten);
		cout << "Nhap gioi tinh: ";  fflush(stdin); gets_s( GioiTinh);
		cout << "Nhap nam sinh: "; cin >> NamSinh;
		cout << "Nhap diem: "; cin >> GPA;
	}
	friend class LIST;
};

class LIST {
	int count;
	SINHVIEN E[MAX];
public:
	void Init(LIST& L) {// Khoi tao danh sach rong
		L.count = -1;
	}
	int Add(LIST& L, SINHVIEN X) {
		if (L.count==MAX-1) {
			return 0;
		}
		else {
			L.count++;
			L.E[L.count] = X;
			return 1;
		}
	}
	void NhapDS(LIST& L) {
		L.Init(L);
		for (int i = 0; i < MAX; i++)
		{
			cout << "Nhap TT SV thu " << i << endl;
			L.E[i].Nhap();
			if (strcmp(L.E[i].MaSV,"***") == 0) {
				return;
			}
			if (!Add(L, L.E[i])) {
				return;
			}
		}
	}
	void XuatDS(LIST L) {
		cout << setw(5) << "STT" << setw(10) << "MaSV" << setw(25) << "Ho va Ten" << setw(10) << "Nam Sinh" << setw(10) << "Diem TK" << endl;
		for (int i = 0; i <= L.count; i++)
		{
			cout << setw(5) << i + 1 << setw(10) << L.E[i].MaSV << setw(17) << L.E[i].HoDem << setw(8) << L.E[i].Ten << setw(10) << L.E[i].NamSinh << setw(10) << L.E[i].GPA << endl;
		}
	}
	void Delete_first(LIST &L) {
		if (L.count < 1) {
			return;//DS rong
		}
		else {
			for (int i = 1; i <= L.count; i++)
			{
				L.E[i - 1] = L.E[i];
			}
			L.count--;
		}
	}
	int Search(LIST L, char *Ma) {
		int k=0;
		for (int i = 0; i < L.count; i++)
		{
			if (strcmp(L.E[i].MaSV,Ma) == 0) {
				k = i;
			}
		}
		return k;
	}
};
int main() {
	LIST L;
	L.NhapDS(L);
	L.XuatDS(L);
}