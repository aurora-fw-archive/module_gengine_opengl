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

#include <AuroraFW/GEngine/_GLEW.h>
#include <AuroraFW/GEngine/_OpenGL.h>
#include <AuroraFW/GEngine/GL/Shader.h>

#include <AuroraFW/Math/Vector2D.h>
#include <AuroraFW/Math/Vector3D.h>
#include <AuroraFW/Math/Vector4D.h>
#include <AuroraFW/Math/Matrix4x4.h>

namespace AuroraFW {
	namespace GEngine {
		class DuplicatedShaderException : public std::exception
		{
		private:
			const std::string _str;
		public:
			DuplicatedShaderException(const char *);
			virtual const char* what() const throw();
		};

		class AFW_EXPORT GLProgram {
		public:
			GLProgram(const char* );
			GLProgram(std::string );
			GLProgram(const char *, GLShader *, size_t );
			GLProgram(std::string, GLShader *, size_t );
			GLProgram(const char *, GLuint *, size_t );
			GLProgram(std::string , GLuint *, size_t );
			~GLProgram();

			bool addShader(GLShader* );
			bool addShader(GLuint );
			bool removeShader(GLShader *);
			bool removeShader(GLuint );

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
			inline void enable() const;
			inline void disable() const;
			inline void glValidate() const;

			void setUniform1f(const std::string &, float );
			void setUniform2f(const std::string &, const Math::Vector2D& );
			void setUniform3f(const std::string &, const Math::Vector3D& );
			void setUniform4f(const std::string &, const Math::Vector4D& );
			void setUniform1fv(const std::string &, float *, size_t );
			void setUniform2fv(const std::string &, const Math::Vector2D**, size_t );
			void setUniform3fv(const std::string &, const Math::Vector3D**, size_t );
			void setUniform4fv(const std::string &, const Math::Vector4D**, size_t );
			void setUniform1i(const std::string &, int );
			void setUniform1iv(const std::string &, int *, size_t );
			void setUniformMat4(const std::string &, const Math::Matrix4x4 &);
			GLint getUniformLocation(const std::string &);
			GLint getUniformLocation(const char* );

		private:
			GLint _generated = GL_FALSE;
			GLuint _program;
			std::string _name;
			GLShaderType _type;
		};

		inline void GLProgram::enable() const {GLCall(glUseProgram(_program));}
		inline void GLProgram::disable() const {GLCall(glUseProgram(0));}

		inline bool GLProgram::addShader(GLShader* shader)
		{
			glAttachShader(_program, shader->_shader);
		}

		inline void GLProgram::setUniform1f(const std::string &name, float val)
		{
			GLCall(glUniform1f(getUniformLocation(name), val));
		}
		inline void GLProgram::setUniform2f(const std::string &name, const Math::Vector2D& vec)
		{
			GLCall(glUniform2f(getUniformLocation(name), vec.x, vec.y));
		}
		inline void GLProgram::setUniform3f(const std::string &name, const Math::Vector3D& vec)
		{
			GLCall(glUniform3f(getUniformLocation(name), vec.x, vec.y, vec.z));
		}
		inline void GLProgram::setUniform4f(const std::string &name, const Math::Vector4D& vec)
		{
			GLCall(glUniform4f(getUniformLocation(name), vec.x, vec.y, vec.z, vec.w));
		}

		inline void GLProgram::setUniform1i(const std::string &name, int val)
		{
			GLCall(glUniform1i(getUniformLocation(name),val));
		}

		inline void GLProgram::setUniformMat4(const std::string &name, const Math::Matrix4x4& matrix)
		{
			GLCall(glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, (const float*)matrix.m));
		}

		inline GLint GLProgram::getUniformLocation(const std::string &name)
		{
			GLCall(GLint ret = glGetUniformLocation(_program, name.c_str()));
			return ret;
		}

		inline GLint GLProgram::getUniformLocation(const char* name)
		{
			GLCall(GLint ret = glGetUniformLocation(_program, name));
			return ret;
		}

		void setUniform3f(const std::string &, Math::Vector3D& );
		void setUniform4f(const std::string &, Math::Vector4D& );
	}
}

#endif // AURORAFW_GENGINE_GL_PROGRAM_H