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

	std::vector<Quote*> quotesRecord;
	Store* sellerStore;

public:
	Seller();
	~Seller();
	void quoteProduct(int& clothes);
	std::string getSellerStore()const;
	std::string getSellerName() const;
	int getSellerCode() const;
	void setClothesSpecifications(int clothesType, int alternative1, int alternative2, int quality);
	int getClothesStockAmount();
	std::string parseNum(int value);
};
#endif // !SELLER_H
