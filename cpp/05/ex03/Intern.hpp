/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:09:01 by haryu             #+#    #+#             */
/*   Updated: 2022/10/25 22:18:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_hpp
# define Intern_hpp

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "ShrubberyCrationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPradonForm.hpp"

class Intern {
private:
	std::string forms[4];
public:
	Intern(void);
	Intern(const Intern& target);
	~Intern(void);
	Intern&	operator=(const Intern& target);

	Form*	makeForm(const std::string & type, const std::string & target);
};

#endif