//Author Hungka

#include <iostream>
#include<iomanip>
#include<stdio.h>
#include <string>
using namespace std;

class Student {
private:
	string MaSV;
	string HoDem;
	string Ten;
	string GioiTinh;
	int NamSinh;
	float GPA;
public:
    Student(string MaSV="", string HoDem="", string Ten="", string GioiTinh="", int NamSinh=0, float gpa=0)
        : MaSV(MaSV), HoDem(HoDem), Ten(Ten), GioiTinh(GioiTinh), NamSinh(NamSinh), GPA(gpa) {}
	void Nhap() {
		cout << "Nhap ma sinh vien:"; fflush(stdin); getline(cin,MaSV);
		if (MaSV.compare( "***") == 0) {
			return;
		}
		cout << "Nhap ho dem: "; fflush(stdin); getline(cin,HoDem);
		cout << "Nhap ten: ";  fflush(stdin); getline(cin,Ten);
		cout << "Nhap gioi tinh: ";  fflush(stdin); getline(cin,GioiTinh);
		cout << "Nhap nam sinh: "; cin >> NamSinh;
		cout << "Nhap diem: "; cin >> GPA;
	}
	void setDiem(float Diem) {
		this->GPA = Diem;
	}
	float getDiem() {
		return GPA;
	}
	void setMaSV(string MaSV) {
		this->MaSV=MaSV;
	}
	string getMaSV() {
		return MaSV;
	}
	friend ostream& operator << (ostream&, Student&);
	bool operator == (const Student& sv) {
		return MaSV.compare(sv.MaSV) == 0;
	}
	friend class LIST;
};

ostream& operator << (ostream& out, Student& L) {
	out << setw(10) << L.MaSV << setw(15) << L.HoDem << setw(5) << L.Ten << setw(13) << L.NamSinh << setw(10) << L.GPA << endl;
	return out;
}

class Node {
public:
    Student data;
    Node* next;
    Node(Student data) {
        this->next = nullptr;
        this->data = data;
    }
};

class LIST {
private:
    Node* head;
    Node* tail;
public:
    LIST() {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void add(Student data) {
        Node* p = new Node(data);
        if (isEmpty()) {
            head = tail = p;
        }
        else {
            p->next = head;
            head = p;
        }
    }
	void NhapDS(LIST& L) {
		Student X;
		int i = 1;
		do
		{
			cout << "Nhap TT SV thu " << i << endl;
			X.Nhap();
			if (X.MaSV.compare("***") == 0) {
				return;
			}
            cin.ignore();
            addTail(X);
			i++;
		} while (1);
	}
    void addTail(Student data) {
        Node* p = new Node(data);
        if (isEmpty()) {
            head = tail = p;
        }
        else {
            tail->next = p;
            tail = p;
        }
    }
    void showList() {
        Node* p = head;
		int i = 0;
		cout << setw(5) << "STT" << setw(10) << "MaSV" << setw(20) << "Ho va Ten" << setw(13) << "Nam Sinh" << setw(10) << "Diem TK" << endl;
        while (p != nullptr) {
            cout << setw(5) << i + 1 << p->data << endl;
            p = p->next;
			i++;
        }
        cout << endl;
    }
	// hàm cập nhật điểm và theo mã sinh viên
	bool update(Student data) {
		Node* p = head;
		while (p != nullptr) {
			if (p->data == data) {
				p->data.setDiem(data.getDiem());
				return true; // update success
			}
			p = p->next;
		}
		return false;
	}
	void update_vip(LIST& L, string MaSV, float DiemN) {
		Node* p = head;
		Student data;
		while (p != nullptr) {
			if (p->data.MaSV.compare(MaSV) == 0) {
				p->data.setDiem(DiemN);
			}
			p = p->next;
		}
	}
	bool addAfterX(Student sv,int x) {
		Node* p = new Node(sv); // tạo node mới p
		Node* nodeX = head; // bắt đầu từ node head
		int k = 1;
		if (x == 0 || nodeX == nullptr) {
			add(sv);
			return true;
		}
		else {
			while (nodeX != nullptr && k < x) { // tìm nodeX
				nodeX = nodeX->next; // chuyển tới node kế tiếp
				++k;
				if (x > k) {
					break;
				}
			}
			if (x > k) {
				addTail(sv);
				return true;
			}
			else {
				p->data = sv;
				p->next = nodeX->next;
				nodeX->next = p;
				return true;
			}
		}
		return false;
	}	
	void removeByMaSV(string name) {
		if (isEmpty()) {
			cout << "Danh sach rong.\n";
			return;
		}
		Node* x = head;
		Node* prevX = head;
		while (x != nullptr) {
			if (x->data.getMaSV().compare(name) == 0) {
				if (x == head) {
					deleteHead();
					x = head; // cập nhật lại x
					continue;
				}
				else if (x == tail) {
					deleteTail();
					x = tail;
					continue;
				}
				else if (x != nullptr) {
					prevX->next = x->next;
					Node* r = x;
					x = x->next;
					delete r;
					continue;
				}
			}
			prevX = x;
			x = x->next;
		}
	}
	void addAfterX_vip(LIST& L, int& x) {
		Student sv;
		cout << "Nhap Vi Tri Can Chen:"; cin >> x;
		cout << "Nhap TT SV Can chen:\n";
		cin.ignore();
		sv.Nhap();
		Node* p = new Node(sv); // tạo node mới p
		Node* nodeX = head; // bắt đầu từ node head
		int k = 1;
		if (x ==0 || nodeX == nullptr) {
			add(sv);
		}
		else{		
			while (nodeX != nullptr && k != x ) { // tìm nodeX
				nodeX = nodeX->next; // chuyển tới node kế tiếp
				++k;
			}
			if (x>k) {
				k = 1;
				while (nodeX != nullptr && k < x) { // tìm nodeX
					nodeX = nodeX->next; // chuyển tới node kế tiếp
					++k;
					if (x > k) {
						break;
					}
				}
				cout << "Chen SV vao Vi tri " << x << " Khong Hop Le!!\n";
				cout << "Vay Chen vao vi tri cuoi cung\n";
				addTail(sv);
			}
			else {
				p->data = sv;
				p->next = nodeX->next;
				nodeX->next = p;
			}
		}
	}
	void deleteHead() {
		if (head == nullptr) {
			cout << "Khong Co SV nao de xoa\n";
		}
		else {
			head = head->next;
		}
		//        Hoặc	C2
		/*  Node* r = head; // lưu lại head
		    head = head->next; // cập nhật head mới
		    delete r; // xóa head						*/
	}
	void deleteTail() {
		//		  Cách 1 Duyệt Từ nút head đến tail  Hơi Vất =)) 
		Node* r = head;
		if (head == nullptr || head->next == nullptr) { // Kiem tra DS Co 0 , 1 pt
			deleteHead();
		}
		while (r->next->next !=nullptr)
		{
			r = r->next; // Duyet DS
		}
		r->next = r->next->next;
		//        Hoặc	C2	
		/*	Student sv;
			Node* r = tail;  //Tro r de not cuoi 
			Node* x=new Node(sv);  // Khoi Tao Node x bat ki
			x->next = nullptr; //Cap Nhat X tro den null 
			tail = x; //Gan not cuoi DS la X
			delete r;									*/
		
	}
	void remove(int &y) {
		cout << "Nhap Vi Tri Xoa "; cin >> y;
		int k = 1;
		Node* z = head;
		Node* nodeX = head;
		while (nodeX != nullptr && k != y) { // tìm nodeX
			nodeX = nodeX->next; // chuyển tới node kế tiếp
			++k;
		}
		if (y > k) {
			cout << "Vi Tri Xoa K Dung Do DS chi chua " << k << " SV" << endl;
		}
		else {
			if (z == head) {
				deleteHead();
			}
			else if (z == tail) {
				deleteTail();
			}
			else if (z != nullptr) {
				nodeX->next = z->next;
				delete z;
			}
		}
	}
	void sortGPA() { // sắp xếp giảm dần cua diem
		for (auto p = head; p != nullptr; p = p->next)
		{
			for (auto q = p->next; q != nullptr; q = q->next) {
				if (q->data.getDiem() > p->data.getDiem()) { // node sau > node trước, đổi chỗ
					auto tmp = p->data;
					p->data = q->data;
					q->data = tmp;
				}
			}
		}
	}
};
int main() {
	LIST students;
        //Tu dong input cac gia tri
	students.add(Student{ "ACC01", "TRAN VAN", " NAM", "Nam", 2002,2 });
	students.add(Student{ "ACC02", "TRAN VAN", " PHONG", "Nam", 2003,2.3 });
	cout << "Danh sach truoc update: \n";   
	students.showList();
	cout << "Ban Co Muon Nhap Them SV ?\nEnter *** De huy Nhap Them SV" << endl;
        students.NhapDS(students);
	students.showList();
	students.update(Student("ACC01", "", "", "", 0, 3.2));
	cout << "Sau Khi Update Diem theo MaSV\n";
	students.showList();
	string MaSV;
	float Diem;
	cout << "Nhap Ma SV Can thay doi diem:";
	getline(cin, MaSV);
	cout << "Nhap Diem Thay Doi:"; cin >> Diem;
	students.update_vip(students,MaSV,Diem);
	students.showList();
	students.addAfterX({ "ACC03", "NGUYEN VAN", " HUNG", "Nam", 2001,3.1 }, 0);
	students.showList();
	int x,y;
	students.addAfterX_vip(students,x);
	students.showList();
	students.deleteHead();
	students.showList();
	students.deleteTail();
	students.showList();
	students.remove(y);
	students.showList();
	string MaSV1;
	cout << "Nhap Vao Ma SV can xoa: ";
	cin.ignore();
	getline(cin, MaSV1);
	students.removeByMaSV(MaSV1);
	students.showList();
	students.sortGPA();
	students.showList();
}
