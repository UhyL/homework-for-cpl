//
// Created by 27756 on 2022/11/14.
//
#include <stdio.h>
#include <stdbool.h>
bool standard = false;

void Pour(int a, int b, int c, int k, int VA, int VB, int VC, int a0, int b0, int c0, int step);



int main() {
  int k, VA, VB, VC, a0, b0, c0, a, b, c;
  /**
   * k表示步数，VA、vB、VC表示容积，a、b、c表示开始有的水，a0、b0、c0表示最终剩余的水
   */
  scanf("%d%d%d%d%d%d%d%d%d%d", &k, &VA, &VB, &VC, &a, &b, &c, &a0, &b0, &c0);

  int step = 0;

  Pour(a, b, c, k, VA, VB, VC, a0, b0, c0, step);

  if (standard) {
	printf("Yes");
  } else {
	printf("No");
  }

  return 0;
}

void Pour(int a, int b, int c, int k, int VA, int VB, int VC, int a0, int b0, int c0, int step) {

  if((a0 == 0) && (b0 == 0) && (c0 == 0)) {
	if((a != 0)||(b != 0) || (c != 0) ) {
	  return;
	}
  }

  if (step > k) {
	return;
  } else if ((a == a0) && (b == b0) && (c == c0)) {
	standard = true;
	return;
  }

  int a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6, c1, c2, c3, c4, c5, c6;
  a1 = a2 = a3 = a4 = a5 = a6 = a;
  b1 = b2 = b3 = b4 = b5 = b6 = b;
  c1 = c2 = c3 = c4 = c5 = c6 = c;
  if ((a1 + b1) <= VB) {
	b1 = a1 + b1;
	a1 = 0;
  } else {
	b1 = VB;
	a1 = 0;
  }

  if ((a2 + c2) <= VC) {
	c2 = a2 + c2;
	a2 = 0;
  } else {
	c2 = VC;
	a2 = 0;
  }

  if ((b3 + a3) <= VA) {
	a3 = a3 + b3;
	b3 = 0;
  } else {
	a3 = VA;
	b3 = 0;
  }

  if ((b4 + c4) <= VC) {
	c4 = b4 + c4;
	b4 = 0;
  } else {
	c4 = VC;
	b4 = 0;
  }

  if ((a5 + c5) <= VA) {
	a5 = a5 + c5;
	c5 = 0;
  } else {
	a5 = VA;
	c5 = 0;
  }

  if ((b6 + c6) <= VB) {
	b6 = b6 + c6;
	c6 = 0;
  } else {
	b6 = VB;
	c6 = 0;
  }

  step++;

  Pour(a1, b1, c1, k, VA, VB, VC, a0, b0, c0, step);
  Pour(a2, b2, c2, k, VA, VB, VC, a0, b0, c0, step);
  Pour(a3, b3, c3, k, VA, VB, VC, a0, b0, c0, step);
  Pour(a4, b4, c4, k, VA, VB, VC, a0, b0, c0, step);
  Pour(a5, b5, c5, k, VA, VB, VC, a0, b0, c0, step);
  Pour(a6, b6, c6, k, VA, VB, VC, a0, b0, c0, step);
}


