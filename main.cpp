#include <iostream>

#include "maze/maze.h"

int main(int argc, char *argv[]) {
    maze maze(3, 3);

    maze.add_road(point(0, 1), point(0, 2));
    maze.add_road(point(0, 0), point(1, 0));
    maze.add_road(point(0, 1), point(1, 1));
    maze.add_road(point(0, 2), point(1, 2));
    maze.add_road(point(1, 0), point(1, 1));
    maze.add_road(point(1, 1), point(1, 2));
    maze.add_road(point(1, 1), point(2, 1));
    maze.add_road(point(1, 2), point(2, 2));
    maze.add_road(point(2, 0), point(2, 1));
    std::cout << maze.render() << std::endl;

    return 0;
}
