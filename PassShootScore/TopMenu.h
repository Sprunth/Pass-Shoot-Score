#pragma once

#include "Globals.h"
#include "GUI.h"

#include <stack>

class TopMenu
{
public:


	/// Call the relevant drawing commands to draw menu using ImGui
	static void Draw();

private:

	static void FileMenuOptions();

	static bool Exit;

};

