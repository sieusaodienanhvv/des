#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iomanip>


using namespace std;
int count = 0;
class staff{
	private:
		string ID;
		string fullname;
		string position;
		string birthday;
		string pay;
	public:
		friend class node;
		friend class danhsach;
};
class node {
	private:
	    staff data;
		node *next;
	    node *previous;
    public:
    	friend class danhsach;
};
class danhsach {
	private:
		node *head, *last;
    public:
      node *create_node(staff);
      void add_staff_head();
      void add_staff_last();
      void add_staff_at();
      void remove_staff_at();
      void update_staff_at();
      void show_list();
      danhsach();
      ~danhsach();
      
};
int main() {
   int chon;
   danhsach m;
   system("color b");
   while (1) //perform switch operation 
   {
	   cout << setfill('>') << setw(10) << (' ') << "EMPLOYEE MANAGEMENT SYSTEM" << (' ') << setfill('<') << setw(10) << ('<');
	  cout << "\n" << "\n";
	  cout <<setfill('-') << setw(47) << ('-') << "\n";
      cout << "Enter" << setfill(' ') << setw(5) << (' ') << "1:" << setw(4) << (' ') << "To Add staff at head" << "\n";
	  cout <<setfill('-') << setw(47) << ('-') << "\n";
      cout << "Enter" << setfill(' ') << setw(5) << (' ') << "2:" << setw(4) << (' ') << "To Add staff at last" << "\n";
      cout <<setfill('-') << setw(47) << ('-') << "\n";
      cout << "Enter" << setfill(' ') << setw(5) << (' ') << "3:" << setw(4) << (' ') << "To Add staff after position" << "\n";
      cout <<setfill('-') << setw(47) << ('-') << "\n";
      cout << "Enter" << setfill(' ') << setw(5) << (' ') << "4:" << setw(4) << (' ') << "To Remove staff" << "\n";
      cout <<setfill('-') << setw(47) << ('-') << "\n";
      cout << "Enter" << setfill(' ') << setw(5) << (' ') << "5:" << setw(4) << (' ') << "To Update staff" << "\n";
      cout <<setfill('-') << setw(47) << ('-') << "\n";
      cout << "Enter" << setfill(' ') << setw(5) << (' ') << "6:" << setw(4) << (' ') << "To view list of staff" << "\n";
      cout <<setfill('-') << setw(47) << ('-') << "\n";	
      cout << "Enter" << setfill(' ') << setw(5) << (' ') << "0:" << setw(4) << (' ') << "To Exit" << "\n" ;
      cout <<setfill('-') << setw(47) << ('-') << "\n";
      cout << "Enter Your Choice: ";
      cin >> chon;
      system("cls");
      switch(chon) {
         case 1:
			m.add_staff_head();
			cout << setfill(' ') << setw(10) << (' ') <<"ENTER TO BACK MENU";
			cin.get();
			system("cls");
        	 break;
         case 2:
		 	m.add_staff_last();
			 cout << setfill(' ') << setw(10) << (' ') <<"ENTER TO BACK MENU";
			 cin.get();
			 system("cls");
        	 break;
         case 3:
		 	m.add_staff_at();
			 cin.get();
			 system("cls");
        	 break;
         case 4:
		 	m.remove_staff_at();
			 cin.get();
			 system("cls");
        	 break;
         case 5:
            m.update_staff_at();
            cin.get();
			system("cls");
        	 break;
         case 6:
            m.show_list();
            cin.get();
               system("cls");
         	break;
         case 0:
         	cout << "\n\n";
            cout <<  setfill(' ') << setw(5) << (' ') << "Thank for using my program! <3" << "\n";
            cout <<  setfill(' ') << setw(9) << (' ') << "See u next time :D" << "\n";
            exit(1);
         default:
            cout << "Chon lai ban oi :(" << endl;

      }
   }
   return 0;
}
danhsach::danhsach(){
	head = NULL;
    last = NULL;
}
danhsach::~danhsach(){
	cout << " List was delete " << "\n";
};
node* danhsach::create_node(staff v) {
   count++;
   node *t;
   t = new node;
   t->data = v;
   t->next = NULL;
   t->previous = NULL;
   return t;
}
void danhsach::add_staff_head() {
   staff a;
   fflush(stdin);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "HO VA TEN" << setfill(' ') << setw(2) << (' ') << ":";
   getline(cin,a.fullname);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "ID" << setfill(' ') << setw(9) << (' ') << ":" ;
   getline(cin,a.ID);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "NGAY SINH:" << setfill(' ') << setw(1) << (' ') << ":";
   getline(cin,a.birthday);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "CHUC VU:" << setfill(' ') << setw(3) << (' ') << ":";
   getline(cin,a.position);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "LUONG:" << setfill(' ') << setw(5) << (' ') << ":";
   getline(cin,a.pay);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
	node *t = create_node(a);
   if (head == last && head == NULL) {
	  	cout << "\n**LAN DAU THEM THONG TIN THANH CONG**\n";
		  head = last = t;
     	 head->next = last->next = NULL;
    	  head->previous = last->previous = NULL;
   } else {
		t->next = head;
		head->previous = t;
		head = t;
		head->previous = last;
		last->next = head;
		cout << "\n";
		cout << setfill(' ') << setw(9) << (' ') << "**THEM THANH CONG**" << "\n";
   }
}
void danhsach::add_staff_last() {
   staff a;
   fflush(stdin);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "HO VA TEN" << setfill(' ') << setw(2) << (' ') << ":";
   getline(cin,a.fullname);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "ID" << setfill(' ') << setw(9) << (' ') << ":" ;
   getline(cin,a.ID);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "NGAY SINH:" << setfill(' ') << setw(1) << (' ') << ":";
   getline(cin,a.birthday);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "CHUC VU:" << setfill(' ') << setw(3) << (' ') << ":";
   getline(cin,a.position);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "LUONG:" << setfill(' ') << setw(5) << (' ') << ":";
   getline(cin,a.pay);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   fflush(stdin);
   node *t;
   t = create_node(a);
   if (head == last && head == NULL) {
   		cout << "\n**LAN DAU THEM THONG TIN THANH CONG**" << "\n";
     	 head = last = t;
		head->next= last->next = NULL;
		head->previous = last->previous= NULL;
   } else {
		last->next = t;
		t->previous = last;
		last = t;
		head->previous = last;
		last->next= head;
		cout << "\n";
		cout << setfill(' ') << setw(9) << (' ') << "**THEM THANH CONG**" << "\n";
   }
}
void danhsach::add_staff_at() {
   staff a;
   int at;
	cout << "THEM THONG TIN NHAN VIEN SAU STT:";
	cin >> at;
	system("cls");
   node* t = create_node(a);
	 if(head == last && head == NULL){
		 cout << "\nDANH SACH TRONG BAN OI :(\n";
         head = last = t;
         head->next = last->next = NULL;
         head->previous = last->previous = NULL;
         cout << "ENTER CUMBACK NAO";
         cin.get();
         return;
      }
    if (count < at) {
   		cout << setfill(' ') << setw(9) << (' ') << "choi vay la khong duoc roi :(" << "\n";
   		cout << setfill(' ') << setw(11) << (' ') <<"ENTER TO COMEBACK NAO Ban";
   		cin.get();
   		count--;
      }
	 else {
	fflush(stdin);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "HO VA TEN" << setfill(' ') << setw(2) << (' ') << ":";
   getline(cin,a.fullname);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "ID" << setfill(' ') << setw(9) << (' ') << ":" ;
   getline(cin,a.ID);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "NGAY SINH:" << setfill(' ') << setw(1) << (' ') << ":";
   getline(cin,a.birthday);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "CHUC VU:" << setfill(' ') << setw(3) << (' ') << ":";
   getline(cin,a.position);
   cout <<setfill('-') << setw(40) << ('-') << "\n";
   cout << "LUONG:" << setfill(' ') << setw(5) << (' ') << ":";
   getline(cin,a.pay);
   cout <<setfill('-') << setw(40) << ('-') << "\n"; 
      	int count = 0;
		node* z = head;
      while(count != at-1) {
      	count++;
         z = z->next;
		 }
		 node* ptr;
            ptr->next = t;
            t->previous= ptr;
            t->next= z->next;
            z->previous = t;
            cout << "DA THEM THONG TIN NHAN VIEN SAU STT: " << at << endl;
         }
      }
void danhsach::remove_staff_at() {
   int at;
   if (head == last && head == NULL) {
		cout << "Nothing to remove :(" << "\n";
		return;
   }
     cout << "Xoa thong tin nhan vien tai vi tri:";
   	cin >> at;
   if (count < at) {
      cout<<"choi vay la khong duoc nha :("<<"\n";
      return;
   }
   node* t = head;
   if(at == 1) {
	count--;
	 cout << "XOA THONG TIN NHAN VIEN SAU STT:" << at << "\n";
	 last = t;
	 t = NULL;
	 cout << "Xoa thong tin thanh cong" << "\n" ;
	   }
   if(head != last && head != NULL) {
      count--;
      int count = 1;
		cout << "Thuc hien xoa thong tin nhan vien tai vi tri:" << at << "\n";
		while(count != at-1){
		count++;
		t = t->next;
		}
		last->next = t->next;
		t->next->previous = last;
		head = t->next;
		delete t;
		cout << "Xoa thong tin thanh cong" << "\n" ;
   	}
}
void danhsach::update_staff_at() {
   staff a;
   int at;
    cout<<"\n"<<"CAP NHAP THONG TIN NHAN VIEN TAI VI TRI: ";
	cin >> at;
    system("cls");
   if (head == last && head == NULL) {
      cout << setfill(' ') << setw(9) << (' ') << "Danh sach dang trong ban oi :( them xong roi quay lai con kip xem battle rap" << "\n";
      cout << setfill(' ') << setw(30) << (' ') << "ENTER TO QUAY LAI BAN GI OI";
      cin.get();
   }
     else if (count < at) {
     cout << "\n";
      cout << setfill(' ') << setw(15) << (' ') << "Quay ban nhay the :( an cho dung coi nao" << "\n";
      cout << setfill(' ') << setw(9) << (' ') << "ENTER To QUAY LAI NAO BAN GI Oi";
      cin.get();
   }
   else{
    fflush(stdin);
cout <<setfill('-') << setw(30) << ('-') << "\n";
   cout << "HO VA TEN" << setfill(' ') << setw(2) << (' ') << ":";
   getline(cin,a.fullname);
   cout <<setfill('-') << setw(30) << ('-') << "\n";
   cout << "ID" << setfill(' ') << setw(9) << (' ') << ":" ;
   getline(cin,a.ID);
   cout <<setfill('-') << setw(30) << ('-') << "\n";
   cout << "NGAY SINH:" << setfill(' ') << setw(1) << (' ') << ":";
   getline(cin,a.birthday);
   cout <<setfill('-') << setw(30) << ('-') << "\n";
   cout << "CHUC VU:" << setfill(' ') << setw(3) << (' ') << ":";
   getline(cin,a.position);
   cout <<setfill('-') << setw(30) << ('-') << "\n";
   cout << "LUONG:" << setfill(' ') << setw(5) << (' ') << ":";
   getline(cin,a.pay);
   cout <<setfill('-') << setw(30) << ('-') << "\n";
   }
   
 
   node *s = head;
   if (head != last && head != NULL) {
   		int count = 0;
   		while(count != at){
			count++;
			s = s->next;
		   }
      s->data = a;
      cout<<"Cap nhap thong tin thanh cong"<<endl;
   }
}

void danhsach::show_list(){
  	int dem = 0;
	node *s = head;
	cout << setfill(' ') << setw(10) << ' ' << "DANH SACH NHAN VIEN " << "\n";
	for(int i=0;i <=count-1;i++){
	 dem++;
	 cout << "|STT:" << dem <<" ";
	 cout << "ID:" << s->data.ID << " ";
	 cout << "Ten nhan vien:" << s->data.fullname << " ";
	 cout << "Ngay sinh:" << s->data.birthday << " ";
	 cout << "Chuc vu:" << s->data.position <<" ";
	 cout << "Luong:" << s->data.pay <<" VND| --->\n";
		s = s->next;
	}
	cout << "\n";
	cin.get();
}
