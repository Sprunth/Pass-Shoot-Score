
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
	GLFWwindow* window;
};
