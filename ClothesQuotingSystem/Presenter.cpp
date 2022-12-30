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

void Presenter::seeQuoteRecord()
{
}

void Presenter::startQuote(int& clothes)
{
	m_Seller->quoteProduct(clothes);
}

const std::string Presenter::seeSellerName()
{
	return m_Seller->getSellerName();;
}

const int* Presenter::seeSellerCode()
{
	return m_Seller->getSellerCode();
}