/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:14:48 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/15 17:08:32 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main (int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	
	std::string filename = av[1];
	if (filename.empty())
	{
		std::cerr << "Error: empty filename" << std::endl;
		return (1);
	}
	
	std::string to_replace = av[2];
	if (to_replace.empty())
	{
		std::cerr << "Error: empty string to replace" << std::endl;
		return (1);
	}
	
	std::string replace_with = av[3];
	if (replace_with.empty())
	{
		std::cerr << "Error: empty string to replace with" << std::endl;
		return (1);
	}
	
	std::string output_filename = filename + ".replace";
	
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open:" << filename << std::endl;
		return (1);
	}

	std::string tmp;
	std::string content;
	while (std::getline(infile, tmp))
	{
		content += tmp + '\n';
	}
	
	
	std::ofstream outfile(output_filename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: could not open:" << output_filename << std::endl;
		return (1);
	}

	
	size_t pos = 0;
	while ((pos = content.find(to_replace, pos)) != std::string::npos)
	{
		std::string before = content.substr(0, pos);
		outfile << before;
		outfile << replace_with;
		content = content.substr(pos + to_replace.length());
		pos = 0;
	}
	outfile << content;
	return (0);
	
}