#pragma once
#include "OrderBookEntry.h"
#include <vector>
#include <string>
using namespace std;

class CSVReader{
    public:
        CSVReader();
        static vector<OrderBookEntry> readCSV(string csvFile);

    private:
        static vector<string> tokenise(string csvLine, char separator);
        static OrderBookEntry stringsToOBE(vector<string>strings);

};