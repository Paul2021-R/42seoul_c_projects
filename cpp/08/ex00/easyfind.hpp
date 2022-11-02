/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:07:28 by haryu             #+#    #+#             */
/*   Updated: 2022/11/02 23:47:03 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>

/**
 * @brief 타입 T를 받아들여서. 벡터 T 안을 반복자로 확인 및, valTwo가 존재하면 이에 대한 대응한 반환값을 전달
 * 
 * @tparam T 
 * @param intContainer 컨테이너
 * @param valTwo 
 * @return int 0 ~ n 벡터 상에 valTwo의 위치, -1 찾지 못한 경우
 */
template<typename T>
int easyfind(const std::vector<T>& intContainer, int valTwo);


# include "easyfind.tpp"
#endif