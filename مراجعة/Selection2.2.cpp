#include <iostream>
using namespace std;

// find max up to 10
int main() {
    int x, s1,e1,s2,e2,s3,e3,cnt;
    cnt=0;
    cin>>x;
    cin>>s1;
    cin>>e1;
    cin>>s2;
    cin>>e2;
    cin>>s3;
    cin>>e3;

    bool firstinercal =s1<=x&&x<=e1;
    bool  secondinercal =s2<=x&&x<=e2;
    bool  thirdinercal =s3<=x&&x<=e3;

    if (firstinercal
        )
        cnt++;


    if (secondinercal)
        cnt++;

    if (thirdinercal)
        cnt++;



    cout<<cnt<<endl;

    return 0;
}
