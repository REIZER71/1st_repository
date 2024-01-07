#include <iostream>
using namespace std;
// добавить чтение с файла
// добавить два уровня сортировки
// добавить таймер
// добавить вторую сортировку (туда добавить пункт 2 и 3)
int main() 
{
	int arr1[10] = {4,2,6,8,7,9,3,5,1,10};
	// print unsorted
	for (int i = 0; i < size(arr1); i++) {
		cout << arr1[i] << " ";
	}
	cout << endl << endl;
	// bubble sort
	for (int I = 0; I<size(arr1)-1; I++)
	{
		for (int II = 0; II<size(arr1) - 1; II++)
		{
			if (arr1[II] > arr1[II + 1])
			{
				swap(arr1[II], arr1[II + 1]);
			}
		}
	}
	// print sorted
	for (int i = 0; i < size(arr1); i++)
	{
		cout << arr1[i] << " ";
	}



	int arr2[10] = { 4,2,6,8,7,9,3,5,1,10 };
	// print unsorted
	for (int i = 0; i < size(arr1); i++) {
		cout << arr1[i] << " ";
	}
	cout << endl << endl;
	//
}