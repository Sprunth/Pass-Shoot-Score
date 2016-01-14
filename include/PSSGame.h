
#include "GUI.h"
#include "Player.h"
#include "Team.h"

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
