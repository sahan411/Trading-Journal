#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cmath>

using namespace std;

enum TradeType {
    BUY = 'B',
    SELL = 'S',
    INVALID = '\0'
};

class Trade {
public:
    int tradeId;
    string symbol;
    int lotSize;
    double price;
    string date;
    string comment;
    double stopLoss;
    double takeProfit;
    TradeType type;
    Trade* next;

    Trade() {
        tradeId = 0;
        symbol = "";
        date = "";
        comment = "";
        lotSize = 0;
        price = 0;
        stopLoss = 0;
        takeProfit = 0;
        type = BUY;
        next = NULL;
    }

    Trade(string symbol, int lotSize, string date, string comment, double price, double stopLoss, double takeProfit, TradeType type) {
        this->tradeId = tradeId++;
        this->symbol = symbol;
        this->lotSize = lotSize;
        this->date = date;
        this->comment = comment;
        this->price = price;
        this->stopLoss = stopLoss;
        this->takeProfit = takeProfit;
        this->type = type;
        next = NULL;
    }

    /*int incrementId() {
        return tradeId++;
    }*/
};

class Journal {
private:
    Trade* head;
    Trade* tail;
    int size;

public:
    Journal() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertTrade();

    string enterDate();

    bool isValidDate(int day, int month, int year);


    bool searchDate(string date);

    bool searchPair(string symbol);

    void printTrade();

    void printByDate(string date);

    void printByPair(string symbol);


    void gain();

    void tradeGain();

    void commentTrade();

    void deleteTrade();

    void deleteFirstTrade();

    void deleteLastTrade();

    void menu();
};