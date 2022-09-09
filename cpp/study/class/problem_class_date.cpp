#include <iostream>

class Date {
	private:
		int	year;
		int	month;
		int	date;
	public:
		void	SetDate(void){
			int sp_month[7] = {1, 3, 5, 7, 8, 10, 12};
			std::cout << "날짜의 초기 설정을 시작합니다." << std::endl;
			int value;
			std::cout << "연도를 입력하세요. : ";
			std::cin >> value;
			if (value <= 0) {
				std::cout << "연도를 다시 입력해주세요. : ";
				std::cin >> value;
			}
			year = value;
			std::cout << "달을 입력해주세요. : ";
			std::cin >> value;
			while (value < 1 || value > 12) {
				std::cout << "달을 다시 입력해주세요. : ";
				std::cin >> value;
			}
			month = value;
			std::cout << "일을 입력해주세요. : ";
			std::cin >> value;
			while (true) {
				if (value >= 1 || value <= 31) {
					if (month == 2 && value <= 28)
						break ;
					else {
						for (int i = 0; i < 7 ; i++){
							if (sp_month[i] == month)
								if (value <= 31)
									break ;
						}
						if (month != 2 && value <= 30)
							break ;
					}
				}
				std::cout << "요일을 다시 입력해주세요. : ";
				std::cin >> value;
			}
			date = value;
			std::cout << "초기 일자 설정이 마무리 되었습니다." << std::endl;
			showDate();
		};
		void	AddDay(){
			int value;
			int date_limit[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			std::cout << "몇 일을 추가하시겠습니까? : ";
			std::cin >> value;
			while (value){
				if (date_limit[month] < date + value){
					value -= date_limit[month] - date;
					if (month == 12)
						month = 0;
					else
						month++;
					date = 0;
				}
				else {
					date += value;
					value = 0;
				}
			}
			showDate();
		};
		void	AddMonth(){
			int value;
			int date_limit[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			std::cout << "몇 개월을 추가하시겠습니까? : ";
			std::cin >> value;
			while (value) {
				if (month + value <= 12)
				{
					month += value;
					value = 0;
				}
				else {
					value -= 12 - month + 1;
					year++;
					month = 1;
					if (date_limit[month] < date)
					{
						month++;
						date = 1;
					}
				}
			}
			showDate();
		};
		void	AddYear(){
			int value;
			std::cout << "몇 년을 추가하시겠습니까? : ";
			std::cin >> value;
			year += value;
			showDate();
		};
		void	showDate(){
			std::cout << "설정된 날짜는 " << year << "년 " << month << "월 " << date << "일 입니다." << std::endl;
		};
};

int main() {
	Date remainder;
	int	answer;

	remainder.SetDate();
	while (true)
	{
		std::cout << "날짜를 추가 하시겠습니까? (1) Yes (2) No" << std::endl;
		std::cin >> answer;
		if (answer == 2)
			break ;
		std::cout << "추가할 범주를 고르십시오. (1) 연도 (2) 월 (3)일" << std::endl;
		std::cin >> answer;
		if (answer == 1)
			remainder.AddYear();
		else if (answer == 2)
			remainder.AddMonth();
		else if (answer == 3)
			remainder.AddDay();
		else{
			std::cout << "잘못 입력 하셨습니다. 전단계로 돌아갑니다." << std::endl;
		}
	}
	std::cout << "최종 확정 일자는 ";
	remainder.showDate();
	return (0);
}
