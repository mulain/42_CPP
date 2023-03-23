/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: wmardin <wmardin@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/15 19:32:46 by wmardin		   #+#	#+#			 */
/*   Updated: 2023/03/21 14:24:26 by wmardin		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

/*
OSX:
./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`

 Linux:
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
*/

#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <deque>

#define SUBARRAY_SIZE 4

typedef std::vector<int>::const_iterator vec_it;

// UTILS

void myExit(const char* msg, int* array, int exitcode)
{
	if (msg)
		std::cout << msg << std::endl;
	if (array)
		delete[] array;
	exit(exitcode);
}

bool parsePosInt(const char* input, int* result)
{
	long	num;
	char*	endptr;

	if (!input || !input[0])
		return false;
	num = strtol(input, &endptr, 10);
	if (num < 0 || num > INT_MAX || *endptr != 0)
		return false;
	*result = num;
	return true;
}

int* checkAndParse(int size, char** argv)
{
	int*	array;
	int		num;
	
	if (size < 2)
		myExit("Please provide >= 2 positive ints to sort.", NULL, 1);
	array = new int[size];
	for (size_t i = 1; argv[i]; i++)
	{
		if (parsePosInt(argv[i], &num))
			array[i - 1] = num;
		else
			myExit("Invalid input detected.", array, 1);
	}
	return array;
}

void printIntArray(std::string msg, int* array, int size)
{
	std::cout << msg << ":\t";
	for (int i = 0; i < size; i++)
		std::cout << array[i] << (i < size - 1 ? " " : "\n");
}

int* copyIntArray(int* src, int size)
{
	int* copy = new int[size];
	for (int i = 0; i < size; i++)
		copy[i] = src[i];
	return copy;
}

// MERGE INSERT SORT

/*
Vanilla insertion sort.
Stores the evaluated value in <<key>> and keeps moving preceding values to the right as long
as they are greater than <<key>>. The original array position of the value contained in <<key>>
can get overwritten, but is of course saved in <<key>> and get's written once the compare
array position does not contain a value > key. 
*/
template <typename Container>
void insertionSort(Container& data, int start, int end)
{
	for (int i = start + 1; i <= end; i++)
	{
		int key = data[i];
		int j = i;
		while (j > start && data[j - 1] > key)
		{
			data[j] = data[j - 1];
			j--;
		}
		data[j] = key;
	}
}

/*
Receives the entire data. But will only merge the parts referenced by start, mid and end.
Iterates over the two parts writing the smaller value and incrementing the half from
which it was taken.
Finally writes any possible remaining values from the leftover half.
*/
template <typename Container>
void merge(Container& data, int start, int mid, int end)
{
	Container left(data.begin() + start, data.begin() + mid + 1);
	Container right(data.begin() + mid + 1, data.begin() + end + 1);
	size_t index_left = 0, index_right = 0, index_data = start;

	while (index_left < left.size() && index_right < right.size())
	{
		if (left[index_left] <= right[index_right])
			data[index_data++] = left[index_left++];
		else
			data[index_data++] = right[index_right++];
	}
	while (index_left < left.size())
		data[index_data++] = left[index_left++];
	while (index_right < right.size())
		data[index_data++] = right[index_right++];
}

/*
The actual begin of the function, splitting the data into subarrays.
Once the chunks are smaller than the desired subarray size: insertion sort.
Until then: split the received chunk in half, recursively call this function for both halves and
merge the result. At that point, the result will have undergone insertion sort through the
recursive calls.
*/
template <typename Container>
void mergeInsertSort(Container& data, int start, int end)
{
	if (end - start < SUBARRAY_SIZE)
		insertionSort(data, start, end);
	else
	{
		int mid = start + (end - start) / 2;
		mergeInsertSort(data, start, mid);
		mergeInsertSort(data, mid + 1, end);
		merge(data, start, mid, end);
	}
}

/*
Overload so you can leisurely call the function just by passing the container.
*/
template <typename Container>
void mergeInsertSort(Container& data)
{
	mergeInsertSort(data, 0, data.size() - 1);
}

int main (int argc, char** argv)
{
	int size = argc - 1;
	int* array_vec = checkAndParse(size, argv);
	int* array_deq = copyIntArray(array_vec, size);
	printIntArray("Before", array_vec, size);
	
	// merge-insert sort algorithm using std::vector
	clock_t	start = clock();
	std::vector<int> vec(array_vec, array_vec + size);
	mergeInsertSort(vec);
	for (int i = 0; i < size; i++)
		array_vec[i] = vec[i];
	clock_t end = clock();
	double duration_vec = (double)(end - start) / CLOCKS_PER_SEC * 1e3;

	// merge-insert sort algorithm using std::deque
	start = clock();
	std::deque<int> deq(array_deq, array_deq + size);
	mergeInsertSort(deq);
	for (int i = 0; i < size; i++)
		array_deq[i] = deq[i];
	end = clock();
	double duration_deq = (double)(end - start) / CLOCKS_PER_SEC * 1e3;

	printIntArray("After", array_vec, size);
	std::cout << std::setprecision(3) << std::fixed;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << duration_vec << " ms" << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::deque:  " << duration_deq << " ms" << std::endl;
	delete[] array_vec;
	delete[] array_deq;
}
