// FplConsoleTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "fplbase/input.h"
#include "fplbase/mesh.h"
#include "fplbase/renderer.h"
#include "fplbase/shader.h"
#include "mathfu/glsl_mappings.h"

#include "game.h"

int main()
{
	fun_with_fpl::Game game;
	game.Initialize(mathfu::vec2i(960, 640), "Simple FPLBase example");

	// A vertex shader that passes untransformed position thru.
	char* vertex_shader =
		"attribute vec4 aPosition;\n"
		"void main() { gl_Position = aPosition; }\n";

	// A fragment shader that outputs a green pixel.
	char* fragment_shader =
		"void main() { gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0); }\n";

	fplbase::Shader* shader = game.GetRenderer()->CompileAndLinkShader(vertex_shader, fragment_shader);
	assert(shader);

	while (game.Loop()) {}

	game.ShutDown();

    return 0;
}

