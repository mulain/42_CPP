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
• Your program must be able to use a positive integer sequence as argument.
• Your program must use a merge-insert sort algorithm to sort the positive integer sequence.
• If an error occurs during program execution, an error message should be displayed on the standard output.
You must use at least two different containers in your code to
validate this exercise.  Your program must be able to handle at
least 3000 different integers.

Here are some additional guidelines on the information you should display line by line on the standard output
• On the first line you must display an explicit text followed by the unsorted positive integer sequence.
• On the second line you must display an explicit text followed by the sorted positive integer sequence.
• On the third line you must display an explicit text indicating the time used by your algorithm by specifying
the first container used to sort the positive integer sequence.
• On the last line you must display an explicit text indicating the time used by your algorithm by specifying
the second container used to sort the positive integer sequence.

$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$>

./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

*/

#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <deque>

#define SPLITSIZE 5

typedef std::vector<int>::const_iterator vec_it;

void myExit(std::string msg, int* array, int exitcode)
{
	if (!msg.empty())
		std::cout << msg << std::endl;
	if (array)
		delete[] array;
	exit(exitcode);
}

template <typename Container>
void mergeInsert(Container& A, Container& B)
{
	int index_a = 0;	
	int index_b = 0;
	int size_a = A.size();
	int size_b = B.size();
	while (index_a < size_a && index_b < size_b)
	{
		if (A[index_a] < B[index_b])
			index_a++;
		else
		{
			A.insert(A.begin() + index_a, B[index_b]);
			index_a++;
			index_b++;
			size_a++;
		}
	}
	while (index_b < size_b)
	{
		A.push_back(B[index_b]);
		index_b++;
	}
}

template <typename Container>
void mergeInsertSort(Container& input)
{
	int n = input.size();
	if (n < 2)
		return;
	Container left(input.begin(), input.begin() + n / 2);
	Container right(input.begin() + n / 2, input.end());
	mergeInsertSort(left);
	mergeInsertSort(right);
	input.clear();
	mergeInsert(input, left);
	mergeInsert(input, right);
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

int* checkAndParse(int argc, char** argv)
{
	int*	array;
	int		num;
	
	if (argc < 3)
		myExit("Please provide >= 2 positive ints to sort.", NULL, 1);
	array = new int[argc];
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

int main (int argc, char** argv)
{
	int* array_vec = checkAndParse(argc, argv);
	int* array_dq = checkAndParse(argc, argv);
	int size = argc - 1;
	printIntArray("Before", array_vec, size);
	
	// merge-insert sort algorithm using std::vector
	clock_t	start = clock();
	std::vector<int> vec(array_vec, array_vec + size);
	mergeInsertSort(vec);
	for (int i = 0; i < size; i++)
		array_vec[i] = vec[i];
	clock_t end = clock();
	double duration_vec = (double)(end - start) / CLOCKS_PER_SEC * 1000;

	// merge-insert sort algorithm using std::deque
	start = clock();
	std::deque<int> dq(array_dq, array_dq + size);
	mergeInsertSort(dq);
	for (int i = 0; i < size; i++)
		array_dq[i] = dq[i];
	end = clock();
	double duration_dq = (double)(end - start) / CLOCKS_PER_SEC * 1000;

	printIntArray("After", array_vec, size);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector:\t" << duration_vec << " ms" << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::deque:\t" << duration_dq << " ms" << std::endl;
	delete[] array_vec;
	delete[] array_dq;
}
