#pragma once
#include "Globals.h"

#include "GUI.h"

class View
{
public:
	View();
	virtual ~View();

	void Draw();

	void SetSize(int x, int y) { windowSize = ImVec2((float)x, (float)y); }
	void SetTitle(std::string title) { windowName = title; }

protected:
	
	virtual void DrawView() = 0;


private:
	ImVec2 windowSize;
	std::string windowName;
};

