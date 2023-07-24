/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:17:47 by mtomomit          #+#    #+#             */
/*   Updated: 2023/04/27 16:44:03 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main()
{
	std::ofstream	ofs;

	ofs.open("./test/test.txt", std::ofstream::out | std::ofstream::trunc);
	ofs << "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n"
			"Mauris blandit pulvinar eros vel sollicitudin. Maecenas \n"
			"lobortis purus mauris, sit amet fermentum ante maximus a. \n"
			"Nulla pulvinar nisl eu sem consequat imperdiet. Quisque porta \n"
			"vulputate magna, nec suscipit purus molestie eu. Fusce ut \n"
			"convallis augue. Duis finibus malesuada lectus, non rutrum \n"
			"nunc auctor eget. Sed pellentesque tempus lacus in tempor. \n"
			"Sed ullamcorper condimentum urna a maximus. Nulla ac maximus sem. \n"
			"Phasellus gravida maximus nisl, eget semper lectus tincidunt sit amet. \n"
			"Ut dignissim est non nulla ultricies dapibus. Integer sapien enim, \n"
			"sollicitudin a eros ac, ullamcorper vulputate mi. Morbi quam est, \n"
			"porttitor at auctor vel, porttitor in neque. Sed mi erat, venenatis \n"
			"in magna nec, porta placerat risus. Etiam nisi erat, ullamcorper vel\n"
			"lorem vitae, vehicula blandit erat. Duis blandit diam eu arcu consequat, eget elementum mi porta.\n";
}
