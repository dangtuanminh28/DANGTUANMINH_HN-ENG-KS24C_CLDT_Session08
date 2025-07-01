#include <stdio.h>

#define MAX_SIZE 1000

// B4: Nhập mảng
void inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// B5: Sắp xếp nổi bọt
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// B6: Tìm kiếm nhị phân đệ quy
int handleFindNumber(int arr[], int findNumber, int start, int end) {
    if (start > end) {
        return -1; // Không tìm thấy
    }

    int mid = (start + end) / 2;

    if (arr[mid] == findNumber) {
        return mid;
    }

    if (arr[mid] < findNumber) {
        return handleFindNumber(arr, findNumber, mid + 1, end);
    }

    return handleFindNumber(arr, findNumber, start, mid - 1);
}

// In mảng ra màn hình
void printArray(int arr[], int size) {
    printf("Mang: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm chính
int main() {
    int size;
    int arr[MAX_SIZE];
    int findNumber;

    // B1: Nhập số lượng phần tử
    do {
        printf("Nhap so luong phan tu (0 < n < 1000): ");
        scanf("%d", &size);
        if (size <= 0 || size >= MAX_SIZE) {
            printf("So luong khong hop le. Vui long nhap lai!\n");
        }
    } while (size <= 0 || size >= MAX_SIZE);

    // B2: Nhập số cần tìm
    printf("Nhap so can tim: ");
    scanf("%d", &findNumber);

    // B3+B4: Nhập mảng
    inputArray(arr, size);

    // Trước khi sắp xếp
    printf("Truoc khi sap xep:\n");
    printArray(arr, size);

    // B5: Sắp xếp
    bubbleSort(arr, size);

    // Sau khi sắp xếp
    printf("Sau khi sap xep:\n");
    printArray(arr, size);

    // B6: Tìm kiếm nhị phân
    int position = handleFindNumber(arr, findNumber, 0, size - 1);

    // B7: In kết quả
    if (position == -1) {
        printf("Khong ton tai phan tu\n");
    } else {
        printf("Phan tu o vi tri thu %d\n", position + 1);
    }

    return 0;
}