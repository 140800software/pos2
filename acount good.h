#pragma once

#include<string>
using namespace std;

class acountGood {
private:
	string name;
	string unit;
	int count=0;
	float price;
	float discount = 1;
	bool promotion=0;
	
public:
	acountGood(string na, string uni,float pri, float disc,bool pro) {
		name = na;
		unit = uni;
		price = pri;
		
		promotion = pro;
		discount = disc;
		
	}
	float intatal();//得到这个商品的总价
	string getName() {
		return name;
	}
	string getUnit() {
		return unit;
	}
	float getPrice() {
		return price;
	}
	float getDiscount() {
		return discount;
	}
	void increase() {
		count++;
	}
	int getCount() {
		return count;
	}
	bool getPromotion() {//得知该物品是否为买二赠一商品
		return promotion;
	}
	int getDecreaseCount();//得到由于买二赠一减少的数量
	int getDecreaseMoney();//得到由于买二赠一减少的价格
};


struct link
{
	string barcode;
	link*next = NULL;
	acountGood* item = NULL;
	link() {};
	link(string bar) {
		barcode = bar;
	}
};
