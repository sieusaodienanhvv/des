#include<stdio.h>
#include<string.h>


typedef struct hocsinh
{
    char tenhs[20];
    float diemly;
    float diemhoa;
    float diemtoan;
};

void nhapsoluong(int &soluong);
void nhap(hocsinh hs[]);
void nhaphs(hocsinh hs[], int soluong);
void xuat(hocsinh hs[]);
void xuaths(hocsinh hs[], int soluong);


int main()
{
    int soluong;
    hocsinh hs[100];
    nhapsoluong(soluong);
    nhaphs(hs,soluong);
    xuaths(hs,soluong);
    return 0;
}

void nhapsoluong(int &soluong)
{
    printf("\nnhap so luong hoc sinh:");
    scanf("%d",&soluong);
}

void nhap(hocsinh &hs)
{
    printf("\nnhap ten hoc sinh:");
    fflush(stdin);
    gets(hs.tenhs);
    printf("\nnhap diem thi mon toan:");
    scanf("%f",&hs.diemtoan);
    printf("\nnhap diem thi mon hoa:");
    scanf("%f",&hs.diemhoa);
    printf("\nnhap diem thi mon ly:");
    scanf("%f",&hs.diemly);
}

void nhaphs(hocsinh hs[], int soluong)
{
    for(int i=0; i<soluong; i++)
    {
        printf("\nnhap du lieu hoc sinh thu: %d",i+1);
        nhap(hs[i]);
    }
}

void xuat(hocsinh hs)
{
    printf("\nten cua sinh vien la:%s", hs.tenhs);
    printf("\ndiem thi mon toan la:%.2f", hs.diemtoan);
    printf("\ndiem thi mon hoa la:%.2f",hs.diemhoa);
    printf("\ndiem thi cua mon ly la:%.2f",hs.diemly);
}

void xuaths(hocsinh hs[], int soluong)
{
    for(int i=0; i<soluong; i++)
    {
        printf("\ndu lieu cua hoc sinh thu: %d",i+1);
        xuat(hs[i]);
    }
}


void timkiemten(hocsinh *hs, int soluong)
{
    char nhaptencantim[20];
    fflush(stdin);
    printf("\nnhap sinh vien can tim:");
    gets(nhaptencantim);
    for(int i=0; i<soluong; i++)
    {
        if(strcmp(nhaptencantim,(hs+i)->tenhs)==0)
        {
            printf("\nten ban moi nhap co trong danh sach");
        }
    }
}