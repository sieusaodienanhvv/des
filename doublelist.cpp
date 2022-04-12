#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
class Nhanvien{
	private:
		string Ten;
		int Luong;
	public:
	friend class  node;
	friend class LinkedList;
	Nhanvien(){
		Ten=" ";
		Luong =0;
	}
	~Nhanvien(){
	}
	void Nhap();
	void Xuat();
	int getLuong();
};
class  node{
	private:
    Nhanvien a;
    node *next;
    public:
    friend class LinkedList;
 };
class LinkedList{
	private: 
	node *head;
	public:
node *CreateNode(Nhanvien a);
void AddTail(Nhanvien a);
void  AddHead(Nhanvien a);
void  AddAt(Nhanvien a, int position);
void DelHead();
void  DelTail();
void  DelAt(int position);
void Traverser();
node *InitHead();
int Length();
void Input();	
};

void Nhanvien::Nhap(){
	cout<<"nhap ten nhan vien vao: ";
	fflush(stdin);
	getline(cin,Ten);
	cout<<"Nhap luong nhan vien vao: ";
	cin>>Luong;
}
void Nhanvien::Xuat(){
	cout<<"Ten nhan vien: "<<Ten<<endl;
    cout<<"Luong thang: "<<Luong<<endl;
}
int Nhanvien::getLuong(){
	return (this->Luong);
}
node* LinkedList::CreateNode(Nhanvien a){
	a.Nhap();
    node *temp; 
    temp = new node; 
    temp->next = NULL;
    temp->a = a; 
    return temp;
}
void LinkedList::AddTail(Nhanvien a){
    node *temp,*p;
    temp = CreateNode(a);
    if(head == NULL){
        head = temp; 
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}
void  LinkedList::AddHead(Nhanvien a){
    node *temp = CreateNode(a); 
    if(head == NULL){
        head = temp;
    }else{
        temp->next = head; 
        head = temp; 
    }
}
void  LinkedList::AddAt(Nhanvien a, int position){
    if(position == 0 || head == NULL){
        AddHead(a); 
    }else{
        int k = 1;
        node *p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            AddTail(a);
        }else{
            node *temp = CreateNode(a);
            temp->next = p->next;
            p->next = temp;
        }
    }
}
void LinkedList::DelHead(){
    if(head == NULL){
        cout<<"\nCha co gi de xoa het!";
    }else{
        head = head->next;
    }
}
void  LinkedList::DelTail(){
    if (head == NULL || head->next == NULL){
        cout<<"khong co gi de xoa";
    }
    node *p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next;
}
void  LinkedList::DelAt(int position){
    if(position == 0 || head == NULL || head->next == NULL){
       cout<<"Khong co gi de xoa";
    }else{
        int k = 1;
        node *p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            DelTail();
        }else{
            p->next = p->next->next;
        }
    }
}
void LinkedList::Traverser(){
    cout<<"\n";
    for(node *p = head; p != NULL; p = p->next){
    	Nhanvien b;
		b=p->a;
		b.Xuat();
    }
}
node* LinkedList::InitHead(){
    head = NULL;
    return head;
}
int LinkedList::Length(){
    int length = 0;
    for(node *p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
void LinkedList::Input(){
    head = InitHead();
    Nhanvien a;
    int n;
    cout<<"Nhap so luong nhan vien vao:";
    cin>>n;
    for(int i = 0; i < n; i++){
        AddTail(a);
    }
}
void Menu(LinkedList a,int &t){
	int c;
	system("cls");
   while (1)
   {
   	  cout<<"Chuong trinh quan li nhan vien"<<endl;
      cout<<"1.Nhap"<<endl;
      cout<<"2.Xuat"<<endl;
      cout<<"3.Them dau danh sach"<<endl;
	  cout<<"4.Them cuoi danh sach "<<endl;
	  cout<<"5.Them vi tri bat ki danh sach "<<endl;
      cout<<"6.Xoa bat ki rong danh sach"<<endl;
      cout<<"7.Tim Nhan vien luong cao mhat"<<endl;
      cout<<"8.Thoat"<<endl;
      cout<<"Nhap su lua chon: ";
      cin>>c;
      switch(c) {
         case 1:
         		a.Input();
         	t=1;
            getch();
            return Menu(a,t);
         case 2:
         	if(t==1){
         	a.Traverser();
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(a,t);
        case 3:
         	if(t==1){
         		Nhanvien b;
         	 a.AddHead(b);
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(a,t);
        case 4:
         	if(t==1){
         	Nhanvien b;
         	a.AddTail(b);
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(a,t);
        case 5:
         	if(t==1){
         	int i;
         	cout<<"Nhap vi tri can them: ";
         	cin>>i;
         	Nhanvien b;
         	a.AddAt(b,i);
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(a,t);
        case 6:
         	if(t==1){
         	int i;
         	cout<<"Nhap vi tri can xoa: ";
         	cin>>i;
         	a.DelAt(i);
        	 }
        	 else cout<<"Phai nhap truoc! (lua chon 1) ";
         	getch();
            return  Menu(a,t);
        case 7:
            exit(1);
         default:
            cout<<"Wrong choice"<<endl;
      }
   }
}
int main(){
	LinkedList a;
	int t=0;
	Menu(a,t);
}
