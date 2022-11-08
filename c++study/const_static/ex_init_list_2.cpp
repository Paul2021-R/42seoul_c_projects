#include <iostream>

class Marine {
	int			hp;
	int 		coord_x, coord_y;
	bool		is_dead;

	const int	default_damage;

public:
	Marine();
	Marine(int x, int y);
	Marine(int x, int y, int default_damage);
	int		attack();
	void	be_attacked(int damage_earn);
	void	move(int x, int y);

	void	status_show();
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
	: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage) :
	coord_x(x),
	coord_y(y),
	hp(50),
	default_damage(default_damage),
	is_dead(false) {}

void	Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int		Marine::attack() { return (default_damage);}
void	Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0)
		is_dead = true;
	if (is_dead == true)
		std::cout << " 마린이 죽었습니다! " << std::endl;
}
void Marine::status_show() {
	std::cout << " *** MArine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " hp : " << hp << std::endl;
}

int main(void) {
	Marine	marine1(2, 3);
	Marine	marine2(3, 5);
	Marine	marine3(3, 5, 10);

	marine1.status_show();
	marine2.status_show();
	marine3.status_show();

	std::cout << std::endl << " 마린 1이 마린 2를 3회 공격했다! " << std::endl;
	for(int i = 0; i < 3; i++) marine2.be_attacked(marine1.attack());
	std::cout << std::endl << " 마린 3이 마린 1을 5회 공격했다! " << std::endl;
	for(int i = 0; i < 5; i++) marine1.be_attacked(marine3.attack());
	
	marine1.status_show();
	marine2.status_show();
	marine3.status_show();
}
