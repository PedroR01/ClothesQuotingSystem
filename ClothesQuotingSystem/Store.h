#pragma once
#ifndef STORE_H
#define STORE_H
#include <string>
#include <vector>

class Clothes;
//class Shirt;
//class Pants;

class Store
{
private:
	std::string storeName;
	std::string address;
	std::vector<Clothes*> clothesList;

	//Shirt* _shirt;
	//Pants* _pants;

public:
	Store();
	~Store();
	std::string getStoreInfo() const;
	void getClothesInfo();
	void setClothesPreferences(int clothesType, int alternative1, int alternative2, int quality);
	int getClothesStock(int clothesType);
	void setUnitsAndQuote(int& clothes, int units, double quote);
	double getUnitPrice();
	void getClothesSpecs(bool& alternative1, bool& alternative2, bool& quality);
	void getClothesSpecs(bool& alternative1, bool& quality);
};

#endif // !STORE_H
