#pragma once

#include "Globals.h"
#include "GUI.h"

#include <stack>

class TopMenu
{
public:
	/// Adds a new option to the Top Menu
	/// All new children new unique names.
	/// If adding a new menu option fails, function returns false.
	/// If ref:parent is empty, we add to the top level.
	static bool RegisterNewMenuItem(std::string parent, std::string newMenuOptionName);
	
	/// Removes a menu option by string name
	/// If no such menu option exists, function returns false
	static bool RemoveMenuItem(std::string menuOptionName);

	/// Call the relevant drawing commands to draw menu using ImGui
	static void Draw();

private:
	/// Each entry here is a submenu
	/// The first string is the parent (the submenu owner)
	/// Each parent has a vector of strings, being menu items
	/// Those either correspond to menu items or possibly another submenu layer
	static std::map<std::string, std::vector<std::string>> subMenus;

	static std::map<std::string, bool> MenuClickState;
};

