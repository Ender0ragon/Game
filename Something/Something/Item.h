#pragma once

#include <string>;

using namespace std;

class Item
{
public:
	Item(string nam, int am, int dmg, int use);

	string name;
	int amount;
	int damage;
	int uses;
};