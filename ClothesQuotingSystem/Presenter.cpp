#include "Presenter.h"
#include "IView.h"
#include "Seller.h"

Presenter::Presenter(IView* view) : m_View(view), m_Seller(new Seller())
{
}

Presenter::~Presenter()
{
	delete m_Seller;
}

#pragma region SEND

void Presenter::sendClothesData(int clothesType, int alternative1, int alternative2, int quality)
{
	m_Seller->setClothesSpecifications(clothesType, alternative1, alternative2, quality);
}

void Presenter::sendDataToQuote(int& clothes, int units, double quote)
{
	m_Seller->setUnitsAndQuote(clothes, units, quote);
}

#pragma endregion

#pragma region SEE/RETURN

std::string Presenter::seeSellerStore() const
{
	return m_Seller->getSellerStore();
}

std::string Presenter::seeSellerName() const
{
	return m_Seller->getSellerName();
}

int Presenter::seeSellerCode() const
{
	return m_Seller->getSellerCode();
}

int Presenter::returnStock(int clothesType)
{
	return m_Seller->getClothesStockAmount(clothesType);
}

std::string Presenter::seeQuoteInfo(int choose)
{
	return m_Seller->getQuoteInfo(choose);
}

double Presenter::seeUnitPrice()
{
	return m_Seller->getUnitPrice();
}

void Presenter::seeQuoteRecord()
{
	m_Seller->getQuoteRecord();
}

#pragma endregion