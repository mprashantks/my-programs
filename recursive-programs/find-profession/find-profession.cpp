#include <iostream>
#include <queue>

using namespace std;

void findPos(int level, int pos) {
    int i=1, j=1;

    queue<char> prof;
    prof.push('e');

    while(i < level) {
        while(!prof.empty()) {

        }
        if(prof.front() == 'e') {
            prof.push('e');
            prof.push('d');
        } else {
            prof.push('d');
            prof.push('e');
        }
        prof.pop();
        i++;
    }

    while(j < pos) {
        prof.pop();
        j++;
    }

    cout << prof.front();
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int level, pos;
	    cin >> level >> pos;

	    findPos(level, pos);

	    cout << endl;

	    numberOfTestCases--;
	}
	return 0;
}
