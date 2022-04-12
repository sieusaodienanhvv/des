#include <iostream>
#define MAX 100
using namespace std;


void hoanvi(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void nhapmang(int &n, int a[]){
    cout<<"nhap so luong phan tu:";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }
}
void xuatmang(int n, int a[]){
    cout<<"a[]=";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}
void sapxepchon(int n, int a[]){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]<a[j]){
                hoanvi(a[i],a[j]);
            }
        }
    }
}
void sapxepchen(int n, int a[]){
    int pos, x;
    for(int i=0; i<n; i++){
        x=a[i];
        pos=i-1;
        while((pos>=0)&&(a[pos]<x)){
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1]=x;
    }
}
void sapxepnoibot(int n, int a[]){
    for(int i=0; i<n-1; i++){
        for(int j=n; j>i; j--){
            if(a[i]<a[j-1]){
                hoanvi(a[i], a[j-1]);
            }
        }
    }
}
void sapxepcay(int n, int a[], int i){
    int x = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && a[r] > a[x])
        x=l;
    if(r < n && a[l] > a[x])
        x=r;
    if (x != i){
        int t = a[i];
        a[i]= a[x];
        a[x]=t;
        sapxepcay(n, a, i);
    }
}
void quicksort(int n, int a[], int l, int r){    // chay khong chay duoc
    int x = a[r];
    int left = l;
    int right = r-1;
    while(true){
        while(left <= r && a[left] < x) left++;
        while(left >= l && a[right] > x) right--;
        if (left >= right) break;
        hoanvi(a[left], a[right]);
        left++;
        right--;
    }
    hoanvi(a[left], a[right]);
    if(l < r){
        int b = left;
        quicksort(n, a, l, b-1);
        quicksort(n, a, b+1, r);
    }
}
void sittingheapsort(int n, int a[], int l, int r){
    int x, i, j;
    i = l;
    j= 2*i;
    x=a[i];
    while(j<=r){
        if(j<r)
            if(a[j]<a[j+1])
                j=j+1;
        if(a[j]<x)
            break;
        else{
            a[i]=a[j];
            i=j;
            j=2*i;
            a[i]= x;
        }
    }
}
void heapsort(int n, int a[]){
    int l, r;
    l = n/2;
    while(l>0){
        sittingheapsort(n, a, l, l-1);
        l=l-1;
    }
    while(r<0){
        hoanvi(a[l], a[r]);
        r=r-l;
        sittingheapsort(n, a, r+1, r);
    }
}

int main(){
    int n, a[MAX], i, h[MAX], k, l, r;
    nhapmang(n, a);
    cout<<"mang da nhap la ";
    xuatmang(n, a);
    cout<<endl;
    sapxepchon(n, a);                       //1
    cout<<"mang moi sap xep la ";
    xuatmang(n, a);
    cout<<endl;
    sapxepchen(n, a);                      //2                             
    cout<<"mang moi sap xep la ";
    xuatmang(n, a);
    cout<<endl;
    sapxepnoibot(n, a);                                                 //3 
    cout<<"mang moi sap xep la ";
    xuatmang(n, a);
    cout<<endl;
    sapxepcay(n, a, i);                         //4
    cout<<"mang moi sap xep la ";
    xuatmang(n, a);
    cout<<endl;
    quicksort(n, a, l, r);                          //5
    cout<<"mang moi sap xep la ";
    xuatmang(n, a);
    cout<<endl;
    heapsort(n, a);
    cout<<"mang moi sap xep la ";
    xuatmang(n, a);
    cout<<endl;
    return 0;
}
