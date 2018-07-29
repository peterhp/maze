#include "maze.h"

#include <string>
#include <vector>
#include <utility>
#include <algorithm>

Maze::Maze(int cell_rows, int cell_cols) {
    grid = std::vector<std::vector<int>>(axis_c2m(cell_rows),
            std::vector<int>(axis_c2m(cell_cols), WALL));

    for (auto cell_row = 0; cell_row < cell_rows; ++cell_row) {
        for (auto cell_col = 0; cell_col < cell_cols; ++cell_col) {
            grid[axis_c2m(cell_row)][axis_c2m(cell_col)] = CELL;
        }
    }
}

void Maze::add_road(const point &cell1, const point &cell2) {
    auto road_pos = mid_point(pos_c2m(cell1), pos_c2m(cell2));
    grid[road_pos.first][road_pos.second] = ROAD;
}

std::string Maze::render() const {
    std::vector<std::string> rows;
    std::transform(grid.begin(), grid.end(), std::back_inserter(rows), [](auto row) {
        return join(row.begin(), row.end(), [](auto cell) {
            return cell == WALL ? RUNE_WALL : RUNE_ROAD;
        }, " * ");
    });

    return join(rows.begin(), rows.end(), [](const std::string &s) { return s; }, "\n");
}
