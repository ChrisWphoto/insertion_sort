#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <time.h>

using namespace std;

//global for recursive algorithms
int comps = 0;
int swaps = 0;

void ShellSort(vector <int> &num) {
	int comps, swaps;
	comps = swaps = 0;

	int i, temp, flag = 1, numLength = num.size();
	int gap = numLength;
	bool insertionNeeded = false;
	int swapPos = 0;
	int key;

	while (true)  {    // boolean flag (true when not equal to 0) 
		gap = (gap - 1) / 2;
		if (gap == 0)
			break;

		for (int k = 0; k < gap; k++) {
			for (int j = gap + k; j < numLength; j += gap) {
				key = num[j];

				insertionNeeded = false;
				for (i = j - gap; i >= 0; i -= gap) {   // Smaller values move right
					++comps;
					if (key < num[i]) {
						++swaps;
						swapPos = i;
						num[i + gap] = num[i];
						insertionNeeded = true;
					}
					else
						break;
				}
				if (insertionNeeded) {
					num[swapPos] = key;    //Put key into its proper location
					++swaps;
				}
			}
		}
	}
	cout << comps << swaps;
	return;
}


void selection_sort(vector<int>& vec){
	int comps, swaps;
	comps = swaps = 0;
	for (int fill = 0; fill != vec.size(); ++fill) {
		int pos_min = fill;
		for (int next = fill + 1; next != vec.size(); ++next) {
			++comps;
			if (vec[next] < vec[pos_min]){
				pos_min = next;

			}

		}
		if (fill != pos_min){
			swap(vec[pos_min], vec[fill]);
			++swaps;
		}

	}
	cout << comps << " " << swaps << endl;
}


void BubbleSort(vector <int> &num){
	int comps, swaps;
	comps = swaps = 0;
	for (int i = 1; i <= num.size(); i++){
		for (int j = 0; j < num.size() - i; j++){
			++comps;
			if (num[j + 1] < num[j])
				swaps++;
			swap(num[j], num[j + 1]);// swap elements
		}
	}
	cout << comps << " " << swaps << endl;
}

void bubble_sort_improved(vector <int> &vec){
	int comps, swaps;
	comps = swaps = 0;
	bool exchanges = false;
	for (int i = 1; i <= vec.size(); i++){
		exchanges = false;
		for (int j = 0; j < vec.size() - i; j++){
			++comps;
			if (vec[j + 1] < vec[j]){
				++swaps;
				swap(vec[j], vec[j + 1]);// swap elements
				exchanges = true;
			}
		}
		if (!exchanges)
			break;
	}
	cout << comps << " " << swaps << endl;
}

void bubble_sort_list(list<int> &li){
	bool exchanges = false;
	list<int>::iterator itr = li.begin();
	for (int i = 1; i <= li.size(); i++){
		exchanges = false;
		itr = li.begin();
		for (int j = 0; j < li.size() - i; j++){
			list<int>::iterator current = itr;
			if (*(++itr)< *current){
				swap(*current, *itr);// swap elements
				exchanges = true;
			}
		}
		if (!exchanges)
			break;
	}
}

void insertion_sort(std::vector <int> &num) {
	int comps, swaps;
	comps = swaps = 0;
	int i, j, key;
	bool insertionNeeded = false;

	for (j = 1; j < num.size(); j++) {
		key = num[j];
		insertionNeeded = false;
		for (i = j - 1; i >= 0; i--){ // larger values move right
			++comps;
			if (key < num[i]) {

				swaps++;
				num[i + 1] = num[i];
				insertionNeeded = true;
			}
			else
				break;
		}
		if (insertionNeeded){
			num[i + 1] = key;    //Put key into its proper location
			swaps++;
		}
	}
	cout << comps << " " << swaps << endl;
}


void insertion_sort_lists(std::list<int> &num){

	if (num.size() <= 1)
		return;


	int key;
	int i = 0;
	int j;
	j = i;
	bool insertionNeeded;

	list<int>::iterator keyItr, shiftItr, shiftItrPlusOne;	//declare ShiftItr is one position behind key. ShiftItrPlusOne is one postition in front. 
	keyItr = num.begin();
	++keyItr;												 //set key iterator to second item in list; 

	for (keyItr; keyItr != num.end(); ++keyItr){			//keyItr goes from 2nd item to last item
		key = *keyItr;
		insertionNeeded = false;
		shiftItr = keyItr;
		--shiftItr;											//set shiftItr to be one behind the key
		++i;
		for (j = i - 1; j >= 0;){                           //runs from keyItr -1 to beggining
			if (key < *shiftItr){
				shiftItrPlusOne = shiftItr;
				shiftItrPlusOne++;
				*shiftItrPlusOne = *shiftItr;				//shift item one space forward
				insertionNeeded = true;
				--j;
				if (j == -1)								//stop iterator from decrementing past beginning of list. 
					break;
				--shiftItr;
			}

			else
				break;
		}
		if (insertionNeeded){
			*(--shiftItrPlusOne) = key;						  //place key before the last shifted item

		}
	}

}



void merge(std::vector<int>& array, std::vector<int>& result, int lowPointer, int highPointer, int upperBound) {

	int j = 0;
	int lowerBound = lowPointer;
	int mid = highPointer - 1;
	int n = upperBound - lowerBound + 1; //number of items

	while (lowPointer <= mid && highPointer <= upperBound){
		++comps; ++swaps;
		if (array[lowPointer] < array[highPointer])
			result[j++] = array[lowPointer++];
		else
			result[j++] = array[highPointer++];
	}

	while (lowPointer <= mid){
		++swaps;
		result[j++] = array[lowPointer++];
	}

	while (highPointer <= upperBound){
		++swaps;
		result[j++] = array[highPointer++];
	}

	for (j = 0; j < n; j++){ //copy the items from the temporary array to the original array
		++swaps;
		array[lowerBound + j] = result[j];
	}
	;
}

void mergesort(std::vector<int>& array, std::vector<int>& result, int lowerBand, int upperBand) {
	int midpoint;
	if (lowerBand < upperBand) {
		midpoint = (lowerBand + upperBand) / 2;
		mergesort(array, result, lowerBand, midpoint); //merge sort the left half
		mergesort(array, result, midpoint + 1, upperBand); //merge sort the right half
		merge(array, result, lowerBand, midpoint + 1, upperBand);
	}
}

void mergeSort(std::vector<int>& array){

	std::vector<int> result = array;
	mergesort(array, result, 0, array.size() - 1);

	cout << comps << swaps;
}



int partition(int first, int last, std::vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.
	int up = first + 1;
	int down = last - 1;
	do {

		while ((up != last) && !(arr[first] < arr[up])) {
			++comps;
			++up;
		}
		while (arr[first] < arr[down]) {
			++comps;
			--down;
		}
		if (up < down) {
			// if up is to the left of down,
			swap(arr[up], arr[down]);
			++swaps;
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[down], arr[first]);
	++swaps;
	return down;
}

void sort_median(std::vector<int>& arr, int first, int last){

	bool exchanges = true;
	int middle = (first + last) / 2;
	if (arr[first]>arr[middle])
		swap(arr[first], arr[middle]);
	if (arr[middle] > arr[last])
		swap(arr[middle], arr[last]);
	if (arr[first] > arr[middle])
		swap(arr[first], arr[middle]);


	//swap the middle with the left 
	swap(arr[middle], arr[first]);
}

int partitionB(int first, int last, std::vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.


	int up = first + 1;
	int down = last - 1;
	sort_median(arr, first, last - 1);
	int mid = first;
	do {
		while ((up != last - 1) && !(arr[mid] < arr[up])) {
			++up;
			comps++;
		}
		while (arr[mid] < arr[down]) {
			--down;
			++comps;
		}
		if (up < down) {
			// if up is to the left of down,
			swap(arr[up], arr[down]);
			++swaps;
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[mid], arr[down]);
	++swaps;
	return down;
}

void middle_quick_sort(int first, int last, std::vector<int>& arr) {
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partitionB(first, last, arr);

		// Sort the left half.
		middle_quick_sort(first, pivot, arr);

		// Sort the right half.
		middle_quick_sort(pivot + 1, last, arr);
	}
}

void middle_quick_sort_wrapper(vector<int>& arr){
	middle_quick_sort(0, arr.size(), arr);
	cout << comps << swaps;
}

void quick_sort(int first, int last, std::vector<int>& arr) {
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partition(first, last, arr);

		// Sort the left subarray.
		quick_sort(first, pivot, arr);

		// Sort the right subarray.
		quick_sort(pivot + 1, last, arr);
	}
}

void quick_sort_wrapper(vector<int>& arr){
	quick_sort(0, arr.size(), arr);
	cout << comps << swaps;
}


vector<int> random_vector(size_t size){
	vector<int> v1;
	for (int i = 0; i < size; i++)
		v1.push_back(rand() % size); //put a random number between 0 and size
	return v1;
}

vector<int> sorted_vector(size_t size){
	vector<int> v1;
	for (int i = 0; i < size; i++)
		v1.push_back(i);
	return v1;
}

vector<int> reversed_vector(size_t size){
	vector<int> v1;
	for (int i = size - 1; i >= 0; i--)
		v1.push_back(i);
	return v1;
}

int main(){

	vector<int> v1;
	v1 = random_vector(10000);

	//list<int> num; 

	/*for (int i = 0; i < 10000; i++){
	num.push_back(rand() % 10);
	}*/
	clock_t t1, t2;
	t1 = clock();


	//insertion_sort_lists(num);

	//v1 = sorted_vector(10000);
	//v1 = reversed_vector(10000);

	//bubble_sort_improved(v1);

	//selection_sort(v1);

	insertion_sort(v1);

	//ShellSort(v1);

	/*ShellSort(v1);*/

	//mergeSort(v1);

	//quick_sort_wrapper(v1);

	//middle_quick_sort_wrapper(v1);

	t2 = clock();
	float diff((float)t2 - (float)t1);
	cout << diff << endl;
	system("pause");


	return 0;
}