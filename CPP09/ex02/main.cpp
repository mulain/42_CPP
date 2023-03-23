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
#include <climits>
#include <cstdlib>
#include <ctime>
#include <vector>
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
	int size = 4;
	int n = input.size();
	if (n < size)
		return;
	Container left(input.begin(), input.begin() + n / size);
	Container right(input.begin() + n / size, input.end());
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
