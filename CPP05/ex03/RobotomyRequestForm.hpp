/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:09:30 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <cstdlib>

# define RRF_SIGN_GRADE 72
# define RRF_EXEC_GRADE 45

class RobotomyRequestForm : public AForm  {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const target);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		void	execute(Bureaucrat const & executor) const;
};

#endif
