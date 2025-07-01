#include <stdio.h>

#define MAX 1000

// Hàm sắp xếp chèn
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];     // phần tử cần chèn
        int j = i - 1;
        // Dời các phần tử lớn hơn key sang phải
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Chèn key vào đúng vị trí
        arr[j + 1] = key;
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

    // B1: Nhập số lượng phần tử
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    // Kiểm tra điều kiện hợp lệ
    if (n <= 0 || n >= MAX) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    // B2: Nhập các phần tử
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // B3: Gọi hàm sắp xếp
    insertionSort(arr, n);

    // B4: In kết quả
    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    return 0;
}