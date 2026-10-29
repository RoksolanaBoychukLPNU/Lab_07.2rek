#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// рекурсивно формує рядок rowNo; colNo - номер поточного стовпчика
void CreateRow(int** a, const int rowNo, const int n, const int Low,
    const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

// рекурсивно формує всі рядки матриці
void CreateRows(int** a, const int k, const int n, const int Low,
    const int High, int rowNo)
{
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < k - 1)
        CreateRows(a, k, n, Low, High, rowNo + 1);
}

// рекурсивно виводить рядок rowNo
void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
    cout << setw(5) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << endl;
}

// рекурсивно виводить усі рядки матриці
void PrintRows(int** a, const int k, const int n, int rowNo)
{
    PrintRow(a, rowNo, n, 0);
    if (rowNo < k - 1)
        PrintRows(a, k, n, rowNo + 1);
    else
        cout << endl;
}

// рекурсивно шукає максимальний елемент рядка rowNo;
// colNo - номер поточного стовпчика, max - максимум серед переглянутих
int MaxInRow(int** a, const int rowNo, const int n, int colNo, int max)
{
    if (colNo == n)
        return max;
    if (a[rowNo][colNo] > max)
        max = a[rowNo][colNo];
    return MaxInRow(a, rowNo, n, colNo + 1, max);
}

// рекурсивно шукає суму максимальних елементів рядків rowNo, rowNo+1, ..., k-1
int SumRowMax(int** a, const int k, const int n, int rowNo)
{
    if (rowNo < k)
        return MaxInRow(a, rowNo, n, 1, a[rowNo][0]) + SumRowMax(a, k, n, rowNo + 1);
    else
        return 0;
}

int main()
{
    srand((unsigned)time(NULL));

    int Low = -50;          // нижня межа діапазону значень
    int High = 50;          // верхня межа діапазону значень

    int k, n;               // k - кількість рядків, n - кількість стовпчиків
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;
    cout << endl;

    int** a = new int* [k];  // динамічна матриця k x n
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    CreateRows(a, k, n, Low, High, 0);
    PrintRows(a, k, n, 0);

    for (int i = 0; i < k; i++)
        cout << "max in row " << i << " = " << MaxInRow(a, i, n, 1, a[i][0]) << endl;
    cout << "Sum of row maxima = " << SumRowMax(a, k, n, 0) << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
