#include<iostream>
using namespace std;
class Exam{
    string name, examDate;
    int *score;
    public:
    Exam(string name, string date, int score):name(name),examDate(date){
        this->score = new int(score);
    }
    void setName(string name){this->name = name;}
    void setExamDate(string date){this->examDate = date;}
    void setScore(int score){*this->score = score;}
    string getName(){return name;}
    string getExamDate(){return examDate;}
    int getScore(){return *score;}
    void printData(){
        cout<<"Name: "<<name<<endl;
        cout<<"Exam Date: "<<examDate<<endl;
        cout<<"Score: "<<*score<<endl;
    }
};
int main() {
    Exam e1("sahil", "23-Aug-2024", 12.5);
    e1.printData();
    Exam e2(e1);
    cout<<endl<<"Before Changing data e2s data: "<<endl<<endl;
    e2.printData();
    e2.setName("Ali");
    e2.setExamDate("24-Aug-2024");
    e2.setScore(15);
    cout<<endl<<"After Changing data e2s data: "<<endl<<endl;
    e2.printData();
    cout<<endl<<"After Changing data e1s data: "<<endl<<endl;
    e1.printData();
}