/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:07:28 by haryu             #+#    #+#             */
/*   Updated: 2022/10/30 13:28:50 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <vector>

/**
 * @brief 타입 T를 받아들여서. T 가 정수들의 컨테이너라고 추정하고, 이 함수는 두번째 매개변수 의 첫 발견을 첫 매개변수에서 발견해 내야 함. 
 * 미 발견 시, 예외 처리 해줘야 함, 또는 에러 값을 전달해야 함. 표준 컨테이너의 동작에 대해 공부할 것.
 * 
 * 
 * @tparam T 
 * @param valOne 컨테이너
 * @param valTwo 
 * @return int 
 */
template<typename T>
int easyfind(T intContainer, int valTwo);


# include "easyfind.tpp"
#endif