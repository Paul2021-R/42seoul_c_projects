/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:21:22 by haryu             #+#    #+#             */
/*   Updated: 2022/11/02 21:58:25 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
int easyfind(const std::vector<T>& intContainer, int valTwo) {
	int ret = 0;

	for (typename std::vector<T>::const_iterator itr = intContainer.cbegin(); itr != intContainer.cend(); ++itr) {
		if (*itr == valTwo) {
			return (ret);
		}
		ret++;
	}
	return (-1);
}