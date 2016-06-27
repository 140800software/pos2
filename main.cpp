#include<iostream>
#include<fstream>
#include<time.h>
#include"acount good.h"
using namespace std;

int main() {
	link* getFinalList();
	link*head = getFinalList();
	link*p = head;	
	cout << "***商店购物清单***" << endl;
	cout << "打印时间：";
	struct tm newtime;
	char am_pm[] = "AM";
	__time64_t long_time;
	char timebuf[26];
	errno_t err;

	// Get time as 64-bit integer.
	_time64(&long_time);
	// Convert to local time.
	err = _localtime64_s(&newtime, &long_time);
	if (err)
	{
		printf("Invalid argument to _localtime64_s.");
		exit(1);
	}
	if (newtime.tm_hour > 12)        // Set up extension. 
		strcpy_s(am_pm, sizeof(am_pm), "PM");
	if (newtime.tm_hour > 12)        // Convert from 24-hour 
		newtime.tm_hour -= 12;    // to 12-hour clock. 
	if (newtime.tm_hour == 0)        // Set hour to 12 if midnight.
		newtime.tm_hour = 12;

	// Convert to an ASCII representation. 
	err = asctime_s(timebuf, 26, &newtime);
	if (err)
	{
		printf("Invalid argument to asctime_s.");
		exit(1);
	}
	printf("%.19s %s\n", timebuf, am_pm);
	cout << "----------------------" << endl;
	acountGood*pt;
	float total=0,sub;
	int count;
	string name;
	while(p) {
		pt = p->item;
		if (pt->getPromotion() == 1) {
			sub = pt->getDecreaseMoney();
			name = pt->getName();
			count = pt->getDecreaseCount();
		}
		if (pt->getDiscount() != 1) {
			sub = sub + (1 - pt->getDiscount())*pt->getPrice();
		}
		cout << "名称：" << pt->getName() << ",数量：" << pt->getCount() << pt->getUnit() << ",单价：" << pt->getPrice() << ",小计：" << pt->intatal()<<endl;
		total = total + pt->intatal();
		p=p->next;
	}
	cout << "----------------------" << endl;
	cout << "挥泪赠送商品：" << endl;
	cout << "名称：" << name << ",数量：" << count<<endl;
	cout << "----------------------" << endl;
	cout << "总计："<<total << endl;
	cout << "节省：" << sub << endl;
	cout << "**********************" << endl;
	system("pause");



	return 0;
}

link* getList() {
	string jud;
	link*head = NULL;
	link*p = NULL;

	ifstream ifile("新建文本文档.txt");
	if (ifile >> jud) {

		string barcode;
		while (ifile >> barcode) {
			
			string  name, unit;
			bool promotion = 0;
			float price, discount = 1;
		

			while (ifile >> jud) {
				if (jud == "name:") {
					ifile >> name;
				
					continue;
				}
				else if (jud == "unit:") {
					ifile >> unit;
				
					continue;
				}
				else if (jud == "price:") {
					ifile >> price;
					
					continue;
				}
				else if (jud == "promotion:") {
					string a;

					ifile >> a;
					if (a == "true")
						promotion = 1;
					
					
					continue;
				}
				else if (jud == "discount:") {
					ifile >> discount;
					
					continue;
				}
				else if (jud == "},") {//生成节点
					if (head == NULL) {
						link*ptr = new link(barcode);
						ptr->item= new acountGood(name, unit, price, discount, promotion);
						//cout << "1";
						head = ptr;
						p = head;
						
						break;

					}
					else {
						link*ptr = new link(barcode);
						ptr->item = new acountGood(name, unit, price, discount, promotion);
						p->next = ptr;
						p = p->next;
						
						break;

					}
				}

			}


		}

	}
	ifile.close();
	return head;

}
link* getFinalList() {
	link* getList();
	link* head = getList();
	link* p = head;
	string jud;
	ifstream ifile("新建文本文档2.txt");

	while (ifile >> jud) {

		p = head;
		while (p) {
			if (p->barcode == jud) {

				acountGood*pw = NULL;
				pw = p->item;
				pw->increase();

			}
			p = p->next;
		}

	}
	return head;
}
