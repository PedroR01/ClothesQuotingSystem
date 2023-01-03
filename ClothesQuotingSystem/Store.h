#pragma once
#ifndef STORE_H
#define STORE_H
#include <string>
#include <vector>

class Clothes;

class Store
{
private:
	std::string storeName;
	std::string address;

public:
	Store();
	~Store();

#pragma region Setters

	void setClothesPreferences(int clothesType, int alternative1, int alternative2, int quality);
	void setUnitsAndQuote(int units, double quote);

#pragma endregion

#pragma region Getters

	std::string getStoreInfo() const;
	void getClothesInfo();
	int getClothesStock(int clothesType);
	void getClothesSpecs(bool& alternative1, bool& alternative2, bool& quality);
	void getClothesSpecs(bool& alternative1, bool& quality); // OVERLOAD/SOBREGARGA
	double getUnitPrice();

#pragma endregion
};

#endif // !STORE_H
