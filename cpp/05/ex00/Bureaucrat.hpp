/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:10:11 by haryu             #+#    #+#             */
/*   Updated: 2022/10/19 13:20:18 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_hpp
# define Bureaucrat_hpp

# include <iostream>
# include <string>
# include <stdexcept>

typedef unsigned int			Grade;

class Bureaucrat {
private:
	const std::string			name;
	Grade						grade;
	void						tryGradeIsOk(void);
public:
								Bureaucrat(void);
								Bureaucrat(const std::string& name, Grade grade);
								Bureaucrat(const Bureaucrat& target);
	virtual						~Bureaucrat(void);
	Bureaucrat&					operator=(const Bureaucrat& target);

	std::string					getName(void) const;
	Grade						getGrade(void) const;

	void						setGrade(Grade value);

	void						increaseGrade(Grade value);
	void						increaseGrade(void);
	void						decreaseGrade(Grade value);
	void						decreaseGrade(void);

	/**
	 * @brief Construct a new Grade Too High Exception object, exception 처리를 위한 예외 객체 설정
	 * 
	 */
	class GradeTooHighException : public std::exception {
	public:
		virtual const char*				what(void) const throw();		
	};

	/**
	 * @brief Construct a new Grade Too Low Exception object, exception 처리를 위한 예외 객체 설정
	 * 
	 */
	class GradeTooLowException : public std::exception {
	public:
		virtual const char*				what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& s, const Bureaucrat& target);

#endif