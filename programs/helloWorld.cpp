#include <iostream> 
#include <string>

using namespace std;

int main(void) {
    cout << "Hello World!" << endl;
    
    cout << "What is your name?" << endl;
    string userName;
    cin >> userName;
    cout << "Hello " << userName << endl;

    return 0;
}