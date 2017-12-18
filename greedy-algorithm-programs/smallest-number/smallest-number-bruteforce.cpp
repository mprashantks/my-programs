#include <iostream>
#include <math.h>

using namespace std;

bool flag = false;

int smallestNumber(int sum, int no_of_digits, int mul, int num, int s_num) {
    if(s_num == sum) {
        flag = true;
        return num;
    }
    if(no_of_digits <= 0)
        return num;

    for(int i=0; i<9; i++) {
        num += (i+1)*mul;
        s_num += (i+1);
        num = smallestNumber(sum, no_of_digits-1, mul/10, num, s_num);
        if(!flag) {
            num -= (i+1)*mul;
            s_num -= (i+1);
        } else
            break;
    }
    return num;
}

void smallNum(int s, int d) {
    int num = smallestNumber(s, d, pow(10,d-1), 0, 0);
    flag?cout<<num<<endl:cout<<-1<<endl;
    flag = false;
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int s, d;
	    cin >> s >> d;
	    smallNum(s, d);
	    numberOfTestCases--;
	}
	return 0;
}
