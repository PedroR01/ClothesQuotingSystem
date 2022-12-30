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
	Seller* m_Seller = nullptr;
	explicit Presenter(IView* view);
	~Presenter();
	void seeQuoteRecord();
	void startQuote(int& clothes);
	const std::string seeSellerName();
	const int* seeSellerCode();
};

#endif // !PRESENTER_H
