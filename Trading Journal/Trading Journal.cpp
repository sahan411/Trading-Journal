#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include "Trading Journal.h"

using namespace std;


void Journal::insertTrade()
{
    string symbol;
    int lotSize;
    double price;
    string date;
    string comment;
    double stopLoss;
    double takeProfit;
    char tradeType;
    system("cls");
    cout << "\n\n\t\t\t\t\t\t+---------------------------------------------------------------+" << endl;
    cout << "\t\t\t\t\t\t|                        ENTER NEW TRADE                        |" << endl;
    cout << "\t\t\t\t\t\t+---------------------------------------------------------------+\n" << endl;

    try {
        do {
            cout << "\t\t\t\t\t\t\tSymbol      : ";
            cin >> symbol;


            if (symbol.length() == 2 && isalpha(symbol[0]) && isalpha(symbol[1])) {
                break;
            }
            else {
                cout << "\n\t\t\t\t\t\tInvalid symbol. Please enter a valid symbol with two letters.\n";
            }

        } while (true);
        do {
            cout << "\t\t\t\t\t\t\tLot Size    : ";
            if (!(cin >> lotSize)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\t\t\t\t\t\tInvalid input. Please enter a valid numnber.\n";
            }
            else if (lotSize <= 0) {
                cout << "\n\t\t\t\t\t\tInvalid lot size. Please enter a positive value.\n";
            }
            else {
                break;
            }

        } while (true);
        do {
            cout << "\t\t\t\t\t\t\tPrice       : ";
            if (!(cin >> price)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\t\t\t\t\t\tInvalid input. Please enter a valid number.\n";
            }
            else if (price <= 0) {
                cout << "\n\t\t\t\t\t\tInvalid price. Please enter a positive value.\n";
            }
            else {
                break;
            }

        } while (true);
        do {
            cout << "\t\t\t\t\t\t\tStop Loss   : ";
            if (!(cin >> stopLoss)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\t\t\t\t\t\tInvalid input. Please enter a valid number.\n";
            }
            else if (stopLoss <= 0) {
                cout << "\n\t\t\t\t\t\tInvalid stop loss. Please enter a positive value.\n";
            }
            else {
                break;
            }

        } while (true);
        do {
            cout << "\t\t\t\t\t\t\tTake Profit : ";
            if (!(cin >> takeProfit)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n\t\t\t\t\t\tInvalid input. Please enter a valid number.\n";
            }
            else {
                break;
            }

        } while (true);
        date = enterDate();
        fflush(stdin);
        do {
            cout << "\t\t\t\t\t\t\tTrade Type (B/b for BUY, S/s for SELL) : ";
            cin >> tradeType;
            if (!(tradeType == 'B' || tradeType == 'b' || tradeType == 'S' || tradeType == 's')) {
                std::cout << "\n\t\t\t\t\t\tInvalid trade type. Please try again.\n";
            }
            else {
                break;
            }

        } while (true);
        TradeType type;
        if (tradeType == 'B' || tradeType == 'b') {
            type = BUY;
        }
        else {
            type = SELL;
        }

        Trade* temp = new Trade(symbol, lotSize, date, comment, price, stopLoss, takeProfit, type);
        temp->tradeId = size + 1;
        cout << "\n\t\t\t\t\t\t\tTrade ID    : " << temp->tradeId << endl;

        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;

        cout << "\n\t\t\t\t\t\tTrade has been added successfully." << endl;
        char response = NULL;
        cout << "\t\t\t\t\t\tDo you want to add another trade (y/n) ? ";
        cin >> response;
        system("cls");
        if (response == 'Y' || response == 'y') {
            insertTrade();
        }
        else if (response == 'N' || response == 'n') {
            menu();
        }
        else
            cout << "\t\t\t\t\t\tInvalid option." << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

}

string Journal::enterDate()
{
    {
        string date;
        do {
            int day, month, year;
            do {
                cout << "\t\t\t\t\t\t\tDate        : Day   > ";
                if (!(cin >> day)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\t\t\t\t\t\tInvalid input. Please enter a valid day.\n";
                }
                else if (day <= 0) {
                    cout << "\n\t\t\t\t\t\tInvalid day. Day cannot be negative.\n";
                }
                else {
                    break;
                }

            } while (true);
            do {
                cout << "\t\t\t\t\t\t\t              Month > ";
                if (!(cin >> month)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\t\t\t\t\t\tInvalid input. Please enter a valid month.\n";
                }
                else if (month <= 0) {
                    cout << "\n\t\t\t\t\t\tInvalid month. Month cannot be negative.\n";
                }
                else {
                    break;
                }

            } while (true);
            do {
                cout << "\t\t\t\t\t\t\t              Year  > ";
                if (!(cin >> year)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\n\t\t\t\t\t\tInvalid input. Please enter a valid year.\n";
                }
                else if (year <= 0) {
                    cout << "\n\t\t\t\t\t\tInvalid year. Year cannot be negative.\n";
                }
                else {
                    break;
                }

            } while (true);
            if (!isValidDate(day, month, year)) {
                cout << "\n\t\t\t\t\t\tInvalid date. Please enter a valid date.\n";
            }
            else {
                date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
                return date;
            }

        } while (true);
    }
    //return string();
}

bool Journal::isValidDate(int day, int month, int year)
{
    {
        if (year < 0 || month < 1 || month > 12 || day < 1) {
            return false;
        }
        int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (year % 4 == 0) {
            monthDays[1] = 29;
        }

        return (day <= monthDays[month - 1]);
    }
}

bool Journal::searchDate(string date)
{
    {
        Trade* current = head;
        for (int i = 0; i < size; i++) {
            if (current->date == date) {
                current = current->next;
                return true;
            }
        }
        return false;
    }
}

bool Journal::searchPair(string symbol)
{
    {
        Trade* current = head;
        for (int i = 0; i < size; i++) {
            if (current->symbol == symbol) {
                current = current->next;
                return true;
            }
        }
        return false;
    }
}

void Journal::printTrade()
{
    {
        Trade* current = head;
        if (head == NULL) {
            cout << "\t\t\t\t\t\tNo trades to show." << endl;
        }
        else {
            cout << "\n\t+----------+----------+------------+-----------+-------------+---------------+--------+------------+----------------------------------------+" << endl;
            cout << "\t| Trade ID |  Symbol  |  Lot Size  |   Price   |  Stop Loss  |  Take Profit  |  Type  |    Date    |                COMMENT                 |" << endl;
            cout << "\t+----------+----------+------------+-----------+-------------+---------------+--------+------------+----------------------------------------+" << endl;
            for (int i = 0; i < size; i++) {
                cout << "\t|" << left << setw(9) << current->tradeId << " | " << left << setw(8) << current->symbol << " | " << left << setw(10) << current->lotSize
                    << " | " << left << setw(9) << current->price << " | " << left << setw(11) << current->stopLoss << " | " << left << setw(13) << current->takeProfit
                    << " | " << left << setw(6) << ((current->type == BUY) ? "BUY" : "SELL") << " | " << left << setw(10) << current->date << " |" << left << setw(40) << current->comment << "|" << endl;
                current = current->next;
            }
            cout << "\t+----------+----------+------------+-----------+-------------+---------------+--------+------------+----------------------------------------+" << endl;
        }
    }
}

void Journal::printByDate(string date)
{
    {
        Trade* current = head;
        if (!searchDate(date)) {
            cout << "\n\t\t\t\t\t\tNo trades on " << date << endl;
        }
        if (searchDate(date)) {
            cout << "\n\t+----------+----------+------------+-----------+-------------+---------------+--------+------------+----------------------------------------+" << endl;
            cout << "\t| Trade ID |  Symbol  |  Lot Size  |   Price   |  Stop Loss  |  Take Profit  |  Type  |    Date    |                COMMENT                 |" << endl;
            cout << "\t+----------+----------+------------+-----------+-------------+---------------+--------+------------+----------------------------------------+" << endl;
            for (int i = 0; i < size; i++) {
                if (current->date == date) {
                    cout << "\t|" << left << setw(9) << current->tradeId << " | " << left << setw(8) << current->symbol << " | " << left << setw(10) << current->lotSize
                        << " | " << left << setw(9) << current->price << " | " << left << setw(11) << current->stopLoss << " | " << left << setw(13) << current->takeProfit
                        << " | " << left << setw(6) << ((current->type == BUY) ? "BUY" : "SELL") << " | " << left << setw(10) << current->date << " |" << left << setw(40) << current->comment << "|" << endl;
                }
                current = current->next;
            }
            cout << "\t+----------+----------+------------+-----------+-------------+---------------+--------+------------+----------------------------------------+" << endl;
        }
        cout << "\n\t\t\t\t\t\tPress and enter any key to return > ";
        char ch = NULL;
        cin >> ch;
    }
}

void Journal::printByPair(string symbol)
{
    {
        Trade* current = head;
        if (!searchPair(symbol)) {
            cout << "\n\t\t\t\t\t\tNo trades of " << symbol << endl;
        }
        // eu, gu,xu,cu,gj
        if (searchPair(symbol)) {
            cout << "\n\t+----------+----------+------------+-----------+-------------+---------------+--------+------------+----------------------------------------+" << endl;
            cout << "\t| Trade ID |  Symbol  |  Lot Size  |   Price   |  Stop Loss  |  Take Profit  |  Type  |    Date    |                COMMENT                 |" << endl;
            cout << "\t+----------+----------+------------+-----------+-------------+---------------+--------+------------+----------------------------------------+" << endl;
            for (int i = 0; i < size; i++) {
                if (current->symbol == symbol) {
                    cout << "\t|" << left << setw(9) << current->tradeId << " | " << left << setw(8) << current->symbol << " | " << left << setw(10) << current->lotSize
                        << " | " << left << setw(9) << current->price << " | " << left << setw(11) << current->stopLoss << " | " << left << setw(13) << current->takeProfit
                        << " | " << left << setw(6) << ((current->type == BUY) ? "BUY" : "SELL") << " | " << left << setw(10) << current->date << " |" << left << setw(40) << current->comment << "|" << endl;
                }
                current = current->next;
            }
            cout << "\t+----------+----------+------------+-----------+-------------+---------------+--------+------------+----------------------------------------+" << endl;
        }
        cout << "\n\t\t\t\t\t\tPress and enter any key to return > ";
        char ch = NULL;
        cin >> ch;
    }
}

void Journal::gain()
{
    {
        Trade* current = head;
        double totalGain = 0;
        while (current != NULL) {
            double pipValue = 10.0;                  // pip value is $100 for 1 lot
            double lotSize = current->lotSize / 1.0; // Convert lot size to standard lots
            double tradeGain;
            if (current->type == BUY) {
                tradeGain = (current->takeProfit - current->price) * lotSize;
            }
            else {
                tradeGain = (current->price - current->takeProfit) * lotSize;
            }
            totalGain += tradeGain;

            current = current->next;
        }
        cout << "\n\t\t\t\t\t\tAll time gain : $ " << totalGain << endl;
        //cout << "\n\t\t\t\t\t\tTrade ID " << current->tradeId << " Gain: $" << tradeGain << endl;
        cout << "\n\t\t\t\t\t\tPress and enter any key to return > ";
        char ch = NULL;
        cin >> ch;

    }
}

void Journal::tradeGain()
{
    {
        if (head == NULL) {
            cout << "\n\t\t\t\t\t\tAdd trades and try again. ";
        }
        else {
            cout << "\n\t\t\t\t\t\tEnter trade ID : ";
            int gainId;
            cin >> gainId;
            Trade* current = head;
            while (current != NULL) {
                if (current->tradeId == gainId) {
                    double pipValue = 10.0;                  // pip value is $100 for 1 lot
                    double lotSize = current->lotSize / 1.0; // Convert lot size to standard lots
                    double tradeGain;
                    if (current->type == BUY) {
                        tradeGain = (current->takeProfit - current->price) * lotSize;
                    }
                    else {
                        tradeGain = (current->price - current->takeProfit) * lotSize;
                    }
                    cout << "\n\t\t\t\t\t\tGain of trade " << gainId << " : $ " << tradeGain << endl;
                    //cout << "\n\t\t\t\t\t\tTrade ID " << current->tradeId << " Gain: $" << tradeGain << endl;

                    break;
                }
                current = current->next;
            }
        }
        cout << "\n\t\t\t\t\t\tPress and enter any key to return > ";
        char ch = NULL;
        cin >> ch;
    }
}

void Journal::commentTrade()
{
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t+---------------------------------------------------------------+" << endl;
        cout << "\t\t\t\t\t\t|                     COMMENT YOUR TRADES                       |" << endl;
        cout << "\t\t\t\t\t\t+---------------------------------------------------------------+\n" << endl;
        printTrade();
        if (head == NULL) {
            cout << "\n\t\t\t\t\t\tAdd trades and try again. Press and enter any key to return > ";
            char ch = NULL;
            cin >> ch;
            menu();
        }
        cout << "\n\t\t\t\t\t\tEnter trade ID to comment : ";
        int commentId;
        cin >> commentId;
        if ((head == NULL) && (commentId < 1 || commentId > size)) {
            cout << "\t\t\t\t\t\tInvalid position. There is no trade at this position.\n" << endl;
        }
        else {
            Trade* current = head;
            for (int i = 0; i < commentId - 2; i++) {
                current = current->next;
            }
            if (current->comment.empty()) {
                cout << "\n\n\t\t\t\t\t\tNo comment available for this trade." << endl;
            }
            else {
                cout << "\n\n\t\t\t\t\t\tComment of this trade : " << current->comment << endl;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string comment = "";
            cout << "\n\t\t\t\t\t\tEnter Comment : ";
            getline(cin, comment);
            current->comment = comment;
        }
        cout << "\n\t\t\t\t\t\tYour comment on trade " << commentId << " has been added successfully." << endl;
        char response = NULL;
        cout << "\n\t\t\t\t\t\tDo you want to comment on another trade (y/n) ? ";
        cin >> response;
        if (response == 'Y' || response == 'y') {
            commentTrade();
        }
        else if (response == 'N' || response == 'n') {
            menu();
        }
        else {
            cout << "\t\t\t\t\t\tInvalid option." << endl;
        }
    }
}

void Journal::deleteFirstTrade()
{
    Trade* temp = head;
    if (size == 1) {
        delete temp;
        head = NULL;
        tail = NULL;
        size = 0;
    }
    else {
        head = head->next;
        delete temp;
        size--;
    }
}

void Journal::deleteLastTrade()
{
    Trade* temp = tail;
    if (size == 1) {
        delete temp;
        head = NULL;
        tail = NULL;
        size = 0;
    }
    else {
        Trade* current = head;
        for (int i = 0; i < size - 2; i++) {
            current = current->next;
        }
        tail = current;
        tail->next = NULL;
        delete temp;
        size--;
    }
 }

void Journal::deleteTrade()
{
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t+---------------------------------------------------------------+" << endl;
        cout << "\t\t\t\t\t\t|                        DELETE TRADES                          |" << endl;
        cout << "\t\t\t\t\t\t+---------------------------------------------------------------+\n" << endl;
        printTrade();
        if (head == NULL) {
            cout << "\n\t\t\t\t\t\tPress and enter any key to return > ";
            char ch = NULL;
            cin >> ch;
            menu();
        }
        cout << "\n\t\t\t\t\t\tEnter trade ID to delete : ";
        int deleteId;
        cin >> deleteId;
        if (deleteId < 1 || deleteId > size) {
            cout << "\n\t\t\t\t\t\tInvalid trade ID. There is no trade for this id.\n" << endl;
        }
        else {
            if (deleteId == 1)
                deleteFirstTrade();
            else if (deleteId == size)
                deleteLastTrade();
            else {
                Trade* current = head;
                for (int i = 0; i < deleteId - 2; i++) {
                    current = current->next;
                }
                Trade* temp = current->next;
                current->next = temp->next;
                delete temp;
                size--;
            }
            cout << "\n\t\t\t\t\t\tTrade ID " << deleteId << " has been deleted successfully." << endl;
            while (true) {
                cout << "\t\t\t\t\t\tDo you want to delete another trade (y/n) ? ";
                char response = NULL;
                cin >> response;
                if (response == 'Y' || response == 'y') {
                    deleteTrade();
                }
                else if (response == 'N' || response == 'n') {
                    menu();
                }
                else {
                    cout << "\n\t\t\t\t\t\tInvalid option. Press 'a' to try again > ";
                    char ch = NULL;
                    cin >> ch;
                    if (ch != 'a')
                        break;
                }
            }
        }
    }
}

void Journal::menu()
{
    {
    L1:while (true) {
        system("cls");
        cout << "\n\n\t\t\t\t\t\t+---------------------------------------------------------------+" << endl;
        cout << "\t\t\t\t\t\t|                   FINANCIAL TRADING JOURNAL                   |" << endl;
        cout << "\t\t\t\t\t\t+---------------------------------------------------------------+\n\n" << endl;
        cout << "\t\t\t\t\t\t\t[1] Enter New Trade\t";
        cout << "[2] Display Trades\n" << endl;
        cout << "\t\t\t\t\t\t\t[3] View your Gain\t";
        cout << "[4] Add Comments\n" << endl;
        cout << "\t\t\t\t\t\t\t[5] Delete Trades\t";
        cout << "[6] Exit Programme" << endl;
        char response = NULL;
        cout << "\n\n\t\t\t\t\t\tEnter an option to continue (1-6) > "; cin >> response;
        char choice = NULL;
        string date = "";
        string pair = "";
        char ch = NULL;
        switch (response) {
        case '1':
            insertTrade();
            break;
        case '2':
            while (true) {
                system("cls");
                cout << "\n\n\t\t\t\t\t\t+---------------------------------------------------------------+" << endl;
                cout << "\t\t\t\t\t\t|                        DISPLAY TRADES                         |" << endl;
                cout << "\t\t\t\t\t\t+---------------------------------------------------------------+\n\n" << endl;
                cout << "\t\t\t\t\t\t\t\t[1] Display By Date\n" << endl;
                cout << "\t\t\t\t\t\t\t\t[2] Display By Pair\n" << endl;
                cout << "\t\t\t\t\t\t\t\t[3] Display All Trades\n" << endl;
                cout << "\t\t\t\t\t\t\t\t[4] Main Menu\n" << endl;
                cout << "\n\t\t\t\t\t\tEnter an option (1-4) > ";
                cin >> choice;
                system("cls");
                switch (choice) {
                case '1':
                    cout << "\n\n\t\t\t\t\t\t+---------------------------------------------------------------+" << endl;
                    cout << "\t\t\t\t\t\t|                        TRADES BY DATE                         |" << endl;
                    cout << "\t\t\t\t\t\t+---------------------------------------------------------------+\n" << endl;
                    date = enterDate();
                    printByDate(date);
                    break;
                case '2':
                    cout << "\n\n\t\t\t\t\t\t+---------------------------------------------------------------+" << endl;
                    cout << "\t\t\t\t\t\t|                        TRADES BY PAIR                         |" << endl;
                    cout << "\t\t\t\t\t\t+---------------------------------------------------------------+\n" << endl;
                    cout << "\t\t\t\t\t\t\tEnter Pair : ";
                    cin >> pair;
                    printByPair(pair);
                    break;
                case '3':
                    cout << "\n\n\t\t\t\t\t\t+---------------------------------------------------------------+" << endl;
                    cout << "\t\t\t\t\t\t|                       YOUR ALL TRADES                         |" << endl;
                    cout << "\t\t\t\t\t\t+---------------------------------------------------------------+\n" << endl;
                    printTrade();
                    cout << "\n\t\t\t\t\t\tPress and enter any key to return > ";
                    ch = NULL;
                    cin >> ch;
                    break;
                case '4':
                    goto L1;

                default:
                    cout << "\n\t\t\t\t\t\tInvalid option. Press and enter any key to try again > ";
                    cin >> ch;
                    continue;
                    break;
                }
            }
            break;
        case '3':
            while (true) {
                system("cls");
                cout << "\n\n\t\t\t\t\t\t+---------------------------------------------------------------+" << endl;
                cout << "\t\t\t\t\t\t|                        VIEW YOUR GAIN                         |" << endl;
                cout << "\t\t\t\t\t\t+---------------------------------------------------------------+\n\n" << endl;
                cout << "\t\t\t\t\t\t\t\t[1] View Gain By Trade\n" << endl;
                cout << "\t\t\t\t\t\t\t\t[2] View All Time Gain\n" << endl;
                cout << "\t\t\t\t\t\t\t\t[3] Main Menu\n" << endl;
                cout << "\n\t\t\t\t\t\tEnter an option (1-3) > ";
                char choice = NULL;
                cin >> choice;
                system("cls");
                //    double totalGain = 0;
                switch (choice) {
                case '1':
                    cout << "\n\n\t\t\t\t\t\t+---------------------------------------------------------------+" << endl;
                    cout << "\t\t\t\t\t\t|                      VIEW GAIN BY TRADE                       |" << endl;
                    cout << "\t\t\t\t\t\t+---------------------------------------------------------------+\n\n" << endl;
                    printTrade();
                    tradeGain();

                    break;
                case '2':
                    cout << "\n\n\t\t\t\t\t\t+---------------------------------------------------------------+" << endl;
                    cout << "\t\t\t\t\t\t|                      VIEW ALL TIME GAIN                       |" << endl;
                    cout << "\t\t\t\t\t\t+---------------------------------------------------------------+\n\n" << endl;
                    gain();
                    break;
                case '3':
                    goto L1;
                default:
                    cout << "\n\t\t\t\t\t\tInvalid option. Press and enter any key to try again > ";
                    cin >> ch;
                    continue;
                }
            }
            break;
        case '4':
            commentTrade();
            break;
        case '5':
            deleteTrade();
            break;
        case '6':
            exit(0);
        default:
            cout << "\n\t\t\t\t\t\tInvalid option. Press and enter any key to try again > ";
            cin >> ch;
            menu();
        }
    }
    }
}

int main() {
    try {
        Journal t1;
        t1.menu();
        /* t1.insertTrade();
         t1.printTrade();
         t1.insertTrade();
         t1.printTrade();
         t1.insertTrade();
         t1.printTrade();
         t1.insertTrade();
         t1.printTrade();
         t1.deleteTrade();
         t1.printTrade();*/
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    //return 0;
}