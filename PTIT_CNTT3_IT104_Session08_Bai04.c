#include <stdio.h>

#define MAX 1000

// Hoán đổi 2 số nguyên
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Thuật toán sắp xếp chọn (Selection Sort)
void selectionSort(int arr[], int n) {
    int minIndex;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        // Tìm phần tử nhỏ nhất trong đoạn còn lại
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Hoán đổi phần tử nhỏ nhất với arr[i]
        swap(&arr[i], &arr[minIndex]);
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" ]\n");
}

int main() {
    int n;
    int arr[MAX];

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    // Kiểm tra điều kiện hợp lệ
    if (n <= 0 || n >= MAX) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    // Nhập phần tử
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Sắp xếp mảng
    selectionSort(arr, n);

    // In mảng sau khi sắp xếp
    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    return 0;
}