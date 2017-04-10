#include "stdafx.h"
#include "camera.h"

#include "mathfu/matrix.h"

namespace fun_with_fpl
{
	Camera::Camera(const mathfu::mat4& model_view_projection,
		           const mathfu::vec4& bg_color)
		: model_view_projection_(model_view_projection),
	      bg_color_(bg_color)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Apply(fplbase::Renderer& renderer) const
	{
		renderer.ClearFrameBuffer(bg_color_);
		renderer.set_model_view_projection(model_view_projection_);
	}
}
