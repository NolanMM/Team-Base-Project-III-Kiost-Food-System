#pragma once

#include <string>

using namespace std;

class Item
{
	string name;
	string description;
	int calories;
	float weight;
	float price;

	Item();
	Item(string name, string description, float weight, float price);
	Item(string name, string description, int calories, float price);
	Item(string name, string description, int calories, float weight, float price);

public:

	void SetItemName(string newName);
	void SetItemDescription(string newDescription);
	void SetItemCalories(int newCalories);
	void SetItemWeight(float newWeight);
	void SetItemPrice(float newPrice);

	string GetItemName();
	string GetItemDescription();
	int GetItemCalories();
	float GetItemWeight();
	float GetItemPrice();
};