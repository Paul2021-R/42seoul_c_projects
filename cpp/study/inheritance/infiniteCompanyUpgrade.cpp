#include <iostream>
#include <string>

typedef unsigned int INT;

class Employee {
protected:
	std::string		name;
	INT				age;
	std::string		position;
	INT				rank;
public:
	Employee(std::string name, INT age, std::string position, INT rank)
		: name(name), age(age), position(position), rank(rank) {}

	Employee(const Employee& target) {
		name = target.name;
		age = target.age;
		position = target.position;
		rank = target.rank;
	}

	virtual void print_info(void) {
		std::cout << name << " (" << position << " , " << age << ") ==> " << calculate_pay() << "만원" << std::endl;
	}
	virtual INT calculate_pay(void) { return 200 + rank * 50;}
};

class Manager : public Employee {
private:
	INT	yearOfService;
public:
	Manager(std::string name, INT age, std::string position, INT rank, INT yearOfService)
		: Employee(name, age, position, rank), yearOfService(yearOfService) {};
	INT	calculate_pay(void) override { return (200 + rank * 50 + 5 * yearOfService); }
	void print_info(void) override {
		std::cout << name << " (" << position << " , " << age << ") ==> " << calculate_pay() << "만원" << std::endl;
	}
};

class EmployeeList {
private:
	INT	alloc_employee;			// 할당한 총 직원 수
	INT	current_employee;		// 현재 직원 수
	Employee** employee_list;	// 직원 데이터
public:
	EmployeeList(INT alloc_employee): alloc_employee(alloc_employee) {
		employee_list = new Employee*[alloc_employee];
		current_employee = 0;
	}
	void add_employee(Employee* employee) {
	    // 사실 current_employee 보다 alloc_employee 가 더
    	// 많아지는 경우 반드시 재할당을 해야 하지만, 여기서는
    	// 최대한 단순하게 생각해서 alloc_employee 는
    	// 언제나 current_employee 보다 크다고 생각한다.
    	// (즉 할당된 크기는 현재 총 직원수 보다 많음)
		employee_list[current_employee] = employee;
		current_employee++;
	}
	int current_employee_num() { return current_employee; }
	void print_employee_info() {
		INT total_pay = 0;

		for (int i = 0; i < current_employee; i++) {
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
	}
	~EmployeeList() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];
		}
		delete[] employee_list;
	}
};

int main() {
  EmployeeList emp_list(10);
  emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
  emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

  emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
  emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
  emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
  emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
  emp_list.add_employee(new Employee("길", 36, "인턴", -2));
  emp_list.print_employee_info();
  return 0;
}