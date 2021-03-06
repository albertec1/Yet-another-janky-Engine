
#include "Window.h"
#include <vector>

class Win_Console : public Window
{
public:
	Win_Console(bool _active);
	virtual ~Win_Console();

	void Draw() override;

	void CleanUp() override;
	void ConsoleLog(const char* text);

private:

	std::vector<char*>	buffer;
	bool scrollToBottom;
};