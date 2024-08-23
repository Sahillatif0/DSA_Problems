#include<iostream>
using namespace std;
class Document{
    string* text;
    public:
    Document(string text):text(new string(text)){}
    Document(const Document& other){
        text = new string(*other.text);
    }
    Document& operator = (const Document& other){
        text = new string(*other.text);
        return *this;
    }
    void setText(string text){
        *this->text = text;
    }
    string getText(){
        return *text;
    }
    ~Document(){
        delete text;
    }

};
int main() {
    Document t1("Hello this is text1");
    cout<<"Text in document 1: "<<t1.getText()<<endl;
    Document t2(t1);
    cout<<"Text in document 2: "<<t2.getText()<<endl;
    t2.setText("Hello this is text2");
    cout<<"Text in document 2 after changing: "<<t2.getText()<<endl;
    cout<<"Text in document 1: "<<t1.getText()<<endl;
    Document t3("text 3");
    cout<<"Text in document 3: "<<t3.getText()<<endl;
    t3 = t1;
    t3.setText("Hello this is text3");
    cout<<"Text in document 3 after changing: "<<t3.getText()<<endl;
    cout<<"Text in document 1: "<<t1.getText()<<endl;
    cout<<"Text in document 2: "<<t2.getText()<<endl;

}