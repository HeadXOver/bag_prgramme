#include "resolution.h"

#include "temp_solution.h"
#include "staff.h"

int resolution_prise(int volumn, std::vector<Staff>& staffs, std::vector<int>& out_resolution_index)
{
    const int staff_size = (int)staffs.size();

    std::vector<std::vector<TempSolution>> temp_solution_map(staff_size + 1, std::vector<TempSolution>(volumn + 1, TempSolution(0, std::vector<int>())));

    for (int j = 0; j <= volumn; ++j) {
        temp_solution_map[0][j] = TempSolution(0, {});
    }

    for (int j = 0; j <= staff_size; ++j) {
        temp_solution_map[0][j] = TempSolution(0, {});
    }

    TempSolution chose(0, {});
    TempSolution not_chose(0, {});
    for (int i = 1; i <= staff_size; ++i) {
        for (int j = 1; j <= volumn; ++j) {
            not_chose = temp_solution_map[i - 1][j];

            if (j < staffs[i - 1].volumn) {
                temp_solution_map[i][j] = not_chose;
                continue;
            }

            chose = TempSolution(staffs[i - 1].price, {i});
            chose += temp_solution_map[i - 1][j - staffs[i - 1].volumn];

            if (chose.sum_prize > not_chose.sum_prize) {
                temp_solution_map[i][j] = chose;
            }
            else {
                temp_solution_map[i][j] = not_chose;
            }
        }
    }

    out_resolution_index = temp_solution_map[staff_size][volumn].staffs;

    return temp_solution_map[staff_size][volumn].sum_prize;
}
