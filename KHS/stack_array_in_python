import sys
input = sys.stdin.readline

s = []
exam = []
num = []
results = []

n = int(input())

for i in range(1, n+1):
	exam.append(int(input()))
	num.append(i)

for k in range(n):
	if exam[k] in num:
		for z in range(num.index(exam[k])+1):
			s.append(num[0])
			results.append('+')
			del num[0]
		s.pop()
		results.append('-')
	elif exam[k] == s[-1]:
		s.pop()
		results.append('-')
	else:
		print('NO')
		quit()

for result in results:
	print(result)
