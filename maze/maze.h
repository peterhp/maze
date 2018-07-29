#ifndef _CPP_HEADER_MAZE_H_
#define _CPP_HEADER_MAZE_H_

#include <string>
#include <vector>
#include <utility>

typedef std::pair<int, int> point;

static inline point mid_point(const point &pt1, const point &pt2) {
    return point((pt1.first + pt2.first) / 2, (pt1.second + pt2.second) / 2);
}

#define CELL 1
#define WALL 2
#define ROAD CELL

#define RUNE_ROAD "[R]"
#define RUNE_WALL "[W]"

class maze {
public:
    maze(int cell_rows, int cell_cols);

    void add_road(const point &cell1, const point &cell2);

    std::string render() const;

private:
    inline static int axis_c2m(int c_axis) {
        return c_axis * 2 + 1;
    }

    inline static point pos_c2m(const point &cell) {
        return point(axis_c2m(cell.first), axis_c2m(cell.second));
    }

private:
    std::vector<std::vector<int>> grid;
};

#endif // maze.h
