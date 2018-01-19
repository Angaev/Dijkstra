#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

int main()
{
    char FileName[20];
    bool isFileLoad;
    do
    {
        std::cout << "Enter FileName (example: input.txt): " << std::endl;
        std::cin >> FileName;

        std::ifstream grafFile(FileName);
        isFileLoad = grafFile.is_open();
        if (!isFileLoad)
        {
            std::cout << "Can't found file, try again! Ctrl + C for exit " << std::endl;
        }
    } while (!isFileLoad);
    std::ifstream grafFile(FileName);
    int matrixSize;
    grafFile >> matrixSize;
    std::cout << "Matrix size: " << matrixSize << std::endl;

    float **grafMatrix = new float *[matrixSize]; // объявили двумерный массив
    for (int count = 0; count < matrixSize; count++)
        grafMatrix[count] = new float[matrixSize];

    for (int count_row = 0; count_row < matrixSize; count_row++)
        for (int count_column = 0; count_column < matrixSize; count_column++)
            grafFile >> grafMatrix[count_row][count_column];

    for (int count_row = 0; count_row < matrixSize; count_row++)
    {
        for (int count_column = 0; count_column < matrixSize; count_column++)
            std::cout << grafMatrix[count_row][count_column] << "   ";
        std::cout << std::endl;
    }

    
}