#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <windows.h>
//toDo
//загрузка из графа формата[сделано]
/*
5
1-2-10
вершина-вершина-вес
*/

//отмечать постоянные метки

//запоминать предыдущие вершины и восстанавлить по требованию (1->3->5)

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

void setColor(ConsoleColor text, ConsoleColor background)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, (WORD)((background << 4) | text));
}

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
void printState(int *distance, int matrixSize, bool *visited)
{
    for (int j = 0; j <= matrixSize - 1; j++)
    {
        if (visited[j])
        {
            setColor(Red, Black);
        }
        if (distance[j] == 10000)
        {
            std::cout << "INF"
                      << " ";
        }
        else
        {
            std::cout << distance[j] << " ";
        }
        setColor(White, Black);
    }
    std::cout << std::endl;
}

bool yesOrNo()
{
    do
    {
        char key;
        std::cin >> key;
        if (key == 'y')
        {
            return true;
        }
        else if (key == 'n')
        {
            return false;
        }
        std::cout << "use 'y' or 'n'" << std::endl;
    } while (true);
}

void zeroMatrix(int matrixSize, float **&grafMatrix)
{
    for (int count_row = 0; count_row < matrixSize; count_row++)
    {
        for (int count_column = 0; count_column < matrixSize; count_column++)
            grafMatrix[count_row][count_column] = 0;
    }
}

void printMatrix(int matrixSize, float **grafMatrix)
{
    for (int count_row = 0; count_row < matrixSize; count_row++)
    {
        for (int count_column = 0; count_column < matrixSize; count_column++)
            std::cout << grafMatrix[count_row][count_column] << "   ";
        std::cout << std::endl;
    }
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
                printState(distance, matrixSize, visited);
            }
        }
    }
    printState(distance, matrixSize, visited);

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

bool dijkstraPrintVertex(int vertex, int matrixSize, float **&grafMatrix, int target)
{
    int inf = 10000;
    int tempVertex = vertex;
    int *distance = new int[matrixSize];
    bool *visited = new bool[matrixSize];
    int min;
    int index;
    int u;
    bool wasPrint = false;

    int m = vertex;
    for (int i = 0; i < matrixSize; i++)
    {
        distance[i] = inf;
        visited[i] = false;
    }

    distance[vertex] = 0;

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
                if (i == target)
                {
                    wasPrint = true;
                    std::cout << u << " -> ";
                }
            }
        }
    }

    if (wasPrint)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    setColor(White, Black);
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

    // объявили двумерный массив
    float **grafMatrix = new float *[matrixSize];
    for (int count = 0; count < matrixSize; count++)
        grafMatrix[count] = new float[matrixSize];

    zeroMatrix(matrixSize, grafMatrix);
    // загрузка из файла-графа в матрицу
    int x, y;
    float value;
    for (int count = 0; count < matrixSize * matrixSize; count++)
    {
        grafFile >> x;
        grafFile >> y;
        grafFile >> value;
        std::cout << x << " " << y << " " << value << " " << std::endl;
        grafMatrix[x - 1][y - 1] = value;
    }

    std::cout << "\n\n Your graf in matrix:"
              << std::endl;
    //вывод полученной матрицы
    printMatrix(matrixSize, grafMatrix);
    grafFile.close();

    int vertex;
    std::cout << "Enter vertex (from 0 to " << matrixSize - 1 << "):" << std::endl;
    std::cin >> vertex;
    std::cout << std::endl;

    dijkstra(vertex, matrixSize, grafMatrix);

    std::cout << "in details? y/n: ";
    if (yesOrNo())
    {
        std::cout << "Enter your target vertex: " << std::endl;
        int target;
        std::cin >> target;
        if (dijkstraPrintVertex(vertex, matrixSize, grafMatrix, target))
        {
            std::cout << " " << target << std::endl;
        }
        else
        {
            std::cout << "No way!" << target << std::endl;
        }
    }
}
