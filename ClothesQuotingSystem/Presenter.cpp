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