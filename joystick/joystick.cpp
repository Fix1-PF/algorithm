#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name);
int upDown(char alpha);
int leftRight(string answer, int index);


int main() {
	vector<string> answer;
	
	answer.push_back("JEROEN");
	answer.push_back("JAN");
	
	for(int i = 0; i < answer.size(); i++) {
		cout << solution(answer[i]) << " ";
	}
	cout << endl;
	
	return 0;
}

int solution(string name) {
	vector<bool> array_check(name.length(), false);
    vector<int> distance(name.length(), 0);
	int answer = 0;
	
	for(int i = 0; i < name.length(); i++) {
		if(name[i] == 'A') {
			array_check[i] = true;
		}
		answer += upDown(name[i]);
	}
	
	int index = 0;
	distance[0] = 0;
	for(int i = index; i < name.length(); i++) {
		
	}
	
    return answer;
}

int upDown(char alpha) {	
	if(alpha - 'A' > ('Z' - alpha) + 1)
		return ('Z' - alpha) + 1;
	else
		return alpha - 'A';
}

int leftRight(string answer, int index) {
	if(answer[index + 1] == 'A') {
		
	} else
		return 1;	
	
}









