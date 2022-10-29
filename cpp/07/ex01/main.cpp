/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:55:48 by haryu             #+#    #+#             */
/*   Updated: 2022/10/29 14:03:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main(void) {
	int array1[]={1,2,3,4,5};
	char array2[]={'a','b','c','d','e'};
	float array3[]={1.1,2.2,3.3,4.4,5.5};

	::iter(array1, 5, printAddrVal);
	::iter(array2, 5, printAddrVal);
	::iter(array3, 5, printAddrVal);
}