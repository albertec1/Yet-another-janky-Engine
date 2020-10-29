
#include "Win_Configuration.h"
#include "ImGui.h"
#include "ModuleWindow.h"
#include "Color.h"

// ---------------------------------------------------------
Win_Configuration::Win_Configuration(int _max_fps) : Window("Configuration"),
fps_log(100), ms_log(100)
{}

Win_Configuration::~Win_Configuration()
{}

void Win_Configuration::CleanUp()
{
}

void Win_Configuration::AddInput(const char* entry)
{
}

void Win_Configuration::AddFPS(float fps, float ms)
{
}

void Win_Configuration::Draw()
{
	//ImGui::Begin("Configuration", &active, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing);
	if (!active)
		return;

	if (ImGui::Begin("Configuration", &active))
	{
		if (ImGui::CollapsingHeader("Application"))
		{
			if (ImGui::SliderInt("Max FPS", &max_fps, 0, 120))
			{
				changeFPSlimit = true;
			}
			
			ImGui::Text("Limit Framerate:");
			ImGui::SameLine();
			ImGui::TextColored(YELLOW, "%i", max_fps);

			char title[25];
			sprintf_s(title, 25, "Framerate %.1f", fps_log[fps_log.size() - 1]);
			ImGui::PlotHistogram("##framerate", &fps_log[0], fps_log.size(), 0, title, 0.0f, 100.0f, ImVec2(310, 100));
			sprintf_s(title, 25, "Milliseconds %0.1f", ms_log[ms_log.size() - 1]);
			ImGui::PlotHistogram("##milliseconds", &ms_log[0], ms_log.size(), 0, title, 0.0f, 40.0f, ImVec2(310, 100));
		}
		ImGui::End();
	}
}