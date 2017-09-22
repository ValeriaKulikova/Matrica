// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//Составить матрицу из случайных элементов  А и В которые не превышают 50  и посчитать сумму с помощью потоков

#include <iostream>
#include <ctime>
#include <iomanip>
#include <thread>
using namespace std;

void summa(int** arr, int j, int a, int b, int* result)
{

	int sum = 0, i;
	for (i = 0; i < a; i++)
	{
		sum += arr[i][j];

	}
	*result = sum;
}


int main(int argc, char* argv[])

{
	int a, b, i, j, sum = 0;
	int** arr;
	a = rand() % 3 + 1;
	b = rand() % 3 + 1;
	const int numThreads = b;
	arr = new int*[a];
	for (i = 0; i < a; i++)
		arr[i] = new int[b];
	for (i = 0; i < a; i++)
		for (j = 0; j < b; j++)
			arr[i][j] = rand() % 101 - 50;
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	std::thread *threads = new thread[numThreads];
	int* result = new int[b];
	for (int i = 0; i < numThreads; ++i)
	{
		threads[i] = std::thread(summa, arr, i, a, b, &result[i]);

	}

	for (int i = 0; i < b; ++i)
	{
		threads[i].join();
		sum += result[i];
	}

	cout << sum;
	getchar();
	delete arr;
	return 0;

}

