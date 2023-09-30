#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>


bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


int* removePrimes(int* arr, int& size) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    int* newArr = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;

    size = newSize;
    return newArr;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* dynamicArray = new int[size];

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = std::rand() % 100 + 1;
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    dynamicArray = removePrimes(dynamicArray, size);

    std::cout << "Массив после удаления простых чисел: ";
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] dynamicArray;

    return 0;
}
