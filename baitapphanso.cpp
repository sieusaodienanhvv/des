#include<iostream>
using namespace std;

class Phanso{
    private:
        int tuso;
        int mauso;
    public:
        Phanso();
        Phanso(int Tuso, int Mauso);
        Phanso(const int &a);
        ~Phanso();
        void set(int a, int b);
        int gettu();
        int getmau();        
        void nhap();
        void xuat();
        Phanso gan();
        Phanso nghichdao();
        Phanso rutgon();
        Phanso tong(Phanso a);
        Phanso hieu(Phanso a);
        Phanso tich(Phanso a);
        Phanso thuong(Phanso a);
        int sosanh(Phanso a);
};
Phanso::Phanso(){
    tuso=0;
    mauso=1;
}
Phanso::Phanso(int Tuso, int Mauso){
    tuso=Tuso;
    mauso=Mauso;
}
Phanso::Phanso(const int &a){   
    tuso=a;
    mauso=a;
}
Phanso::~Phanso(){}


void Phanso::nhap(){
    cout<<"nhap tu so: ";
    cin>>tuso;
    do{
        cout<<"nhap mau so: ";
        cin>>mauso;
    }while(mauso==0);
}


Phanso Phanso::nghichdao(){
    if(tuso != 0)
    {
        return Phanso(mauso, tuso);
    }
}

int ucln(int a, int b){
    while(a!=b){
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}
Phanso Phanso::rutgon(){
    int a=ucln(tuso,mauso);
    tuso=tuso/a;
    mauso=mauso/a;
    return Phanso(tuso, mauso);
}

void Phanso::xuat(){
    if(tuso==0)
        cout<<tuso<<endl;
    else if(mauso==1)
        cout<<tuso<<endl;
    else
        cout<<tuso<<"/"<<mauso<<endl;
}
int Phanso::gettu(){
    return this->tuso;
}
int Phanso::getmau(){
    return this->mauso;
}
Phanso Phanso::tong(Phanso a){
    return Phanso(tuso*a.mauso+a.tuso*mauso, mauso*a.mauso);
}
Phanso Phanso::hieu(Phanso a){
    return Phanso(tuso*a.mauso-a.tuso*mauso, mauso*a.mauso);
}
Phanso Phanso::tich(Phanso a){
    return Phanso(tuso*a.tuso, mauso*a.mauso);
}
Phanso Phanso::thuong(Phanso a){
    return Phanso(tuso*a.mauso, mauso*a.tuso);
}
int Phanso::sosanh(Phanso a){
    if((tuso/mauso)>(a.tuso/a.mauso))
        return 1;
    else if((tuso/mauso)<(a.tuso/a.mauso))
        return -1;
    else
        return 0;
}
 
int main(){
    Phanso phanso1, phanso2;
    cout<<"Phan so 1 la:"<<endl;
    phanso1.nhap();
    cout<<"phan so vua nhao la:";
    phanso1.xuat();
    Phanso b = phanso1.rutgon();
    cout<<"phan so ru gon la:";
    phanso1.xuat();
    cout<<"phan so 1 nghich dao la:";
    Phanso d=phanso1.nghichdao();
    d.nghichdao();

    cout<<"Phan so 2 la:"<<endl;
    phanso2.nhap();
    cout<<"phan so vua nhao la:";
    phanso2.xuat();
    Phanso f = phanso2.rutgon();
    cout<<"phan so ru gon la:";
    phanso2.xuat();
    cout<<"phan so 2 nghich dao la:";
    Phanso e=phanso2.nghichdao();
    e.xuat();
    
    cout<<"tong 2 phan so la:";
    Phanso psTong=phanso1.tong(phanso2);
    psTong.xuat();
    
    cout<<"hieu 2 phan so la:";
    Phanso psHieu=phanso1.hieu(phanso2);
    psHieu.xuat();
    
    cout<<"tich 2 phan so la:";
    Phanso psTich=phanso1.tich(phanso2);
    psTich.xuat();
    
    cout<<"thuong 2 phan so la:";
    Phanso psThuong=phanso1.thuong(phanso2);
    psThuong.xuat();
    int c = phanso1.sosanh(phanso2);
    if(c=-1)
        cout<<"ps1<ps2";
    else if(c=1)
        cout<<"ps1>ps2";
    else
        cout<<"ps1=ps2";
    return 0;
}
