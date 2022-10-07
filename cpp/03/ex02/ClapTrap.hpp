/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:27:33 by haryu             #+#    #+#             */
/*   Updated: 2022/10/07 01:13:28 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


// 상속의 조건을 명확히 이해해야 한다. 
/*
ex00 에서 해야할 일 
1) 출력부에서 상속이 될 것을 고려한 ClapTrap이라는 표현 삭제 
2) 상속해서 사용 가능한 멤버 함수들에 대해서 이해하고, 이 부분이 같이 사용 가능하도록 모듈화 시킬것 
*/

/* 
1) 각 멤버 변수들은 동일하게 ClapTrap의 그것을 쓴다. 
2) 그러나 이때 hitPoint 는 represent the health of the ClapTrap 이라고 하였으니 만큼, 특정 값으로 하되, 레퍼런스 타입으로 하는게 타당하다. 
3) 나머지 멤버들은 그냥 ClapTrap에서 상속 받아 사용한다. 
4) 출력을 다르게 해야 하는 만큼, 값은 기반 클래스에서 들고오되, 메시지를 다르게 출력하는 함수 오버라이딩이 되어야 한다(동일 함수명, 그러나 해당 클래스 에서만 사용하는 방식으로)
5) 고유한 것들은 해당 클래스에서 직접 구현 되어야 한다. 
*/

/*
개선해야할 사항 
1) 출력 파트에서 ClapTrap 이라는 부분을 독립적으로 만들어 버리기(그러면 공통 부분은 그대로 쓸 수 있음)
2) 강제 세팅하는 함수들의 경우 ClapTrap 등의 구체적인 표현은 삭제 해야 한다. 
*/

#include <iostream>
#include <string>

typedef	unsigned int			Point_i;

class ClapTrap 
{
private:
	std::string 	name;
	std::string		type;
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
	 * @brief 활동 에너지를 관리하기 위한 멤버함수. 상속하여 사용 가능함수. 
	 * 
	 * @return true 에너지 사용함
	 * @return false 에너지 사용 불가 
	 */
	bool	useEnergy(void);
	bool	useEnergy(Point_i& ep);

	/**
	 * @brief 타겟을 지정된 데미지 만큼 공격하고, 활동한 것 만큼 에너지를 소비한다.
	 * 
	 * @param target 
	 */
	void	attack(const std::string& target);
	void	attack(const std::string& target, const std::string name_, const std::string& type_, const Point_i hp, Point_i& ep, const Point_i ad);

	/**
	 * @brief 지정된 양만큼의 공격을 당한다. 
	 *
	 * @param amount 
	 */
	void	takeDamage(Point_i amount);
	void	takeDamage(Point_i amount, const std::string& name_, const std::string& type_, Point_i& hp);

	/**
	 * @brief 지정된 양 만큼 회복한다. 
	 *
	 * @param amount 
	 */
	void	beRepaired(Point_i amount);
	void	beRepaired(Point_i amount, const std::string name_, const std::string& type_, Point_i& hp, Point_i& ep);

	/**
	 * @brief System 권한, 인자 만큼 객체의 값을 수정한다. 
	 *
	 * @param amount
	 * @return ture 값 수정 성공
	 * @return false 값 수정 실패
	 */
	bool	initHitPoint(Point_i amount);
	bool	initHitPoint(Point_i amount, const std::string& name, const std::string& type_, Point_i& hp);

	/**
	 * @brief System 권한, 인자 만큼 객체의 값을 수정한다. 
	 *
	 * @param amount
	 * @return ture 값 수정 성공
	 * @return false 값 수정 실패
	 */
	bool	initEnergyPoint(Point_i amount);
	bool	initEnergyPoint(Point_i amount, const std::string& name_, const std::string& type_, Point_i& ep);

	/**
	 * @brief System 권한, 인자 만큼 객체의 값을 수정한다. 
	 *
	 * @param amount
	 * @return ture 값 수정 성공
	 * @return false 값 수정 실패
	 */
	bool	initAttackDamage(Point_i amount);
	bool	initAttackDamage(Point_i amount, const std::string& name_, const std::string& type_, Point_i& ad);

	/**
	 * @brief System 권한, string 클래스 인자로 수정된다.
	 *
	 * @param target 수정할 이름
	 * @return ture 값 수정 성공
	 * @return false 값 수정 실패
	 */
	bool	setName(std::string target);
	bool	setName(std::string target, std::string& name_, const std::string& type_);

	/**
	 * @brief 공격에 대한 출력 파트
	 * 
	 * @param target 
	 * @param code 
	 */
	void	printAttack(const std::string& target, const int code);
	void	printAttack(const std::string& target, const int code, const std::string& name_, const std::string& type_, const Point_i ad);

	/**
	 * @brief 공격받음 대한 출력 파트
	 * 
	 * @param amount 
	 * @param code 
	 */
	void	printTakeDamage(Point_i amount, int code);
	void	printTakeDamage(Point_i amount, int code, const std::string name_, const std::string type_, const Point_i& hp);

	/**
	 * @brief 회복 활동에 대한 출력 파트
	 * 
	 * @param amount 
	 * @param code 
	 */
	void	printBeRepaired(Point_i amount, int code);
	void	printBeRepaired(Point_i amount, int code, const std::string& name_, const std::string& type_);

	/**
	 * @brief 생성자 생성 성공 시 출력할 메시지
	 *
	 */
	void	printConstructor(std::string type);
	void	printConstructor(std::string name_, std::string type_, Point_i hp, Point_i ep, Point_i ad) const;
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
