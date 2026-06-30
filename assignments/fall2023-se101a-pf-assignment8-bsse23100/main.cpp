#include <iostream>
#include <string>
#include<fstream>
using namespace std;
int main() {
    ofstream write("a.txt",ios::app);
    write<<"tayyab"<<'\0';
    write.close();
    ifstream read("a.txt");
    string ch;
    getline(read,ch);
    cout<<ch.size()<<endl;
    return 0;
}
