#include "TopMenu.h"

using namespace std;

map<string, bool> TopMenu::MenuClickState;
map<string, vector<string>> TopMenu::subMenus;

bool TopMenu::RegisterNewMenuItem(std::string parent, std::string newMenuOptionName)
{
	if (MenuClickState.count(newMenuOptionName) != 0)
	{
		// entry exists already
		return false;
	}

	MenuClickState.insert(pair<string, bool>(newMenuOptionName, false));

	if (!parent.empty())
	{
		if (subMenus.count(parent) == 0)
		{
			// submenu option doesn't exist. Make it
			subMenus.insert(pair<string, vector<string>>(parent, vector<string>()));
		}

		// this menu key exists now
		subMenus[newMenuOptionName].push_back(newMenuOptionName);
	}


	return true;
}

bool TopMenu::RemoveMenuItem(std::string menuOptionName)
{
	// todo

	if (MenuClickState.count(menuOptionName) == 0)
	{
		// name doesn't exist
		return false;
	}

	MenuClickState.erase(menuOptionName);

	for (auto entry : subMenus)
	{
		auto entryVector = entry.second;

		auto findRes = find(entryVector.begin(), entryVector.end(), menuOptionName);
		if (findRes != entryVector.end())
			entryVector.erase(findRes);
	}

	if (subMenus.count(menuOptionName) != 0)
		subMenus.erase(menuOptionName);

	return true;
}

void TopMenu::Draw()
{
	/// Essentially it is a binary tree traversal in iterative form using a stack
	/// We need a way to denote 'close submenu', which we'll use '\n' to denote


	ImGui::BeginMainMenuBar();

	stack<string> toProcess;

	for (auto it_rev = subMenus.rbegin(); it_rev != subMenus.rend(); ++it_rev)
	{
		toProcess.push(it_rev->first);
	}

	while (!toProcess.empty())
	{
		auto entry = toProcess.top();
		toProcess.pop();

		auto r = subMenus.count(entry);
		if (r != 0)
		{
			// this entry is a submenu parent
			ImGui::BeginMenu(entry.c_str());

			// add its children to the stack
			for (int j = subMenus[entry].size() - 1; j >= 0; j--)
			{
				toProcess.push(subMenus[entry][j]);
			}

			toProcess.push("\n");
		}
		else
		{
			// it has no submenu children
			ImGui::MenuItem(entry.c_str(), nullptr, &MenuClickState[entry]);
		}

		
	}
	
	ImGui::EndMainMenuBar();
}

