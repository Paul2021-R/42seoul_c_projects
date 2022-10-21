/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCrationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:52:44 by haryu             #+#    #+#             */
/*   Updated: 2022/10/21 09:36:16 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCrationForm_hpp
# define ShrubberyCrationForm_hpp

# include "Form.hpp"
# include <fstream>

class ShrubberyCrationForm: public Form {
public:
								ShrubberyCrationForm(void);
								ShrubberyCrationForm(std::string& name, Grade sign, Grade ex);
								ShrubberyCrationForm(const ShrubberyCrationForm& target);
								~ShrubberyCrationForm(void);
	ShrubberyCrationForm&		operator=(const ShrubberyCrationForm& target);

	void						execute(const Bureaucrat & Executor) const;
};
#endif