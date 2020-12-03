/* Seth Tal
 * 12 / 03 / 2020
 * Day1 puzzle, Part 1: Finding the numbers from "input" that sum to 2020
*/

// Contains includes for this file
#pragma region Includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#pragma endregion Includes


// The main program
#pragma region Main
int main()
{
    std::vector<int> inputAsInt = std::vector<int>();

    std::fstream inputFile;
    inputFile.open("input.txt", std::ios::in);
    
    if(inputFile.is_open())
    {
        std::string line;
        while (getline(inputFile, line))
        {
            inputAsInt.push_back(stoi(line));
        }
    }

    inputFile.close();

    int a, b = 0;

    for (int i = 0; i < inputAsInt.size(); i++)
    {
        a = inputAsInt[i];
        for (int j = i; j < inputAsInt.size(); j++)
        {
            b = inputAsInt[j];

            if (a + b == 2020)
            {
                std::cout << "a: " << a << ", b: " << b << " = " << a+b << std::endl;
                std::cout << "a*b = " << a*b << std::endl;
            }
        }
    }

    return 0;
}
#pragma endregion Main