/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:10:11 by haryu             #+#    #+#             */
/*   Updated: 2022/10/26 17:58:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_hpp
# define Bureaucrat_hpp

# include <iostream>
# include <string>
# include <exception>

typedef unsigned int			Grade;

# define EXCEPT_FAILED "Grade setting Failed. : "
# define GRADE_HIGH "Grade setting is too high. : "
# define GRADE_LOW "Grade setting is too low. : "
# define GRADE_CHANGE "Grade is changed : "

class Form;

class Bureaucrat {
public:
								Bureaucrat(void);
								Bureaucrat(const std::string& name, Grade grade);
								Bureaucrat(const Bureaucrat& target);
	virtual						~Bureaucrat(void);
	Bureaucrat&					operator=(const Bureaucrat& target);

	std::string					getName(void) const;
	Grade						getGrade(void) const;

	void						increaseGrade(void);
	void						decreaseGrade(void);
	
protected:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char*				what(void) const throw();		
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char*				what(void) const throw();
	};
	void						tryGradeIsOk(void);
	void						printExceptError(GradeTooLowException& e);
	void						printExceptError(GradeTooHighException& e);
	void						setGrade(Grade value);

private:
	const std::string			name;
	Grade						grade;
};

std::ostream& operator<<(std::ostream& s, const Bureaucrat& target);

#endif