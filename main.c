#include <stdio.h>
#include <conio.h>


void NhapMang(float a[], int *n) {
    int i;
    printf("Nhap n = ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Nhap a[%d]: ", i+1);
        scanf("%f", &a[i]);
    }
}

void XuatMang(float a[], int n) {
    printf("Cac phan tu co trong mang la:\n");
    int i;
    for(i=0; i<n; i++) {
        printf("a[%d] = %.2f\n", i+1, a[i]);
    }
}

void Search (float A[], int n, float x) {

    for (int i = 0; i < n; i++)
        if (A[i] == x) printf("A[%d] = %.2f", i, x);
}

void Max_Min(float a[], int n, float *Max, float *Min) {
    for (int i = 1; i < n; i++) {
        if (*Max < a[i]) *Max = a[i];
        if (*Min > a[i]) *Min = a[i];
    }

}

float Tinhtong (float A[], int n, float x)
{
    float tong;
    for (int i = 0; i < n; i++)
        if (A[i] > x) tong += A[i];
    return tong;
}

void Sorting(float A[], int n) {
    float temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i+1; j < n; j++)
            if (A[i] > A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
}

int main() {
    int n, choose;
    float Max, Min;
    float a[100], x;
   /* do {
        printf("Nhap n (1<n<101): ");
        scanf("%d",&n);
    } while(n<2 || n>100); */
    NhapMang(a, &n);
    XuatMang(a, n);

    do
    {

        printf("1. Tim kiem phan tu co gia tri bang x \n");
        printf("2. Tim max, min \n");
        printf("3. Tinh tong cac phan tu lon hon so x cho truoc \n");
        printf("4. Sap xep cac phan tu trong mang \n");
        printf("5. Exit \n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("Nhap x = ");
            scanf("%f", &x);
            Search(a, n, x);
            break;
        case 2:
            Max = a[0];
            Min = a[0];
            Max_Min(a, n, &Max, &Min);
            printf("Max = %.2f  Min = %.2f", Max, Min);
            break;
        case 3:
            printf("Nhap x = ");
            scanf("%f", &x);
            printf("Tong cac phan tu lon hon %.2f la: %.2f ", x, Tinhtong(a, n, x));
            break;
        case 4:
            Sorting(a, n);
            XuatMang(a, n);
            break;
        case 5: break;
        default: printf("Vui long chon lai");

        }
        getch();
        system("cls");
        } while (choose != 5);
    return 0;
}
