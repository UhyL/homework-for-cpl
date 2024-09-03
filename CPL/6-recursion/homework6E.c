//
// Created by 27756 on 2022/11/4.
//
#include <stdio.h>
#include <math.h>
#define error 1e-5
double a, b;

double Integral(double a, double b, int array[], int n, int p);

double f1(double l, double r, int p, int array[], int n);

double f2(int array[], int n, double x, int p);

int main() {
  int n, p;

  int array[21] = {0};
  scanf("%d%d", &n, &p);
  for (int i = 0; i <= n; ++i) {
	scanf("%d", &array[i]);
  }
  scanf("%lf%lf", &a, &b);

  printf("%lf", Integral(a, b, array, n, p));

}

double Integral(double l, double r, int array[], int n, int p) {
  double SL, SR, S;
  double count = (r - l) / (b - a);
  double mid = (l + r) / 2;
  SL = f1(l, mid, p, array, n);
  SR = f1(mid, r, p, array, n);
  S = f1(l, r, p, array, n);

  if (fabs(SL + SR - S) <= (15 * error * count)) {
	return SL + SR + (SL + SR - S) / 15;
  }
  return Integral(l, mid, array, n, p) + Integral(mid, r, array, n, p);

}

double f1(double l, double r, int p, int array[], int n) {
  double mid1 = (l + r) / 2;
  return ((4 * f2(array, n, mid1, p) + f2(array, n, l, p) + f2(array, n, r, p)) / 6) * (r - l);
}

double f2(int array[], int n, double x, int p) {
  double sum = 0;

  for (int i = 0; i <= n; ++i) {
	sum = sum + array[i] * pow(x, i);
  }

  sum = pow(sum, p);

  return sum;
}
