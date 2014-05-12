#include "Store.h"

item::item()
{
	itemName = "";
	price = 0;
	number = 0;
}

string item::getItem()
{
	return itemName;
}
float item::getPrice()
{
	return price;
}
int item::getNumber()
{
	return number;
}

void setItem(string item)
{
	item = itemName;
}
float setPrice(int prc)
{
	prc = price
}
void setNumber(int num)
{
	num = number;
}
