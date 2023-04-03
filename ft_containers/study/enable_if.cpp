#include <iostream>
#include <vector>

int main() {

// Create Vector { 8, 8, 8, 8}
std::vector<int> v1(4, 8);

while(!v1.empty()) {
	int val = *(v1.begin());
	std::cout << val << " ";
	v1.pop_back();
}
std::cout << std::endl;

// // Create another vector {8, 8, 8, 8}
// std::vector<int> v2(std::begin(v1), v1.end());

// // Create the vector {1, 2, 3, 4}
// int arr[] = {1, 2, 3, 4, 5, 6, 7};
// std::vector<int> v3(arr, arr + 4);

}