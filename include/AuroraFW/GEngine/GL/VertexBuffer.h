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

#ifndef AURORAFW_GENGINE_GL_VERTEXBUFFER_H
#define AURORAFW_GENGINE_GL_VERTEXBUFFER_H

#include <AuroraFW/Global.h>

#include <AuroraFW/GEngine/GL/Global.h>

namespace AuroraFW {
	namespace GEngine {
		class AFW_EXPORT GLVertexBuffer {
		public:
			GLVertexBuffer(GL::BufferUsage );
			~GLVertexBuffer();

			void resize(uint );
			void setData(uint, const void *);

			void release() const;
			void bind() const;
			void unbind() const;

			uint getSize() const;

		private:
			GLuint _buffer;
			uint _size;
			GL::BufferUsage _busage;
		};

		inline GLVertexBuffer::~GLVertexBuffer()
		{
			GLCall(glDeleteBuffers(1, &_buffer));
		}

		inline void GLVertexBuffer::release() const
		{
			GLCall(glUnmapBuffer(GL::Array));
		}

		inline void GLVertexBuffer::unbind() const
		{
			GLCall(glBindBuffer(GL::Array, 0));
		}

		inline uint GLVertexBuffer::getSize() const
		{
			return _size;
		}
	}
}

#endif // AURORAFW_GENGINE_GL_VERTEXBUFFER_H