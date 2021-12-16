// Щетинин Дмитрий Олегович Б9120-09.03.02ист.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
#include <omp.h>
#include <chrono>
#include <time.h>


using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "Кол-во потоков:" << omp_get_num_procs();
    const int n = 1000000;
    int* Asgl = new int[n];
    double* Abdl = new double[n];
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        Asgl[i] = rand();
        Abdl[i] = rand();
    }
    unsigned int t;
    // суммируем первый массив 
    t = clock();
    for (int i = 0; i < n; i++)
    {
        sum1 += Asgl[i];
    }
    t = clock() - t;
    cout << "\nВремя затраченное на суммирование первого массива: " << "\t" << t;
    // суммируем второй массив
    t = clock();
    for (int i = 0; i < n; i++)
    {
        sum2 += Abdl[i];
    }
    t = clock() - t;
    sum1 = 0; sum2 = 0;
    cout << "\nВремя затраченное на суммирование второго массива: " << "\t" << t;
    ///
    t = clock();
    #pragma omp parallel shared(Asgl) reduction (+: sum1) num_threads(2)
    {
    #pragma omp for
        for (int i = 0; i < n; ++i)
        {
            sum1 += Asgl[i];
        }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на суммирование первого массива (2 потока): " << "\t" << t;
    ///
    sum1 = 0; sum2 = 0;
    t = clock();
    #pragma omp parallel shared(Asgl) reduction (+: sum2) num_threads(2)
    {
    #pragma omp for
        for (int i = 0; i < n; ++i)
        {
            sum2 += Abdl[i];
        }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на суммирование второго массива (2 потока): " << "\t" << t;
    ///
    t = clock();
    #pragma omp parallel shared(Asgl) reduction (+: sum1) num_threads(4)
    {
    #pragma omp for
        for (int i = 0; i < n; ++i)
        {
            sum1 += Asgl[i];
        }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на суммирование первого массива (4 потока): " << "\t" << t;
    ///
    sum1 = 0; sum2 = 0;
    t = clock();
    #pragma omp parallel shared(Asgl) reduction (+: sum2) num_threads(4)
    {
    #pragma omp for
        for (int i = 0; i < n; ++i)
        {
            sum2 += Abdl[i];
        }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на суммирование второго массива (4 потока): " << "\t" << t;
    ///
    t = clock();
    #pragma omp parallel shared(Asgl) reduction (+: sum1) num_threads(8)
    {
    #pragma omp for
        for (int i = 0; i < n; ++i)
        {
            sum1 += Asgl[i];
        }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на суммирование первого массива (8 потока): " << "\t" << t;
    ///
    sum1 = 0; sum2 = 0;
    t = clock();
    #pragma omp parallel shared(Asgl) reduction (+: sum2) num_threads(8)
    {
    #pragma omp for
        for (int i = 0; i < n; ++i)
        {
            sum2 += Abdl[i];
        }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на суммирование второго массива (8 потока): " << "\t" << t;
    ///
    t = clock();
    #pragma omp parallel shared(Asgl) reduction (+: sum1) num_threads(16)
    {
    #pragma omp for
        for (int i = 0; i < n; ++i)
        {
            sum1 += Asgl[i];
        }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на суммирование первого массива (16 потока): " << "\t" << t;
    ///
    sum1 = 0; sum2 = 0;
    t = clock();
    #pragma omp parallel shared(Asgl) reduction (+: sum2) num_threads(16)
    {
    #pragma omp for
        for (int i = 0; i < n; ++i)
        {
            sum2 += Abdl[i];
        }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на суммирование второго массива (16 потока): " << "\t" << t;
    ///
    t = clock();
    #pragma omp parallel shared(Asgl) reduction (+: sum1) num_threads(32)
    {
    #pragma omp for
        for (int i = 0; i < n; ++i)
        {
            sum1 += Asgl[i];
        }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на суммирование первого массива (32 потока): " << "\t" << t;
    ///
    sum1 = 0; sum2 = 0;
    t = clock();
    #pragma omp parallel shared(Asgl) reduction (+: sum2) num_threads(32)
    {
    #pragma omp for
        for (int i = 0; i < n; ++i)
        {
            sum2 += Abdl[i];
        }
    }
    t = clock() - t;
    cout << "\nВремя затраченное на суммирование второго массива (32 потока): " << "\t" << t;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
