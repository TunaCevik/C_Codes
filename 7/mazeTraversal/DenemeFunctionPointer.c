#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Duvar '#'
#define Yol '.'

bool checkerRight(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection);
bool checkerLeft(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection);
bool checkerFront(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection);
bool checkerBack(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection);

int main()
{

        const char MazeArray[12][12] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
        {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
        {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}       
    };

    bool (*Maker[4])(const char [][12], size_t, size_t, int) = {checkerRight, checkerLeft, checkerFront, checkerBack};
    for(size_t i = 0; i<4; i++){
        printf("%s",Maker[i](MazeArray, 2,0,0) == false ? "true " : "false ");
    }

    

    return 0;
}
bool checkerRight(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection)
{
    return MazeMap[RowLocation][ColumnLocation] == Yol;
}
bool checkerLeft(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection)
{
    return MazeMap[RowLocation][ColumnLocation] == Yol;
}bool checkerFront(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection)
{
    return MazeMap[RowLocation][ColumnLocation] == Yol;
}bool checkerBack(const char MazeMap[][12], size_t RowLocation, size_t ColumnLocation, int ArrayDirection)
{
    return MazeMap[RowLocation][ColumnLocation] == Yol;
}