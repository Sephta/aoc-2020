/* Seth Tal
 * 12 / 03 / 2020
 * Day4, Part 2: check if the passport data is valid
*/

#pragma region Includes
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#pragma endregion Includes


#pragma region Function_Declarations
///
/// Grabs each line from "input.txt" and stores it inside of a string vector
/// \return vector<string>
///
std::vector<std::string> grabInputData(std::string filename);

///
/// Resets any bool vector to contain only false entries
/// \return none
///
void resetCreds(std::vector<bool> &creds);

///
/// Checks if the given "passport" (just a vector of strings) is valid
/// \param passport The vector of strings containing passport data
/// \return bool
///
bool CorrectNumFields(std::vector<std::string> passport);
#pragma endregion Function_Declarations


#pragma region GLOBALS
enum PassportFields { byr = 0, iyr = 1, eyr = 2, hgt = 3, hcl = 4, ecl = 5, pid = 6 };
static const char* PassportFields_toString[] = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" };

static const int BirthRange[]     = { 1920, 2020 };
static const int IssueYearRange[] = { 2010, 2020 };
static const int ExpirYearRange[] = { 2020, 2030 };
static const int HeightRange_cm[] = { 150, 193 };
static const int HeightRange_in[] = { 59, 76 };
static const int HAIRCOLORLEN     = 6;

enum ValidEyeColor { amb = 0, blu = 1, brn = 2, gry = 3, grn = 4, hzl = 5, oth = 6 };
static const char* ValidEyeColor_toString[] = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };

static const int VALIDPIDLEN      = 9;
#pragma endregion GLOBALS


#pragma region Main
///
/// The main program for Day4 part 2. Program validates given input file
/// \return none
///
int main()
{
    std::vector<std::string> inputData = grabInputData((std::string)"input.txt");
    inputData.push_back(""); // To account for the final passport not being following by a blank line.

    // a number tracking the curr number of valid passports
    int validPassportCount = 0;

    std::vector<std::string> currPassport = std::vector<std::string>();


    for (int i = 0; i < inputData.size(); i++)
    {
        if (inputData[i] != "")
        {
            currPassport.push_back(inputData[i]);
        }
        else if (inputData[i] == "" || i == (inputData.size() - 1))
        {
            if (CorrectNumFields(currPassport))
            {
                
                std::string passport = "";

                for (int j = 0; j < currPassport.size(); j++)
                    passport = passport.append(currPassport[j]).append(" ");

                std::vector<std::string> tokens = std::vector<std::string>();

                auto token = strtok((char*)passport.c_str(), " ");

                validPassportCount++;
            }

            currPassport.clear(); // wipe passport data to grab next set of passport data
        }
    }

    std::cout << "num valid passports: " << validPassportCount << std::endl;

    return 0; // END OF MAIN
}
#pragma endregion Main

#pragma region Helper_funcs
std::vector<std::string> grabInputData(std::string filename)
{
    std::vector<std::string> result = std::vector<std::string>();

    std::fstream inputFile;
    inputFile.open(filename, std::ios::in);
    
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

bool CorrectNumFields(std::vector<std::string> passport)
{
    std::vector<bool> creds = std::vector<bool>(7);

    for (int j = 0; j < passport.size(); j++)
    {
        if (passport[j].find(PassportFields_toString[byr]) != std::string::npos)
            creds[byr] = true;
        if (passport[j].find(PassportFields_toString[iyr]) != std::string::npos)
            creds[iyr] = true;
        if (passport[j].find(PassportFields_toString[eyr]) != std::string::npos)
            creds[eyr] = true;
        if (passport[j].find(PassportFields_toString[hgt]) != std::string::npos)
            creds[hgt] = true;
        if (passport[j].find(PassportFields_toString[hcl]) != std::string::npos)
            creds[hcl] = true;
        if (passport[j].find(PassportFields_toString[ecl]) != std::string::npos)
            creds[ecl] = true;
        if (passport[j].find(PassportFields_toString[pid]) != std::string::npos)
            creds[pid] = true;
    }

    // Count how many passport feilds this passport contains
    int count = 0;
    for (int j = 0; j < creds.size(); j++)
        if (creds[j] == true)
            count++;
    
    if (count == 7)
        return true;
    
    return false;
}
#pragma endregion Helper_funcs
