#include<stdio.h>
#include<stdlib.h>


typedef struct hocsinh
{
    char tenHS[20];
    float diemhoa;
    float diemly;
    float diemtoan;
    float diemtrungbinh;
};

void nhapsoluong(int &soluong);
void nhap(hocsinh *hs);
void nhaphs(hocsinh *hs, int soluong);
void xuat(hocsinh *hs);
void xuaths(hocsinh *hs, int soluong);
float diemTrungBinh(hocsinh *hs);
void sapxephstheodiemtrungbinh(hocsinh *hs, int soluong);
int timkiemdiemmax(hocsinh *hs, int soluong);
void xuathsdiemcaonhat(hocsinh *hs, int soluong);

int main()
{
    int soluong;
    hocsinh *hs=(hocsinh*) malloc(soluong*sizeof(hocsinh));
    nhapsoluong(soluong);
    nhaphs(hs, soluong);
    diemTrungBinh(hs);
    sapxephstheodiemtrungbinh(hs,soluong);
    xuaths(hs, soluong);
    xuathsdiemcaonhat(hs,soluong);
    free(hs);
    return 0;
}

void nhapsoluong(int &soluong)
{
    printf("\nnhap so luong sinh vien:");
    scanf("%d",&soluong);
}

void nhap(hocsinh *hs)
{
    fflush(stdin);
    printf("\nnhap ten sinh vien:");
    gets(hs->tenHS);
    printf("\nnhap diem thi:");
    printf("\nnhap diem mon toan:");
    scanf("%f",&hs->diemtoan);
    printf("\nnhap diem mon ly:");
    scanf("%f",&hs->diemly);
    printf("\nnhap diem mon hoa:");
    scanf("%f",&hs->diemhoa);
}
void nhaphs(hocsinh *hs, int soluong)
{
    for(int i=0; i<soluong; i++)
    {
        printf("\nnhap sinh vien thu: %d",i+1);
        nhap(hs+i);
    }
}
void xuat(hocsinh *hs)
{
    printf("\nten cua sinh vien la:%s",hs->tenHS);
    printf("\ndiem thi cua sinh vien:");
    printf("\ndiem thi mon toan la: %.2f",hs->diemtoan);
    printf("\ndiem mon ly la: %.2f",hs->diemly);
    printf("\ndiem thi mon hoa la: %.2f",hs->diemhoa);
    printf("\ndiem trung binh la: %.2f",diemTrungBinh(hs));
}
void xuaths(hocsinh *hs, int soluong)
{
    for(int i=0; i<soluong; i++)
    {
        printf("\ndiem cua sinh vien thu: %d", i+1);
        xuat(hs+i);
    }
}
float diemTrungBinh(hocsinh *hs)
{
    hs->diemtrungbinh=(hs->diemtoan+hs->diemly+hs->diemhoa)/3;
    return hs->diemtrungbinh;
}
void sapxephstheodiemtrungbinh(hocsinh *hs, int soluong)
{
    for(int i=0; i<soluong-1; i++)
    {
        for(int j=i+1; j<soluong; j++)
        {
            if((hs+i)->diemtrungbinh>(hs+j)->diemtrungbinh)
            {
                hocsinh diem = *(hs+i);
                *(hs+i) = *(hs+j);
                *(hs+j) = diem;
            }
        }
    }
}
int timkiemdiemmax(hocsinh *hs, int soluong)
{
    float diemTB = 0;
    for(int i=0; i<soluong; i++)
    {
        if(diemTB<diemTrungBinh(hs+i))
        {
            diemTB =  diemTrungBinh(hs+i);   
        }
    }
    return diemTB;
}
void xuathsdiemcaonhat(hocsinh *hs, int soluong)
{
    float max=timkiemdiemmax(hs, soluong);
    for(int i=0; i<soluong; i++)
    {
        if(max==(hs+i)->diemtrungbinh)
        {
            printf("\nhoc sinh co diem cao nhat ten la:%s",(hs+i)->tenHS);
        }
    }
}

