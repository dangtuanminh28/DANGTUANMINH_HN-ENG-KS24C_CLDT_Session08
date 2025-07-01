#include <stdio.h>

#define MAX_LENGTH 1000

// Hàm nhập số lượng phần tử của mảng (đảm bảo điều kiện hợp lệ)
int inputSize() {
    int n;
    do {
        printf("Nhap so luong phan tu cua mang: ");
        scanf("%d", &n);
        if (n <= 0 || n >= MAX_LENGTH) {
            printf("So luong khong hop le. Vui long nhap lai!\n");
        }
    } while (n <= 0 || n >= MAX_LENGTH);
    return n;
}

// Hàm nhập các phần tử vào mảng
void inputArray(int arr[], int totalElement) {
    for (int i = 0; i < totalElement; i++) {
        printf("Nhap phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

// Hàm in mảng ra màn hình
void printArray(int arr[], int totalElement) {
    printf("Mang: ");
    for (int i = 0; i < totalElement; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm nhập giá trị cần tìm
int inputSearchValue() {
    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    return value;
}

// Hàm tìm kiếm tuyến tính
int linearSearch(int arr[], int totalElement, int elementSearch) {
    for (int i = 0; i < totalElement; i++) {
        if (arr[i] == elementSearch) {
            return i; // Trả về chỉ số nếu tìm thấy
        }
    }
    return -1; // Không tìm thấy
}

// Hàm chính
int main() {
    int arr[MAX_LENGTH];
    int n = inputSize(); // Nhập số lượng phần tử
    inputArray(arr, n);  // Nhập giá trị vào mảng

    printf("Mang vua nhap la:\n");
    printArray(arr, n);  // In ra mảng

    int elementSearch = inputSearchValue(); // Nhập phần tử cần tìm
    int result = linearSearch(arr, n, elementSearch); // Gọi hàm tìm kiếm

    if (result != -1) {
        printf("Vi tri thu %d\n", result + 1);
    } else {
        printf("Khong ton tai phan tu\n");
    }

    return 0;
}