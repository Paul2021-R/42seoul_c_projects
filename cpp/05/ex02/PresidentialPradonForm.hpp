/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPradonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:13:56 by haryu             #+#    #+#             */
/*   Updated: 2022/10/21 09:07:04 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPradonForm_hpp
# define PresidentialPradonForm_hpp

# include "Form.hpp"
# include <random>

class PresidentialPradonForm: public Form {
public:
	PresidentialPradonForm(void);
	PresidentialPradonForm(const PresidentialPradonForm& target);
	~PresidentialPradonForm(void);
	PresidentialPradonForm&	operator=(const PresidentialPradonForm& target);
};
#endif