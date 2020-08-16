#include "ItemChart.h"
#include <iostream>
#include <algorithm> 
//constexpr unsigned int MAX_ITEM_COUNT = 9;
//constexpr unsigned int MAX_FULL_ITEM_COUNT = 45;

ItemChart::ItemChart() : fullitemCount{ 0 }, itemCount{ 0 }{
}

ItemChart::~ItemChart() {
}

void ItemChart::UpdateChart() {
	//Factor in presence of an item by row
	int rowInx = 0;
	for (int i = 0; i < MAX_ITEM_COUNT; i++) {
		int cloneInx = 0;
		for (int j = rowInx; j <= rowInx + i; j++) {
			this->fullitemCount[j] = std::min(this->itemCount[i], this->itemCount[cloneInx]);
			cloneInx++;
		}
		rowInx += i+1;
	}

	//Divide Diagonals
	int skipInx = 0;
	for (int i = 0; i < MAX_ITEM_COUNT; i++) {
		fullitemCount[skipInx] = fullitemCount[skipInx] / 2;
		skipInx += i + 2;
	}
}

int* ItemChart::GetItems() {
	static int retArr[MAX_FULL_ITEM_COUNT];
	for (int i = 0; i < MAX_FULL_ITEM_COUNT; i++) {
		retArr[i] = this->fullitemCount[i];
	}
	return retArr;
}

void ItemChart::AddItem(int itemIndex) {
	this->itemCount[itemIndex]++;
	this->itemTotal++;
	this->UpdateChart();
}

void ItemChart::RemoveItem(int itemIndex) {
	if (this->itemCount > 0) {
		this->itemCount[itemIndex]--;
		this->itemTotal--;
		this->UpdateChart();
	}
}

void ItemChart::Reset() {
	for(int i : this->itemCount) {
		i = 0;
	}
	for (int i : this->fullitemCount) {
		i = 0;
	}
	this->itemTotal = 0;
	this->UpdateChart();
}