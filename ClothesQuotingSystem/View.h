#pragma once
#ifndef VIEW_H
#define VIEW_H
#include "IView.h"

class Presenter;

class View : public IView
{
private:
	Presenter* m_Presenter;

	void showMainMenu();
	void sellerOptions();
	void quoteMenu();
	void quoteRecord();
public:
	View();
	~View() override;
	void showText(const std::string& text) override;
};
#endif // !VIEW_H
