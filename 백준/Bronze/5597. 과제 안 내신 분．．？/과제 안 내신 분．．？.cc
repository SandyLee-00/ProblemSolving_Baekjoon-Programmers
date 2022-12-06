//
#include <bits/stdc++.h>
using namespace std;
/*

*/
int stu[100];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for(int i = 0; i < 28; i++){
		int a;
		cin >> a;
		stu[a] = 1;
	}
	for(int i = 1; i <= 30; i++){
		if(stu[i] == 0)
			cout << i << "\n";
	}
	
	return 0;
}