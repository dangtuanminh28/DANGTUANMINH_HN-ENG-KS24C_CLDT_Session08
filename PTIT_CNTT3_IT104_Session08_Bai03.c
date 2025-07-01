#include <stdio.h>

// Hàm hoán đổi giá trị 2 biến
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n; i++) {
        swapped = 0;  // Mỗi vòng lặp đặt lại biến swapped
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;  // Có hoán đổi xảy ra
            }
        }
        // Nếu không có hoán đổi nào thì mảng đã sắp xếp xong
        if (swapped == 0) {
            break;
        }
    }
}

// Hàm in mảng
void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    // Kiểm tra hợp lệ
    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 0;
    }

    int arr[n];
    // Nhập mảng
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // In mảng trước khi sắp xếp
    printf("Mang truoc khi sap xep: ");
    printArray(arr, n);

    // Gọi hàm sắp xếp
    bubbleSort(arr, n);

    // In mảng sau khi sắp xếp
    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    return 0;
}