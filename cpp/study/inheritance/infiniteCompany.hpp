#ifndef infiniteCompany_hpp
#define infiniteCompany_hpp

#include <iostream>
#include <string>

class Employee {
protected:
	std::string		name;
	int				age;

	std::string		position;
	int				rank;
public:
	Employee(std::string name, int age, std::string position, int rank) :
		name(name), age(age), position(position), rank(rank) {}
	Employee(const Employee& copy) {
		name = copy.name;
		age = copy.age;
		position = copy.position;
		rank = copy.rank;
	}
	void print_info(void) {
		std::cout << name << " (" << position << " , " << age << ") ==> " << calculate_pay() << "만원" << std::endl;
	}
	int calculate_pay(void) {
		return (200 + rank * 50);
	}
};

class Manager : public Employee {
	int year_of_service;

public : 
	Manager(std::string name, int age, std::string position, int rank, int year_of_service) : 
	year_of_service(year_of_service), Employee(name, age, position, rank) {}
	// 복사 생성자
	Manager(const Manager& manager)
		: Employee(manager.name, manager.age, manager.position, manager.rank) {
			year_of_service = manager.year_of_service;
		}

	int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service;}
	void print_info() {
		std::cout << name << " (" << position << " , " << age << ", " << year_of_service << "년차) ==> " << calculate_pay() << "만원" << std::endl;
	}
};

class EmployeeList {
private:
	int		alloc_employee; // 할당한 총 직원 수
	int		current_employee; // 현재 직원 수
	int		current_manager; //현재 매니저 수 
	Employee	**employee_list; // 직원 데이터 
	Manager		**manager_list; // 매니저 데이터 

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee*[alloc_employee];
		manager_list = new Manager*[alloc_employee];

		current_employee = 0;
		current_manager = 0;
	}

	// 사실 current_employee 보다 alloc_employee 가 더
    // 많아지는 경우 반드시 재할당을 해야 하지만, 여기서는
    // 최대한 단순하게 생각해서 alloc_employee 는
    // 언제나 current_employee 보다 크다고 생각한다.
    // (즉 할당된 크기는 현재 총 직원수 보다 많음)
	void add_employee(Employee* employee) {
		employee_list[current_employee] = employee;
		current_employee++;
	}
	void add_manager(Manager* manager) {
		manager_list[current_manager] = manager;
		current_manager++;
	}

	int current_employee_num(){
		return current_employee;
	}
	void print_employee_info() {
		int total_pay = 0;
		for (int idx = 0; idx < current_employee; idx++) {
			employee_list[idx]->print_info();
			total_pay += employee_list[idx]->calculate_pay();
		}
		for (int idx = 0; idx < current_manager; idx++) {
			manager_list[idx]->print_info();
			total_pay += manager_list[idx]->calculate_pay();
		}
		std::cout << "총 비용 : " << total_pay << "만원 " << std::endl;
	}
	~EmployeeList() {
		for (int idx = 0; idx < current_employee; idx++) {
			delete employee_list[idx];
		}
		for (int idx = 0; idx < current_manager; idx++) {
			delete manager_list[idx];
		}
		delete [] employee_list;
		delete [] manager_list;
	}
};

#endif
