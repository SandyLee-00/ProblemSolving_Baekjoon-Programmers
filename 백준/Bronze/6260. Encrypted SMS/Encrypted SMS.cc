#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while(1){
		string str;
		cin >> str;
		if(str == "#"){
			break;
		}

		for(int i = 0; i < str.size(); i++){
			char stri = str[i];
			int add = i + 1;

			if(stri >= 'a' && stri <= 'c'){
				stri -= add;
				while(true){
					if(stri >= 'a' && stri <= 'c'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'd' && stri <= 'f'){
				stri -= add;
				while(true){
					if(stri >= 'd' && stri <= 'f'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'g' && stri <= 'i'){
				stri -= add;
				while(true){
					if(stri >= 'g' && stri <= 'i'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'j' && stri <= 'l'){
				stri -= add;
				while(true){
					if(stri >= 'j' && stri <= 'l'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'm' && stri <= 'o'){
				stri -= add;
				while(true){
					if(stri >= 'm' && stri <= 'o'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'p' && stri <= 's'){
				stri -= add;
				while(true){
					if(stri >= 'p' && stri <= 's'){
						break;
					}
					stri += 4;
				}
			}

			if(stri >= 't' && stri <= 'v'){
				stri -= add;
				while(true){
					if(stri >= 't' && stri <= 'v'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'w' && stri <= 'z'){
				stri -= add;
				while(true){
					if(stri >= 'w' && stri <= 'z'){
						break;
					}
					stri += 4;
				}
			}

			if(stri >= 'A' && stri <= 'C'){
				stri -= add;
				while(true){
					if(stri >= 'A' && stri <= 'C'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'D' && stri <= 'F'){
				stri -= add;
				while(true){
					if(stri >= 'D' && stri <= 'F'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'G' && stri <= 'I'){
				stri -= add;
				while(true){
					if(stri >= 'G' && stri <= 'I'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'J' && stri <= 'L'){
				stri -= add;
				while(true){
					if(stri >= 'J' && stri <= 'L'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'M' && stri <= 'O'){
				stri -= add;
				while(true){
					if(stri >= 'M' && stri <= 'O'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'P' && stri <= 'S'){
				stri -= add;
				while(true){
					if(stri >= 'P' && stri <= 'S'){
						break;
					}
					stri += 4;
				}
			}

			if(stri >= 'T' && stri <= 'V'){
				stri -= add;
				while(true){
					if(stri >= 'T' && stri <= 'V'){
						break;
					}
					stri += 3;
				}
			}

			if(stri >= 'W' && stri <= 'Z'){
				stri -= add;
				while(true){
					if(stri >= 'W' && stri <= 'Z'){
						break;
					}
					stri += 4;
				}
			}

			cout << stri;
		}

		cout << "\n";
	}



	return 0;
}