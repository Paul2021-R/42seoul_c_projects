/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCrationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:52:44 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 00:23:03 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCrationForm_hpp
# define ShrubberyCrationForm_hpp

# include "Form.hpp"
# include <fstream>

class ShrubberyCrationForm: public Form {
public:
								ShrubberyCrationForm(void);
								ShrubberyCrationForm(const std::string& target);
								ShrubberyCrationForm(const ShrubberyCrationForm& target);
								~ShrubberyCrationForm(void);
	ShrubberyCrationForm&		operator=(const ShrubberyCrationForm& target);

	void						execute(const Bureaucrat & Executor) const;
private:
	std::string					target;
};
#endif