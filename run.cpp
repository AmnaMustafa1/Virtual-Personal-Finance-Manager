#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class FinanceManager {
private:
    double income;
    double expenses;
    double savings;
    string username;

public:
    FinanceManager() : income(0), expenses(0), savings(0) {}

    void setUsername() {
        cout << "Enter your name: ";
        getline(cin, username);
    }

    void addIncome() {
        double amount;
        cout << "Enter income amount: $";
        cin >> amount;
        income += amount;
        updateSavings();
        cout << "Income added successfully!\n";
    }

    void addExpense() {
        double amount;
        cout << "Enter expense amount: $";
        cin >> amount;
        expenses += amount;
        updateSavings();
        cout << "Expense added successfully!\n";
    }

    void viewSummary() const {
        cout << "\n--- Financial Summary for " << username << " ---\n";
        cout << fixed << setprecision(2);
        cout << "Total Income: $" << income << endl;
        cout << "Total Expenses: $" << expenses << endl;
        cout << "Savings: $" << savings << endl;
    }

    void saveToFile() const {
        ofstream file("FinanceReport.txt");
        if (!file) {
            cout << "Error creating report file.\n";
            return;
        }

        file << "--- Financial Report ---\n";
        file << "Name: " << username << "\n";
        file << fixed << setprecision(2);
        file << "Total Income: $" << income << endl;
        file << "Total Expenses: $" << expenses << endl;
        file << "Savings: $" << savings << endl;

        file.close();
        cout << "Report saved to 'FinanceReport.txt'\n";
    }

private:
    void updateSavings() {
        savings = income - expenses;
    }
};

int main() {
    FinanceManager manager;
    int choice;

    cout << "=== Virtual Personal Finance Manager ===\n";
    manager.setUsername();

    do {
        cout << "\n1. Add Income\n2. Add Expense\n3. View Summary\n4. Save Report\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // To clear the input buffer

        switch (choice) {
        case 1:
            manager.addIncome();
            break;
        case 2:
            manager.addExpense();
            break;
        case 3:
            manager.viewSummary();
            break;
        case 4:
            manager.saveToFile();
            break;
        case 5:
            cout << "Exiting... Have a great day!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

