#include "TopMenu.h"

using namespace std;

bool TopMenu::Exit = false;

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

	if (Exit)
		exit(0);
}

