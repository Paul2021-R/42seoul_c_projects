/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:43:10 by haryu             #+#    #+#             */
/*   Updated: 2022/10/21 09:31:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef From_hpp
# define From_hpp

# include "Bureaucrat.hpp"

//	abstract class
//	바람직한 순수 가상함수 클래스를 만들 때는 과감히 키워드들만 남기는 것이 효과적 이다.
//	기반 클래스의 속성은 private 로 남겨 두어야 한다. 
//	하지만 이 경우 private 멤버 변수들의 접근이 가능한 getter나 setter를 남겨야 하고, 따라서 이 방법으로 접근이 가능한가? 에 대해 애매하다. 
//	결론적으로 접근 지시자의 행동 자체가 private 접근 지시자로 인해 접근 불가가 되었으므로, Form 에 대한 초기화, getter, setter 존재가 구현되어야 하며, 그 외의 기능들에 대해서는 개별 함수에 지정되어 있어야한다. 
//	abstract class 기준, 정의되거나 상속되는 하나 이상의 함수가 재 정의가 필요한 '순수 가상 함수'를 하나 이상 포함하는 경우를 의미한다. 
//	즉, 순수 가상함수를 하나라도 포함하고 있다면, 이는 추상클래스다. 
class Form {
public:
                                    Form(void);
                                    Form(const std::string& name, Grade sign, Grade ex);
                                    Form(const Form& target);
    virtual                         ~Form(void);
    Form&                           operator=(const Form& target);

/* ************************************************************************** */

    std::string						getName(void) const;
    Grade							getGrade(const std::string& type) const;
	bool							getSignOrNot(void) const;

/* ************************************************************************** */
    
    void							beSigned(const Bureaucrat& Charger);
	/**
	 * @brief 추상 클래스 근거, 파생 클래스들에서 해야할 작업들에 대한 순수 추상함수
	 * 
	 * @param Executor 권한을 가지고 실행할 대상
	 */
	virtual void					execute(const Bureaucrat& Executor) const = 0;    
private:
    const std::string               name;
    const Grade                     gradeForSign;
    const Grade                     gradeForEx;
    bool                            blank;
    
    void							tryGradeIsOk(const Grade& value);
    class GradeTooHighException : public std::exception {
    public:
        virtual const char*         what(void) const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char*         what(void) const throw();
    };
    void							printExceptError(GradeTooLowException& e);
    void							printExceptError(GradeTooHighException& e);
};

std::ostream& operator<<(std::ostream& s, const Form& target);

#endif