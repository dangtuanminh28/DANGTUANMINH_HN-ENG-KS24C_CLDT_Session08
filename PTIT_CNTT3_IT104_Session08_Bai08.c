#include <stdio.h>

//Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

//Linear Search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

//Binary Search
int binarySearch(int arr[], int left, int right, int x) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] < x) return binarySearch(arr, mid + 1, right, x);
    return binarySearch(arr, left, mid - 1, x);
}

// In mảng
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

    // Nhập số lượng phần tử với kiểm tra hợp lệ
    do {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
        if (n <= 0 || n > 1000) {
            printf("So luong phan tu khong hop le!\n");
        }
    } while (n <= 0 || n > 1000);

    int arr[n];

    // Nhập các phần tử
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang truoc khi sap xep: ");
    printArray(arr, n);

    // Nhập giá trị cần tìm
    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    // Tìm tuyến tính
    int valueLinear = linearSearch(arr, n, x);

    // Sắp xếp rồi tìm nhị phân
    insertionSort(arr, n);
    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    int valueBinary = binarySearch(arr, 0, n - 1, x);

    // In kết quả
    printf("Ket qua tim kiem:\n");

    if (valueLinear != -1)
        printf("Tuyen tinh: Tim thay %d tai vi tri thu %d\n", x, valueLinear + 1);
    else
        printf("Tuyen tinh: Khong tim thay %d\n", x);

    if (valueBinary != -1)
        printf("Nhi phan: Tim thay %d tai vi tri thu %d\n", x, valueBinary + 1);
    else
        printf("Nhi phan: Khong tim thay %d\n", x);

    return 0;
}