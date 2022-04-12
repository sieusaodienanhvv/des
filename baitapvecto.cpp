#include <iostream>
#include <vector>
using namespace std;

void xuat(vector<int> a){
    for(int i=0; i<a.size(); i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> a;
    int them, n, xoa, thembatki, socanthem, lenght;
    cout<<"nhap so luong phan tu: ";
    cin>>n;
    for(int i=0; i<n; i++){
        a.push_back(i);
    }
    cout<<"mang da cho la: ";
    xuat(a);
    if(a.size()==0){
        cout<<"ham rong."<<endl;
    }
    else
    {
        cout<<"ham co gia tri."<<endl;;
    }
    cout<<"nhap phan tu can them vao cuoi mang: ";
    cin>>them;
    a.push_back(them);
    xuat(a);
    cout<<"nao muon xoa phan tu o vi tri nao: ";
    cin>>xoa;
    a.erase(a.begin() +xoa);
    xuat(a);
    cout<<"nao muon them phan tu o vi tri nao: ";
    cin>>thembatki;
    cout<<"so can them: ";
    cin>>socanthem;
    a.insert(a.begin() + thembatki, socanthem);
    xuat(a);
    cout<<"nhap so phan tu ban muon duyet:";
    cin>>lenght;
    cout<<"duyet "<<lenght<<" phan tu co trong mang: ";
    for(int i=0; i<lenght; i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    cout<<"xoa tai ca phan tu";
    a.clear();
    xuat(a);
    if(a.size()==0){
        cout<<"ham rong."<<endl;
    }
    else
    {
        cout<<"ham co gia tri."<<endl;;
    }
    
    return 0;
}