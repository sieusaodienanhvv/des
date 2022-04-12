#include <iostream>
using namespace std;

int hashtable[100];

void nhap(int &n, int a[]){
    do{
        cout<<"nhap n:";
        cin>>n;
    }while(n>3);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
int hambam(int x){
    return(x%5);
}
//chi dung khi cac so du cua cac so nhap khac nhau
void khoitao(int n,int a[]) {
  for (int i = 0; i < 2*n; i++){
    int index = hambam(a[i]);
    for(int j=0; j< 2*n; j++){
        if(index==j){
            hashtable[index]=j;
        }
    }
  }
  for (int i = 0; i < 2*n; i++)
    cout << i << " " << hashtable[i] << endl;
}


int main(){
    int n, a[100];
    nhap(n,a);
    khoitao(n,a);
}