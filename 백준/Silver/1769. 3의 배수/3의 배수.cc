// 1769번 3의 배수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

string res = "NO";

int check_exit(long long n){
	if(n / 10 == 0) return 1;
	else return 0;
}

void do_exit(int n){
	if(n % 3 == 0) res = "YES";
	cout << res;
}

long long get_sum(string X){
	long long sum = 0;
	for(int i = 0; i < X.size(); i++){
		sum += X[i] - '0';
	}
	return sum;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string X; cin >> X;
	if(X.size() == 1){
		cout << 0 << "\n";
		do_exit(stoi(X));
		return 0;
	}
	long long num = get_sum(X);
	
	int cnt = 1;
	// cout << num << " ";
	
	while(!check_exit(num)){
		//cout << num << " ";
		cnt += 1;
		string num_str = to_string(num);
		num = get_sum(num_str);
	}
	cout << cnt << "\n";
	//cout << "num " << num << "\n";
	do_exit(num);
	
	return 0;
}