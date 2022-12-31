#pragma once
#ifndef PRESENTER_H
#define PRESENTER_H
#include <string>

class IView;
class Seller;

class Presenter
{
private:
	IView* m_View = nullptr;

public:
	Seller* m_Seller;
	explicit Presenter(IView* view);
	~Presenter();
	void seeQuoteRecord();
	void startQuote(int& clothes);
	std::string seeSellerStore() const;
	std::string seeSellerName() const;
	int seeSellerCode() const;
	void sendClothesData(int clothesType, int alternative1, int alternative2, int quality);
	int returnStock();
};

#endif // !PRESENTER_H
