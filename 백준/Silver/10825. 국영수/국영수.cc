// 10825번 국영수
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

struct Student{
	int kor;
	int eng;
	int math;
	string name;
};

bool cmp(const Student& a, const Student& b){
	if(a.kor > b.kor) return true;
	else if(a.kor == b.kor && a.eng < b.eng) return true;
	else if(a.kor == b.kor && a.eng == b.eng && a.math > b.math) return true;
	else if(a.kor == b.kor && a.eng == b.eng && a.math == b.math && a.name < b.name) return true;
	
	return false;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<Student> v;
	for(int i = 0; i < N; i++){
		string d; cin >> d;
		int a, b, c; cin >> a >> b >> c;
		Student tmp;
		tmp.name = d;
		tmp.kor = a;
		tmp.eng = b;
		tmp.math = c;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);

	for(int i = 0; i < N; i++){
		//cout << i;
		cout << v[i].name << "\n";
	}
	
	return 0;
}