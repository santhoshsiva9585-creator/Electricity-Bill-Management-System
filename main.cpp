#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    int consumerNo;
    string consumerName;
    float units, amount;

    cout << "===== Electricity Bill Management System =====\n";

    cout << "Enter Consumer Number: ";
    cin >> consumerNo;

    cin.ignore();

    cout << "Enter Consumer Name: ";
    getline(cin, consumerName);

    cout << "Enter Units Consumed: ";
    cin >> units;

    if(units <= 100)
        amount = units * 1.5;
    else if(units <= 300)
        amount = (100 * 1.5) + ((units - 100) * 3.0);
    else if(units <= 500)
        amount = (100 * 1.5) + (200 * 3.0) + ((units - 300) * 4.5);
    else
        amount = (100 * 1.5) + (200 * 3.0) + (200 * 4.5) + ((units - 500) * 6.0);

    ofstream file("bill_records.txt", ios::app);

    file << "\nConsumer No : " << consumerNo;
    file << "\nConsumer Name : " << consumerName;
    file << "\nUnits : " << units;
    file << "\nBill Amount : Rs." << amount;
    file << "\n---------------------------\n";

    file.close();

    cout << "\n===== BILL =====\n";
    cout << "Consumer No   : " << consumerNo << endl;
    cout << "Consumer Name : " << consumerName << endl;
    cout << "Units Used    : " << units << endl;
    cout << fixed << setprecision(2);
    cout << "Bill Amount   : Rs." << amount << endl;

    cout << "\nRecord saved successfully in bill_records.txt\n";

    return 0;
}
