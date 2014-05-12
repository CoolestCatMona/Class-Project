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

void item::setItem(string item)
{
	itemName = item;
}
void item::setPrice(float prc)
{
	price = prc;
}
void item::setNumber(int num)
{
	number = num;
}
