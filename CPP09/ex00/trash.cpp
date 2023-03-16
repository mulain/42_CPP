bool BitcoinExchange::parseDate(std::string input, Date* date)
{
	size_t	delim;
	long	year;
	long	month;
	long	day;

	// parse year
	delim = input.find('-');
	if (delim == std::string::npos)
		return false;
	if (!parseYear(input.substr(0, delim).c_str(), &year))
		return false;
	input.erase(0, delim + 1);
	
	// parse month
	delim = input.find('-');
	if (delim == std::string::npos)
		return false;
	if (!parseMonth(input.substr(0, delim).c_str(), &month))
		return false;
	input.erase(0, delim + 1);

	// parse day
	if (!parseDay(input.c_str(), &day, year, month))
		return false;
	
	//clean this shite up! just return false on date creation
	date->setYear(static_cast<int>(year));
	date->setMonth(static_cast<int>(month));	
	date->setDay(static_cast<int>(day));
	return true;
}

bool BitcoinExchange::parseYear(const char* input, long* year)
{
	char*	endptr;

	*year = strtol(input, &endptr, 10);
	if (*year < 1 || *year > 9999 || *endptr != 0)
		return false;
	return true;
}

bool BitcoinExchange::parseMonth(const char* input, long* month)
{
	char*	endptr;

	*month = strtol(input, &endptr, 10);
	if (*month < 1 || *month > 12 || *endptr != 0)
		return false;
	return true;
}

bool BitcoinExchange::parseDay(const char* input, long* day, int year, int month)
{
	char*	endptr;

	*day = strtol(input, &endptr, 10);
	if (*day < 1 || *day > 31 || *endptr != 0)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (*day > 30)
			return false;
	}
	else if (month == 2)
	{
		if (isLeapYear(year))
		{
			if (*day > 29)
				return false;
		}
		else if (*day > 28)
			return false;
	}
	return true;
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}