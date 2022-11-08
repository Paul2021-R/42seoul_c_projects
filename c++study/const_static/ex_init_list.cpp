#include <iostream>

class Marine {
	int		hp;
	int 	coord_x, coord_y;
	int		damage;
	bool	is_dead;

public:
	Marine();
	Marine(int x, int y);
	int		attack();
	void	be_attacked(int damage_earn);
	void	move(int x, int y);

	void	status_show();
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
	: coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

void	Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int		Marine::attack() { return (damage);}
void	Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0)
		is_dead = true;
}
void Marine::status_show() {
	std::cout << " *** MArine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " hp : " << hp << std::endl;
}

int main(void) {
	Marine	marine1(2, 3);
	Marine	marine2(3, 5);

	marine1.status_show();
	marine2.status_show();
}
