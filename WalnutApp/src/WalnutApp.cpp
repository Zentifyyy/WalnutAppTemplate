#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include "Walnut/UI/UI.h"

class ExampleLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Hello");
		ImGui::Button("Button");
		ImGui::End();

		ImGui::ShowDemoWindow();

		UI_DrawAboutModal();
	}

	void UI_DrawAboutModal()
	{
		if (!m_AboutModalOpen)
			return;

		ImGui::OpenPopup("About");
		m_AboutModalOpen = ImGui::BeginPopupModal("About", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
		if (m_AboutModalOpen)
		{
			auto image = Walnut::Application::Get().GetApplicationIcon();
			ImGui::Image(image->GetDescriptorSet(), { 48, 48 });

			ImGui::SameLine();
			Walnut::UI::ShiftCursorX(20.0f);

			ImGui::BeginGroup();
			ImGui::Text("Walnut application framework");
			ImGui::Text("by Studio Cherno.");
			ImGui::EndGroup();

			if (Walnut::UI::ButtonCentered("Close"))
			{
				m_AboutModalOpen = false;
				ImGui::CloseCurrentPopup();
			}

			ImGui::EndPopup();
		}
	}

	void ShowAboutModal()
	{
		m_AboutModalOpen = true;
	}
private:
	bool m_AboutModalOpen = false;
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Walnut Example";
	spec.CustomTitlebar = true;

	spec.IconPath = "img/AppIcon.png";
	
	// Now you can customise your titlebars colours from here
	spec.TitlebarButtonColour = ImColor(255, 225, 135, 100);
	spec.TitlebarButtonHoveredColour = ImColor(255, 225, 135, 60);
	spec.TitlebarButtonPressedColour = ImColor(255, 225, 135, 30);

	// You can also change the titlebar size and vertical padding
	spec.TitlebarPaddingY = 9.0f;
	spec.TitlebarHeight = 64.0f;

	// And you can disable logging to lower file clutter
	spec.UseLogging = false;

	// You can now change the size of the logo on the titlebar
	spec.LogoSize = { 48.0f, 48.0f };

	Walnut::Application* app = new Walnut::Application(spec);

	//And you can set the applications icon to a .png

	// Note: Application icon has to be in the same relitive directory
	// to the exe for distibution or the exe wont launch due to missing
	// resources

	app->SetApplicationIcon("img/AppIcon.png");

	std::shared_ptr<ExampleLayer> exampleLayer = std::make_shared<ExampleLayer>();
	app->PushLayer(exampleLayer);
	app->SetMenubarCallback([app, exampleLayer]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Help"))
		{
			if (ImGui::MenuItem("About"))
			{
				exampleLayer->ShowAboutModal();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}