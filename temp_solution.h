#pragma once

#include <vector>

//////////////////////////////////////////////////////////
//@brief �ݴ�Ľ⣬�����۸����Ʒ����
//////////////////////////////////////////////////////////

struct TempSolution
{
	TempSolution(int sumPrize, std::vector<int> s);

	void operator+=(const TempSolution& s);

	int sum_prize;
	std::vector<int> staffs;
};

