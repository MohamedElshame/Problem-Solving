#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    while(n!=-1) {
        if (n%8==0||n%4==0&&n%3==0) {
            cout<<n<<" ";
            n--;


        }
        else {
            n--;
        }


    }



}