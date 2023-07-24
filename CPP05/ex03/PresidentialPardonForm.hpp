/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:09:24 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

# define PPF_SIGN_GRADE 25
# define PPF_EXEC_GRADE 5

class PresidentialPardonForm : public AForm{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const target);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		void	execute(Bureaucrat const & executor) const;
};
#endif
