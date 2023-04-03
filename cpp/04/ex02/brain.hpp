/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:13:43 by haryu             #+#    #+#             */
/*   Updated: 2022/10/15 11:47:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef brain_hpp
# define brain_hpp

#include <iostream>
#include <string>

class Brain {
private:
	std::string* ideas;
public:
	Brain(void);
	Brain(const Brain& target);
	~Brain(void);
	Brain&			operator=(const Brain& target);
	void 			setIdeas(const std::string& str);
	void			setIdeas(const std::string& str, int num);
	std::string&	getIdeas(int num);
};

#endif