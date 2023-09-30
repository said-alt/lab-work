#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    int M, N;
    std::cout << "Введите размеры массивов A и B: ";
    std::cin >> M >> N;

    std::vector<int> A(M);
    std::vector<int> B(N);


    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < M; i++) {
        A[i] = rand() % 100 + 1;
    }
    for (int i = 0; i < N; i++) {
        B[i] = rand() % 100 + 1;
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

    std::vector<int> result;


    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());


    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(result));

    std::cout << "Общие элементы без повторений: ";
    for (int elem : result) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
