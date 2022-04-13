#include <iostream>
using namespace std;

template<class T> void selectionSort(T* arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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
    selectionSort(numbers, 10);
    selectionSort(grades, 10);
    selectionSort(names, 9);
    cout << "Sau khi sap xep: \n";
    showArrayElements(numbers, 10);
    showArrayElements(grades, 10);
    showArrayElements(names, 9);
    return 0;
}