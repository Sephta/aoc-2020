/* Seth Tal
 * 12 / 03 / 2020
 * Day1 puzzle, Part 2: Find 3 numbers from "input" that sum to 2020. Return their product.
*/

// Contains includes for this file
#pragma region Includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#pragma endregion Includes


// The main program
#pragma region Main
int main()
{
    // Vector to store the input from "input.txt"
    std::vector<int> inputAsInt = std::vector<int>();

    std::fstream inputFile;  // opens the file
    inputFile.open("input.txt", std::ios::in);
    
    if(inputFile.is_open())
    {
        std::string line;
        while (getline(inputFile, line))
        {
            inputAsInt.push_back(stoi(line));
        }
    }

    inputFile.close();  // closes the file

    int a, b, c = 0;
    int count = 0;

    for (int i = 0; i < inputAsInt.size() - 2; i++)
    {
        a = inputAsInt[i];
        for (int j = i+1; j < inputAsInt.size() - 1; j++)
        {
            // std::cout << "j: " << j << std::endl;

            b = inputAsInt[j];
            for (int k = j+1; k < inputAsInt.size(); k++)
            {

                count++;
                c = inputAsInt[k];
                if (a + b + c == 2020)
                {
                    std::cout << "a: " << a << ", b: " << b  << ", c: " << c << " = " << a+b+c << std::endl;
                    std::cout << "a*b*c = " << a*b*c << std::endl;
                }
            }
        }
    }

    return 0;
}
#pragma endregion Main
