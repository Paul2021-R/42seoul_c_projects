/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCrationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:52:44 by haryu             #+#    #+#             */
/*   Updated: 2022/10/25 21:23:30 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCrationForm_hpp
# define ShrubberyCrationForm_hpp

# include "Form.hpp"
# include <fstream>

class ShrubberyCrationForm: virtual public Form {
public:
								ShrubberyCrationForm(void);
								ShrubberyCrationForm(const std::string& target);
								ShrubberyCrationForm(const ShrubberyCrationForm& target);
								~ShrubberyCrationForm(void);
	ShrubberyCrationForm&		operator=(const ShrubberyCrationForm& target);

	void						execute(const Bureaucrat & Executor) const;
private:
	std::string					target;
	void						makeShruberry(const Bureaucrat & Executor) const;
	class GradeTooLowException : public std::exception {
    public:
        virtual const char*		what(void) const throw();
    };
	void						printExceptError(GradeTooLowException& e) const;
	void						tryGradeIsOk(const Bureaucrat& Executor) const;
};
#endif