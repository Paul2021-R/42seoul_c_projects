#include <iostream>

class Marine {
	static int TotalMarineNum;
	const static int i = 0;

	int hp;
	int coord_x, coord_y;
	bool IsDead;

	const int DefaultDamage;

	public:
		Marine();
		Marine(int x, int y);
		Marine(int x, int y, int DefaultDamage);

		int Attack() const;
		Marine& BeAttacked(int DamageEarn);
		void Move(int x, int y);
		void ShowStatus();
		static void ShowTotalMarine();
		~Marine() {TotalMarineNum--;}
};

int Marine::TotalMarineNum = 0;

void Marine::ShowTotalMarine() {
	std::cout << "전체 마린 수 : " << TotalMarineNum << std::endl;
}

Marine::Marine() :
	hp(50), coord_x(0), coord_y(0), DefaultDamage(5), IsDead(false) {TotalMarineNum++;}

Marine::Marine(int x, int y) :
	hp(50), coord_x(x), coord_y(y), DefaultDamage(5), IsDead(false) {TotalMarineNum++;}

Marine::Marine(int x, int y, int DefaultDamage) :
	hp(50), coord_x(x), coord_y(y), DefaultDamage(DefaultDamage), IsDead(false) {TotalMarineNum++;}

void Marine::Move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::Attack() const {return DefaultDamage;}

Marine& Marine::BeAttacked(int DamageEarn) {
	this->hp -= DamageEarn;
	if (this->hp <= 0) IsDead = true;

	return *this;
}

void Marine::ShowStatus() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
	std::cout << " 현재 총 마린 수 : " << TotalMarineNum << std::endl;
}

int main(void) {
	Marine marine1(2, 3, 5);
	marine1.ShowStatus();

	Marine marine2(3, 5, 10);
	marine2.ShowStatus();

	std::cout << std::endl << "마린 1이 마린 2를 두번 공격 했다!" << std::endl;
	marine2.BeAttacked(marine1.Attack()).BeAttacked(marine1.Attack());

	marine1.ShowStatus();
	marine2.ShowStatus();
}
