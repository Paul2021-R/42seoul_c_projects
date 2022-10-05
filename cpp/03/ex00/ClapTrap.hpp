/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:27:33 by haryu             #+#    #+#             */
/*   Updated: 2022/10/05 16:27:30 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

typedef	unsigned int			Point_i;

class ClapTrap 
{
private:
	std::string 	name;
	Point_i			hitPoint;
	Point_i			energyPoint;
	Point_i			attackDamage;

public:
	//OCCF
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(std::string name, Point_i hp, Point_i ep, Point_i ad);
	ClapTrap(const ClapTrap& target);
	~ClapTrap(void);
	ClapTrap&	operator=(const ClapTrap &target);

	/**
	 * @brief 활동 에너지를 관리하기 위한 멤버함수.
	 * 
	 * @return true 에너지 사용함
	 * @return false 에너지 사용 불가 
	 */
	bool	useEnergy(void);
	/**
	 * @brief 타겟을 지정된 데미지 만큼 공격하고, 활동한 것 만큼 에너지를 소비한다.
	 * 
	 * @param target 
	 */
	void	attack(const std::string& target);
	/**
	 * @brief 지정된 양만큼의 공격을 당한다. 
	 *
	 * @param amount 
	 */
	void	takeDamage(Point_i amount);
	/**
	 * @brief 지정된 양 만큼 회복한다. 
	 *
	 * @param amount 
	 */
	void	beRepaired(Point_i amount);

	/**
	 * @brief System 권한, 인자 만큼 객체의 값을 수정한다. 
	 *
	 * @param amount
	 * @return ture 값 수정 성공
	 * @return false 값 수정 실패
	 */
	bool	initHitPoint(Point_i amount);
	/**
	 * @brief System 권한, 인자 만큼 객체의 값을 수정한다. 
	 *
	 * @param amount
	 * @return ture 값 수정 성공
	 * @return false 값 수정 실패
	 */
	bool	initEnergyPoint(Point_i amount);
	/**
	 * @brief System 권한, 인자 만큼 객체의 값을 수정한다. 
	 *
	 * @param amount
	 * @return ture 값 수정 성공
	 * @return false 값 수정 실패
	 */
	bool	initAttackDamage(Point_i amount);
	/**
	 * @brief System 권한, string 클래스 인자로 수정된다.
	 *
	 * @param target 수정할 이름
	 * @return ture 값 수정 성공
	 * @return false 값 수정 실패
	 */
	bool	setName(std::string target);
	void	printAttack(const std::string& target, const int code);
	void	printTakeDamage(Point_i amount, int code);
	void	printBeRepaired(Point_i amount, int code);
	/**
	 * @brief 생성자 생성 성공 시 출력할 메시지
	 *
	 */
	void	printConstructor(void);
};

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

#endif
