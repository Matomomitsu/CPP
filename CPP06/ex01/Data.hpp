/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:00:09 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/25 13:09:13 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {
	public:
		Data(void);
		virtual ~Data(void);
		Data & operator=(Data const & rhs);
		Data(Data const & src);
		int	number;
		std::string	string;
};

#endif
