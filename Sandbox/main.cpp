#include <Viscos/Viscos.h>
#include <Viscos/Core/EntryPoint.h>
#include <Viscos/Graphics/VertexBuffer.h>
#include <Viscos/Graphics/IndexBuffer.h>
#include <Viscos/Graphics/ShaderProgram.h>

using namespace Viscos;

class TestLayer : public Viscos::Layer
{
public:
	TestLayer(const std::string& name) : Layer(name)
	{
		uint32_t indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		m_IndexBuffer = IndexBuffer::Create(indices, std::size(indices), Buffer::Usage::Static, IndexBuffer::Type::Uint32);
	}

	void OnAttach() override
	{
		VSCS_INFO("{} attached", GetName());
		m_ShaderProgram = ShaderProgram::Create();
		m_ShaderProgram->Attach(Shader::CreateFromFile(Shader::Stage::Vertex, "res/GLShaders/Triangle.vert"));
		m_ShaderProgram->Attach(Shader::CreateFromFile(Shader::Stage::Pixel, "res/GLShaders/Triangle.frag"));
		m_ShaderProgram->Link();
	}

	void OnDetach() override
	{
		VSCS_INFO("{} detached", GetName());
	}

	void OnEvent(Event& e) override
	{
		
	}

	void OnUpdate() override
	{
		Renderer::Clear(0.20241011f);
	}

private:
	std::unique_ptr<VertexBuffer> m_VertexBuffer;
	std::unique_ptr<IndexBuffer> m_IndexBuffer;
	std::unique_ptr<ShaderProgram> m_ShaderProgram;
};

class Sandbox : public Viscos::Application
{
public:
	Sandbox(const ApplicationSpecification& as) : Application(as)
	{
		auto testLayer = std::make_unique<TestLayer>("Gameplay");

		PushLayer(std::move(testLayer));
	}
};

Application* Viscos::CreateApplication()
{
	ApplicationSpecification as{};
	as.Name = "Viscos Engine Sandbox";

	return new Sandbox(as);
}
