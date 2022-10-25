/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:30:31 by haryu             #+#    #+#             */
/*   Updated: 2022/10/25 21:50:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_hpp
# define RobotomyRequestForm_hpp

# include "Form.hpp"
# include <random>

class RobotomyRequestForm: public Form {
public:
									RobotomyRequestForm(void);
									RobotomyRequestForm(const std::string& target);
									RobotomyRequestForm(const RobotomyRequestForm& target);
									~RobotomyRequestForm(void);
	RobotomyRequestForm&			operator=(const RobotomyRequestForm& target);
	void							execute(const Bureaucrat & Executor) const;
private:
	std::string						target;
	class GradeTooLowException : public std::exception {
    public:
        virtual const char*			what(void) const throw();
    };
	void							printExceptError(GradeTooLowException& e) const;
	void							tryGradeIsOk(const Bureaucrat& Executor) const;
};
#endif