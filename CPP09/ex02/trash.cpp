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