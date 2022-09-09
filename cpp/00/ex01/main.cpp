/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:30:02 by haryu             #+#    #+#             */
/*   Updated: 2022/09/08 21:05:28 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phone.hpp"

int main(void){
	ContactElement cur(0);
	
	cur.AddContact();
	cur.ShowContact();
	return (0);
}
