#include<stdio.h>

char chess[50][50], copy[50][50];

int black(int vertical, int horizontal) {
	
	int count = 0;
	if (chess[vertical][horizontal] == 'W') {
		chess[vertical][horizontal] = 'B';
		count++;
	}

	for (int i = vertical + 1; i < vertical + 8; i++) {
		if (chess[i - 1][horizontal] == chess[i][horizontal]) {
			count++;
			if (chess[i][horizontal] == 'B')
				chess[i][horizontal] = 'W';
			else
				chess[i][horizontal] = 'B';
		}
	}

	for(int i = vertical; i < vertical + 8; i++)
		for (int j = horizontal + 1; j < horizontal + 8; j++) {
			if (chess[i][j - 1] == chess[i][j]) {
				count++;
				if (chess[i][j] == 'B')
					chess[i][j] = 'W';
				else
					chess[i][j] = 'B';
			}
		}

	for (int i = vertical; i < vertical + 8; i++)
		for (int j = horizontal; j < horizontal + 8; j++)
			chess[i][j] = copy[i][j];

	return count;
}

int white(int vertical, int horizontal) {

	int count = 0;
	if (chess[vertical][horizontal] == 'B') {
		chess[vertical][horizontal] = 'W';
		count++;
	}

	for (int i = vertical + 1; i < vertical + 8; i++) {
		if (chess[i - 1][horizontal] == chess[i][horizontal]) {
			count++;
			if (chess[i][horizontal] == 'B')
				chess[i][horizontal] = 'W';
			else
				chess[i][horizontal] = 'B';
		}
	}

	for (int i = vertical; i < vertical + 8; i++)
		for (int j = horizontal + 1; j < horizontal + 8; j++) {
			if (chess[i][j - 1] == chess[i][j]) {
				count++;
				if (chess[i][j] == 'B')
					chess[i][j] = 'W';
				else
					chess[i][j] = 'B';
			}
		}

	for (int i = vertical; i < vertical + 8; i++)
		for (int j = horizontal; j < horizontal + 8; j++)
			chess[i][j] = copy[i][j];

	return count;
}

int location(int n, int m) {

	int d_vertical, d_horizontal, min = 2500;
	int i, j, nb, nw;

	for (i = 0; i < n - 7; i++)
		for (j = 0; j < m - 7; j++) {
			d_vertical = i;
			d_horizontal = j;
			nb = black(d_vertical, d_horizontal);
			nw = white(d_vertical, d_horizontal);
			if (nb <= nw && min > nb)
				min = nb;
			else if (nw < nb && min > nw)
				min = nw;
		}
	return min;
}

int main() {

	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++)
		for (int j = 0; j < m; j++) {
			scanf(" %c", &chess[i][j]);
			copy[i][j] = chess[i][j];
		}

	printf("%d", location(n, m));
}