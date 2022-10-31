#pragma once

using namespace std;

class Order
{
	int orderNumber;
	int date;			//Format: DDMMYYYYTIME - (date - month - yaer - time) 
	float amount;


	Order();
	Order(int, int, float);

public:
	
	void SetOrderAmount(float);
	float GetOrderAmount();

};	