/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:07:09 by haryu             #+#    #+#             */
/*   Updated: 2022/10/07 01:31:41 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_hpp
#define ScavTrap_hpp

#include "ClapTrap.hpp"

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

class ScavTrap : public ClapTrap {
private :
    std::string name;
    std::string type;
	Point_i&	hitPoint;
    Point_i     energyPoint;
    Point_i     attackDamage;
public :
    ScavTrap(void);
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& target);
    ScavTrap& operator=(const ScavTrap& target);
    ~ScavTrap(void);


    void        guardGate(void);
    void        attack(const std::string& target);

    std::string&    getName(void);
    std::string&    getType(void);
    Point_i&        getHp(void);
    Point_i&        getEp(void);
    Point_i&        getAd(void);
};

#endif