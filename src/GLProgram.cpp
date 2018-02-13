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

#include <AuroraFW/GEngine/GL/Program.h>
#include <AuroraFW/CLI/Log.h>

namespace AuroraFW {
	namespace GEngine {
		GLProgram::GLProgram()
			: _program(glCreateProgram())
		{}

		GLuint GLProgram::generate()
		{
			GLCall(glLinkProgram(_program));
			GLint isLinked = 0;
			GLCall(glGetProgramiv(_program, GL_LINK_STATUS, (int *)&isLinked));
			if(isLinked == GL_FALSE)
			{
				GLint maxLength = 0;
				GLCall(glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &maxLength));

				//The maxLength includes the NULL character
				GLchar* errorLog = static_cast<GLchar*>(malloc(maxLength));
				GLCall(glGetProgramInfoLog(_program, maxLength, &maxLength, errorLog));
				CLI::Log(CLI::Error, errorLog);
				free(errorLog);

				GLCall(glDeleteProgram(_program));

				//Use the infoLog as you see fit.
			}
			GLCall(glValidateProgram(_program));

			return _program;
		}

		void GLProgram::enable() const
		{
			GLCall(glUseProgram(_program));
		}

		void GLProgram::disable() const
		{
			GLCall(glUseProgram(0));
		}

		void GLProgram::addShader(GLShader* shader)
		{
			GLCall(glAttachShader(_program, shader->_shader));
		}

		void GLProgram::setValue(const std::string &name, float val)
		{
			GLCall(glUniform1f(getUniformLocation(name), val));
		}

		void GLProgram::setValue(const std::string &name, const Math::Vector2D& vec)
		{
			GLCall(glUniform2f(getUniformLocation(name), vec.x, vec.y));
		}

		void GLProgram::setValue(const std::string &name, const Math::Vector3D& vec)
		{
			GLCall(glUniform3f(getUniformLocation(name), vec.x, vec.y, vec.z));
		}

		void GLProgram::setValue(const std::string &name, const Math::Vector4D& vec)
		{
			GLCall(glUniform4f(getUniformLocation(name), vec.x, vec.y, vec.z, vec.w));
		}

		void GLProgram::setValue(const std::string &name, int val)
		{
			GLCall(glUniform1i(getUniformLocation(name),val));
		}

		void GLProgram::setValue(const std::string &name, const Math::Matrix4x4& matrix)
		{
			GLCall(glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, (const float*)matrix.m));
		}

		GLint GLProgram::getUniformLocation(const std::string &name)
		{
			GLCall(GLint ret = glGetUniformLocation(_program, name.c_str()));
			return ret;
		}

		GLint GLProgram::getUniformLocation(const char* name)
		{
			GLCall(GLint ret = glGetUniformLocation(_program, name));
			return ret;
		}
	}
}