#include <iostream>
using namespace std;
class Date
{
public:
    int date, month, year;
    Date() {}
    Date(int d, int m, int y) : date(d), month(m), year(y) {}
};
void sortDate(Date records[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (records[j].year < records[min].year)
                min = j;
        Date temp = records[i];
        records[i] = records[min];
        records[min] = temp;
    }
}
int main()
{
    int n = 5;
    Date records[5];
    for (int i = 0; i < 5; i++)
    {
        int date, month, year;
        cout << "Enter record " << i + 1 << ": " << endl;
        cout << "date: ";
        cin >> date;
        cout << "month: ";
        cin >> month;
        cout << "year: ";
        cin >> year;
        records[i] = Date(date, month, year);
    }
    sortDate(records, n);
    for (int i = 0; i < n; i++)
    {
        cout << records[i].date << "/" << records[i].month << "/" << records[i].year << endl;
    }
}