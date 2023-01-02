#pragma once
#ifndef IVIEW_H
#define IVIEW_H
#include <string>

// Pure abstract base view class
class IView
{
public:
	virtual ~IView() = default;
	virtual void showText(const std::string& text) = 0;
	virtual void showTextWithSection(const std::string& text) = 0;
	virtual void showTextWithOptions(const std::string& text) = 0;
	virtual std::string parseNum(double value) = 0;
};
#endif // !IVIEW_H
