#include <Viscos/Viscos.h>
#include <Viscos/Core/EntryPoint.h>
#include <Viscos/Graphics/VertexInput.h>
#include <Viscos/Graphics/VertexBuffer.h>
#include <Viscos/Graphics/IndexBuffer.h>
#include <Viscos/Graphics/ShaderProgram.h>

using namespace Viscos;

static float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f,
};
static uint16_t indices[] = { 0, 1, 2 };

class TestLayer : public Viscos::Layer
{
public:
	TestLayer(const std::string& name) : Layer(name)
	{
	}

	void OnAttach() override
	{
		VSCS_INFO("{} attached", GetName());
		m_ShaderProgram = ShaderProgram::Create();
		m_ShaderProgram->Attach(Shader::CreateFromFile(Shader::Stage::Vertex, "res/GLShaders/Triangle.vert"));
		m_ShaderProgram->Attach(Shader::CreateFromFile(Shader::Stage::Pixel, "res/GLShaders/Triangle.frag"));
		m_ShaderProgram->Link();
		VSCS_INFO("Shaders loaded.");

		m_VertexBuffer = VertexBuffer::Create(vertices, sizeof(vertices), Buffer::Usage::Static);
		VSCS_INFO("Vertex buffer created.");

		m_VertexBufferLayout = std::make_unique<VertexBufferLayout>(3 * sizeof(float), std::initializer_list<VertexAttribute>{
			{ VertexAttribute::Type::Float32, 3, 0, false }
		});
		VSCS_INFO("Vertex buffer layout created.");

		m_VertexInput = VertexInput::Create();
		m_VertexInput->AddVertexBuffer(*m_VertexBuffer, *m_VertexBufferLayout);
		m_VertexInput->SetIndexBuffer(IndexBuffer::Create(indices, sizeof(indices), Buffer::Usage::Static, IndexBuffer::Type::Uint16));

		VSCS_INFO("Vertex input created.");
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

		m_ShaderProgram->Bind();
		m_VertexInput->Bind();

		Renderer::DrawIndexed(*m_VertexInput);
	}

private:
	std::unique_ptr<VertexInput> m_VertexInput;
	std::unique_ptr<VertexBufferLayout> m_VertexBufferLayout;
	std::unique_ptr<VertexBuffer> m_VertexBuffer;
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
