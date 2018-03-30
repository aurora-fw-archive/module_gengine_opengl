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

#include <AuroraFW/GEngine/GL/Shader.h>
#include <AuroraFW/STDL/STL/String.h>
#include <AuroraFW/STDL/STL/Vector.h>
#include <AuroraFW/IO/File.h>
#include <AuroraFW/CLI/Log.h>

namespace AuroraFW {
	namespace GEngine {
		InvalidShaderException::InvalidShaderException()
			: _str("Can't load the shader.")
		{}

		const char* InvalidShaderException::what() const throw()
		{
			return _str;
		}

		void GLShader::init() {
			switch(_type)
			{
				case Vertex:
					_shader = glCreateShader(GL_VERTEX_SHADER);
					break;
				case Fragment:
					_shader = glCreateShader(GL_FRAGMENT_SHADER);
					break;
				case Geometry:
					_shader = glCreateShader(GL_GEOMETRY_SHADER);
					break;
				case TessellationControl:
					_shader = glCreateShader(GL_TESS_CONTROL_SHADER);
					break;
				case TessellationEvaluation:
					_shader = glCreateShader(GL_TESS_EVALUATION_SHADER);
					break;
				case Compute:
					_shader = glCreateShader(GL_COMPUTE_SHADER);
					break;
				case Unknown:
				default:
					throw InvalidShaderException();
					break;
			};
		}

		GLShader::GLShader(GLShader::ShaderType type)
			: _type(type)
		{
			init();
		}

		GLShader::~GLShader()
		{
			if(_type != Cached)
				GLCall(glDeleteShader(_shader));
		}

		GLint GLShader::getInfo(GLShader::Parameter param)
		{
			GLint ret;
			GLCall(glGetShaderiv(_shader, param, &ret));
			return ret;
		}

		GLShader& GLShader::compileFromSource(const char* src)
		{
			GLCall(glShaderSource(_shader, 1, &src, AFW_NULL));
			GLCall(glCompileShader(_shader));
			_compiled = getInfo(CompileStatus);
			if(_compiled == GL_FALSE)
			{
				GLint maxLength = getInfo(LogLength);
				GLchar* errorLog = static_cast<GLchar*>(malloc(maxLength));
				GLCall(glGetShaderInfoLog(_shader, maxLength, &maxLength, errorLog));
				CLI::Log(CLI::Error, errorLog);
				free(errorLog);

				GLCall(glDeleteShader(_shader));
			}
			return *this;
		}
	}
}