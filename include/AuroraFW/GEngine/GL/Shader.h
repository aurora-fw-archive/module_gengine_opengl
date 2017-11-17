/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU Lesser General Public License version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE included in
** the packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************/

#ifndef AURORAFW_GENGINE_GL_SHADER_H
#define AURORAFW_GENGINE_GL_SHADER_H

#include <AuroraFW/Global.h>

#include <AuroraFW/GEngine/Shader.h>
#include <AuroraFW/GEngine/_GLEW.h>
#include <AuroraFW/GEngine/_OpenGL.h>

namespace AuroraFW {
	namespace GEngine {
		enum GLShaderType {
			Unknown = 0,
			Vertex = 0x1,
			Fragment = 0x2,
			Geometry = 0x4,
			TessellationControl = 0x8,
			TessellationEvaluation = 0x10,
			Compute = 0x20
		};

		class AFW_EXPORT GLShader : public Shader {
		public:
			GLShader(GLShaderType );
			~GLShader();

			bool compileFromSource(const char* );
			bool compileFromSource(const std::string& );
			bool compileFromFile(const char* );
			bool compileFromFile(const std::string );

			GLuint getShader();

		private:
			GLuint _shader;
			GLShaderType _type;
		};
	}
}

#endif // AURORAFW_GENGINE_GL_SHADER_H