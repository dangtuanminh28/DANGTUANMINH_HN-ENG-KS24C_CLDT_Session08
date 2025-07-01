#include <stdio.h>

//Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) { // Duyệt từng phần tử từ vị trí thứ 1 đến hết mảng
        int temp = arr[i];        // Lưu giá trị tại vị trí i vào biến tạm
        int j = i - 1;
        // Di chuyển các phần tử lớn hơn temp sang phải
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];  // Dời phần tử sang phải
            j--;
        }
        arr[j + 1] = temp;        // Chèn temp vào đúng vị trí đã tìm được
    }
}

// Hàm in mảng ra màn hình
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Nhập số lượng phần tử mảng
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    int arr[n];
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    // In mảng sau khi sắp xếp
    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    return 0;
}