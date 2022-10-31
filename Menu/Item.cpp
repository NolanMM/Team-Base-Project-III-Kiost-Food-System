#include "Item.h"

//Default and copy constructors

Item::Item()
{
	this->name = "DefaultName";
	this->description = "DefaultDescription";
	this->calories = 0;
	this->weight = 0;
	this->price = 0;
}


Item::Item(string name, string description, float weight, float price)
{
	this->name = name;
	this->description = description;
	this->calories = 0;
	this->weight = weight;
	this->price = price;
}


Item::Item(string name, string description, int calories, float price)
{
	this->name = name;
	this->description = description;
	this->calories = calories;
	this->weight = 0;
	this->price = price;
}


Item::Item(string name, string description, int calories, float weight, float price)
{
	this->name = name;
	this->description = description;
	this->calories = calories;
	this->weight = weight;
	this->price = price;
}

//Setters

void Item::SetItemName(string newName)
{
	this->name = newName;
}

void Item::SetItemDescription(string newDescription)
{
	this->description = newDescription;
}

void Item::SetItemCalories(int newCalories)
{
	this->calories = newCalories;
}

void Item::SetItemWeight(float newWeight)
{
	this->weight = newWeight;
}

void Item::SetItemPrice(float newPrice)
{
	this->price = newPrice;
}

//Getters

string Item::GetItemName()
{
	return this->name;
}


string Item::GetItemDescription()
{
	return this->description;
}

int Item::GetItemCalories()
{
	return this->calories;
}

float Item::GetItemWeight()
{
	return this->weight;
}

float Item::GetItemPrice()
{
	return this->price;
}



