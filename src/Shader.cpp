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

#include <AuroraFW/GEngine/GLShader.h>
#include <AuroraFW/STDL/STL/String.h>
#include <AuroraFW/STDL/STL/Vector.h>
#include <AuroraFW/IO/File.h>

namespace AuroraFW {
	namespace GEngine {
		GLShader::GLShader(GLShaderType type)
			: type(_type)
		{}

		GLShader::~GLShader()
		{
			glDeleteShader(_shader)
		}

		bool GLShader::compile()
		{
			std::string vert, frag;
			std::string* shaders[2] = { &vert, &frag };
			GLShader::PreProcess(source, shaders);
			GLShaderErrorInfo info;
			if (!GLShader::Compile(shaders, info))
			{
				error = info.message[info.shader];
				return false;
			}
			return true;
		}

		GLuint GLShader::load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			const char* vertSrc = IO::readFile(vertPath).c_str();
			const char* fragSrc = IO::readFile(fragPath).c_str();

			glShaderSource(vertex, 1, &vertSrc, AFW_DONTCARE);
			glShaderSource(vertex, 1, &fragSrc, AFW_DONTCARE);

			GLint ret;

			glCompileShader(vertex);
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &ret);
			if(ret == GL_FALSE)
			{
				GLint len;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &len);
				std::vector<char> err(len);
				glGetShaderInfoLog(vertex, len, &len, &err[0]);
				CLI::Log(CLI::Error, "Failed to compile vertex shader");
				CLI::Log(CLI::Error, &error[0]);
				glDeleteShader(vertex);
			}
			
			glCompileShader(fragment);
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &ret);
			if(ret == GL_FALSE)
			{
				GLint len;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &len);
				const char* log = malloc(length);
				glGetShaderInfoLog(fragment, len, &len, &err[0]);
				CLI::Log(CLI::Error, "Failed to compile fragment shader");
				CLI::Log(CLI::Error, &error[0]);
				glDeleteShader(fragment);
			}
			free(vertSrc);
			free(fragSrc);

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);
			
			glLinkProgram(program);
			glValidateProgram(program);
			
			glDeleteShader(vertex);
			glDeleteShader(fragment);
			
			return program;
		}

		void GLShader::enable() const
		{
			glUseProgram(_sID);
		}

		void GLShader::disable() const
		{
			glUseProgram(0);
		}
	}
}