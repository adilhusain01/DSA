#include <iostream>

using namespace std;

enum class color{
    violet,indigo,blue,green,yellow,orange,red
};

int main(){
    color selected=color::blue;

    switch(selected){
        case color::violet:
            cout<<"violet selected"<<endl;
            break;
        case color::indigo:
            cout<<"indigo selected"<<endl;
            break;
        case color::blue:
            cout<<"blue selected"<<endl;
            break;
        case color::green:
            cout<<"green selected"<<endl;
            break;
        case color::yellow:
            cout<<"yellow selected"<<endl;
            break;
        case color::orange:
            cout<<"orange selected"<<endl;
            break;
        case color::red:
            cout<<"red selected"<<endl;
            break;
        default:
            cout<<"No selected"<<endl;
            break;
    }

    return 0;
}