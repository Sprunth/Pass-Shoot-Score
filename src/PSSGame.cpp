
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
	glfwTerminate();
}


void PSSGame::Init()
{
	glfwMakeContextCurrent(window);
	gl3wInit();

	ImGui_ImplGlfwGL3_Init(window, true);

	clearCol = ImColor(140, 160, 170);
	simulating = false;
	showTest = false;
	showDebug = false;

	WorldDB::NewWorld();
}

void PSSGame::Run()
{
	t = TeamFactory::CreateTeam();
	t->SetName("Team 1");
	auto p1 = PlayerFactory::CreatePlayer();
	//auto p2 = PlayerFactory::CreatePlayer();
	p1->SetName("Player 1");
	//p2->SetName("Player 2");
	t->AddPlayer(p1);
	//t->AddPlayer(p2);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		//auto io = ImGui::GetIO();

		ImGui_ImplGlfwGL3_NewFrame();

		if (simulating)
		{
			// todo: disable gui, etc.
			bool stop = false;
			WorldDB::Simulate(stop);

			if (stop)
				simulating = false;
		}
		else
		{
			Draw();
		}

		Render();
	}
}


void PSSGame::Draw()
{
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

	if (ImGui::BeginMenu(WorldDB::GetWorldTimeStr().c_str()))
	{
		ImGui::MenuItem("Continue", 0, &simulating);

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
}

void PSSGame::Render()
{
	// Rendering
	int display_w, display_h;
	glfwGetFramebufferSize(window, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);
	glClearColor(clearCol.x, clearCol.y, clearCol.z, clearCol.w);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui::Render();
	glfwSwapBuffers(window);
}

