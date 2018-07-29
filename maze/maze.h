#ifndef _CPP_HEADER_MAZE_H_
#define _CPP_HEADER_MAZE_H_

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <sstream>

typedef std::pair<int, int> point;

static inline point mid_point(const point &pt1, const point &pt2) {
    return point((pt1.first + pt2.first) / 2, (pt1.second + pt2.second) / 2);
}

template<typename InputIt, typename UnaryOp>
std::string join(InputIt first, InputIt last, UnaryOp unary_op, const std::string &deli = std::string()) {
    std::vector<std::string> strs;
    std::transform(first, last, std::back_inserter(strs), unary_op);

    std::ostringstream oss;
    std::copy(strs.begin(), strs.end(), std::ostream_iterator<std::string>(oss, deli.c_str()));

    std::string str= oss.str();
    return str.empty() ? str : str.substr(0, str.length() - deli.length());
}

#define CELL 1
#define WALL 2
#define ROAD CELL

#define RUNE_ROAD "[R]"
#define RUNE_WALL "[W]"

class Maze {
public:
    Maze(int cell_rows, int cell_cols);

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
