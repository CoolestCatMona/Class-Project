#ifndef STORE_H_
#define STORE_H_
#include "headerfile.h"

typedef string name;
class item
{
public:
	item();
	name getItem();				//CALC - Gets Item name
	float getPrice();				//CALC - Gets Item Price
	int getNumber();			//CALC - Gets Number of items owned

	void setItem(name item);	//CALC - Sets Item name
	void setPrice(float prc);		//CALC - Sets Item Price
	void setNumber(int num);	//CALC - Sets Number of items owned
private:
	name itemName;
	int price;
	int number;

};



#endif /* STORE_H_ */
