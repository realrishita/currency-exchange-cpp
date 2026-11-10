#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
using namespace std;

MerkelMain::MerkelMain(){

}

void MerkelMain::init(){
    loadOrderBook();
    int input;
    while(true){
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::loadOrderBook(){
    orders = CSVReader::readCSV("20200317.csv");
}



void MerkelMain::printMenu(){
    //1 print help
    cout<<"1: Print Help"<<endl;
    //2 print exchange stats
    cout<<"2: Print Exchange Stats"<<endl;
    //3 make an offer
    cout<<"3: Make an Offer"<<endl;
    //4 make a bid
    cout<<"4: Make a bid"<<endl;
    //5 print wallet 
    cout<<"5: Print Wallet"<<endl;
    //6 continue
    cout<<"6: Continue"<<endl;

    cout<<"=============="<<endl;
}

void MerkelMain::printHelp(){
    cout<<"Help - Your aim it to make money. Analyse the market and make bids and offers."<<endl;
}

void MerkelMain::printMarketStats(){
    cout<<"OrderBook contains: "<< orders.size() << " entries"<<endl;
    unsigned int bids = 0;
    unsigned int asks = 0;
    for (OrderBookEntry& e : orders){
        if (e.orderType == OrderBookType::ask){
            asks ++;
        }
        if (e.orderType == OrderBookType::bid){
            bids ++;
        }
    }
    cout<<"OrderBook asks: "<< asks << " OrderBook bids: "<< bids <<endl;
}

void MerkelMain::enterOffer(){
    cout<<"Make an offer - Enter the amount."<<endl;
}

void MerkelMain::enterBid(){
    cout<<"Make a bid - Enter the amount."<<endl;
}

void MerkelMain::printWallet(){
    cout<<"Your wallet is empty."<<endl;
}

void MerkelMain::gotoNextTimeframe(){
    cout<<"Going to next time frame."<<endl;
}

int MerkelMain::getUserOption(){
    int userOption;
    cout<<"Type in 1-6"<<endl;
    cin>>userOption;
    cout<<"You chose: "<<userOption<<endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption){
    if(userOption == 0){
    cout<<"Invalid choice. Choose 1-6."<<endl;
    }
    if(userOption == 1){
        printHelp();
    }
    if(userOption == 2){
        printMarketStats();
    }
    if(userOption == 3){
        enterOffer();
    }
    if(userOption == 4){
        enterBid();
    }
    if(userOption == 5){
        printWallet();
    }
    if(userOption == 6){
        gotoNextTimeframe();
    }
}