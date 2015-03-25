#include <string>
#include <iostream>


using namespace std;


void changeMiddle(string& s) {
    s.replace(s.length()/2, 1, "L");
}

int main() {
    string sA="R";
    string sB="RRL";
    string sC="RRLRRLL";
    string sD="RRLRRLLRRRLLRLL";

    cout << sA << " ";
    changeMiddle(sA);
    cout << sA << endl;


    cout << sB << " ";
    changeMiddle(sB);
    cout << sB << endl;

    cout << sC << " ";
    changeMiddle(sC);
    cout << sC << endl;

    cout << sD << " ";
    changeMiddle(sD);
    cout << sD << endl;

    string s ="RRL";
    cout << s << endl;
    changeMiddle(s);
    cout << s << endl;
}

