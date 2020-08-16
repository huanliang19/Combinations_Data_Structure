#include "ItemChart.h"
#include <iostream>

//constexpr unsigned int MAX_ITEM_COUNT = 9;
//constexpr unsigned int MAX_FULL_ITEM_COUNT = 45;

int main(){
	ItemChart *ic = new ItemChart();
	ic->AddItem(0);
	ic->AddItem(1);
	ic->AddItem(1);
	ic->AddItem(1);
	ic->AddItem(2);
	ic->AddItem(2);
	int* arr = ic->GetItems();
	for (int i = 0; i < MAX_FULL_ITEM_COUNT; i++)
		std::cout << *(arr + i) << ", ";
	return 0;
}