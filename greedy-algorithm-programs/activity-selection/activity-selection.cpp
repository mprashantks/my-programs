#include <iostream>
#include <map>

using namespace std;

void activitySelection (int *start_time, int *finish_time, int size) {
    multimap<int, int> activity;
    for(int i=0; i<size; i++) {
        activity.insert(pair <int, int> (finish_time[i], start_time[i]));
    }

    multimap<int, int>::iterator it1;
    multimap<int, int>::iterator it2;
    it1 = activity.begin();
    it2 = activity.begin();
    ++it2;
    int count = 0;

    while(it2 != activity.end()){
        if(it1->first <= it2->second) {
            count++;
            it1 = it2++;
        } else
            it2++;
    }
    cout << count+1 << endl;
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

	    activitySelection(start_time, finish_time, size);

	    numberOfTestCases--;
	}
	return 0;
}
