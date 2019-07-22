#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void solve(double meal_cost, int tip_percent, int tax_percent);

int main()
{
    double mCost;
    int pTip, pTax;
    scanf("%lf%d%d", &mCost, &pTip, &pTax);
    solve(mCost, pTip, pTax);
    return 0;
}

void solve(double meal_cost, int tip_percent, int tax_percent) {
    printf("%d",
           (int) round(meal_cost * ((100 + tip_percent + tax_percent) / 100.00)));
}
