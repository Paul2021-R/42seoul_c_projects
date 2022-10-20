/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCrationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:52:44 by haryu             #+#    #+#             */
/*   Updated: 2022/10/21 01:59:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCrationForm_hpp
# define ShrubberyCrationForm_hpp
class ShrubberyCrationForm {
private:
	
public:
	ShrubberyCrationForm(void);
	ShrubberyCrationForm(const ShrubberyCrationForm& target);
	~ShrubberyCrationForm(void);
	ShrubberyCrationForm&	operator=(const ShrubberyCrationForm& target);
};
#endif