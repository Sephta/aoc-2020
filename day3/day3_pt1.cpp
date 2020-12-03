/* Seth Tal
 * 12 / 03 / 2020
 * Day3, Part 1: traverse the slope
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
int Slope_Calculator(int right, int down, std::vector<std::string> lines)
{
    int result = 0;

    int slopeTracker = right;

    for (int i = 1; i < lines.size(); i++)
    {
        if (i % down == 0)
        {
            if (lines[i][slopeTracker] == '#')
                result++;

            slopeTracker = (slopeTracker + right) % lines[i].length();
        }
    }

    return result;
}
#pragma endregion Helper_funcs

#pragma region Main
int main()
{
    std::vector<std::string> inputData = std::vector<std::string>();

    std::ifstream input;
    input.open("input.txt");
    std::string line;
    while (getline(input, line))
        inputData.push_back(line);
    input.close();

    // SLOPE Calcs
    // ------------------------------------------
    long long result1 = Slope_Calculator(1, 1, inputData);
    long long result2 = Slope_Calculator(3, 1, inputData);
    long long result3 = Slope_Calculator(5, 1, inputData);
    long long result4 = Slope_Calculator(7, 1, inputData);
    long long result5 = Slope_Calculator(1, 2, inputData);
    // ------------------------------------------

    std::cout << "(1, 1) : " << result1 << std::endl;
    std::cout << "(3, 1) : " << result2 << std::endl;
    std::cout << "(5, 1) : " << result3 << std::endl;
    std::cout << "(7, 1) : " << result4 << std::endl;
    std::cout << "(1, 2) : " << result5 << std::endl;

    long long solution = result1*result2*result3*result4*result5;

    std::cout << "solution: " << solution << std::endl;

    return 0;
}
#pragma endregion Main
