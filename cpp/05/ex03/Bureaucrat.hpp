/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:10:11 by haryu             #+#    #+#             */
/*   Updated: 2022/10/27 18:39:28 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_hpp
# define Bureaucrat_hpp

# include <iostream>
# include <string>
# include <stdexcept>

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

/* ************************************************************************** */

	std::string					getName(void) const;
	Grade						getGrade(void) const;

	void						setGrade(Grade value);

	void						increaseGrade(void);
	void						decreaseGrade(void);

/* ************************************************************************** */

	void						signForm(Form & paper);
	void						executeForm(Form const & form);
	void						signAndExecute(Form & paper);

/* ************************************************************************** */

private:
	const std::string			name;
	Grade						grade;

/* ************************************************************************** */
	void						tryGradeIsOk(void);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char*				what(void) const throw();		
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char*				what(void) const throw();
	};
	virtual void				printExceptError(GradeTooLowException& e);
	virtual void				printExceptError(GradeTooHighException& e);
};

std::ostream& operator<<(std::ostream& s, const Bureaucrat& target);

#endif