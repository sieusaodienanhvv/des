#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class sinhvien{
    private:
        string msv;
        string ten;
        string lop;
        int namsinh;
        float diemtb;
    public:
        sinhvien();
        ~sinhvien();
        friend istream &operator>>(istream &is, sinhvien &sv);
        friend ostream &operator<<(ostream &os, sinhvien sv);
        float get_diemtb();
        int get_namsinh();
        bool operator==(sinhvien sv);
        bool operator>(sinhvien sv);
};
sinhvien::sinhvien(){
     msv="";
     ten="";
     lop="";
     namsinh=0;
     diemtb=0;
}
sinhvien::~sinhvien(){}
istream &operator>>(istream &is, sinhvien &sv){
    cout<<"nhap msv:";
    cin.ignore();
    getline(is, sv.msv);
    cout<<"nhap ten sinh vien:";
    getline(is, sv.ten);
    cout<<"nhap lop sinh vien:";
    getline(is, sv.lop);
    cout<<"nhap nam sinh:";
    is>>sv.namsinh;
    cout<<"nhap diem trung binh:";
    is>>sv.diemtb;
    return is;
}
ostream  &operator<<(ostream &os, sinhvien sv){
    os<<"msv:"<<sv.msv<<endl;
    os<<"ten sinh vien:"<<sv.ten<<endl;
    os<<"lop:"<<sv.lop<<endl;
    os<<"nam sinh:"<<sv.namsinh<<endl;
    os<<"diem trung binh:"<<sv.diemtb<<endl;
    return os;
}
bool sinhvien::operator==(sinhvien sv){
    if(this->diemtb==sv.diemtb)
        return true;
    return false;
}
bool sinhvien::operator>(sinhvien sv){
    if(this->diemtb>sv.diemtb)
        return true;
    return false;
}
float sinhvien::get_diemtb(){
    return this->diemtb;
}
int sinhvien::get_namsinh(){
    return this->namsinh;
}
void nhapdanhsachsinhvien(int n, sinhvien *sv){
    for(int i = 0; i < n; i++){
        cout<<"stt:"<<i+1<<endl;
        cin>>*(sv+i);
    }
}
void xuatdanhsachsinhvien(int n, sinhvien *sv){
    for(int i = 0; i < n; i++){
        cout<<"stt:"<<i+1<<endl;
        cout<<*(sv+i);
    }
}
void hoanvi(sinhvien *a, sinhvien *b){
    sinhvien c=*a;
    *a=*b;
    *b=c;
}
void sapxepgiamdandiemtb(int n, sinhvien *sv){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((sv+i)->get_diemtb() < (sv+j)->get_diemtb()){
                hoanvi((sv+i),(sv+j));       
            }
        }
    }
}
void sapxeptangdannamsinh(int n, sinhvien *sv){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((sv+i)->get_namsinh() > (sv+j)->get_namsinh()){
                hoanvi((sv+i),(sv+j));       
            }
        }
    }
}
void thongkehocsinhkem(int n, sinhvien *sv){
    int dem=0;
    for(int i=0; i<n; i++){
            if((sv+i)->get_diemtb()<1){
                dem++;
            }
    }
    cout<<"hoc sinh kem la:"<<dem<<endl;
}
int main(){
    //sinhvien sv1, sv2, sv3;
    //cin>>sv1;
    //cout<<sv1;
    //cin>>sv2;
    //cout<<sv2;
    //bool a = sv1.operator==(sv2);
    //if (a == true){
    //    cout<<"hai sinh vien co diem trung binh bang nhau"<<endl;
    //}
    //bool b = sv2.operator>(sv2);
    //if (b == true){
    //    cout<<"sinh vien 1 cao diem hon sinh vien 2"<<endl;
    //}
    //else{
    //   cout<<"sinh vien 1 cao diem hon sinh vien 2"<<endl;
    //}
    int n, luachon;
    sinhvien *sv;
    while(1){
        cout<<"nhap lua chon cua ban"<<endl;
        cout<<"1. nhap danh sach sinh vien."<<endl;
        cout<<"2. xuat danh sach vua nhap."<<endl;
        cout<<"3. sap xep sinh vien theo diemtb."<<endl;
        cout<<"4. sap xem sinh vien theo nam sinh."<<endl;
        cout<<"5. thong ke sinh vien kem."<<endl;
        cout<<"6. dong chuong trinh"<<endl;
        cout<<"nhap lua chon cua ban:";
        cin>>luachon;
        switch(luachon){
            case 1:
                cout<<"nhap so luong sinh vien:";
                cin>>n;
                sv = new sinhvien[n];
                nhapdanhsachsinhvien(n, sv);
                break;
            case 2:
                xuatdanhsachsinhvien(n, sv);
                break;
            case 3:
                sapxepgiamdandiemtb(n, sv);
                xuatdanhsachsinhvien(n, sv);
                break;
            case 4:
                sapxeptangdannamsinh(n, sv);
                xuatdanhsachsinhvien(n, sv);
                break;
            case 5:
                thongkehocsinhkem(n, sv);
                xuatdanhsachsinhvien(n, sv);
                break;
            case 6:
                delete sv;
                exit(0);
        }
    }
    return 0;
}
