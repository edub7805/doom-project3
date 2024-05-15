// Level.h

#ifndef LEVEL_INCLUDED
#define LEVEL_INCLUDED

#include <iostream>
#include <string>
#include <stdio.h>

class Level {
public:
    Level();
    void display() const;

private:
    static const int WIDTH = 70;
    static const int HEIGHT = 18;
    char m_grid[HEIGHT][WIDTH];

    void initializeGrid(); // Creates my grid
    void generateRooms();  // Creates the rooms within the grid
    bool canPlaceRoom(int startX, int startY, int endX, int endY);
};


#endif // LEVEL_INCLUDED
