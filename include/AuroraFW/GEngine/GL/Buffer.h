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

#ifndef AURORAFW_GENGINE_GL_BUFFER_H
#define AURORAFW_GENGINE_GL_BUFFER_H

#include <AuroraFW/Global.h>

#include <AuroraFW/GEngine/GL/Global.h>

#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_UNPACK_BUFFER 0x88EC

#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA

namespace AuroraFW {
	namespace GEngine {
		namespace GL {
			enum BufferType : GLenum
			{
				Array = GL_ARRAY_BUFFER,
				VertexBuffer = GL_ARRAY_BUFFER,
				ElementArray = GL_ELEMENT_ARRAY_BUFFER,
				IndexBuffer = GL_ELEMENT_ARRAY_BUFFER,
				PixelPack = GL_PIXEL_PACK_BUFFER,
				PixelUnpack = GL_PIXEL_UNPACK_BUFFER
			};

			enum BufferUsage : GLenum
			{
				StreamDraw = GL_STREAM_DRAW,
				StreamRead = GL_STREAM_READ,
				StreamCopy = GL_STREAM_COPY,
				StaticDraw = GL_STATIC_DRAW,
				StaticRead = GL_STATIC_READ,
				StaticCopy = GL_STATIC_COPY,
				DynamicDraw = GL_DYNAMIC_DRAW,
				DynamicRead = GL_DYNAMIC_READ,
				DynamicCopy = GL_DYNAMIC_COPY
			};
		}

			class AFW_EXPORT GLBuffer {
			public:
				GLBuffer(GL::BufferType );
				~GLBuffer();

				void bind() const;
				void unbind() const;

			private:
				GLuint _buffer;
				GL::BufferType _btype;
			};

			inline GLBuffer::~GLBuffer() {
				GLCall(glDeleteBuffers(1, &_buffer));
			}

			inline void GLBuffer::bind() const
			{
				GLCall(glBindBuffer(_btype, _buffer));
			}

			inline void GLBuffer::unbind() const
			{
				GLCall(glBindBuffer(_btype, 0));
			}
		}
}

#endif // AURORAFW_GENGINE_GL_BUFFER_H