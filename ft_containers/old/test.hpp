/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:23:34 by haryu             #+#    #+#             */
/*   Updated: 2022/12/21 23:16:44 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <sys/time.h>

#include <__tree>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include "__tree.hpp"
#include "iterator.hpp"
#include "map.hpp"
#include "set.hpp"
#include "stack.hpp"
#include "type_traits.hpp"
#include "utility.hpp"
#include "vector.hpp"

#define L_CYAN "\033[1;96m"
#define RESET "\033[0m"
#define PRINT(...) std::cout, L_CYAN, __VA_ARGS__, RESET, "\n"

template <typename T>
std::ostream& operator,(std::ostream& out, const T& t) {
  out << t;
  return out;
}



#endif 