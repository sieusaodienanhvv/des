#include<iostream>
#include<string>
#include<conio.h>
#include<fstream> 
using namespace std;
class Docgia{
	private:
		string Tensinhvien;
		string Mssv;
	public:
		Docgia();
		Docgia(string Tensinhvien,string Mssv);
		~Docgia();
	friend istream &operator  >>(istream &is,Docgia &a);
	friend ostream &operator <<(ostream &os,Docgia a);
	string getTensinhvien();
};
class Sach{
	private:
		string Tensach;
		string Theloai;
	public:
		Sach();
		Sach(string Tensach,string Theloai);
		~Sach();
	friend istream &operator >>(istream &is,Sach &a);
	friend ostream &operator <<(ostream &os,Sach a);
};
class Quanli{
	private:
		Docgia docgia;
		int Sosach;
		Sach sach[10];
	public:
	friend istream &operator >>(istream &is,Quanli &a);
	friend ostream &operator <<(ostream &os,Quanli a);
	int getsosach(); 
	string getTensinhvien();
};
class Node
{
	private: 
    Quanli a;
    Node *next;
    public:
	friend class Queue; 
};
class Queue
{
	private: 
    Node *head;
    Node *tail;
    public:
 	void CreateQueue();
 	Node* CreateNode(Quanli b);
 	void DestroyQueue();
 	int IsEmpty();
 	void EnQueue(Node *node);
 	void DeQueue();
 	void Front();
 	void PrintQueue(int &t);
 	void Search(string Ten);
 	void Max();
 	void Gan(Quanli sach[],int n);
 	void Intep(); 
};
void Nhap(Queue &q,int &n); 
void Search(Queue q);
void Max(Queue q);
void Thongke(Queue q); 
void Thongketen(Queue q,int n); 
void Menu(Queue q,int n, int &t);
int main(){
	int n;
	Queue q;
	int t=0; 
	Menu(q,n,t);
	return 0;
}
Docgia::Docgia(){
	Tensinhvien="0";
	Mssv="0";
}
Docgia::Docgia(string Tensinhvien,string Mssv){
	this->Tensinhvien=Tensinhvien;
	this->Mssv=Mssv;
}
istream &operator  >>(istream &is,Docgia &a){
	cout<<"Nhap ten sinh vien vao: ";
	fflush(stdin);
	getline(is,a.Tensinhvien);
	cout<<"Nhap ma so sinh vien vao: ";
	fflush(stdin);
	getline(is,a.Mssv);
	return is;
}
ostream &operator <<(ostream &os,Docgia a){
	cout<<"Ten sinh vien: "<<a.Tensinhvien<<"||Ma so sinh vien: "<<a.Mssv<<endl;
	return os;
}
string Docgia::getTensinhvien(){
	return (this->Tensinhvien);
}
Docgia::~Docgia(){
}
Sach::Sach(){
	Tensach="0";
	Theloai="0";
}
Sach::Sach(string Tensach,string Theloai){
	this->Tensach=Tensach;
	this->Theloai=Theloai;
}
istream &operator  >>(istream &is,Sach &a){
	cout<<"Nhap ten sach vao: ";
	fflush(stdin);
	getline(is,a.Tensach);
	cout<<"Nhap the loai sach: ";
	fflush(stdin);
	getline(is,a.Theloai);
	return is;
}
ostream &operator <<(ostream &os,Sach a){
	cout<<"Ten sach: "<<a.Tensach<<"||Theloai: "<<a.Theloai<<endl;
	return os;
}
Sach::~Sach(){
}
istream &operator >>(istream &is,Quanli &a){
	is>>a.docgia;
	cout<<"Nhap so luong sach can muon: ";
	is>>a.Sosach;
	for(int i=0; i<a.Sosach; i++){
	cout<<"Nhap thong tin sach thu "<<i+1<<" : "<<endl;
	is>>a.sach[i];
	}
	return is;
}
ostream &operator <<(ostream &os,Quanli a){
	cout<<a.docgia;
	for(int i=0; i<a.Sosach; i++){
	cout<<"Thong tin sach thu "<<i+1<<" : ";
	cout<<a.sach[i];
	}
	return os; 
}
string Quanli::getTensinhvien(){
	Docgia a=this->docgia;
	return(a.getTensinhvien());
}
int Quanli::getsosach(){
	return (this->Sosach); 
} 
void Queue::CreateQueue()
{
    head = NULL;
    tail = NULL;
}
Node* Queue::CreateNode(Quanli b)
{
    Node *node = new Node;
    node->a = b;
    node->next = NULL;
    return node;
}
void Queue::DestroyQueue()
{
    Node *node = head;
    while (head != NULL)
    {
        head = node->next;
        delete node;
        node = head;
    }
    tail = NULL;
}

int Queue::IsEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}

void Queue::EnQueue(Node *node)
{
	if (IsEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}
void Queue::Intep(){
	ofstream File;
	File.open("DanhSachTheoThuTu.txt",ios::out); 
	Node *node = head;
	int t=1; 
    while (node != NULL)
    {
    	
    	Quanli b=node->a; 
    	File<<"Danh sach theo thu tu muon sach: "<<endl; 
		File<<t<<"."<<b.getTensinhvien()<<"("<<b.getsosach()<<"cuon )"<<endl; 
		t=t+1; 
		node = node->next;
	}
	File.close(); 
}
void Queue::DeQueue()
{
    if (IsEmpty())
    cout<<"Danh sach rong!"<<endl;
    Node *node = head;
    head = node->next;
    delete node;
}

void Queue::Front()
{
    if (IsEmpty())
        cout<<"Danh sach rong!"; 
    else {
    	Quanli b=head->a; 
    	cout<<b; 
	} 
}

void Queue::PrintQueue(int &t)
{
    Node *node = head;
    while (node != NULL)
    {
    	Quanli b=node->a; 
        cout <<b<<endl;
        t=t+b.getsosach();
        node = node->next;
    }
}
void Queue::Search(string Ten)
{
	int t=0;
	Node *p=NULL;
	for(Node* node=head;node !=NULL;node=node->next){
		if(Ten==node->a.getTensinhvien()){
			p = node;
			t=1;
			break;
		}
	} 
    if(t) cout<<"Co sinh vien "<<Ten<<" trong danh sach"<<endl<<p->a;
    else cout<<"Khong co sinh vien "<<Ten<<" trong danh sach";
}
void Queue::Gan(Quanli sach[],int n){
	Node* node = head;
	for(int i=0;i<n; i++ ){
		sach[i]=node->a;
		node=node->next;
	}
}
void Queue::Max()
{
	Node *p=head;
	Node *Max=head;
	int max=Max->a.getsosach();
	for(Max=Max->next ; Max !=NULL;Max=Max->next){
		if(max<Max->a.getsosach()){
			p=Max;
			max=Max->a.getsosach();
		}
	} 
	cout<<"Nguoi muon nhieu sach nhat la: "<<endl<<p->a<<endl;
	cout<<"So sach muon la: "<<max<<endl;
}
void Nhap(Queue &q,int &n){
	q.CreateQueue();
 	Node *node;
	cout<<"Nhap so phan tu vao: ";
	cin>>n; 
 	for (int i = 0; i < n; i++)
 	{ 
 	 	Quanli b;
		cout<<"Nhap sinh vien thu "<<i+1<<" vao: "<<endl;
		cin>>b; 
       	node = q.CreateNode(b);
  		q.EnQueue(node);
  		cout<<endl; 
 	}
}
void Thongke(Queue q){
 	int t=0; 
	cout<<"Danh sach:"<<endl;
	q.PrintQueue(t);
	cout<<"Tong sach cho muon la: "<<t<<endl;
}
void Search(Queue q){
	string Ten;
	cout<<"Nhap ten can tim vao: ";
	fflush(stdin);
	getline(cin,Ten);
	q.Search(Ten);
}
void Max(Queue q){
	q.Max();
}
void Thongketen(Queue q,int n){
	Quanli sach[n];
	ofstream file;
	file.open("DanhSachTheoTen.txt",ios::out); 
	int b[n];
	for(int i=0; i<n; i++){
		b[i]=1;
	}
	//gan danh sach lien ket qua mang sach[n]
	q.Gan(sach,n); 
	for(int i=0; i<n; i++){
		for(int j=i+1;j<n;j++){
			if((sach[i].getTensinhvien()).compare(sach[j].getTensinhvien())>0){
				Quanli a=sach[i];
				sach[i]=sach[j];
				sach[j]=a;
			}
		}
	}
	cout<<"Danh sach sach theo ten (A->Z)"<<endl;
	file<<"Danh sach theo ten (A->z) "<<endl;
	for(int i=0; i<n; i++){
		cout<<sach[i]<<endl;
		file<<i+1<<"."<<sach[i].getTensinhvien()<<"("<<sach[i].getsosach()<<"cuon )"<<endl; 
	}
	file.close();
}
void Menu(Queue q,int n,int &t){
	int c;
	system("cls");
   while (1)
   {
      cout<<"1.Nhap danh sach"<<endl;
      cout<<"2.Them vao danh sach"<<endl;
      cout<<"3.Xoa phan tu dau"<<endl;
	  cout<<"4.Lay gia tri dau "<<endl;
      cout<<"5.Thong ke theo thu tu muon sach"<<endl;
      cout<<"6.Tim kiem"<<endl;
      cout<<"7.Thong tin nguoi muon sach nhieu nhat"<<endl;
      cout<<"8.Thong ke theo ten(A->Z) va in ra tep "<<endl;
      cout<<"9.In ra tep"<<endl;
      cout<<"10.Xoa danh sach"<<endl;
      cout<<"11.Thoat"<<endl;
      cout<<"Nhap su lua chon: ";
      cin>>c;
      switch(c) {
         case 1:
         	Nhap(q,n);
         	t=1;
         	cout<<endl<<"Hoan thanh!"; 
            getch();
            return Menu(q,n,t);
         case 2:
         	if(t==1){
         	Node *node;
         	Quanli b;
			cout<<"Nhap sinh vien thu vao: "<<endl;
			cin>>b; 
       		node = q.CreateNode(b);
  			q.EnQueue(node);
  			cout<<endl; 
  			cout<<endl<<"Hoan thanh!"; 
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(q,n,t);
         case 3:
         	if(t==1){
         		q.DeQueue(); 
         		cout<<endl<<"Hoan thanh!"; 
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(q,n,t);
         case 4:
         	if(t==1){
         		q.Front(); 
         		cout<<endl<<"Hoan thanh!"; 
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(q,n,t);
         case 5:
         	if(t==1){
         		Thongke(q);
         		cout<<endl<<"Hoan thanh!"; 
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(q,n,t);
         case 6:
         	if(t==1){
         		Search(q);
         		cout<<endl<<"Hoan thanh!"; 
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(q,n,t);
         case 7:
         	if(t==1){
         		Max(q);
         		cout<<endl<<"Hoan thanh!"; 
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(q,n,t);
         case 8:
         	if(t==1){
         		Thongketen(q,n);
         		cout<<endl<<"Hoan thanh!"; 
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(q,n,t);
         case 9:
         	if(t==1){
         		q.Intep();
         		cout<<endl<<"Hoan thanh!"; 
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(q,n,t);
         case 10:
         	if(t==1){
         		q.DestroyQueue();
         		cout<<endl<<"Hoan thanh!"; 
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(q,n,t);
         case 11:
         	q.DestroyQueue(); 
            exit(1);
         default:
            cout<<"Wrong choice"<<endl;
      }
   }
}



