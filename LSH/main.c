//
//  main.c
//  acmicpc-1874
//
//  Created by 이상현 on 2021/09/27.
//

#include <stdio.h>

void push(void);
void pop(void);

int TestCase[100000] = {0, };
int Stack[100000] = {0, };
char Result[200000];
int top = -1;
int init = 1;
int v1 = 0;
int count = 0;
int checksum = 0;

int main(int argc, const char * argv[]) {
	int n;
	
	scanf("%d", &n);
	 
	for (int i = 0; i < n; i++) scanf("%d", &TestCase[i]);
	 
	while (1) {
		if (top < 0 || Stack[top] < TestCase[v1]) push();
		else if (Stack[top] == TestCase[v1++]) pop();
		else { checksum = -1; break; }
		
		if (count == n * 2) break;
	 }
	
	if (checksum == 0) for (int i = 0; i < count; i++) printf("%c\n", Result[i]);
	else printf("NO\n");
	
	return 0;
}

void push(void) {
	Stack[++top] = init++;
	Result[count++] = '+';
	// printf("+\n");
}

void pop(void) {
	top--;
	Result[count++] = '-';
	// printf("-\n");
}
