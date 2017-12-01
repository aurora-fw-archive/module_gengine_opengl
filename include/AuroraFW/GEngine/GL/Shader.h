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
#include <AuroraFW/GEngine/GL/Global.h>

#include <AuroraFW/GEngine/_GLEW.h>
#include <AuroraFW/GEngine/_OpenGL.h>

#include <AuroraFW/STDL/STL/String.h>

namespace AuroraFW {
	namespace GEngine {
		enum GLShaderType {
			Unknown = 0x31,
			Cached = 0x32,
			Vertex = 0x1,
			Fragment = 0x2,
			Geometry = 0x4,
			TessellationControl = 0x8,
			TessellationEvaluation = 0x10,
			Compute = 0x20
		};

		enum GLShaderParam : GLenum {
			Type = GL_SHADER_TYPE,
			DeleteStatus = GL_DELETE_STATUS,
			CompileStatus = GL_COMPILE_STATUS,
			LogLength = GL_INFO_LOG_LENGTH,
			SourceLength = GL_SHADER_SOURCE_LENGTH
		};

		class InvalidShaderException : public std::exception
		{
		private:
			const char* _str;
		public:
			InvalidShaderException();
			virtual const char* what() const throw();
		};

		class GLProgram;
		
		class AFW_EXPORT GLShader
		{
		friend GLProgram;
		public:
			GLShader(GLShaderType);
			~GLShader();

			static GLuint importCachedSourceFileShader(std::string );
			static GLuint importCachedSourceFileShader(const char* );
			static GLuint compileShaderFromSource(std::string& );
			static GLuint compileShaderFromSource(const char* );
			static GLuint compileShaderFromFile(std::string );
			static GLuint compileShaderFromFile(const char* );
			static GLint getShaderInfo(GLuint, GLShaderParam );
			GLShader& importCachedSourceFile(const char *);
			GLShader& importCachedSourceFile(std::string );
			GLShader& compileFromSource(const std::string &);
			GLShader& compileFromSource(const char *);
			GLShader& compileFromFile(const std::string );
			GLShader& compileFromFile(const char* );
			GLint getInfo(GLShaderParam );
			bool isCompiled();
			GLuint getShader();

		private:
			void init();
			GLuint _shader;
			GLShaderType _type;
			GLint _compiled = GL_FALSE;
		};
	}
}

#endif // AURORAFW_GENGINE_GL_SHADER_H