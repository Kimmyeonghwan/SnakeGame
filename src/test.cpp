#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char *argv[])
{
    ifstream f("../map/1.txt", ios::in);
    if(f.fail()) cout << "OMG" << endl;
    else cout << "GOD" << endl;
    string s;
    getline(f, s ,'44');
    cout << s << endl;
    cout << s << endl;


}

