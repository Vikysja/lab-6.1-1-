#include <iostream>
#include <iomanip>

using namespace std;

void Create(int* list, const int size, const int Low, const int High);
void Processing(int* list, const int size, int& sum, int& count);
void Print(int* list, const int size);

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    srand((unsigned)time(NULL));

    //srand(1); // для перевірки правильності способів

    const int n = 25;
    int c[n];

    int Min = 5;
    int Max = 90;

    int sum = 0;
    int count = 0;

    cout << "Iтерацiйний спосiб" << endl; 
    cout << endl;

    Create(c, n, Min, Max);
    cout << "Before: "; Print(c, n);

    Processing(c, n, sum, count);
    cout << "After:  "; Print(c, n);

    cout << endl;

    cout << "Sum: " << setw(4) << sum << endl
        << "Count: " << setw(2) << count << endl;
}

// Заповнення масиву випадковими значеннями
void Create(int* list, const int size, const int Min, const int Max)
{
    for (int i = 0; i < size; i++)
        list[i] = rand() % (Max - Min + 1) + Min; // де Min - ліва межа, а Max - права
}

// обчислення кількості, суми та присвоєння елементам, що підходять по умові значення 0
void Processing(int* list, const int size, int& sum, int& count) {
    for (int i = 0; i < size; i++)
    {
        if ( !(list[i] % 2) || i % 8 != 0) { // парний або індекс не кратрий 8
            sum += list[i];
            list[i] = 0;
            count++;
        }
    }
}

// Вивід масиву
void Print(int* list, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(3) << list[i];
    cout << endl;
}