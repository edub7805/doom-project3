//  Level.cpp
//  Proj3

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Level.h"
#include "utilities.h"

using namespace std;

Level::Level() {
    srand(time(nullptr)); // Seed the random generator
    initializeGrid();
    generateRooms();
}

void Level::initializeGrid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            m_grid[i][j] = '#'; // Fill grid with walls
        }
    }
}

void Level::generateRooms() {
    int numRooms = rand() % 3 + 4; // Generate between 4 and 6 rooms
    int maxAttempts = 50; // To avoid an infinite loop
    for (int attempt = 0; attempt < numRooms && attempt < maxAttempts; attempt++) {
        int roomWidth = rand() % 6 + 10; // Room widths between 10 and 15
        int roomHeight = rand() % 8 + 3; // Room heights between 3 and 10
        int x = rand() % (WIDTH - roomWidth - 2) + 1; // Randomize our starting x
        int y = rand() % (HEIGHT - roomHeight - 2) + 1; // and y

        if (canPlaceRoom(x, y, roomWidth, roomHeight)) {
            for (int i = y; i < y + roomHeight; i++) {
                for (int j = x; j < x + roomWidth; j++) {
                    m_grid[i][j] = ' '; // Place room
                }
            }
        }
        else attempt--; // If the room is not valid, lower the number of rooms
    }
}

bool Level::canPlaceRoom(int startX, int startY, int roomWidth, int roomHeight) {
    int endX = startX + roomWidth + 1;  // Extra space for right border
    int endY = startY + roomHeight + 1; // Extra space for bottom border
    
    // Check if the room is within the grid boundaries
    if (startX - 1 < 0 || startY - 1 < 0 || endX >= WIDTH || endY >= HEIGHT) {
        return false;  // The room extends beyond the grid
    }
    
    for (int i = startY - 1; i <= endY; i++) {
        for (int j = startX - 1; j <= endX; j++) {
            if (m_grid[i][j] == ' ') return false; // Check if the room overlaps
        }
    }
    return true;
}

void Level::display() const {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << m_grid[i][j];
        }
        cout << endl;
    }
}
