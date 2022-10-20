/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:30:31 by haryu             #+#    #+#             */
/*   Updated: 2022/10/21 02:30:51 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_hpp
# define RobotomyRequestForm_hpp
class RobotomyRequestForm {
private:
	
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm& target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& target);
};
#endif