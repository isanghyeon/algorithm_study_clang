#include <stdio.h>

const int max = 100000;
const int super_max = 300000;

int top = -1;
int result_idx = 0;

int full(int s[]) {
	if (top == max - 1)
		return 1;
	else
		return 0;
}

int empty(int s[]) {
	if (top == -1)
		return 1;
	else
		return 0;
}

int push(int s[], int data) {
	if (full(s))
		return 0;
	else {
		s[++top] = data;
		return 1;
	}
}

int pop(int s[]) {
	int tmp = 0;

	if (empty(s))
		return 0;
	else
		return s[top--];
}

int peek(int s[]) {
	if (empty(s))
		return 0;
	else
		return s[top];
}

int main()
{
	int s[max];
	int exam[max];
	char result[super_max];
	int n, i, z, k, range, r;
	int idx = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &exam[i - 1]);
	}

	for (k = 0; k < n; k++) {
		if (idx < exam[k]) {
			range = exam[k] - idx;
			for (z = 1; z <= range; z++) {
				push(s, idx + z);
				result[result_idx] = '+';
				result_idx++;
			}
			idx = exam[k];
			pop(s);
			result[result_idx] = '-';
			result_idx++;
		}
		else if (exam[k] == peek(s)) {
			pop(s);
			result[result_idx] = '-';
			result_idx++;
		}
		else {
			printf("NO");
			return 0;
		}
	}

	for (r = 0; r < result_idx; r++) {
		printf("%c\n", result[r]);
	}
	return 0;
}
