#include "temp_solution.h"

TempSolution::TempSolution(int sumPrize, std::vector<int> s) : sum_prize(sumPrize), staffs(s)
{
}

void TempSolution::operator+=(const TempSolution& s)
{
    this->sum_prize += s.sum_prize;
    for (auto i : s.staffs)
        this->staffs.push_back(i);
}
