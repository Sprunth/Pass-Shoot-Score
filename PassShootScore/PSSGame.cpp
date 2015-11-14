#include "PSSGame.h"

PSSGame::PSSGame()
{
	window = glfwCreateWindow(1280, 720, "Pass Shoot Score", nullptr, nullptr);

	auto player = std::make_shared<Player>();
	playerView.LoadPlayer(player);
}


PSSGame::~PSSGame()
{
	
}


void PSSGame::Init()
{
	glfwMakeContextCurrent(window);
	gl3wInit();

	ImGui_ImplGlfwGL3_Init(window, true);
}


void PSSGame::Run()
{
	ImVec4 clearColor = ImColor(140, 160, 170);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		ImGui_ImplGlfwGL3_NewFrame();

		// draw here
		playerView.Draw();

		// Rendering
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui::Render();
		glfwSwapBuffers(window);
	}
	ImGui_ImplGlfwGL3_Shutdown();
}

