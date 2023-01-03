#pragma once
#ifndef VIEW_H
#define VIEW_H
#include "IView.h"

class Presenter;

class View : public IView
{
private:
	Presenter* m_Presenter;
	bool step5InputError;

	void header(std::string actualSection);
	void showMainMenu();
	void quoteMenu();
	void quoteRecord();
	void selectOption(int& input, int min, int max);
	void selectOption(double& input, int min, int max); // OVERLOAD/SOBRECARGA
public:
	View();
	~View() override;

	void showText(const std::string& text) override;
	void showTextWithSection(const std::string& text) override;
	void showTextWithOptions(const std::string& text) override;
	std::string parseNum(double value) override;
};
#endif // !VIEW_H
