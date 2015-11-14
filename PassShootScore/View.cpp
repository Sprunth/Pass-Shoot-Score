#include "View.h"


View::View()
{
	SetSize(48, 32);
}


View::~View()
{
}

void View::Draw()
{
	ImGui::SetNextWindowSize(windowSize, ImGuiSetCond_FirstUseEver);
	ImGui::Begin(windowName.c_str(), nullptr, 0);
	DrawView();
	ImGui::End();
}
