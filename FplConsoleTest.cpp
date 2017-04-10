// FplConsoleTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "fplbase/input.h"
#include "fplbase/mesh.h"
#include "fplbase/renderer.h"
#include "fplbase/shader.h"
#include "mathfu/glsl_mappings.h"

int main()
{
	fplbase::Renderer renderer;
	renderer.Initialize(mathfu::vec2i(960, 640), "Simple FPLBase example");

	fplbase::InputSystem input;
	input.Initialize();

	// A vertex shader that passes untransformed position thru.
	char* vertex_shader =
		"attribute vec4 aPosition;\n"
		"void main() { gl_Position = aPosition; }\n";

	// A fragment shader that outputs a green pixel.
	char* fragment_shader =
		"void main() { gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0); }\n";

	fplbase::Shader* shader = renderer.CompileAndLinkShader(vertex_shader, fragment_shader);
	assert(shader);

	while (!input.exit_requested()) {
		renderer.AdvanceFrame(input.minimized(), input.Time());
		input.AdvanceFrame(&renderer.window_size());

		float color = (1.0f - std::cos(input.Time())) / 2.0f;
		renderer.ClearFrameBuffer(mathfu::vec4(color, 0.0f, color, 1.0f));

		renderer.set_model_view_projection(mathfu::mat4::Ortho(-1.0, 1.0, -1.5, 1.5, -1.0, 1.0));

		shader->Set(renderer);

		fplbase::Mesh::RenderAAQuadAlongX(
			mathfu::vec3(-0.5f, -0.5f, 0),
			mathfu::vec3(0.5f, 0.5f, 0));
	}

	renderer.ShutDown();

    return 0;
}

