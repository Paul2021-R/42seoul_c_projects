/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:43:10 by haryu             #+#    #+#             */
/*   Updated: 2022/10/19 21:22:37 by haryu            ###   ########.fr       */
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
    Grade                           getGrade(std::string& type) const;
    
    void                            setSignGrade(Grade value);
    void                            setExecuteGrade(Grade value);
    
    void                            increaseGrade(int code);
    void                            decreaseGrade(int code);

    void                            beSigned(const Bureaucrat& Charger);
    
private:
    const std::string               name;
    const Grade                     gradeForSign;
    const Grade                     gradeForEx;
    bool                            blank;
    
    void                            tryGradeIsOk(void);
    class GradeTooHighException : public std::exception {
    public:
        virtual const char*         what(void) const throw();
    }
    class GradeTooLowException : public std::exception {
    public:
        virtual const char*         what(void) const throw();
    }
    void				    		printExceptError(GradeTooLowException& e);
    void				    		printExceptError(GradeTooHighException& e);
};

std::ostream& operator<<(std::ostream& s, const Form& target) {
    std::cout << target.getName() << " [ " << target.getGrade("sign") << " / " << target.geGrade("execute") << " ] ";
    return s;
}

#endif