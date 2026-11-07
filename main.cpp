#include <iostream>
#include <string>
#include <vector>
#include"OrderBookEntry.h"
#include "MerkelMain.h"
using namespace std;

int main(){
    MerkelMain app{};
    app.init();

//    vector<OrderBookEntry> orders;

//    orders.push_back(   OrderBookEntry{1000,
//                          0.02,
//                        "2020/03/17 17:01:24.884492",
//                        "BTC/USDT",
//                        OrderBookType::bid}   );

//    orders.push_back(   OrderBookEntry{2000,
//                          0.02,
//                        "2020/03/17 17:01:24.884492",
//                        "BTC/USDT",
//                        OrderBookType::bid}   );

//    //cout<<"The price is: "<< orders[1].price <<endl;

//    for (OrderBookEntry& order : orders){
//        cout<<"The price is: "<< order.price <<endl;
//    }

//    for (unsigned int i = 0; i < orders.size() ; ++i){
//        cout<<"The price is: "<< orders[i].price <<endl;
//    }

//    for (unsigned int i = 0; i < orders.size() ; ++i){
//        cout<<"The price is: "<< orders.at(i).price <<endl;
//    }

    return 0;
}