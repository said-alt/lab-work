#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    int M, N;
    std::cout << "Введите размеры массивов A и B: ";
    std::cin >> M >> N;

    std::vector<int> A(M);
    std::vector<int> B(N);

   
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int& elem : A) {
        elem = std::rand() % 100 + 1;
    }
    for (int& elem : B) {
        elem = std::rand() % 100 + 1;
    }

    std::cout << "Массив A: ";
    for (int elem : A) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив B: ";
    for (int elem : B) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::set<int> A_set(A.begin(), A.end());
    std::set<int> B_set(B.begin(), B.end());

    std::vector<int> result;

    for (int elem : A_set) {
        if (B_set.find(elem) == B_set.end()) {
            result.push_back(elem);
        }
    }

    for (int elem : B_set) {
        if (A_set.find(elem) == A_set.end()) {
            result.push_back(elem);
        }
    }

    std::cout << "Элементы, которые не являются общими для A и B: ";
    for (int elem : result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

