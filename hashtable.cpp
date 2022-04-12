#include<iostream>
using namespace std;

int hashTable[21];
int hashTableSize = 21;



void nhap(int &n, int a[]){
   cin>>n;
   for(int i=0; i<n; i++){
      cin>>a[i];
   }
}
int hashFunc(int s){
   return s%5;
}
void insert(int n, int a[])
{
   for(int i=0; i<n; i++){
      int index = hashFunc(a[i]);
      while(hashTable[index] != 0)
         index = (index + 1) % hashTableSize;
      hashTable[index] = a[i];
   }
}
void search(int n, int a[])
{
   int x, dem;
   cin>>x;
   int index = hashFunc(x);
   while(hashTable[index] != x && hashTable[index] != 0)
      index = (index + 1) % hashTableSize;
   for(int i=0; i<n; i++){
      if(hashTable[index] == x){
         cout << x << " is found!" << endl;
         break;
      }
      else{
         cout << x << " is not found!" << endl;
         break;
      }
   }
}
void xuat(int n, int a[]){
   for(int i=0; i<2*n; i++){
      cout<<i<<" "<<hashTable[i]<<endl;
   }
}
int main(){
   int n ,a[100];
   nhap(n ,a);
   insert(n, a);
   xuat(n, a);
   search(n ,a);
   return 0;
}