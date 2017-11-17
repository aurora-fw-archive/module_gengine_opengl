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

#ifndef AURORAFW_GENGINE_GL_SHADERPROGRAM_H
#define AURORAFW_GENGINE_GL_SHADERPROGRAM_H

#include <AuroraFW/Global.h>

namespace AuroraFW {
	namespace GEngine {
		class DuplicatedShaderTypeException : public std::exception
		{
		private:
			const std::string _path;
		public:
			DuplicatedShaderTypeException(const char *);
			virtual const char* what() const throw();
		};

		class AFW_EXPORT GLShaderProgram {
		public:
			GLShaderProgram();
			~GLShaderProgram();
			bool addShader(GLShader &);
			bool addShaderFromSource(const char *);
			bool addShaderFromSource(const std::string &);
			bool addShaderFromFile(const char *);
			bool addShaderFromFile(const std::string &);
			
			void link();
			void bind();
		};
	}
}

#endif // AURORAFW_GENGINE_GL_SHADERPROGRAM_H