/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:41:59 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/02 12:13:04 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

int	main(void)
{
	time_t		rawtime;
	struct tm	*timeinfo;
	char		timeoutput[18];
	char const	*timeformat = "[%G%m%d_%H%M%S]";

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(timeoutput, 18, timeformat, timeinfo);
	std::cout << timeoutput << std::endl;
}
