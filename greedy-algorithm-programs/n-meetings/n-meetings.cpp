#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meeting {
    int pos, start_time, finish_time;
};

bool sortFun(meeting a, meeting b) {
    return (a.finish_time < b.finish_time);
}

void meetingSelection (int *start_time, int *finish_time, int size) {
    vector<meeting> meetings;
    meeting obj[size];
    for(int i=0; i<size; i++) {
        obj[i].pos = i+1;
        obj[i].start_time = start_time[i];
        obj[i].finish_time = finish_time[i];
        meetings.push_back(obj[i]);
    }

    sort(meetings.begin(), meetings.end(), sortFun);

    int i=0, j=1;
    while(j < meetings.size()) {
        if(meetings[i].finish_time < meetings[j].start_time) {
            cout << meetings[i].pos << " ";
            i = j;
            j++;
        } else
            j++;
    }
    cout << meetings[i].pos << endl;
}

int main() {
	//code
	int numberOfTestCases;

	cin>>numberOfTestCases;
	while(numberOfTestCases > 0) {
	    //Code to solve problem
	    int size;
	    cin >> size;
	    int *start_time = new int[size];
	    int *finish_time = new int[size];
	    for(int i=0; i<size; i++)
	        cin >> start_time[i];
	    for(int i=0; i<size; i++)
	        cin >> finish_time[i];

	    meetingSelection(start_time, finish_time, size);

	    numberOfTestCases--;
	}
	return 0;
}
