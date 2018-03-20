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

#ifndef AURORAFW_GENGINE_GL_PROGRAM_H
#define AURORAFW_GENGINE_GL_PROGRAM_H

#include <AuroraFW/Global.h>
#if(AFW_TARGET_PRAGMA_ONCE_SUPPORT)
	#pragma once
#endif

#include <AuroraFW/Internal/Config.h>

#include <AuroraFW/GEngine/GL/Global.h>
#include <AuroraFW/GEngine/GL/Shader.h>

#include <AuroraFW/Math/Vector2D.h>
#include <AuroraFW/Math/Vector3D.h>
#include <AuroraFW/Math/Vector4D.h>
#include <AuroraFW/Math/Matrix.h>

namespace AuroraFW {
	namespace GEngine {
		class AFW_API DuplicatedShaderException : public std::exception
		{
		private:
			const std::string _str;
		public:
			DuplicatedShaderException(const char *);
			virtual const char* what() const throw();
		};

		class AFW_API GLProgram {
		public:
			GLProgram();
			GLProgram(GLShader *, size_t );
			GLProgram(GLuint *, size_t );
			~GLProgram();

			void addShader(GLShader* );
			void addShader(GLuint );
			void removeShader(GLShader *);
			void removeShader(GLuint );

			bool addShaderFromSource(GLShaderType , const char *);
			bool addShaderFromSource(GLShaderType , const std::string &);
			bool addShaderFromFile(GLShaderType , const char *);
			bool addShaderFromFile(GLShaderType , const std::string &);
			bool addCachedSourceFile(const char *);
			bool addCachedSourceFile(std::string );

			bool isGenerated();
			GLuint generate();
			GLuint getProgram();
			static void enableProgram(GLProgram* );
			static void enableProgram(GLuint& );
			static void disableProgram(GLProgram* );
			static void disableProgram(GLuint& );
			void enable() const;
			void disable() const;
			void glValidate() const;

			void setValue(const std::string &, float );
			void setValue(const std::string &, const Math::Vector2D& );
			void setValue(const std::string &, const Math::Vector3D& );
			void setValue(const std::string &, const Math::Vector4D& );
			void setValue(const std::string &, float *, size_t );
			void setValue(const std::string &, const Math::Vector2D**, size_t );
			void setValue(const std::string &, const Math::Vector3D**, size_t );
			void setValue(const std::string &, const Math::Vector4D**, size_t );
			void setValue(const std::string &, int );
			void setValue(const std::string &, int *, size_t );
			void setValue(const std::string &, const Math::Matrix4x4 &);
			GLint getUniformLocation(const std::string &);
			GLint getUniformLocation(const char* );

		private:
			GLint _generated = GL_FALSE;
			GLuint _program;
			GLShaderType _type;
		};

		void setValue(const std::string &, Math::Vector3D& );
		void setValue(const std::string &, Math::Vector4D& );
	}
}

#endif // AURORAFW_GENGINE_GL_PROGRAM_H
