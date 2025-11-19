#include <bits/stdc++.h>

using namespace std;

class staff{
    private:
        string mNV , name , phongBan;
        double luong;
    public:
        friend ostream& operator<<(ostream& COUT , staff& x){
            COUT << "ma nhan vien: " << x.mNV <<" "
                 << "ho va ten: " << x.name << " "
                 << "Phong Ban: " << x.phongBan<< " "
                 << "Luong: " << x.luong <<endl;
            return COUT;
        }
        friend istream& operator>>(istream& CIN , staff& x){
            cout <<"Nhap ma nhan vien: "; getline (CIN >> ws , x.mNV );
            cout <<"Nhap ho va ten: "; getline (CIN >>ws , x.name);
            cout <<"Nhap phong Ban: "; getline (CIN >>ws , x.phongBan);
            cout <<"NHap so luong: ";  CIN >> x.luong;
            return CIN;
        }
        static bool cmp(staff & a , staff & b){
            return a.luong < b.luong;
        }
        string getMNV(){
            return mNV;
        }
};
class Company{
    private:
        vector<staff> danhSach;
    public:
        void inDs();
        void sapxepLuong();
        void timkiemnv();
        void themnv();
        void xoanNv();  
};
class app{
    private:
        Company khai;
        void menu();
        void xulimenu(int luachon);
    public:
        void run();
};
void Company::inDs(){
    cout <<"--------- DANH SACH CONGTY--------"<< endl;
    for ( staff nv : danhSach){
        cout << nv;
    }
}
void Company::sapxepLuong(){
    vector<staff> dssort = danhSach;
    sort(dssort.begin() , dssort.end(), staff::cmp);
    for ( staff nv : dssort){
        cout << nv;
    }
}
void Company::timkiemnv(){
    string searchnv;
    cout << "Nhap mx nhan vien muon tim kiem: "; getline ( cin >> ws , searchnv);
    for ( staff nv : danhSach){
        if ( nv.getMNV() == searchnv){
            cout << nv;
        }
    }
}
void Company::xoanNv(){
    string deleteNv;
    cout <<"Nhap ma nhan vien muon xoa: "; getline ( cin >>ws , deleteNv);
    int index = -1;
    for ( int i = 0 ; i < danhSach.size() ; i++){
        if ( danhSach[i].getMNV() == deleteNv){
            index = i;
            break;
        }
    }
    if ( index != -1){
        danhSach.erase(danhSach.begin() + index);
        cout << "da xoa nhan vien!!";
    }else cout <<"ko tim thay nhan vien can xoa!!!";
}
void Company::themnv() {
    staff nvMoi;
    cout << "--- Nhap thong tin nhan vien moi ---" << endl;
    cin >> nvMoi; 
    
    danhSach.push_back(nvMoi);
    cout << "Da them nhan vien moi." << endl;
}
void app::menu(){
        cout << "\n======================================" << endl;
        cout << "==   CHUONG TRINH QUAN LY NHAN VIEN   ==" << endl;
        cout << "======================================" << endl;
        cout << "1. Them nhan vien moi" << endl;
        cout << "2. In danh sach nhan vien" << endl;
        cout << "3. Xoa nhan vien (theo MaNV)" << endl;
        cout << "4. Tim kiem nhan vien (theo MaNV)" << endl;
        cout << "5. Sap xep danh sach theo luong (giam dan)" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "--------------------------------------" << endl;
}
void app::xulimenu(int luachon){
    switch(luachon){
        case 1: {
            khai.themnv();
            break;
        }
        case 2: {
            khai.inDs();
            break;
        }
        case 3: {
            khai.xoanNv();
            break;
        }
        case 4:{
            khai.timkiemnv();
            break;
        }
        case 5:{
            khai.sapxepLuong();
        }
        case 0: {
            luachon = 0;
            break;
        }
    }
}

void app::run(){
    int luachon;
    do {
        menu();
        cout << ">> Nhap lua chon cua bn: "; cin >> luachon;
        if(cin.fail()){
            cout <<"Phai nhap so";
            cin.clear();
            cin.ignore();
            int luachon = -1;
        }
        else{
            xulimenu(luachon);
        }
    }while(luachon != 0);
}
int main(){
    app Quanlynhansu;
    Quanlynhansu.run();
}