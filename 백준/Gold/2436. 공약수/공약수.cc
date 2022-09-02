// 2436번 공약수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

int gcd(int a, int b){
	if(a == 0){
		return b;
	}
	else return gcd(b % a, a);
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int max_div, min_mul;
	cin >> max_div >> min_mul;
	vector<int> elements;
	for(int i = 1; i * i <= min_mul; i++){
		int sec_num = min_mul / i;
		if(min_mul % i == 0 && min_mul % sec_num == 0){
			elements.push_back(i);
			elements.push_back(sec_num);
			// cout << sec_num;
		}
	}
	sort(elements.begin(), elements.end());
	elements.erase(unique(elements.begin(), elements.end()), elements.end());

	vector<int> div;
	for(int i = 0; i < elements.size(); i++){
		if(elements[i] % max_div == 0){
			div.push_back(elements[i]);
			// cout << elements[i] << " ";
		}
	}
	int res1 = 1, res2 = 1;
	
	for(int i = 0; i < div.size(); i++){
		for(int j = i; j < div.size(); j++){
			int g_res = gcd(div[i], div[j]);
			
			int fir = div[i] / max_div;
			int sec = div[j] / max_div;
			// cout << div[i] << " " << div[j] << "\n";
			
			if(fir * sec * max_div == min_mul && g_res == max_div){
				res1 = div[i];
				res2 = div[j];
			}
		}
	}
	cout << res1 << " " << res2;
	
	return 0;
}