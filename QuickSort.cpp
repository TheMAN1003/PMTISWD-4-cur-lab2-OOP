#include <iostream>
#include <cmath>

using namespace std;

class Sort {
public:
	Sort(){
		cout << "Hey :)" << endl;
	}
	~Sort(){
		cout << "Bye :(" << endl;
	}
	void input(int arr[], int size) {
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
	}
	void print(int arr[], int size) {
		cout << "[";
		for (int i = 0; i < size - 1; i++) {
			cout << arr[i] << ", ";
		}
		cout << arr[size - 1] <<  "]" << endl;
	}
	void swap(int* a, int* b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	int partition(int arr[], int first, int last) {
		int mdn = floor((first + last) / 2);
		if (arr[mdn] < arr[first]) {
			swap(&arr[first], &arr[mdn]);
		}
		if (arr[last] < arr[first]) {
			swap(&arr[first], &arr[last]);
		}
		if (arr[mdn] < arr[last]) {
			swap(&arr[mdn], &arr[last]);
		}
		int pivot = arr[last];
		int big = first - 1;
		for (int i = first; i < last; i++) {
			if (arr[i] <= pivot) {
				big++;
				swap(&arr[big], &arr[i]);
			}
		}
		swap(&arr[big + 1], &arr[last]);
		return (big + 1);
	}
	void quicksort(int arr[], int first, int last) {
		if (first >= last || first < 0) {
			return;
		}
		int pivot = partition(arr, first, last);
		quicksort(arr, first, pivot - 1);
		quicksort(arr, pivot + 1, last);
		return;
	}
};

int main()
{
	cout << "It's alive! ALIVE!!!" << endl;
}