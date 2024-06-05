/*************************************************************************
> File Name: adaper.cpp
> Author: CarlSun
> Mail:sunxiuyang04@gmail.com 
> Created Time: Tue Aug  9 19:59:58 2016
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<adaper.h>
using namespace std;
int main(){
	Player* b = new Forwards("James");
	b->attack();
	Player* m = new Center("Maddie");
	m->attack();
	Player* ym = new Translator("YaoMing");
	ym->attack();
	ym->defense();
	delete b;
	delete m;
	delete ym;
}
