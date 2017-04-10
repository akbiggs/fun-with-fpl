#include "stdafx.h"
#include "game.h"

namespace
{
	const mathfu::vec4 kColorCornflowerBlue =
		mathfu::vec4(0.392f, 0.584f, 0.930f, 1.0f);
	const mathfu::mat4 kCameraProjection2d =
		mathfu::mat4::Ortho(-1.0f, 1.0f, -1.5f, 1.5f, -1.0f, 1.0f);
}

namespace fun_with_fpl
{
	Game::Game()
		: renderer_(new fplbase::Renderer()),
		  input_system_(new fplbase::InputSystem()),
	      camera_(kCameraProjection2d, kColorCornflowerBlue)
	{
	}

	Game::~Game()
	{
	}

	void Game::Initialize(const mathfu::vec2i window_size, const char* title) const
	{
		renderer_->Initialize(window_size, title);
		input_system_->Initialize();
	}

	void Game::ShutDown() const
	{
		renderer_->ShutDown();
	}

	bool Game::Loop() const
	{
		if (input_system_->exit_requested())
		{
			return false;
		}

		renderer_->AdvanceFrame(input_system_->minimized(), input_system_->Time());
		input_system_->AdvanceFrame(&renderer_->window_size());
		camera_.Apply(*renderer_);

		return true;
	}

	fplbase::Renderer* Game::GetRenderer() const
	{
		return renderer_.get();
	}

	fplbase::InputSystem* Game::GetInputSystem() const
	{
		return input_system_.get();
	}
}
