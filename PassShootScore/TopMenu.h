#pragma once

#include "Globals.h"
#include "GUI.h"

class TopMenu
{
public:
	/// Adds a new option to the Top Menu
	/// All new children new unique names.
	/// If adding a new menu option fails, function returns false.
	/// If ref:parent is empty, we add to the top level.
	bool RegisterNewMenuItem(std::string parent, std::string newMenuOptionName);
	
	/// Removes a menu option by string name
	/// If no such menu option exists, function returns false
	bool RemoveMenuItem(std::string menuOptionName);

	/// Call the relevant drawing commands to draw menu using ImGui
	void Draw();

private:
	// todo: add structure to handle submenus


	static std::map<std::string, bool> MenuClickState;
};

