#pragma once
#ifndef __ItemChart_H_INCLUDED__
#define __ItemChart_H_INCLUDED__
constexpr unsigned int MAX_ITEM_COUNT = 9;
constexpr unsigned int MAX_FULL_ITEM_COUNT = 45;

#include <iostream>

class ItemChart {
private:
	int itemTotal;
	int itemCount[MAX_ITEM_COUNT]; //array[]
	int fullitemCount[MAX_FULL_ITEM_COUNT]; //array[]
	void UpdateChart();

public:
	ItemChart();
	~ItemChart();
	int* GetItems();
	void AddItem(int compItemIndex);
	void RemoveItem(int itemIndex);
	void Reset();
};

#endif