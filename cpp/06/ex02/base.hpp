/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:01:56 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 09:59:24 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef base_hpp
# define base_hpp

#include <iostream>
#include <string>

class Base {
public:
	virtual ~Base(void) {}
	virtual void printMyself(void) = 0;
	static int seed;
};
#endif