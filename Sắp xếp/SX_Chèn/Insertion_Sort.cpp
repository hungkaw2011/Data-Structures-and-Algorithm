#include <iostream>
using namespace std;

// thuật toán sắp xếp chèn
template<class T> void insertionSort(T* arr, int size) {
    for (int i = 1; i < size; i++)
    {
        T target = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > target) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = target;
    }
}

template<class T> void showArrayElements(T* arr, size_t size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[] = { 1, 8, 5, 3, 2, 4, 7, 9, 6, 3 };
    float grades[] = { 1.5f, 8.5f, 5.15f, 3.25f, 2.75f, 4.68f, 7.39f, 9.05f, 6.41f, 3.14f };
    string names[] = { "Thanh", "Mai", "Nam", "Huong", "Oanh", "Loan", "Khanh", "Anh", "Phong" };
    cout << "Truoc khi sap xep: \n";
    showArrayElements(numbers, 10);
    showArrayElements(grades, 10);
    showArrayElements(names, 9);
    // sap xep
    insertionSort(numbers, 10);
    insertionSort(grades, 10);
    insertionSort(names, 9);
    cout << "Sau khi sap xep: \n";
    showArrayElements(numbers, 10);
    showArrayElements(grades, 10);
    showArrayElements(names, 9);

    return 0;
}