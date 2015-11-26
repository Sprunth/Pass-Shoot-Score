#include "TopMenu.h"

using namespace std;

bool TopMenu::Exit = false;
bool TopMenu::ShowTestWindow = false;

void TopMenu::Draw()
{
	if (ImGui::BeginMainMenuBar())
	{
		FileMenuOptions();

		ImGui::EndMainMenuBar();
	}
}

void TopMenu::FileMenuOptions()
{
	if (ImGui::BeginMenu("File"))
	{
		ImGui::MenuItem("Exit", nullptr, &Exit);
		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Debug"))
	{
		ImGui::MenuItem("Show Test Window", nullptr, &ShowTestWindow);		
		ImGui::EndMenu();
	}

	if (Exit)
		exit(0);

	if (ShowTestWindow)
		ImGui::ShowTestWindow();
}

