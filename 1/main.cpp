#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
//toDo
//загрузка из графа формата
/*
5
1-2-10
вершина-вершина-вес
*/

//отмечать постоянные метки

//запоминать предыдущие вершины и восстанавлить по требованию (1->3->5)

//печатает заголовок
void printHeader(int matrixSize)
{
    for (int j = 0; j <= matrixSize - 1; j++)
    {
        std::cout << j << "  ";
    }
    std::cout << std::endl;
}

//печатает состояние во время составления массива пути
void printState(int *distance, int matrixSize)
{
    for (int j = 0; j <= matrixSize - 1; j++)
    {
        if (distance[j] == 10000)
        {
            std::cout << "INF"
                      << " ";
        }
        else
        {
            std::cout << distance[j] << " ";
        }
    }
    std::cout << std::endl;
}

void dijkstra(int vertex, int matrixSize, float **&grafMatrix)
{
    int inf = 10000;
    int tempVertex = vertex;
    int *distance = new int[matrixSize];
    bool *visited = new bool[matrixSize];
    int min;
    int index;
    int u;

    int m = vertex;
    for (int i = 0; i < matrixSize; i++)
    {
        distance[i] = inf;
        visited[i] = false;
    }

    distance[vertex] = 0;
    printHeader(matrixSize);

    for (int count = 0; count <= matrixSize - 2; count++)
    {
        min = inf;
        for (int i = 0; i <= matrixSize - 1; i++)
        {
            if (!visited[i] && distance[i] <= min)
            {
                min = distance[i];
                index = i;
            }
        }

        u = index;
        visited[u] = true;
        for (int i = 0; i <= matrixSize - 1; i++)
        {
            if ((!visited[i] && grafMatrix[u][i] != 0) &&
                (distance[u] != inf) && (distance[u] + grafMatrix[u][i] < distance[i]))
            {
                distance[i] = distance[u] + grafMatrix[u][i];
                printState(distance, matrixSize);
            }
        }
    }

    std::cout << "price distance form your vertex to any" << std::endl;
    for (int i = 0; i <= matrixSize - 1; i++)
    {
        if (distance[i] != inf)
        {
            std::cout << m << " -> " << i << " = " << distance[i] << std::endl;
        }
        else
        {
            std::cout << m << " -> " << i << " = No way" << std::endl;
        }
    }
}

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
    grafFile.close();

    int vertex;
    std::cout << "Enter vertex (from 0 to " << matrixSize - 1 << "):" << std::endl;
    std::cin >> vertex;
    std::cout << std::endl;

    dijkstra(vertex, matrixSize, grafMatrix);
}