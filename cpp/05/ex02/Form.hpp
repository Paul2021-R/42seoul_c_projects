/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:43:10 by haryu             #+#    #+#             */
/*   Updated: 2022/10/21 02:49:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef From_hpp
# define From_hpp

# include "Bureaucrat.hpp"

//	abstract class
//	바람직한 순수 가상함수 클래스를 만들 때는 과감히 키워드들만 남기는 것이 효과적 이다. 
class Form {
public:
                                    // Form(void);
                                    // Form(const std::string& name, Grade sign, Grade ex);
                                    // Form(const Form& target);
    virtual                         ~Form(void);
    // Form&                           operator=(const Form& target);

    virtual std::string				getName(void) const = 0;
    virtual Grade                   getGrade(const std::string& type) const = 0;
	virtual bool					getSignOrNot(void) const = 0;
    
    virtual void					beSigned(const Bureaucrat& Charger) = 0;
	virtual void					execute(Bureaucrat const& Execuor) const = 0;    
private:
    const std::string               name;
    const Grade                     gradeForSign;
    const Grade                     gradeForEx;
    bool                            blank;
    
    virtual void					tryGradeIsOk(const Grade& value) = 0;
    class GradeTooHighException : public std::exception {
    public:
        virtual const char*         what(void) const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char*         what(void) const throw();
    };
    virtual void					printExceptError(GradeTooLowException& e) = 0;
    virtual void					printExceptError(GradeTooHighException& e) = 0;
};

std::ostream& operator<<(std::ostream& s, const Form& target);

#endif