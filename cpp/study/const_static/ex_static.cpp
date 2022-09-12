// static 변수 사용 예시

#include <iostream>

class Marine {
	static int	total_marine_num; 
	int			hp;                // 마린 체력
	int			coord_x, coord_y;  // 마린 위치
	bool		is_dead;

	const int	default_damage;  // 기본 공격력

	public:
	Marine();              // 기본 생성자
	Marine(int x, int y);  // x, y 좌표에 마린 생성
	Marine(int x, int y, int default_damage);

	int		attack();                       // 데미지를 리턴한다.
	void	be_attacked(int damage_earn);  // 입는 데미지
	void	move(int x, int y);            // 새로운 위치

	void	show_status();  // 상태를 보여준다.

	~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage) : 
	coord_x(x),
	coord_y(y),
	hp(50),
	default_damage(default_damage),
	is_dead(false) {
	total_marine_num++;
}

void	Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int		Marine::attack() { return default_damage; }
void	Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}
void	Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
	std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void	create_marine() {
	Marine marine3(10, 10, 4);
	marine3.show_status();
}
int main(void) {
	Marine marine1(2, 3, 5);
	marine1.show_status();

	Marine marine2(3, 5, 10);
	marine2.show_status();

	create_marine();

	std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}
