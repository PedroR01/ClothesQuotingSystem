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

	// Podrian ser valores constantes, pero entonces se me dificulta para introducir sus valores por input y obtener estos mismos a traves de getters
	std::string name;
	std::string lastname;
	int sellerCode;

	std::vector<Quote> quotesRecord;
	Store* sellerStore;

public:
	Seller();
	~Seller();
	void quoteProduct(int& clothes, int units);
	std::string getSellerStore()const;
	std::string getSellerName() const;
	int getSellerCode() const;
	void setClothesSpecifications(int clothesType, int alternative1, int alternative2, int quality);
	void getClothesSpecifications(double& initialPrice, bool& alternative1, bool& alternative2, bool& quality);
	void getClothesSpecifications(double& initialPrice, bool& alternative1, bool& quality);
	int getClothesStockAmount(int clothesType);
	void setUnitsAndQuote(int& clothes, int units, double quote);
	std::string parseNum(int value);
	std::string getQuoteInfo(int choose);
	double getUnitPrice();
};
#endif // !SELLER_H
