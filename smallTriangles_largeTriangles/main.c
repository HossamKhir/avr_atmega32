#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle *tr, int n) {
  /*
   * Sort an array a of the length n
   */
  int S[n], p[n];
  int i, j;
  float temp;
  triangle tr_temp;
  for (i = 0; i < n; i++) {
    p[i] = ((tr[i].a + tr[i].b + tr[i].c) / 2);
    S[i] = sqrt(p[i] * (p[i] - tr[i].a) * (p[i] - tr[i].b) *
                       (p[i] - tr[i].c));
  }
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (S[j] > S[j + 1]) {
        temp = S[j];
        tr_temp = tr[j];
        S[j] = S[j + 1];
        tr[j] = tr[j + 1];
        S[j + 1] = temp;
        tr[j + 1] = tr_temp;
      }
    }
  }
}

int main()
{
	int n, i;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for ( i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	printf("\n\n");
	for ( i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
