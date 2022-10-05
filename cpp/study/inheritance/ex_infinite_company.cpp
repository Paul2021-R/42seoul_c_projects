#include "infiniteCompany.hpp"

/*
int main() {
  EmployeeList emp_list(10);
  emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
  emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

  emp_list.add_employee(new Employee("유재석", 41, "부장", 7));
  emp_list.add_employee(new Employee("정준하", 43, "과장", 4));
  emp_list.add_employee(new Employee("박명수", 43, "차장", 5));
  emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
  emp_list.add_employee(new Employee("길", 36, "인턴", -2));
  emp_list.print_employee_info();
  return 0;
}*/

int main() {
  EmployeeList emp_list(10);
  emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
  emp_list.add_employee(new Employee("하하", 34, "평사원", 1));
  emp_list.add_manager(new Manager("유재석", 41, "부장", 7, 12));
  emp_list.add_manager(new Manager("정준하", 43, "과장", 4, 15));
  emp_list.add_manager(new Manager("박명수", 43, "차장", 5, 13));
  emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
  emp_list.add_employee(new Employee("길", 36, "인턴", -2));
  emp_list.print_employee_info();
  return 0;
}
