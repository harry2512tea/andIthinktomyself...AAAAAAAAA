#include <GL/glew.h>
#include <string>

namespace Render
{
	struct Shader
	{
		Shader(const std::string& _vertPath, const std::string& _fragPath);

		void use();
		void unUse();
		GLuint getProgID() { return m_progID; };
	private:
		GLuint m_progID;
	};
}