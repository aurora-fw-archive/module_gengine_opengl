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

#ifndef AURORAFW_GENGINE_GL_VERTEXARRAY_H
#define AURORAFW_GENGINE_GL_VERTEXARRAY_H

#include <AuroraFW/Global.h>

#include <AuroraFW/GEngine/GL/Global.h>

#include <AuroraFW/GEngine/GL/Buffer.h>
#include <AuroraFW/STDL/STL/Vector.h>

namespace AuroraFW {
	namespace GEngine {
		//class AFW_EXPORT GLBuffer;
		class AFW_EXPORT GLVertexArray {
		public:
			GLVertexArray() { GLCall(glGenVertexArrays(1, &_vao)); }
			~GLVertexArray() { GLCall(glDeleteVertexArrays(1, &_vao)); }

			void push(GLBuffer* );
			void add(GLBuffer* , GLint , GLuint );
			void add(GLint , GLuint );

			inline void bind() const { GLCall(glBindVertexArray(_vao)); }
			inline void unbind() const { GLCall(glBindVertexArray(0)); }

		private:
			GLuint _vao;
			std::vector<GLBuffer*> _buffers;
		};

		inline void GLVertexArray::push(GLBuffer* buffer)
		{
			_buffers.push_back(buffer);
		}
	}
}

#endif // AURORAFW_GENGINE_GL_VERTEXARRAY_H