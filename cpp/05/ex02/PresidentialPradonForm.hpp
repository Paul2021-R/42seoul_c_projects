/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPradonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:13:56 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 00:22:53 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPradonForm_hpp
# define PresidentialPradonForm_hpp

# include "Form.hpp"

class PresidentialPradonForm: public Form {
public:
									PresidentialPradonForm(void);
									PresidentialPradonForm(const std::string& target);
									PresidentialPradonForm(const PresidentialPradonForm& target);
									~PresidentialPradonForm(void);
	PresidentialPradonForm&			operator=(const PresidentialPradonForm& target);

	void							execute(const Bureaucrat & Executor) const;
private:
	std::string						target;
};
#endif