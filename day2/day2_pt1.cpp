/* Seth Tal
 * 12 / 03 / 2020
 * Day2, Part 1: Check which passwords from "input.txt" meet their password policy requirements
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

        int count = 0;
        for (int i = 0; i < password.length(); i++)
        {
            if (password[i] == key[0])
                count++;
        }

        char* cMin = strtok((char*)minMax.c_str(), "-");
        char* cMax = strtok((char*)NULL, "-");

        int min = atoi(cMin);
        int max = atoi(cMax);

        if (count >= min && count <= max)
            numValidPasswords++;
    }

    std::cout << "num valid psw: " << numValidPasswords << std::endl;

    return 0;
}
#pragma endregion Main
