#pragma once
#ifndef SELLER_H
#define SELLER_H
#include <string>
#include <vector>

class Quote;
class Store;

class Seller
{
private:

	std::string name;
	std::string lastname;
	int sellerCode;

	std::vector<std::string> quoteInfoVec;
	Store* sellerStore;

public:
	Seller();
	~Seller();

#pragma region ACTIONS

	void quoteProduct(int& clothes, int units);

#pragma endregion

#pragma region SETTERS

	void setClothesSpecifications(int clothesType, int alternative1, int alternative2, int quality);
	void setUnitsAndQuote(int& clothes, int units, double quote);

#pragma endregion

#pragma region GETTERS

	std::string getSellerStore()const;
	std::string getSellerName() const;
	int getSellerCode() const;
	void getClothesSpecifications(double& initialPrice, bool& alternative1, bool& alternative2, bool& quality);
	void getClothesSpecifications(double& initialPrice, bool& alternative1, bool& quality); // OVERLOAD/SOBRECARGA
	int getClothesStockAmount(int clothesType);
	std::string getQuoteInfo(int choose);
	double getUnitPrice();
	void getQuoteRecord();

#pragma endregion

	std::string parseNum(int value);
};
#endif // !SELLER_H
