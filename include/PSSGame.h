
#include "GUI.h"
#include "Player.h"
#include "Team.h"
#include "Debug.h"

#include "WorldDB.h"
#include "PlayerFactory.h"

class PSSGame
{
public:
	PSSGame();
	~PSSGame();

	void Init();
	void Run();

private:
	void Draw();
	void Render();

	ImVec4 clearCol;
	GLFWwindow* window;

	bool simulating;
	bool showTest, showDebug;

	// test
	sptr<Team> t;

#ifdef _DEBUG
	Debug d;
#endif
};
