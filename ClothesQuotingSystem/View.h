#pragma once
#ifndef VIEW_H
#define VIEW_H
#include "IView.h"

class Presenter;

class View : public IView
{
private:
	Presenter* m_Presenter;

	void header();
	void showMainMenu();
	void quoteMenu();
	void quoteRecord();
public:
	View();
	~View() override;
	void showText(const std::string& text) override;
	void showTextWithSection(const std::string& text) override;
	void showTextWithOptions(const std::string& text) override;
	std::string parseNum(int value) override;
};
#endif // !VIEW_H
