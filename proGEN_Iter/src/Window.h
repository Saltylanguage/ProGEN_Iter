#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Gen
{
	using EventCallbackFn = std::function<void(Event&)>;

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "ProGEN_Iter Engine",
					unsigned int width = 1200,
					unsigned int height = 720) : Title(title), Width(width), Height(height) {}
	};

	class GEN_API Window
	{
	public:

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		// Where are window props defined?
		static Window* Create(const WindowProps& props = WindowProps());
	};
}
