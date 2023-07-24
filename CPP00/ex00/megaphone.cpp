/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:12:17 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/22 15:30:41 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int i;
	int o;

	i = 0;
	o = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (o < argc)
		{
			while (argv[o][i])
			{
				std::cout << (char)toupper(argv[o][i]);
				i++;
			}
			o++;
			i = 0;
		}
		std::cout << std::endl;
	}
	return (0);
}
