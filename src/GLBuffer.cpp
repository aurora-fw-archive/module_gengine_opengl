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

#include <AuroraFW/GEngine/GL/Buffer.h>

namespace AuroraFW {
	namespace GEngine {
		GLBuffer::GLBuffer(GLenum type)
			: _type(type)
		{
			GLCall(glGenBuffers(1, &_buffer));
		}

		GLBuffer::GLBuffer(GLenum type, GLsizeiptr count, const void* data, GLenum usage)
			: _type(type)
		{
			GLCall(glGenBuffers(1, &_buffer));
			allocate(type, count, data, usage);
		}

		void GLBuffer::allocate(GLenum type, GLsizeiptr count, const void* data, GLenum usage)
		{
			_type = type;
			bind();
			GLCall(glBufferData(_type, count, data, usage));
		}

		GLsizeiptr GLBuffer::size() const
		{
			GLint ret = 0;
			GLCall(glGetBufferParameteriv(_type, GL_BUFFER_SIZE, &ret));
			return ret;
		}
	}
}