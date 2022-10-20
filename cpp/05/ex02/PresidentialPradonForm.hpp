/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidenttialPradonForm.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:13:56 by haryu             #+#    #+#             */
/*   Updated: 2022/10/21 02:14:13 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPradonForm_hpp
# define PresidentialPradonForm_hpp
class PresidentialPradonForm {
private:
	
public:
	PresidentialPradonForm(void);
	PresidentialPradonForm(const PresidentialPradonForm& target);
	~PresidentialPradonForm(void);
	PresidentialPradonForm&	operator=(const PresidentialPradonForm& target);
};
#endif