#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Tokenises a CSV line into separate string tokens based on a delimiter
std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;

    start = csvLine.find_first_not_of(separator, 0);

    do {
        end = csvLine.find_first_of(separator, start);

        if (start == csvLine.length() || start == end) break;

        if (end >= 0) {
            token = csvLine.substr(start, end - start);
        } else {
            token = csvLine.substr(start, csvLine.length() - start);
        }

        tokens.push_back(token);
        start = end + 1;

    } while (end > 0);

    return tokens;
}

int main()
{
    std::ifstream csvFile{"20200317.csv"};
    std::string line;
    std::vector<std::strings> tokens;

    if (csvFile.is_open())
    {
        std::cout << "File open " << std::endl;

        while (std::getline(csvFile, line))
        {
            std::cout << "Read line "<< line << endl;
            tokens = tokenise(line, ',');
            // 1. Basic validation: verify exactly 5 tokens exist
            if (tokens.size() != 5) 
            {
                cout<<"Bad Line"<<endl;
                continue;
            }

            // 2. Exception handling for numeric conversions
            try 
            {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);

                // Successfully parsed row
                std::cout << "Price: " << price << " | Amount: " << amount << std::endl;
            }
            catch (const std::exception& e)
            {
                // Catches bad float/double conversions and moves to the next line
                std::cout << "Bad float detected!" << tokens[3]<< std::endl;
                std::cout << "Bad float detected!" << tokens[4]<< std::endl;
                break;
            }
        }

        // Close the file stream after processing
        csvFile.close();
    }
    else
    {
        std::cout << "Problem opening file " << csvFilename << std::endl;
    }

    return 0;
}