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

#include <AuroraFW/GEngine/GL/VertexArray.h>

namespace AuroraFW {
	namespace GEngine {
		void GLVertexArray::addBuffer(const GLBuffer& buf, const GLVertexBufferLayout& layout)
		{
			bind();
			buf.bind();
			const std::vector<GLVertexBufferElement> &elements = layout.getElements();
			uint offset = 0;
			for (uint i = 0; i < elements.size(); i++)
			{
				const GLVertexBufferElement &element = elements[i];
				GLCall(glEnableVertexAttribArray(i));
				GLCall(glVertexAttribPointer(i, element.count, element.type,
					element.normalized, layout.getStride(), (const void *)offset));
				offset += element.count * GLVertexBufferElement::sizeOf(element.type);
			}
			buf.unbind();
			unbind();
		}
	}
}