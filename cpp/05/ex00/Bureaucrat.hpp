/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:10:11 by haryu             #+#    #+#             */
/*   Updated: 2022/10/19 00:30:32 by haryu            ###   ########.fr       */
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
public:
								Bureaucrat(const std::string& name, Grade grade);
								Bureaucrat(const Bureaucrat& target);
								~Bureaucrat(void);
	Bureaucrat&					operator=(const Bureaucrat& target);

	const std::string&			getName(void) const;
	const Grade&				getGrade(void);
	bool						setName(std::string& value);
	bool						setGrade(Grade value);

	std::exception&				GradeTooHighException(void); // 고민 필요함. 어서 어떻게 호출 될  것인가?
	std::exception&				GradeTooLowException(void); // 고민 필요함. 어서 어떻게 호출 될  것인가?
};

std::ostream& operator<<(std::ostream& s, const Bureaucrat& target);

#endif