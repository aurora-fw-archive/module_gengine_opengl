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

#include <AuroraFW/GEngine/GL/VertexBuffer.h>

namespace AuroraFW {
	namespace GEngine {
		GLVertexBuffer::GLVertexBuffer(GL::BufferUsage busage)
			: _busage(busage)
		{
			GLCall(glGenBuffers(1, &_buffer));
		}

		void GLVertexBuffer::resize(uint size)
		{
			_size = size;

			bind();
			GLCall(glBufferData(GL::Array, _size, NULL, _busage));
		}

		void GLVertexBuffer::setData(uint size, const void* data)
		{
			bind();
			GLCall(glBufferData(GL::Array, size, data, _busage));
		}

		void GLVertexBuffer::bind() const {
			GLCall(glBindBuffer(GL::Array, _buffer));
		}
	}
}