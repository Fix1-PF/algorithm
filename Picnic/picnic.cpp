#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int countPairings(bool taken[]);

// 학생수 6명
const int n = 6;
//[i][j] == true 인 경우 i와 j는 친구
bool areFriends[6][6] = {{false, true, true, false, false, false},
						 {true, false, true, true, true, false},
						 {true, true, false, true, true, false},
						 {false, true, true, false, true, true},
						 {false, true, true, true, false, true},
						 {false, false, false, true, true, false}};
int main() {
	//taken[i] = i번째 학생이 짝을 찾았으면 true, 아니면 false
	bool taken[6] = {false, false, false, false, false, false};
		
	cout << "학생수 6명" << endl;
	cout << "짝: (0 1), (0 2), (1 2), (1 3), (1 4), (2 3), (2 4), (3 4), (3 5), (4 5)" << endl;
	cout << "짝 지을 수 있는 경우의 수 : " << countPairings(taken) << endl;
	return 0;
}

int countPairings(bool taken[]) {
	// 남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	for(int i = 0; i < n; ++i) {
		if(!taken[i]) {
			firstFree = i;
			break;
		}
	}
	
	// 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	if(firstFree == -1) return 1;
	int ret = 0;
	// 이 학생과 짝지을 학생을 결정한다.
	for(int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		// pairWith(짝지을 학생)과 firstFree(남은 학생들 중 가장 번호가 빠른 학생)이 짝 지을 수 있는경우
		if(!taken[pairWith] && areFriends[firstFree][pairWith]) {
			// 둘을 짝지어 준다.
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	
	return ret;		
}