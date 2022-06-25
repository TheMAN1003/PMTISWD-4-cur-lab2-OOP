#include <iostream>
#include <cmath>

using namespace std;

class ISorter {
	void Sort();
};

class QuickSort : public ISorter {
private:
	int* _arr;
	int _size;
	void swap(int* a, int* b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	int partition(int* arr, int first, int last) {
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
	void quicksort(int first, int last) {
		if (first >= last || first < 0) {
			return;
		}
		int pivot = partition(this->_arr, first, last);
		quicksort(first, pivot - 1);
		quicksort(pivot + 1, last);
		return;
	}
public:
	QuickSort(int* arr, int size) {
		if (arr != nullptr) {
			this->_size = size;
			_arr = new int[this->_size];
			for (int i = 0; i < size; i++) {
				_arr[i] = arr[i];
			}
		}
		else {
			throw exception("you try to input empty array");
		}
	}
	~QuickSort(){
		delete[] _arr;
	}
	void Sort() {
		quicksort(0, this->_size - 1);		
	}
	int operator [] (const int& index) const
	{
		return this->_arr[index];
	}
};

int main()
{
	cout << "It's alive! ALIVE!!!" << endl;
}