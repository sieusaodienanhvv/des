#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
using namespace std;
class Nhanvien{
	private:
		string Ten;
		int Luong;
	public:
	friend class  node;
	friend class  listNode;
	Nhanvien(){
		Ten=" ";
		Luong =0;
		
	}
	~Nhanvien(){
	}
	void Nhap(){
		cout<<"nhap ten nhan vien vao: ";
		fflush(stdin);
		getline(cin,Ten);
		cout<<"Nhap luong nhan vien vao: ";
		cin>>Luong;
	}
	void Xuat(){
	cout<<"Ten nhan vien: "<<Ten<<endl<<"Luong thang: "<<Luong<<endl;
	}
	int getLuong(){
		return (this->Luong);
	}
};
class node {
	private:
	    Nhanvien a;
		node *n;
	    node *p;
    public:
    	friend class listNode;
};
int count = 0;
class listNode {
	private:
		node *start, *last;
    public:
      node *create_node(Nhanvien a);
      void insert_begin();
      void insert_end();
      void insert_pos();
      void delete_pos();
      void search();
      void update();
      void display();
      void reverse();
      listNode() {
         start = NULL;
         last = NULL;
      }
};
int Menu(listNode ls, int &t){
	system("cls");
   int c;
   while (1)  
   {
   	cout<<"Chuong trinh quan li nhan vien"<<endl;
      cout<<"1.insert_begin"<<endl;
      cout<<"2.insert_end"<<endl;
      cout<<"3.insert_pos"<<endl;
      cout<<"4.delete_pos"<<endl;
      cout<<"5.edit_list"<<endl;
      cout<<"6.Search Element"<<endl;
      cout<<"7.output_list"<<endl;
      cout<<"8.search_money luong"<<endl;
      cout<<"9.Thoat"<<endl;
      cout<<"Nhap su lua chon: ";
      cin>>c;
      switch(c) {
         case 1:
            ls.insert_begin();
            t=1;
            getch();
            return  Menu(ls,t);
         case 2:
            ls.insert_end();
            t=1;
            getch();
            return  Menu(ls,t);
         case 3:
         	if(t==1){
         	ls.insert_pos();
        	 }
        	 else cout<<"enter 1, please";
         	getch();
            return  Menu(ls,t);
         case 4:
            if(t==1){
         	ls.delete_pos();
        	 }
        	 else cout<<"enter 1, please";
         	getch();
            return  Menu(ls,t);
         case 5:
            if(t==1){
         	ls.update();
        	 }
        	 else cout<<"enter 1, please ";
         	getch();
            return  Menu(ls,t);
         case 6:
            if(t==1){
         	ls.search();
        	 }
        	 else cout<<"enter 1, please ";
         	getch();
            return  Menu(ls,t);
         case 7:
        	if(t==1){
        	ls.display();
        	 }
        	 else cout<<"enter 1, please ";
         	getch();
            return  Menu(ls,t);
            case 8:
        	if(t==1){
        	ls.search();
        	 }
        	 else cout<<"enter 1, please ";
         	getch();
            return  Menu(ls,t);
         case 9:
            exit(1);
         default:
            cout<<"Wrong enter"<<endl;
      }
   }
}
int main() {
	listNode ls;
	int t=0;
	Menu(ls,t);
   return 0;
}
node* listNode::create_node(Nhanvien b) {
   count++;
   node *t;
   t = new node;
   t->a = b;
   t->n = NULL;
   t->p = NULL;
   return t;
}
void listNode::insert_begin() {
   Nhanvien a;
   a.Nhap();
   node *t;
   t = create_node(a);
   if (start == last && start == NULL) {
      start = last = t;
      start->n = last->n = NULL;
      start->p = last->p = NULL;
   } else {
      t->n = start;
      start->p = t;
      start = t;
      start->p = last;
      last->n = start;
   }
}
void listNode::insert_end() {
   Nhanvien a;
   a.Nhap();
   node *t;
   t = create_node(a);
   if (start == last && start == NULL) {
      start = last = t;
      start->n= last->n = NULL;
      start->p = last->p= NULL;
   } else {
      last->n= t;
      t->p= last;
      last = t;
      start->p = last;
      last->n= start;
   }
}
void listNode::insert_pos() {
   Nhanvien a;
   a.Nhap();
   int pos, i;
   cout<<endl<<"Nhap vi tri can them: ";
   cin>>pos;
   node *t, *s, *ptr;
   t = create_node(a);
   if (start == last && start == NULL) {
      if (pos == 1) {
         start = last = t;
         start->n = last->n = NULL;
         start->p = last->p = NULL;
      } else {
         count--;
         return;
      }
   } else {
      if (count < pos) {
         count--;
         return;
      }
      s = start;
      for (i = 1;i <= count;i++) {
         ptr = s;
         s = s->n;
         if (i == pos - 1) {
            ptr->n = t;
            t->p= ptr;
            t->n= s;
            s->p = t;
            break;
         }
      }
   }
}
void listNode::delete_pos() {
   int pos, i;
   node *ptr, *s;
      if (start == last && start == NULL) {
      cout<<"Danh sach rong!"<<endl;
      return;
   }
   cout<<endl<<"Nhap vi tri can xoa: ";
   cin>>pos;
   s = start;
   if(pos == 1) {
      count--;
      last->n = s->n;
      s->n->p = last;
      start = s->n;
      free(s);
   }
   for (i = 0;i < pos - 1;i++ ) {
      s = s->n;
      ptr = s->p;
   }
   ptr->n = s->n;
   s->n->p = ptr;
   if (pos == count) {
      last = ptr;
   }
   count--;
   free(s);
}
void listNode::update() {
	Nhanvien b;
   int i, pos;
     if (start == last && start == NULL) {
      cout<<"Danh sach rong!"<<endl;
      return;
   }
   cout<<endl<<"Nhap vi tri can sua";
   cin>>pos;
   cout<<"Nhap thong tin nhan vien can them: "<<endl;
	b.Nhap();
   node *s;
   s = start;
   if (pos == 1) {
      s->a = b;
      return;
   }
   for (i=0;i < pos - 1;i++) {
      s = s->n;
   }
   s->a = b;
}
void listNode::search(){
	Nhanvien max;
	node *s = start;
	max=s->a;
  for (int i = 0;i < count;i++) {
  		s = s->n;
  		Nhanvien b=s->a;
      if (max.getLuong()>b.getLuong()) {
      	max=b;
      }
   }
   cout<<"Nhan vien luong thap nhat la: "<<endl;
   max.Xuat();
}
void listNode::display() {
   int i;
   node *s;
   if (start == last && start == NULL) {
      cout<<"The List is empty, nothing to display"<<endl;
      return;
   }
   s = start;
   for (i = 0;i < count-1;i++) {
   	Nhanvien b;
    b = s->a;
    b.Xuat();
    s = s->n;
   }
   Nhanvien c=s->a;
   c.Xuat();
}

 
