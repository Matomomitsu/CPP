/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:07:52 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>

# define SCF_SIGN_GRADE 145
# define SCF_EXEC_GRADE 137
# define SHRUBBERY_TREE \
         "\n\
                    .o00o\n\
                   o000000oo\n\
                  00000000000o\n\
                 00000000000000\n\
              oooooo  00000000  o88o\n\
           ooOOOOOOOoo  ```\'\'  888888\n\
         OOOOOOOOOOOO\'.qQQQQq. `8888\'\n\
        oOOOOOOOOOO\'.QQQQQQQQQQ/.88\'\n\
        OOOOOOOOOO\'.QQQQQQQQQQ/ /q\n\
         OOOOOOOOO QQQQQQQQQQ/ /QQ\n\
           OOOOOOOOO `QQQQQQ/ /QQ\'\n\
             OO:F_P:O `QQQ/  /Q\'\n\
                \\. \\ |  // |\n\
                d\\ \\\\|_////\n\
                qP| \\ _\' `|Ob\n\
                   \\  / \\  \\Op\n\
                   |  | O| |\n\
           _       /\\. \\_/ /\\\n\
            `---__/|_\\\\   //|  __\n\
                  `-\'  `-\'`-\'-\'\n"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const target);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		void	execute(Bureaucrat const & executor) const;
		class FileCreateErrorException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class FileWriteErrorException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

#endif
