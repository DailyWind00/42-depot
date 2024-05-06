/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:11:41 by mgallais          #+#    #+#             */
/*   Updated: 2024/05/06 14:41:21 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <fstream>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Correct syntax : ./Sed_is_for_losers <filename> <string 1> <string 2>" << std::endl;
		return EXIT_FAILURE;
	}

	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	/// Infile & Outfile opens ---
	std::fstream	infile;
	infile.open(argv[1], std::ios::in);
	if (!infile.is_open()) {
		std::cerr << "Error while opening the file" << std::endl;
		return EXIT_FAILURE;
	}
	

	std::string		outfile_name = argv[1];
	outfile_name.append(".replace");

	std::fstream	outfile;
	outfile.open(outfile_name.c_str(), std::ios::out);
	if (!outfile.is_open()) {
		std::cerr << "Error while creating the file" << std::endl;
		infile.close();
		return EXIT_FAILURE;
	}
	// ---

	/// Copying content from infile to outfile ---
	std::string		line;
	size_t			pos = 0;

	std::getline(infile, line, '\0');
	while ((pos = line.find(s1, pos)) != std::string::npos) {
		std::cout << pos << std::endl;
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
	outfile << line;
	// ---

	infile.close();
	outfile.close();
	return EXIT_SUCCESS;
}
