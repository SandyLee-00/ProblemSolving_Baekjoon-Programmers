# 9012번 괄호
import sys

stack = []

def is_matched(par):
	cnt = 0;
	for i in range(len(par)):
		if(par[i] == "("):
			cnt += 1;
		elif(par[i] == ")"):
			cnt -= 1;
		if cnt < 0:
			print("NO");
			return 0;
	if cnt > 0:
		print("NO")
	else:
		print("YES")
		
	return 0

N = int(input())

for i in range(N):
	par = sys.stdin.readline();
	is_matched(par);
	
