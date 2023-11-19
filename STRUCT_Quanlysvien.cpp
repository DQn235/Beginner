#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string Ho_ten;
    int Tuoi;
    float Diem_TB;
};

typedef struct SinhVien SinhVien;

SinhVien nhap(SinhVien x)
{
    cout << "Ho ten: ";
    cin.ignore();
    getline(cin, x.Ho_ten);
    cout << "Tuoi: ";
    cin >> x.Tuoi;
    cout << "Diem trung binh: ";
    cin >> x.Diem_TB;
    return x;
}
void nhap_danh_sach(SinhVien ds[], int &n) {
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        ds[i] = nhap (ds[i]);
    }

}
void Hien_thi(SinhVien x)
{
    cout << "\t" << x.Ho_ten;
    cout << "\t\t" << x.Tuoi;
    cout << "\t" << x.Diem_TB << endl;
}
void Hien_thi_danh_sach(SinhVien ds[], int n) {
    cout << "DANH SACH SINH VIEN" << endl;
    cout << "STT\tHo ten\t\tTuoi\tDiem TB" << endl;
    for (int i = 0; i < n; i++) {
            cout << i + 1;
        Hien_thi(ds[i]);
    }
}

void Chen_sinh_vien(SinhVien ds[], int &n) {   //n thay doi
    cout << "Nhap ten sinh vien can chen: " <<endl;
    ds[n] = nhap(ds[n]);
    n++;
}

void Xoa_sinh_vien(SinhVien ds[], int &n) {   //n thay doi
    string ten;
    cout << "Nhap ten sinh vien can xoa: ";
    cin.ignore();
    getline(cin, ten);
    for (int i = 0; i < n; i++) {
        if (ds[i].Ho_ten == ten) {
            for (int j = i; j < n - 1; j++) {
                ds[j] = ds[j + 1];
            }
            n--;
            cout << "Da xoa sinh vien co ten la " << ten << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ten la " << ten << endl;
}

void Sua_sinh_vien(SinhVien ds[], int n) {
    string ten;
    cout << "Nhap ten sinh vien can sua: ";
    cin.ignore();
    getline(cin, ten);
    for (int i = 0; i < n; i++) {
        if (ds[i].Ho_ten == ten) {
            cout << "Nhap thong tin sinh vien can sua" << endl;
            ds[i] = nhap(ds[i]);
            cout << "Da sua thong tin sinh vien co ten la " << ten << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ten la " << ten << endl;
}

int main() {
    SinhVien ds[100];
    int n=0;
    int chon;
    do {
        cout << "1. Tao danh sach sinh vien" << endl;
        cout << "2. Hien thi danh sach sinh vien" << endl;
        cout << "3. Chen them sinh vien" << endl;
        cout << "4. Xoa mot sinh vien" << endl;
        cout << "5. Sua mot sinh vien" << endl;
        cout << "6. Ket thuc" << endl;
        cout << "Chon chuc nang: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {

            case 1:
               nhap_danh_sach(ds, n);
               break;
            case 2:
                Hien_thi_danh_sach(ds, n);
                break;
            case 3:
                Chen_sinh_vien(ds, n);

                break;
            case 4:
                Xoa_sinh_vien(ds, n);

                break;
            case 5:
                Sua_sinh_vien(ds, n);

                break;
            case 6:
                cout << "Ket thuc chuong trinh" << endl;
                break;
            default:
                cout << "Khong hop le" << endl;
                break;
        }
    } while (chon != 6);

        return 0;
    }
