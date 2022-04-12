#include<iostream>
#include<string>
using namespace std;

class xe{
    private:
        string bienso;
        float trongluong;
    public:
        void nhapxe();
        void xuatxe();
        float trongluongxe();
};
class xecon:public xe{
    private:
        int n;
        int chongoi;
    public:
        void nhapxe();
        void xuatxe();
        int chongoi1();
};
class xetai:public xe{
    private:
        int m;
        float taitrong;
    public:
        void nhapxe();
        void xuatxe();
        float trongtai1();

};

void xe::nhapxe(){
    cout<<"nhap bien so xe:";
    cin.ignore();
    getline(cin, bienso);
    cout<<"nhap trong luong xe:";
    cin>>trongluong;
}
void xecon::nhapxe(){
    xe::nhapxe();
    cout<<"so cho ngoi:";
    cin>>chongoi;
}
void xecon::xuatxe(){
    xe::xuatxe();
    cout<<"so cho ngoi:"<<chongoi<<endl;
}
void xetai::nhapxe(){
    xe::nhapxe();
    cout<<"trong tai:";
    cin>>taitrong;
}
void xetai::xuatxe(){
    xe::xuatxe();
    cout<<"kg"<<taitrong<<endl;
}
void xe::xuatxe(){
    cout<<"bien so la:"<<bienso<<endl;
    cout<<"trong luong xe:"<<trongluong<<endl;
}
float xe::trongluongxe(){
    return this->trongluong;
}

void nhapdanhsachxecon(xecon *a, int n){
    for(int i=0; i<n; i++){
        (a+i)->nhapxe();
    }
}
void xuatdanhsachxecon(xecon *a, int n){
    for(int i=0; i<n; i++){
        (a+i)->xuatxe();
    }
}

void nhapdanhsachxetai(xetai *b, int m){
    for(int i=0; i<m; i++){
        (b+i)->nhapxe();
    }
}
void xuatdanhsachxetai(xetai *b, int m){
    for(int i=0; i<m; i++){
        (b+i)->xuatxe();
    }
}
void min(xecon *a, int n){
	float min=(a+0)->trongluongxe();
	for(int i=0; i<n; i++){
		if(min<(a+i)->trongluongxe()){
			min=(a+0)->trongluongxe();
		}
		else
			min=(a+i)->trongluongxe();
			
	}
	cout<<"min:"<<min<<endl;
}
float xetai::trongtai1(){
	return this->taitrong;
}

void taitrong5tan(xetai *b, int m){
	for(int i=0;i<m;i++){
		if((b+i)->trongtai1()==5){
			(b+i)->xuatxe();
		}
	}
}
int xecon::chongoi1(){
	return this->chongoi;
}
void chongoi7(xecon *a, int n){
	for(int i=0;i<n;i++){
		if((a+i)->chongoi1()==7){
			(a+i)->xuatxe();
		}
	}
}
int main(){
    xetai *b;
    xecon *a;
    int m, n;
    cin>>n>>m;
    a=new xecon[n];
    b=new xetai[m];
    nhapdanhsachxecon(a,n);
    cout<<"___________________________________"<<endl;
    xuatdanhsachxecon(a,n);
    cout<<"___________________________________"<<endl;
    nhapdanhsachxetai(b, m);
    cout<<"___________________________________"<<endl;
    xuatdanhsachxetai(b,m);
    cout<<"___________________________________"<<endl;
    min(a,n);
    cout<<"xe 5 tan:"<<endl;
    taitrong5tan(b,m);
    cout<<"___________________________________"<<endl;
    cout<<"xe 7 cho:"<<endl;
    chongoi7(a,n);
    delete a;
    delete b;
    return 0;
}
