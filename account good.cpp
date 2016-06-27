#include"acount good.h"
using namespace std;

float acountGood::intatal() {
	if (promotion) {
		int c;
		int d;
		c = count / 3;
		d = count % 3;
		return c * 2 * price + d*price;
	}
	else
		return discount*price*count;
}
int acountGood::getDecreaseCount() {
	return count / 3;
}
int acountGood::getDecreaseMoney() {
	return count / 3 * price;
}
