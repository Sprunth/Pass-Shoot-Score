
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
	glfwTerminate();

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

	Debug d;

	auto t = TeamFactory::CreateTeam();
	t->SetName("Team 1");
	auto p1 = PlayerFactory::CreatePlayer();
	auto p2 = PlayerFactory::CreatePlayer();
	p1->SetName("Player 1");
	p2->SetName("Player 2");
	t->AddPlayer(p1);
	t->AddPlayer(p2);

	bool showTest = false, showDebug = false;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		//auto io = ImGui::GetIO();

		ImGui_ImplGlfwGL3_NewFrame();

		//draw here
		ImGui::BeginMainMenuBar();
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				glfwSetWindowShouldClose(window, true);
			}
			ImGui::EndMenu();
		}
#if _DEBUG
		if (ImGui::BeginMenu("Debug"))
		{
			ImGui::MenuItem("Show test window", 0, &showTest);				
			ImGui::MenuItem("Show debug window", 0, &showDebug);

			ImGui::EndMenu();
		}
#endif
		ImGui::EndMainMenuBar();

#ifdef _DEBUG
		if (showTest)
			ImGui::ShowTestWindow(&showTest);
		if (showDebug)
			d.Draw();
#endif

		t->DrawTeamList();
		

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

