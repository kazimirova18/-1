#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    cout << "--------------------Лабораторна №7----------------" << endl;
    cout << "-------------------Сортування Шела----------------" << endl;
    const int n = 4, m = 8;
    int A[n][m];
    srand(time(0));

    // Заповнення масиву та виведення на екран
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = -20 + rand() % 35;
            cout << setw(3) << A[i][j];
        }
        cout << "\n\n";
    }
    cout << "\n\n";


    // Знаходження стовбця з максимальним за модулем елементом
    int max_abs_col = 0;
    int max_abs_val = abs(A[0][0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int abs_val = abs(A[i][j]);
            if (abs_val > max_abs_val)
            {
                max_abs_val = abs_val;
                max_abs_col = j;
            }
        }
    }

    cout << "Стовбець з максимальним за модулем елементом: " << max_abs_col + 1 << endl;


    // Сртування вибраним стовбцем методом Шелла
    int g = n / 2;
    while (g > 0)
    {
        for (int i = g; i < n; i += g)
        {
            double temp = A[i][max_abs_col];
            int l = i - g;
            while (l >= 0 && abs(A[l][max_abs_col]) < abs(temp))
            {
                compars++;
                A[l + g][max_abs_col] = A[l][max_abs_col];
                l -= g;
                swaps++;
            }
            A[l + g][max_abs_col] = temp;
        }
        g /= 2;
    }

    // Зробимо всі значення додатніми
    for (int i = 0; i < n; i++)
    {
        A[i][max_abs_col] = abs(A[i][max_abs_col]);
    }


    // Виведення відсортованого за стовбцем масиву
    cout << "Масив, відсортований за стовбцем з максимальним за модулем елементом:\n";
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++)
        {
            cout << setw(3) << A[i][j];
        }
        cout << "\n\n";
    }




    return 0;
}