#include<iostream>
#include<math.h>
using namespace std;

class sophuc{
    private:
        int phanthuc;
        int phanao;
    public:
        sophuc();
        sophuc(int phanthuc, int phanao);
        sophuc(const int &a);
        ~sophuc();
        void nhap();
        void xuat();
        sophuc getthuc();
        sophuc getao();
        sophuc modun(sophuc a);
        sophuc tong(sophuc a);
        sophuc hieu(sophuc a);
        sophuc tich(sophuc a);
        sophuc thuong(sophuc a);
};

sophuc::sophuc(){
    phanthuc=0;
    phanao=0;
}
sophuc::sophuc(int Phanthuc, int Phanao){
    phanthuc=Phanthuc;
    phanao=Phanao;
}
sophuc::sophuc(const int &a){
    phanthuc=a;
    phanao=a;
}
sophuc::~sophuc(){}
void sophuc::nhap(){
    cout<<"nhap phan thuc:";
    cin>>phanthuc;
    cout<<"nhap phan ao:";
    cin>>phanao;
}
void sophuc::xuat(){
    cout<<"so phuc la:"<<phanthuc<<"+"<<phanao<<"i"<<endl;
}
sophuc sophuc::getthuc(){
    return this->phanthuc;
}
sophuc sophuc::getao(){
    return this->phanao;
}
sophuc sophuc::modun(sophuc sp1){
    float ps;
    ps = sqrt(sp1.phanthuc*sp1.phanthuc+sp1.phanao*sp1.phanao);
    return sp1;
}
sophuc sophuc::tong(sophuc sp1){
    return sophuc(phanthuc+sp1.phanthuc,phanao+sp1.phanao);
}
sophuc sophuc::hieu(sophuc sp1){
    return sophuc(phanthuc-sp1.phanthuc,phanao-sp1.phanao);
}
sophuc sophuc::tich(sophuc sp1){
    return sophuc(phanthuc*sp1.phanthuc-phanao*sp1.phanao,phanthuc*sp1.phanao+phanthuc*sp1.phanao);
}
int main(){
    sophuc sp1, sp2;
    cout<<"nhap so phuc 1: ";
    sp1.nhap();
    sp1.xuat();
    cout<<"nhap so phuc 2: ";
    sp2.nhap();
    sp2.xuat();
    cout<<"modum la:";
    sophuc modun=sp1.modun(sp2);
    modun.xuat();
    cout<<"tong so phuc la: ";
    sophuc tong=sp1.tong(sp2);
    tong.xuat();
    cout<<"hieu so phuc la: ";
    sophuc hieu=sp1.hieu(sp2);
    hieu.xuat();
    cout<<"tich so phuc la: ";
    sophuc tich=sp1.tich(sp2);
    tich.xuat();
}