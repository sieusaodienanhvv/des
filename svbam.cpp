#include<iostream>
using namespace std;

int hashTable[21];
int hashTableSize = 21;
string hashtable[21];

class sv{
    private:
        string ten;
        int msv3so;
    public:
        friend void nhapsv(int &n, sv a[]);
        friend void insert(int n, sv a[]);
        friend void search(int n, sv a[]);
        friend void xuat(int n, sv a[]);
};

void nhapsv(int &n, sv a[]){
   cin>>n;
   for(int i=0; i<n; i++){
      cout<<"nhap ten:";
      cin.ignore();
      getline(cin, a[i].ten);
      cout<<"msv";
      cin>>a[i].msv3so;
   }
}
int hashFunc(int s){
   return s%5;
}
void insert(int n, sv a[])
{
   for(int i=0; i<n; i++){
      int index = hashFunc(a[i].msv3so);
      while(hashTable[index] != 0)
         index = (index + 1) % hashTableSize;
      hashTable[index] = a[i].msv3so;
      hashtable[index] = a[i].ten;
    }
}
void search(int n, sv a[])
{
   int x, dem;
   cin>>x;
   int index = hashFunc(x);
   while(hashTable[index] != x and hashTable[index] != 0)
      index = (index + 1) % hashTableSize;
   for(int i=0; i<n; i++){
      if(hashTable[index] == x){
         cout << x << " co sinh vien nay" << endl;
         break;
      }
      else{
         cout << x << " khong co sinh vien nay" << endl;
         break;
      }
         
   }
}
void xuat(int n, sv a[]){
   for(int i=0; i<9*n; i++){
      cout<<i<<" "<<hashTable[i]<<" "<<hashtable[i]<<endl;
   }
}
int main(){
   int n ;
   sv a[100];
   nhapsv(n ,a);
   insert(n, a);
   xuat(n, a);
   search(n ,a);
   return 0;
}