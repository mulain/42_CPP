std::vector<int> parseVector(int argc, char **argv)
{	
	std::vector<int>	vec;
	int					num;
	
	if (argc < 3)
		myExit("Please provide >= 2 positive ints to sort.", NULL, 1);
	for (size_t i = 1; argv[i]; i++)
	{
		if (parsePosInt(argv[i], &num))
			vec.push_back(num);
		else
			myExit("Invalid input detected.", NULL, 1);
	}
	return vec;
}

void printVector(std::string title, std::vector<int> vec)
{
	std::cout << title << ":\t";
	for (vec_it it = vec.begin(); it != vec.end();)
		std::cout << *it << (++it != vec.end() ? " " : "\n");
}

void mergeInsert(std::vector<int>& A, std::vector<int>& B)
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

void mergeInsertSort(std::deque<int>& input)
{
	int n = input.size();
	if (n < 2)
		return;
	std::deque<int> left(input.begin(), input.begin() + n / 2);
	std::deque<int> right(input.begin() + n / 2, input.end());
	mergeInsertSort(left);
	mergeInsertSort(right);
	input.clear();
	mergeInsert(input, left);
	mergeInsert(input, right);
}
