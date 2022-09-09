#include <iostream>

int main(){
	int	arr[3] = {0, 1, 2};
	int (&ref)[3] = arr;

	for (int idx = 0; idx < 3; idx++)
		std::cout << ref[idx] << std::endl;
	return (0);
}
