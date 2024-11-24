#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Функція для заповнення матриці випадковими числами
void fillMatrix(vector<vector<double>>& matrix, int minVal = -5, int maxVal = 5) {
    for (auto& row : matrix) {
        for (auto& elem : row) {
            elem = rand() % (maxVal - minVal + 1) + minVal;
        }
    }
}

// Функція для виведення матриці
template <typename T>
void printMatrix(const vector<vector<T>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << setw(5) << elem << " ";
        }
        cout << endl;
    }
}

// Завдання 1
void task1(const vector<vector<double>>& A) {
    int n = A.size();
    int m = A[0].size();

    // Транспонована матриця
    vector<vector<double>> AT(m, vector<double>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            AT[j][i] = A[i][j];

    cout << "Транспонована матриця:\n";
    printMatrix(AT);

    // Матриця A, де кожен елемент збільшено в 10 разів
    vector<vector<double>> A10 = A;
    for (auto& row : A10)
        for (auto& elem : row)
            elem *= 10;

    cout << "Матриця зі збільшеними в 10 разів елементами:\n";
    printMatrix(A10);
}

// Завдання 2
void task2(vector<vector<double>>& A) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                A[i][j] *= 5;
            }
            else if (i < j) {
                A[i][j] = 0;
            }
            else {
                A[i][j] = abs(A[i][j]);
            }
        }
    }

    cout << "Перетворена матриця:\n";
    printMatrix(A);
}

// Завдання 3
void task3(const vector<vector<double>>& A) {
    for (int i = 0; i < A.size(); ++i) {
        double sum = 0;
        for (double elem : A[i]) {
            sum += elem;
        }
        cout << "Середнє значення елементів " << i + 1 << "-го рядка: " << sum / A[i].size() << endl;
    }
}

// Завдання 4
void task4(const vector<vector<double>>& A) {
    int n = A.size();
    double maxDiagElem = 0;

    for (int i = 0; i < n; ++i) {
        maxDiagElem = max(maxDiagElem, abs(A[i][i]));
    }

    vector<vector<double>> B = A;
    for (auto& row : B)
        for (auto& elem : row)
            elem /= maxDiagElem;

    cout << "Нова матриця після ділення:\n";
    printMatrix(B);
}

// Завдання 5
void task5(const vector<vector<double>>& A) {
    int n = A.size();
    double minElem = numeric_limits<double>::max();
    int minRow = -1, minCol = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n - i - 1; ++j) {
            if (A[i][j] < minElem) {
                minElem = A[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    cout << "Мінімальний елемент: " << minElem << " на позиції (" << minRow + 1 << ", " << minCol + 1 << ")\n";
}

// Завдання 6
void task6(vector<vector<double>>& A, int k) {
    int countNeg = 0;
    for (auto& elem : A[k - 1]) {
        if (elem > 0)
            elem = 1;
        else if (elem < 0) {
            elem = -1;
            ++countNeg;
        }
    }

    cout << "Перетворений рядок " << k << ": ";
    for (double elem : A[k - 1]) {
        cout << elem << " ";
    }
    cout << "\nКількість від'ємних елементів: " << countNeg << endl;
}

// Завдання 7
void task7(const vector<int>& firstRow) {
    vector<vector<int>> A(5, vector<int>(5));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            A[i][j] = pow(firstRow[j], i + 1);
        }
    }

    cout << "Отримана матриця:\n";
    printMatrix(A);
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int choice;
    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Завдання 1\n";
        cout << "2. Завдання 2\n";
        cout << "3. Завдання 3\n";
        cout << "4. Завдання 4\n";
        cout << "5. Завдання 5\n";
        cout << "6. Завдання 6\n";
        cout << "7. Завдання 7\n";
        cout << "0. Вихід\n";
        cout << "Виберіть пункт меню: ";
        cin >> choice;

        if (choice == 0) break;

        int n, m, k;
        switch (choice) {
        case 1:
            cout << "Введіть розміри матриці n та m: ";
            cin >> n >> m;
            {
                vector<vector<double>> A(n, vector<double>(m));
                fillMatrix(A);
                cout << "Початкова матриця:\n";
                printMatrix(A);
                task1(A);
            }
            break;
        case 2:
            cout << "Введіть розмірність квадратної матриці n: ";
            cin >> n;
            {
                vector<vector<double>> A(n, vector<double>(n));
                fillMatrix(A);
                cout << "Початкова матриця:\n";
                printMatrix(A);
                task2(A);
            }
            break;
        case 3:
            cout << "Введіть кількість рядків (n = 5): ";
            n = 5;
            {
                vector<vector<double>> A(n, vector<double>(5));
                fillMatrix(A);
                cout << "Початкова матриця:\n";
                printMatrix(A);
                task3(A);
            }
            break;
        case 4:
            cout << "Введіть розмірність квадратної матриці n: ";
            cin >> n;
            {
                vector<vector<double>> A(n, vector<double>(n));
                fillMatrix(A);
                cout << "Початкова матриця:\n";
                printMatrix(A);
                task4(A);
            }
            break;
        case 5:
            cout << "Введіть розмірність квадратної матриці n: ";
            cin >> n;
            {
                vector<vector<double>> A(n, vector<double>(n));
                fillMatrix(A);
                cout << "Початкова матриця:\n";
                printMatrix(A);
                task5(A);
            }
            break;
        case 6:
            cout << "Введіть розміри матриці n та m і номер рядка k: ";
            cin >> n >> m >> k;
            {
                vector<vector<double>> A(n, vector<double>(m));
                fillMatrix(A);
                cout << "Початкова матриця:\n";
                printMatrix(A);
                task6(A, k);
            }
            break;
        case 7:
            cout << "Введіть 5 чисел для першого рядка: ";
            {
                vector<int> firstRow(5);
                for (int& elem : firstRow) {
                    cin >> elem;
                }
                task7(firstRow);
            }
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    }

    return 0;
}
