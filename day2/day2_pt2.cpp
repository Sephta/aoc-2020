/* Seth Tal
 * 12 / 03 / 2020
 * Day2, Part 2: Check which passwords from "input.txt" meet their password policy requirements
*/


#pragma region Includes
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>
#include <vector>
#pragma endregion Includes


#pragma region Helper_funcs
std::vector<std::string> grabInputData()
{
    std::vector<std::string> result = std::vector<std::string>();

    std::fstream inputFile;
    inputFile.open("input.txt", std::ios::in);
    
    if(inputFile.is_open())
    {
        std::string line;
        while (getline(inputFile, line))
        {
            result.push_back(line);
        }
    }

    inputFile.close();

    return result;
}
#pragma endregion Helper_funcs


#pragma region Main
int main()
{
    std::vector<std::string> inputData = grabInputData();

    int numValidPasswords = 0;

    for (int i = 0; i < inputData.size(); i++)
    {
        std::string minMax;
        std::string key;
        std::string password;

        std::istringstream iss(inputData[i]);

        if (!(iss >> minMax >> key >> password)) { break; }

        char* cMin = strtok((char*)minMax.c_str(), "-");
        char* cMax = strtok((char*)NULL, "-");

        int min = atoi(cMin);
        int max = atoi(cMax);

        if ((min - 1) >= 0 && (min - 1) < password.length() && (max - 1) >= 0 && (max - 1) < password.length())
        {
            if ((password[min - 1] == key[0]) != (password[max - 1] == key[0]))
                numValidPasswords++;
        }
        else
            continue;
    }

    std::cout << "num valid psw: " << numValidPasswords << std::endl;

    return 0;
}
#pragma endregion Main
