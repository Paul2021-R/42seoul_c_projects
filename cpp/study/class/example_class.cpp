#include <iostream>

class Animal {
	private:
		int food;
		int weight;

	public:
		void	set_animal(int _food, int _weight){
			food = _food;
			weight = _weight;
		}
		void	increase_food(int inc){
			food += inc;
			weight += (inc / 3);
		}
		void	view_stat() {
			std::cout << "이 동물의 food   : " << food << std::endl;
			std::cout << "이 동물의 weight : " << weight << " kg" << std::endl;
		}
		int	GetWeight(){
			return (weight);
		}
};

int main(){
	Animal animal;
	std::cout << "이 동물의 초기값을 설정해 주십시오." << std::endl;
	int set_food;
	int set_weight;
	std::cout << "초기 food 값 : ";
	std::cin >> set_food;
	std::cout << "초기 weight 값 : ";
	std::cin >> set_weight;
	animal.set_animal(set_food, set_weight);
	while (true)
	{
		std::cout << "음식을 얼마나 주시겠습니까? ";
		std::cin >> set_food;
		animal.increase_food(set_food);
		animal.view_stat();
		if (animal.GetWeight() > 100)
		{
			std::cout << "이 동물이 다 컸습니다!" << std::endl;
			break ;
		}
	}
	return (0);
}
