/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:43:10 by haryu             #+#    #+#             */
/*   Updated: 2022/10/20 01:11:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef From_hpp
# define From_hpp

# include "Bureaucrat.hpp"

class Form {
public:
                                    Form(void);
                                    Form(const std::string& name, Grade sign, Grade ex);
                                    Form(const Form& target);
    virtual                         ~Form(void);
    Form&                           operator=(const Form& target);

    std::string                     getName(void) const;
    Grade                           getGrade(const std::string& type) const;
	bool							getSignOrNot(void) const;
    
    void                            beSigned(const Bureaucrat& Charger);
    
private:
    const std::string               name;
    const Grade                     gradeForSign;
    const Grade                     gradeForEx;
    bool                            blank;
    
    void                            tryGradeIsOk(const Grade& value);
    class GradeTooHighException : public std::exception {
    public:
        virtual const char*         what(void) const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char*         what(void) const throw();
    };
    void				    		printExceptError(GradeTooLowException& e);
    void				    		printExceptError(GradeTooHighException& e);
};

std::ostream& operator<<(std::ostream& s, const Form& target);

#endif