#pragma once
#ifndef STORE_H
#define STORE_H
#include <string>
#include <vector>

class Clothes;
class Shirt;
class Pants;

class Store
{
private:
	std::string storeName;
	std::string address;
	std::vector<Clothes*> clothesList;

	Clothes* shirt, * pants;
	Shirt* _shirt;
	Pants* _pants;

public:
	Store();
	~Store();
	std::string getStoreInfo() const;
	void getClothesInfo();
	void setClothesPreferences(int clothesType, int alternative1, int alternative2, int quality);
	int getClothesStock();
};

#endif // !STORE_H
