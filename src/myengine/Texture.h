#pragma once
#include "Component.h"
#include <memory>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

namespace myengine
{
	class Texture : public Component
	{
		GLuint id;
		glm::vec2 size;
		
	
	public:
		Texture(std::string path);
		glm::vec2 getSize();
		GLuint getId();

	};
}