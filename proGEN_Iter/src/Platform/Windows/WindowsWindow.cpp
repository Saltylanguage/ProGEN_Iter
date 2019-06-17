#include "GenPCH.h"
#include "WindowsWindow.h"
#include "Squak.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#include <Glad/glad.h>

namespace Gen
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* desc)
	{
		SQUAK_CORE_ERROR("GLFW Error ({0}): {1}", error, desc);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		SQUAK_CORE_INFO("Creating Window {0} ({1} , {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO : glfwTerminate on system shutdown

			int success = glfwInit();
			GEN_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGL();
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GEN_CORE_ASSERT(status, "Failed to initialize Glad!");

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW Callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			windowData.Width = width;
			windowData.Height = height;

			WindowResizedEvent resizeEvent = WindowResizedEvent(width, height);
			windowData.EventCallback(resizeEvent);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent closeEvent = WindowCloseEvent();

			windowData.EventCallback(closeEvent);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent pressEvent(key, 0);
				windowData.EventCallback(pressEvent);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent releaseEvent(key);
				windowData.EventCallback(releaseEvent);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent releaseEvent(key, 1);
				windowData.EventCallback(releaseEvent);
				break;
			}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode) {
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			KeyTypedEvent event(keycode);
			windowData.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent mbEvent(button);
					windowData.EventCallback(mbEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent mbEvent(button);
					windowData.EventCallback(mbEvent);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent scrollEvent((float)xOffset, (float)yOffset);
			windowData.EventCallback(scrollEvent);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMoveEvent mouseMoveEvent((float)xPos, (float)yPos);
			windowData.EventCallback(mouseMoveEvent);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.VSync = enabled;
	}
}

