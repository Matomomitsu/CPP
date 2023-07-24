/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:01:56 by mtomomit          #+#    #+#             */
/*   Updated: 2023/06/10 17:01:15 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replaceString(std::string filename, std::string search, std::string replace)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	int				i;
	std::string		temp_string;
	char			c;

	ifs.open(filename.c_str(), std::ifstream::in);
	if (ifs.fail()){
		throw (std::string("Failed to open " + filename));
	}
	ofs.open((filename + ".replace").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (ofs.fail()){
		throw (std::string("Failed to open " + filename + ".replace"));
	}
	i = 0;
	while (ifs.get(c))
	{
		if (c != search[i])
		{
			if (i != 0)
				ofs << temp_string;
			temp_string.clear();
			ofs << c;
			i = 0;
		}
		else if (c == search[i])
		{
			temp_string += c;
			i++;
			if (temp_string == search)
			{
				i = 0;
				ofs << replace;
				temp_string.clear();
			}
		}
	}
	ifs.close();
	ofs.close();
}

int main (int argc, char *argv[])
{
	if (argc < 4)
	{
		std::cerr << "Few arguments" << std::endl;
		std::cerr << "Usage: ./replace [FILENAME] [SEARCH] [REPLACE]" << std::endl;
		return (1);
	}
	if (argc > 4)
	{
		std::cerr << "Many arguments" << std::endl;
		std::cerr << "Usage: ./replace [FILENAME] [SEARCH] [REPLACE]" << std::endl;
		return (2);
	}
	std::string filename = argv[1];
	std::string search = argv[2];
	std::string replace = argv[3];
	try{
		replaceString(filename, search, replace);
	}
	catch(std::string error){
		std::cerr << error << std::endl;
	}
	return 0;
}
