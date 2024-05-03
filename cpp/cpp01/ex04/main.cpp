/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:11:41 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/03 11:14:54 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Correct syntax : ./Sed_is_for_losers <filename> <string 1> <string 2>" << std::endl;
		return EXIT_FAILURE;
	}

	/// Infile & Outfile opens ---
	std::fstream	infile;
	infile.open(argv[1], std::ios::in);
	if (!infile.is_open())
	{
		std::cout << "Error while opening the file" << std::endl;
		return EXIT_FAILURE;
	}
	

	std::string		outfile_name = argv[1];
	outfile_name.append(".replace");

	std::fstream	outfile;
	outfile.open(outfile_name.c_str(), std::ios::out);
	if (!outfile.is_open())
	{
		std::cout << "Error while creating the file" << std::endl;
		return EXIT_FAILURE;
	}
	// ---

	/// copying content from infile to outfile ---
	std::string		line;
	size_t			pos;
	while (std::getline(infile, line))
	{
		pos = line.find(argv[2]);
		while (pos != std::string::npos)
		{
			
			pos = line.find(argv[2], pos + 1);
		}
	}
	// ---

	infile.close();
	outfile.close();
	return EXIT_SUCCESS;
}