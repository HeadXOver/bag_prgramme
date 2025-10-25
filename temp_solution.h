#pragma once

#include <vector>

//////////////////////////////////////////////////////////
//@brief 暂存的解，包含价格和物品索引
//////////////////////////////////////////////////////////

struct TempSolution
{
	TempSolution(int sumPrize, std::vector<int> s);

	void operator+=(const TempSolution& s);

	int sum_prize;
	std::vector<int> staffs;
};

