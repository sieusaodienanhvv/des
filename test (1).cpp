#include<iostream>
#include<cstdlib>
#include <unistd.h>
#include<windows.h>
#include<iomanip>
#include <fstream>
using namespace std;
void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
BOOL WINAPI SetConsoleTitle(_In_ LPCTSTR lpConsoleTitle);
void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
BOOL DeleteMenu(
  HMENU hMenu,
  UINT  uPosition,
  UINT  uFlags
);
void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);
    
    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}
class nhanvien{
    private:
          string hovaten;
        int ngay,thang,nam;
        string gioitinh;
        string sdt;
       
        string diachi;
        string mavanphong;
        string manhanvien;
        string chucvu,xeploai;
        int danhgia,nghi;
        float luong;
    public:
       string getMNV(){
            return manhanvien;
		}
		int getGia(){
			return danhgia;
		}
		float getLuong(){
			return luong;
		}
        ~nhanvien();
        void nhap();
        void xuat();
        void them();
        void danhGia();
        void ghi();
};
class nhanvienphongtochuc:public nhanvien{
    private:
        int soluongcacsukien;
        string tensukientochuc;
        string ngaytochucsukien;
    public:
        void nhap();
        void ghi();
        void ghiSK();
        void nhapsukien();
        string getTSK(){
        	return ngaytochucsukien;
		}
		string getSK(){
			return tensukientochuc;
		}
        void xuat();
        void xuatsukien();
};
class nhanvienphongsanxuat:public nhanvien{
    private:
        int soluongSPSX;
        string TenSPSX;
        int soluongSP;
    public:
        void nhap();
        void ghi();
        void ghiSX();
        void nhapsx();
        void xuat();
        void xuatsx();
        void them();
        string getSP(){
        	return TenSPSX;
		}
		int getSL(){
			return soluongSP;
		}
};
class nhanvienphongkinhdoanh:public nhanvien{
    private:
        int soluongcackhoanchitieu;
        string tencackhoanchitieu;
        double tienchi;
    public:
        void nhap();
        void nhapchiphi();
        void xuat();
        void xuatchiphi();
        void them();
        void ghi();
        void ghiKD();
        string getcackhoanchi(){
            return tencackhoanchitieu;
        }
        double gettienchi(){
            return tienchi;
        }
};
//nhanvien::nhanvien(){
//    hovaten="";
//    mavanphong="";
//    manhanvien="";
//    luong=0;
//}
nhanvien::~nhanvien(){}
void nhanvien::nhap(){
 cout<<"Nhap ho va ten:";
    cin.ignore();
    getline(cin, hovaten);
    cout<<"Nhap ngay thang nam sinh:";
    cin>>ngay>>thang>>nam;
    cin.ignore();
    cout<<"Nhap gioi tinh (nam/nu): ";
    
    getline(cin,gioitinh);
    cin.ignore();
    cout<<"Nhap so dien thoai:";
    
    getline(cin, sdt);
   cin.ignore();
    cout<<"Nhap dia chi(noi o hien tai):";
    
    getline(cin, diachi);
    cin.ignore();
    cout<<"Nhap ma van phong:";
    
    getline(cin, mavanphong);
    
    cout<<"Nhap ma nhan vien:";
    cin.ignore();
    getline(cin, manhanvien);
    cout<<"Danh gia (1.xuatsac + 30%; 2.tot + 10%; 3.khong tich cuc -10%): ";
    
    cin>>danhgia;
    cout<<"Nhap chuc vu:";
    cin.ignore();
    getline(cin, chucvu);
    cout<<"So ngay nghi: ";
    cin>>nghi;
    
    cout<<"nhap luong:";
    cin>>luong;
    cout<<"____________________________________________"<<endl;
}
void nhanvien::xuat(){
   cout  << "Ho va ten: "<< setw(2) << setfill(' ') << right<<hovaten<< endl;; 
    
    cout <<"Ngay sinh: " << setw(2) << setfill(' ') << right << ngay<<"/"<<thang<<"/"<<nam<< endl;
   cout  << "Gioi tinh: "<< setw(2) << setfill(' ') << right<<gioitinh<< endl;
    cout <<"So dien thoai: "<< setw(2) << setfill(' ') << right << sdt<< endl;
    
   
    
    cout<< "Dia chi: " << setw(2) << setfill(' ') << right << diachi  << endl;
    
    cout << "Ma van phong:"<< setw(2) << setfill(' ') << right << mavanphong<< endl;
    
    cout <<"Ma nhan vien:"<< setw(2)<< setfill(' ') << right << manhanvien<< endl;
  
    cout <<"Chuc vu:"<< setw(2) << setfill(' ') << right<< chucvu<< endl;
    cout <<"So ngay nghi:"<< setw(2) << setfill(' ') << right<< nghi<< endl;
    
    cout << "Luong:"<< setw(2) << setfill(' ') << right <<showpoint << luong <<"$"<< endl;
    cout<<"____________________________________________"<<endl;
}

void nhanvienphongtochuc::nhap(){
    nhanvien::nhap();
}
void nhanvienphongtochuc::xuat(){
    nhanvien::xuat();
}
void nhanvienphongtochuc::nhapsukien(){
    fflush(stdin);
    cout<<"nhap ten su kien:";
    getline(cin,tensukientochuc);
    cout<<"nhap ngay thang nam to chuc su kien(NN/NN/NNNN):";
    getline(cin,ngaytochucsukien);
    cout<<"____________________________________________"<<endl;
}
void nhanvienphongtochuc::xuatsukien(){
    cout << setw(36) << setfill('.') << left << "Su kien:";
    cout << setw(7) << setfill(' ') << right << showpoint << tensukientochuc << endl;
    cout << setw(36) << setfill('.') << left << "Ngay to chuc:";
    cout << setw(7) << setfill(' ') << right << showpoint << ngaytochucsukien<< endl;
    cout<<"____________________________________________"<<endl;
}

void nhanvienphongsanxuat::nhap(){
    nhanvien::nhap();
}
void nhanvienphongsanxuat::xuat(){
    nhanvien::xuat();
}
void nhanvien::danhGia(){
	if(danhgia==1){
		luong+=luong/100*30;
		cout<<"Nhan vien Gioi"<<endl;
		xeploai="Gioi";
	}
	else if(danhgia==2){
		luong+=luong/100*10;
		cout<<"Nhan vien Tot"<<endl;
		xeploai="Tot";
	}
	else {
		cout<<"Nhan vien Kem"<<endl;
		luong-=luong/100*10;
		xeploai="Kem";	
	}
	cout<<"Luong la: "<<luong<<"$"<<endl;
}
void nhanvienphongsanxuat::nhapsx(){
	cin.ignore();
    cout<<"ten san pham:";
    getline(cin, TenSPSX);
    cout<<"So luong san pham nay la:";
    cin>>soluongSP;
    cout<<"____________________________________________"<<endl;
}
void nhanvienphongsanxuat::xuatsx(){
    cout << setw(36) << setfill('.') << left << "Ten san pham:";
    cout << setw(7) << setfill(' ') << right << showpoint << TenSPSX<< setprecision(2) << fixed << endl;
    cout << setw(36) << setfill('.') << left << "So luong san pham:";
    cout << setw(7) << setfill(' ') << right << showpoint << soluongSP<< setprecision(2) << fixed << endl;
    cout<<"____________________________________________"<<endl;
}

void nhanvienphongkinhdoanh::nhap(){
    nhanvien::nhap();
}
void nhanvienphongkinhdoanh::xuat(){
    nhanvien::xuat();

}
void nhanvienphongkinhdoanh::nhapchiphi(){
	cin.ignore();
    cout<<"Ten cac khoan chi tieu:";
    getline(cin, tencackhoanchitieu);
    cout<<"Tien chi:";
    cin>>tienchi;
    cout<<"____________________________________________"<<endl;
}
void nhanvienphongkinhdoanh::xuatchiphi(){
    cout << setw(36) << setfill('.') << left << "Ten cac khoan chi tieu:";
    cout << setw(7) << setfill(' ') << right << showpoint << tencackhoanchitieu<< setprecision(2) << fixed << endl;
    cout << setw(36) << setfill('.') << left << "Chi phi:";
    cout << setw(7) << setfill(' ') << right << showpoint << tienchi<<"$"<< setprecision(2) << fixed << endl;
    cout<<"____________________________________________"<<endl;
}

void nhapdanhsachnhanvienPTC(nhanvienphongtochuc PTC[100], int &soluongptc, int &soluongcacsukien){
    cout<<"So luong nhan vien:";
    cin>>soluongptc;
    for(int i=1; i<=soluongptc; i++){
        PTC[i].nhap();
    }
    cout<<"So luong su kien trong thang:";
    cin>>soluongcacsukien;
    for(int j=1; j<=soluongcacsukien; j++){
        PTC[j].nhapsukien();
    }
}
void xuatnhanvienPTC(nhanvienphongtochuc PTC[100], int soluongptc){
    for(int i=1; i<=soluongptc; i++){
        PTC[i].xuat();
         PTC[i].danhGia();
    }
}
void xuatSKPTC(nhanvienphongtochuc PTC[100], int soluongcacsukien){
    for(int j=1; j<=soluongcacsukien; j++){
        PTC[j].xuatsukien();
    }
}

void nhapdanhsachnhanvienPSX(nhanvienphongsanxuat PSX[100], int &soluongpsx, int &soluongSPSX){
    cout<<"So luong nhan vien:";
    cin>>soluongpsx;
    for(int i=1; i<=soluongpsx; i++){
        PSX[i].nhap();
    }
    cout<<"So luong cac san pham san xuat trong thang:";
    cin>>soluongSPSX;
    for(int j=1; j<=soluongSPSX; j++){
        PSX[j].nhapsx();
    }
}
void xuatnhanvienPSX(nhanvienphongsanxuat PSX[100], int soluongpsx){
    for(int i=1; i<=soluongpsx; i++){
        PSX[i].xuat();
         PSX[i].danhGia();
    }
}
void xuatSPSX(nhanvienphongsanxuat PSX[100], int soluongSPSX){
	for(int j=1; j<=soluongSPSX; j++){
        PSX[j].xuatsx();
    }
}
void nhapdanhsachnhanvienPKD(nhanvienphongkinhdoanh PKD[100], int &soluongpkd, int &soluongcackhoanchitieu){
    cout<<"So luong nhan vien:";
    cin>>soluongpkd;
    for(int i=1; i<=soluongpkd; i++){
        PKD[i].nhap();
    }
    cout<<"So luong cac san pham san xuat trong thang:";
    cin>>soluongcackhoanchitieu;
    for(int j=1; j<=soluongcackhoanchitieu; j++){
        PKD[j].nhapchiphi();
    }
}
void xuatnhanvienPKD(nhanvienphongkinhdoanh PKD[100], int soluongpkd){
    for(int i=1; i<=soluongpkd; i++){
        PKD[i].xuat();
         PKD[i].danhGia();
    }
}
void xuatcackhoanchitieu(nhanvienphongkinhdoanh PKD[100], int soluongcackhoanchitieu){
    for(int j=1; j<=soluongcackhoanchitieu; j++){
        PKD[j].xuatchiphi();
    }
}

void timkiempkd(string &x,nhanvienphongkinhdoanh PKD[100], int soluongpkd,nhanvienphongsanxuat PSX[100], int soluongpsx,nhanvienphongtochuc PTC[100], int soluongptc){
	cin.ignore();
    cout<<"Nhap ma nhan vien can tim: ";
    getline(cin,x);
        for(int i=1; i<=soluongpkd; i++){
            if(x==PKD[i].getMNV()){
        	    PKD[i].xuat();
        	    
		    }
        }
    cout<<"Ma nhan vien sai yeu cau nhap lai!";
}
void timkiempsx(string &x,nhanvienphongkinhdoanh PKD[100], int soluongpkd,nhanvienphongsanxuat PSX[100], int soluongpsx,nhanvienphongtochuc PTC[100], int soluongptc){
	cin.ignore();
	int g=0;
    cout<<"Nhap ma nhan vien can tim: ";
    getline(cin,x);
	for(int j=1; j<=soluongpsx; j++){
            if(x==PSX[j].getMNV()){
        	    PSX[j].xuat();
        	    
		    }
        }

}
void timkiemptc(string &x,nhanvienphongkinhdoanh PKD[100], int soluongpkd,nhanvienphongsanxuat PSX[100], int soluongpsx,nhanvienphongtochuc PTC[100], int soluongptc){
	cin.ignore();
    cout<<"Nhap ma nhan vien can tim: ";
    getline(cin,x);
	for(int k=1; k<=soluongptc; k++){
            if(x==PTC[k].getMNV()){
        	    PTC[k].xuat();
		    }
        }
    
}

void timSk(nhanvienphongtochuc PTC[100], int soluongcacsukien,string sk){
	for(int j=1; j<=soluongcacsukien; j++){
        if(sk==PTC[j].getSK()){
        	cout<<"Ten su kien: "<<PTC[j].getSK()<<endl;
        	cout<<"Thoi gian to chuc: "<<PTC[j].getTSK()<<endl;
        	break;
		}
    }
    cout<<"Su kien khong ton tai trong cong ty !"<<endl;
}
void timSP(nhanvienphongsanxuat PSX[100], int soluongSPSX,string sp){
	for(int i=1; i<=soluongSPSX; i++){
        if(sp==PSX[i].getSP()){
        	cout<<"Ten san pham "<<PSX[i].getSP()<<endl;
        	cout<<"So luong san pham nay: "<<PSX[i].getSL()<<endl;
        	break;
		}
    }
    cout<<"San pham nay khong co trong cong ty !"<<endl;
}
void delphongtc(nhanvienphongtochuc ptc[100],int soluongptc,int soluongcacsukien, int vitri){
	cout<<"Nhap vi tri nhan vien can xoa:";
	cin>>vitri;
	cout<<"Danh sach moi:"<<endl;
	for(int i=1;i<=soluongptc;i++){
		ptc[vitri]=ptc[vitri+1];
		soluongptc=soluongptc-1;
		xuatnhanvienPTC(ptc, soluongptc);
		break;
	}
	xuatSKPTC(ptc,soluongcacsukien);
}
void delphongsx(nhanvienphongsanxuat psx[100], int soluongpsx, int soluongSPSX, int vitri){
	cout<<"Nhap vi tri nhan vien can xoa:";
	cin>>vitri;
	cout<<"Danh sach moi:"<<endl;
	for(int i=1;i<=soluongpsx;i++){
		psx[vitri]=psx[vitri+1];
		soluongpsx=soluongpsx-1;
		xuatnhanvienPSX(psx, soluongpsx);
		break;
	}
	xuatSPSX(psx,soluongSPSX);
}
void delphongkd(nhanvienphongkinhdoanh pkd[], int soluongpkd, int soluongcackhoanchitieu, int vitri){
	cout<<"Nhap vi tri nhan vien can xoa:";
	cin>>vitri;
	cout<<"Danh sach moi:"<<endl;
	for(int i=1;i<=soluongpkd;i++){
		pkd[vitri]=pkd[vitri+1];
		soluongpkd=soluongpkd-1;
		xuatnhanvienPKD(pkd, soluongpkd);
		break;
	}
	xuatcackhoanchitieu(pkd, soluongcackhoanchitieu);
}
void addptc(nhanvienphongtochuc ptc[100],int soluongptc, int vitri){
    cout<<"Nhap vi tri can them:";
    cin>>vitri;
    cout<<"Nhap thong tin nhan vien can them:"<<endl;
    ptc[vitri].nhap();
    system("cls");
    xuatnhanvienPTC(ptc, soluongptc+1);
}
void addpsx(nhanvienphongsanxuat psx[100],int soluongpsx, int vitri){
    cout<<"Nhap vi tri can them:";
    cin>>vitri;
    cout<<"Nhap thong tin nhan vien can them:"<<endl;
    psx[vitri].nhap();
    system("cls");
    xuatnhanvienPSX(psx, soluongpsx+1);
}
void addpkd(nhanvienphongkinhdoanh pkd[100],int soluongpkd, int vitri){
    cout<<"Nhap vi tri can them:";
    cin>>vitri;
    cout<<"Nhap thong tin nhan vien can them:"<<endl;
    pkd[vitri].nhap();
    system("cls");
    for(int i=1; i<soluongpkd+1; i++){
        xuatnhanvienPKD(pkd, soluongpkd+1);
    }
}
void ThemPTC(nhanvienphongtochuc ptc[100],int soluongptc, nhanvienphongtochuc nv, int vitri){
	cout<<"Nhap vi tri can them:";
    cin>>vitri;
    cout<<"Nhap thong tin nhan vien can them:"<<endl;
    nv.nhap();
    system("cls");
    if(vitri < 1){
        vitri = 1;
    }
    else if(vitri >= soluongptc){
        vitri = soluongptc+1;
    }
    for(int i = soluongptc+1; i >= vitri; i--){
        ptc[i] = ptc[i-1];
    }
	ptc[vitri]=nv;
    xuatnhanvienPTC(ptc, soluongptc+1);
}
void ThemPSX(nhanvienphongsanxuat psx[100],int soluongpsx, nhanvienphongsanxuat nv1, int vitri){
	cout<<"Nhap vi tri can them:";
    cin>>vitri;
    cout<<"Nhap thong tin nhan vien can them:"<<endl;
    nv1.nhap();
    system("cls");
    if(vitri < 1){
        vitri = 1;
    }
    else if(vitri >= soluongpsx){
        vitri = soluongpsx+1;
    }
    for(int i = soluongpsx+1; i >= vitri; i--){
        psx[i] = psx[i-1];
    }
	psx[vitri]=nv1;
    xuatnhanvienPSX(psx, soluongpsx+1);
}
void ThemPKD(nhanvienphongkinhdoanh pkd[100],int soluongpkd, nhanvienphongkinhdoanh nv2, int vitri){
	cout<<"Nhap vi tri can them:";
    cin>>vitri;
    cout<<"Nhap thong tin nhan vien can them:"<<endl;
    nv2.nhap();
    system("cls");
    if(vitri < 1){
        vitri = 1;
    }
    else if(vitri >= soluongpkd){
        vitri = soluongpkd+1;
    }
    for(int i = soluongpkd+1; i >= vitri; i--){
        pkd[i] = pkd[i-1];
    }
	pkd[vitri]=nv2;
    xuatnhanvienPKD(pkd, soluongpkd+1);
}
void nhanvien::ghi(){
	nhanvien abc;
	ofstream file;
    file.open("danhsachnhanvien.txt", ios::app);
	file << endl << setw(36) << setfill('.') << left << "Ho va ten: "; 
    file << setw(7) << setfill(' ') << right <<hovaten  << endl;
    file << endl << setw(36) << setfill('.') << left << "Ngay sinh: "; 
    file << setw(7) << setfill(' ') << right <<ngay  <<"/"<<thang<<"/"<<nam<< endl;
    file << endl << setw(36) << setfill('.') << left << "Gioi tinh: "; 
    file << setw(7) << setfill(' ') << right <<gioitinh<< endl;
    file << endl << setw(36) << setfill('.') << left << "Dia chi: "; 
    file << setw(7) << setfill(' ') << right <<diachi  << endl;
    
    file << endl << setw(36) << setfill('.') << left << "Ma van phong:";
    file << setw(7) << setfill(' ') << right << showpoint << mavanphong << endl;
    file << endl << setw(36) << setfill('.') << left << "Chuc vu: "; 
    file << setw(7) << setfill(' ') << right <<chucvu  << endl;
    file << endl << setw(36) << setfill('.') << left << "Ma nhan vien:";   
    file << setw(7) << setfill(' ') << right << showpoint << manhanvien << endl;
    file << endl << setw(36) << setfill('.') << left << "So ngay nghi: "; 
    file << setw(7) << setfill(' ') << right <<nghi << endl;
    file << endl << setw(36) << setfill('.') << left << "Luong co ban:";
    file << setw(7) << setfill(' ') << right << showpoint << luong <<"$"<<  endl;
    file << endl << setw(36) << setfill('.') << left << "Xep loai nhan vien: "; 
    file << setw(7) << setfill(' ') << right << xeploai << endl;
    file<<"____________________________________________"<<endl;
}
void nhanvienphongtochuc::ghi(){
	nhanvien::ghi();
}
void nhanvienphongsanxuat::ghi(){
    nhanvien::ghi();
}
void nhanvienphongkinhdoanh::ghi(){
    nhanvien::ghi();
}
void nhanvienphongtochuc::ghiSK(){
    ofstream file;
	file.open("thong tin phong PTC.txt", ios::app);
	file << setw(36) << setfill('.') << left << "Su kien:";
    file << setw(7) << setfill(' ') << right << showpoint << tensukientochuc<<  endl;
    file << setw(36) << setfill('.') << left << "Ngay to chuc:";
    file << setw(7) << setfill(' ') << right << showpoint << ngaytochucsukien <<  endl;
    file<<"____________________________________________"<<endl;
    file.close();
}
void nhanvienphongsanxuat::ghiSX(){
    ofstream file;
	file.open("thong tin phong PSX.txt", ios::app);
	file << setw(36) << setfill('.') << left << "Ten san pham:";
    file << setw(7) << setfill(' ') << right << showpoint << TenSPSX<< setprecision(2) << fixed << endl;
    file << setw(36) << setfill('.') << left << "So luong san pham:";
    file << setw(7) << setfill(' ') << right << showpoint << soluongSP<< setprecision(2) << fixed << endl;
    file<<"____________________________________________"<<endl;
    file.close();
}
void nhanvienphongkinhdoanh::ghiKD(){
    ofstream file;
	file.open("thong tin phong PKD.txt", ios::app);
	file << setw(36) << setfill('.') << left << "Ten cac khoan chi tieu:";
    file << setw(7) << setfill(' ') << right << showpoint << tencackhoanchitieu<< setprecision(2) << fixed << endl;
    file << setw(36) << setfill('.') << left << "Chi phi:";
    file << setw(7) << setfill(' ') << right << showpoint << tienchi<<"$"<< setprecision(2) << fixed << endl;
    file<<"____________________________________________"<<endl;
    file.close();
}
void xuatfileptc(nhanvienphongtochuc PTC[100], int soluongptc){
    for(int i=1; i<=soluongptc; i++){
        PTC[i].ghi();
    }
}
void xuatfilept(nhanvienphongtochuc PTC[100], int soluongcacsukien){
    for(int i=1;i<=soluongcacsukien;i++){
        PTC[i].ghiSK();
    }
}
void xuatfilepsx(nhanvienphongsanxuat PSX[100], int soluongpsx){
    for(int i=1; i<=soluongpsx; i++){
        PSX[i].ghi();
    }
}
void xuatfileps(nhanvienphongsanxuat PSX[100], int soluongSPSX){
    for(int i=1;i<=soluongSPSX;i++){
        PSX[i].ghiSX();
    }
}
void xuatfilepkd(nhanvienphongkinhdoanh PKD[100], int soluongpkd){
    for(int i=1; i<=soluongpkd; i++){
        PKD[i].ghi();
    }
}
void xuatfilepk(nhanvienphongkinhdoanh PKD[100],int soluongcackhoanchitieu){
    for(int j=1; j<=soluongcackhoanchitieu; j++){
        PKD[j].ghiKD();
    }
}
int main(){
    DisableResizeWindow();
	DisableCtrButton(0,1,1);
	SetWindowSize(100,100);
	SetConsoleTitle("QuanLyNhanVien");
    nhanvienphongtochuc ptc[100],nv,luu;
    nhanvienphongsanxuat psx[100],nv1,luu1;
    nhanvienphongkinhdoanh pkd[100],nv2,luu2;
    ofstream file;
    nhanvien abc[100];
    int soluongptc,soluongpsx,soluongpkd,soluongcacsukien, soluongSPSX, soluongcackhoanchitieu,vitri;
    int i=1, luachon;
    int chon,l,lcp,lcphong,setting,caidat,luufile;
    string x,sk,sp;
    bool danhap=false;
    SetColor(1,7);
    ofstream outfile;
    nhanvien nvo;
    while(i){
    	cout<<"\n";
    	cout << setw(35) << setfill(' ') << right <<""<<"____________QUAN LI NHAN SU________________"<< endl;
    	cout << setw(35) << setfill(' ') << right <<""<<"|1. Nhap Thong tin Phong To Chuc.         |"<<endl;
		cout << setw(35) << setfill(' ') << right <<""<<"|2. Nhap Thong tin Phong san xuat.        |"<<endl;
		cout << setw(35) << setfill(' ') << right <<""<<"|3. Nhap Thong tin Phong kinh Doanh.      |"<<endl;
        cout << setw(35) << setfill(' ') << right <<""<<"|4. In ra Thong tin Phong To Chuc.        |"<<endl;
        cout << setw(35) << setfill(' ') << right <<""<<"|5. In ra Thong tin Phong san xuat.       |"<<endl;
        cout << setw(35) << setfill(' ') << right <<""<<"|6. In ra  Thong tin Phong kinh Doanh.    |"<<endl;
        cout << setw(35) << setfill(' ') << right <<""<<"|7. Tim kiem.                             |"<<endl;
		cout << setw(35) << setfill(' ') << right <<""<<"|8. Xoa nhan vien.                        |"<<endl;
		cout << setw(35) << setfill(' ') << right <<""<<"|9. Them nhan vien.                       |"<<endl;
		cout << setw(35) << setfill(' ') << right <<""<<"|10.Thoat.                                |"<<endl;
		cout << setw(35) << setfill(' ') << right <<""<<"|_________________________________________|"<<endl;
		cout << setw(35) << setfill(' ') << right <<""<<"Moi lua chon: ";
		cin>>luachon;
		system("cls");
		switch(luachon){
			case 1:
				cout<<"Nhap thong tin phong to chuc:"<<endl;
				nhapdanhsachnhanvienPTC(ptc, soluongptc, soluongcacsukien);
                cout<<"Nhap thanh cong"<<endl;
                danhap=true;
				break;
			case 2:
                cout<<"Nhap thong tin phong san xuat:"<<endl;
                nhapdanhsachnhanvienPSX(psx, soluongpsx, soluongSPSX);
                cout<<"Nhap thanh cong"<<endl;
                danhap=true;
                break;
			case 3:
				cout<<"Nhap thong tin phong kinh doanh:"<<endl;
                nhapdanhsachnhanvienPKD(pkd, soluongpkd, soluongcackhoanchitieu);
                cout<<"Nhap thanh cong"<<endl;
                danhap=true;
				break;
            case 4:
                if(danhap==true){
                    cout<<"Danh sach nhan vien:"<<endl;
                    xuatnhanvienPTC(ptc,soluongptc);
                    xuatSKPTC(ptc, soluongcacsukien);
                    xuatfileptc(ptc,soluongptc);
                    xuatfilept(ptc,soluongcacsukien);
                }
                else{
                    cout<<"Nhap thong tin phong to chuc truoc";
                }
				break;
            case 5:
				if(danhap==true){
                    cout<<"In ra Thong tin Phong san xuat:"<<endl;
                    xuatnhanvienPSX(psx, soluongpsx);
                    xuatSPSX(psx, soluongSPSX);
                    xuatfilepsx(psx,soluongpsx);
                    xuatfileps(psx,soluongSPSX);
                }
                else{
                    cout<<"Nhap thong tin phong san xuat truoc";
                }
				break;
            case 6:
            	if(danhap==true){
                    cout<<"In ra  Thong tin Phong kinh Doanh:"<<endl;
                    xuatnhanvienPKD(pkd, soluongpkd);
                    xuatcackhoanchitieu(pkd, soluongcackhoanchitieu);
                    xuatfilepkd(pkd,soluongpkd);
                    xuatfilepk(pkd, soluongcackhoanchitieu);
                }
                else{
                    cout<<"Nhap thong tin phong kinh doanh truoc";
                }
                break;
            case 7:
            	if(danhap==true){
            		l=1;
            	while(l){
            	    cout<<"Tim kiem:"<<endl;
            	    cout<<" 1.Tim kiem thong tin nhan vien PTC"<<endl;
            	    cout<<" 2.Tim kiem thong tin nhan vien PSX"<<endl;
            	    cout<<" 3.Tim kiem thong tin nhan vien PKD"<<endl;
            	    cout<<" 4.Tim kiem su kien da dien ra bang nhap thoi gian."<<endl;
            	    cout<<" 5.Tim kiem san pham va so luong xuat ra."<<endl;
            	    cout<<" 6.Ket thuc phan tim kiem."<<endl;
            	    cout<<"Moi lua chon: ";
				    cin>>chon;
				    system("cls");
				    switch(chon){
					    case 1:
				            if(danhap==true){
            	                timkiemptc( x,pkd,  soluongpkd, psx, soluongpsx, ptc,  soluongptc);
				            }
                            else{
                                cout<<"Nhap thong tin phong kinh doanh truoc";
                            }
				            break;
				        case 2:
				            if(danhap==true){
            	                timkiempsx( x,pkd,  soluongpkd, psx, soluongpsx, ptc,  soluongptc);
				            }
                            else{
                                cout<<"Nhap thong tin phong kinh doanh truoc";
                            }
				            break;
				        case 3:
				            if(danhap==true){
            	                timkiempkd( x,pkd,  soluongpkd, psx, soluongpsx, ptc,  soluongptc);
				            }
                            else{
                                cout<<"Nhap thong tin phong kinh doanh truoc";
                            }
				            break;
				        case 4:
				            if(danhap==true){
            	                cin.ignore();
				                cout<<"Hay cho biet su kien ban muon tim: ";
				                getline(cin,sk);
				                timSk(ptc,soluongcacsukien,sk);
			                }
            	            else{
                                cout<<"Nhap thong tin Phong to chuc truoc";
                            }
                            break;
                        case 5:
               	            if(danhap==true){
            	                cin.ignore();
            	                cout<<"Nhap ten san pham muon tim: ";
            	                getline(cin,sp);
            	                timSP(psx,soluongSPSX,sp);
            	            }
                            else{
            	                cout<<"Nhap thong tin SP truoc";
			                }
			                break;
			            case 6:
				            l=0;
				            break;
			            default:
				            cout<<"Nhap sai. Moi nhap lai"<<endl;
                        }
                    }
				}
				else{
                    cout<<"Nhap thong tin phong kinh doanh truoc";
                }
            	break;
            case 8:
            	if(danhap==true){
            		caidat=1;
            		while(caidat){
                    cout<<"\n1. Xoa trong Phong To Chuc."<<endl;
				    cout<<"2. Xoa trong Phong san xuat."<<endl;
			        cout<<"3. Xoa trong Phong kinh Doanh."<<endl;
			        cout<<"4. Thoat."<<endl;
            	    cout<<"nhap vao phong can xoa: ";
                    cin>>lcphong;
            	    system("cls");
            		switch(lcphong){
            		case 1:
            			delphongtc(ptc,soluongptc,soluongcacsukien,vitri);
            			cout<<"xoa thanh cong"<<endl;
            			break;
            		case 2:
            			delphongsx(psx,soluongpsx,soluongSPSX,vitri);
						cout<<"xoa thanh cong"<<endl;
            			break;
					case 3:
            			delphongkd(pkd,soluongpkd,soluongcackhoanchitieu,vitri);
            			cout<<"xoa thanh cong"<<endl;
            			break;
                    case 4:
                        caidat=0;
                        break;
            		default:
            			cout<<"Nhap sai .Moi ban nhap lai!"<<endl;
            			break;
				    	}
                	}
				}
            	else{
                    cout<<"Nhap thong tin phong kinh doanh truoc";
                }
				break;
            case 9:
            	if(danhap==true){
            		setting=1;
            		while(setting){
                    cout<<"\n1. Them trong Phong To Chuc."<<endl;
				    cout<<"2. Them trong Phong san xuat."<<endl;
			        cout<<"3. Them trong Phong kinh Doanh."<<endl;
			        cout<<"4. Thoat."<<endl;
            	    cout<<"nhap vao phong can Them: ";
                    cin>>lcp;
            	    system("cls");
            		switch(lcp){
            		case 1:
            			ThemPTC(ptc,soluongptc,nv,vitri);
            			cout<<"them thanh cong"<<endl;
            			break;
            		case 2:
            		 	ThemPSX(psx,soluongpsx,nv1,vitri);
					 	cout<<"xoa thanh cong"<<endl;
            		 	break;
					case 3:
            		 	ThemPKD(pkd,soluongpkd,nv2,vitri);
            		 	cout<<"xoa thanh cong"<<endl;
            		 	break;
                    case 4:
                        setting=0;
                        break;
            		default:
            			cout<<"Nhap sai .Moi ban nhap lai!"<<endl;
            			break;
				    	}
                	}
				}
            	else{
                    cout<<"Nhap thong tin phong kinh doanh truoc";
                }
				break;
            case 10:
			    for(int k=3;k>=0;k--){
				    system("cls");
        		    cout<<"                             THOAT TRONG:"<<k;
        		    sleep(1);
        	    }
        	    i=0;
				break;
			default:
				cout<<"Nhap sai. Moi nhap lai"<<endl;
		}
	}
}

