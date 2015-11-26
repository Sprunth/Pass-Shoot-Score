#include "PSSGame.h"

PSSGame::PSSGame()
{
	ImGuiIO& io = ImGui::GetIO();
	io.IniFilename = "";
	io.Fonts->AddFontFromFileTTF("DroidSans.ttf", 16);

	WorldDatabase::InitializeDatabase();

	

	window = glfwCreateWindow(1280, 720, "Pass Shoot Score", nullptr, nullptr);

	auto player = WorldObjectFactory::CreatePlayer();
	playerView.LoadPlayer(player);

	auto team = WorldObjectFactory::CreateTeam();
	player->SetTeam(team);

	auto worldObjs = WorldDatabase::GetActiveDatabase()->GetAllWorldObjects();

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

		TopMenu::Draw();

		ImGui::ShowTestWindow();

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

