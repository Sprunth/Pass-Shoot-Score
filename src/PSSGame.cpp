
#include "PSSGame.h"

PSSGame::PSSGame()
{
	ImGuiIO& io = ImGui::GetIO();
	io.IniFilename = "";

	window = glfwCreateWindow(1280, 720, "Pass Shoot Score!", nullptr, nullptr);


}

PSSGame::~PSSGame()
{
	ImGui_ImplGlfwGL3_Shutdown();

	glfwDestroyWindow(window);
}


void PSSGame::Init()
{
	glfwMakeContextCurrent(window);
	gl3wInit();

	ImGui_ImplGlfwGL3_Init(window, true);
}

void PSSGame::Run()
{
	ImVec4 clearCol = ImColor(140, 160, 170);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		ImGui_ImplGlfwGL3_NewFrame();

		//draw here

		// Rendering
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clearCol.x, clearCol.y, clearCol.z, clearCol.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui::Render();
		glfwSwapBuffers(window);

	}
}

