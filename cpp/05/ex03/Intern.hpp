/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:09:01 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 01:01:36 by haryu            ###   ########.fr       */
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
	static std::string forms[4];
	Intern(const Intern& target) { (void)target; }
public:
	Intern(void);
	~Intern(void);
	Intern&	operator=(const Intern& target);

	Form*	makeForm(const std::string & type, const std::string & target);
};

#endif