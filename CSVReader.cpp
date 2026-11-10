#include "CSVReader.h"
#include <iostream>
#include <fstream>
using namespace std;

CSVReader::CSVReader(){
}

vector<OrderBookEntry> CSVReader::readCSV(string csvFilename)
{
    vector<OrderBookEntry> entries;

    std::ifstream csvFile{csvFilename};
    std::string line;
    if (csvFile.is_open())
    {
        while (getline(csvFile, line))
        {
            try {
                OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
                entries.push_back(obe);
            } catch (const std::exception& e) {
                // Skips bad line cleanly and moves to the next line!
                cout << "CSVReader::readCSV bad data" << endl;
            }
        }
    }
    cout << "CSVReader::readCSV read " << entries.size() << " entries" << endl;
    return entries;
}

vector<string> CSVReader::tokenise(string csvLine, char separator){
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

OrderBookEntry CSVReader::stringsToOBE(vector<string>tokens){
    
    double price, amount;
        if (tokens.size() != 5) 
    {
        cout<<"Bad Line"<<endl;
        throw exception{};
    }

        // 2. Exception handling for numeric conversions
        try 
        {
            price = std::stod(tokens[3]);
            amount = std::stod(tokens[4]);
        }
        catch (const std::exception& e)
        {
            std::cout << "Bad float detected!" << tokens[3] << std::endl;
            std::cout << "Bad float detected!" << tokens[4] << std::endl;
            throw; 
        }

            OrderBookEntry obe{price,
                            amount,
                            tokens[0],
                            tokens[1],
                            OrderBookEntry::stringToOrderBookType(tokens[2])};
            return obe;
    }