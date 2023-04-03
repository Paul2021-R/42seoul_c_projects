/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 03:17:21 by haryu             #+#    #+#             */
/*   Updated: 2022/09/24 10:37:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class harl;

typedef struct s_type {
		std::string	level;
		void		(harl::*funcPtr)(void);
	}				t_type;

class harl 
{
private:
	t_type	funct[5];
	
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	wrongType(void);

public:
	harl(void);
	void	complain(std::string level);
};

#endif