/* Seth Tal
 * 12 / 03 / 2020
 * Day4, Part 1: check if the passport contains necessary keys
*/

#pragma region Includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#pragma endregion Includes


/* Function declarations */
///
// Grabs each line from "input.txt" and stores it inside of a string vector
/// \return vector<string>
std::vector<std::string> grabInputData();

///
// Resets any bool vector to contain only false entries
/// \param creds A vector of bools
/// \return none
void resetCreds(std::vector<bool> &creds);


// GLOBALS
enum PassportFields { byr = 0, iyr = 1, eyr = 2, hgt = 3, hcl = 4, ecl = 5, pid = 6 };
static const char* PassportFields_toString[] = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" };

static const int test[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

#pragma region Main
int main()
{
    std::vector<std::string> inputData = grabInputData();
    inputData.push_back(""); // To account for the final passport not being following by a blank line.
    
    // a number tracking the curr number of valid passports
    int validPassportCount = 0;

    std::vector<bool> creds = std::vector<bool>(7);
    std::vector<std::string> currPassport = std::vector<std::string>();


    for (int i = 0; i < inputData.size(); i++)
    {
        if (inputData[i] != "")
        {
            currPassport.push_back(inputData[i]);
        }
        else if (inputData[i] == "" || i == (inputData.size() - 1))
        {
            for (int j = 0; j < currPassport.size(); j++)
            {
                if (currPassport[j].find(PassportFields_toString[byr]) != std::string::npos)
                    creds[byr] = true;
                if (currPassport[j].find(PassportFields_toString[iyr]) != std::string::npos)
                    creds[iyr] = true;
                if (currPassport[j].find(PassportFields_toString[eyr]) != std::string::npos)
                    creds[eyr] = true;
                if (currPassport[j].find(PassportFields_toString[hgt]) != std::string::npos)
                    creds[hgt] = true;
                if (currPassport[j].find(PassportFields_toString[hcl]) != std::string::npos)
                    creds[hcl] = true;
                if (currPassport[j].find(PassportFields_toString[ecl]) != std::string::npos)
                    creds[ecl] = true;
                if (currPassport[j].find(PassportFields_toString[pid]) != std::string::npos)
                    creds[pid] = true;
            }

            // Count how many passport feilds this passport contains
            int count = 0;
            for (int j = 0; j < creds.size(); j++)
                if (creds[j] == true)
                    count++;
            
            if (count == 7) // 7 is the amount of passport fields a passport needs
                validPassportCount++;

            currPassport.clear();
            resetCreds(creds);
        }
    }

    std::cout << "num valid passports: " << validPassportCount << std::endl;

    return 0; // END OF MAIN
}
#pragma endregion Main

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

void resetCreds(std::vector<bool> &creds)
{
    for (int i = 0; i < creds.size(); i++)
        creds[i] = 0;
}
#pragma endregion Helper_funcs
