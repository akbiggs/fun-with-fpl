#ifndef _FUN_WITH_FPL_GAME_H_
#define _FUN_WITH_FPL_GAME_H_

#include "stdafx.h"

#include "mathfu/glsl_mappings.h"
#include "fplbase/renderer.h"
#include "fplbase/input.h"

#include "camera.h"

namespace fun_with_fpl
{
	class Game
	{
	public:
		Game();
		~Game();

		void Initialize(mathfu::vec2i window_size, const char* title) const;
		void ShutDown() const;

		bool Loop() const;

		fplbase::Renderer* GetRenderer() const;
		fplbase::InputSystem* GetInputSystem() const;

	private:
		std::unique_ptr<fplbase::Renderer> renderer_;
		std::unique_ptr<fplbase::InputSystem> input_system_;
		Camera camera_;
	};
}

#endif
