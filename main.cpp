#include <iostream>
#include <vector>

#include "staff.h"
#include "resolution.h"

int main()
{
    // staffs {体积，价值}
	std::vector<Staff> staffList = {
		{2, 3},
		{3, 5},
		{4, 6}
	};

	std::vector<int> resolutions;

	std::cout << "max prise: " << std::endl;

	// 输出最大价值，并输出方案
	std::cout << resolution_prise(6, staffList, resolutions) << std::endl;

	std::cout << "resolutions: " << std::endl;
	for (auto i : resolutions)
		std::cout << i << std::endl;
	return 0;
}