#ifndef _FUN_WITH_FPL_CAMERA_H_
#define _FUN_WITH_FPL_CAMERA_H_

#include "fplbase/renderer.h"
#include "mathfu/glsl_mappings.h"

namespace fun_with_fpl
{
	class Camera
	{
	public:
		Camera(const mathfu::mat4& model_view_projection, const mathfu::vec4& bg_color);
		~Camera();

		void Apply(fplbase::Renderer& renderer) const;
	private:
		mathfu::mat4 model_view_projection_;
		mathfu::vec4 bg_color_;
	};
}

#endif