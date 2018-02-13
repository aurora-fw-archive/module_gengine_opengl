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

#include <AuroraFW/GEngine/GL/Renderer.h>

namespace AuroraFW {
	namespace GEngine {
		GLRenderer::GLRenderer()
		{}

		uint GLRenderer::getGLRendererBuffer(uint buf)
		{
			uint ret = 0;
			if (buf & RENDERER_BUFFER_COLOR)
				ret |= GL_COLOR_BUFFER_BIT;
			if (buf & RENDERER_BUFFER_DEPTH)
				ret |= GL_DEPTH_BUFFER_BIT;
			if (buf & RENDERER_BUFFER_STENCIL)
				ret |= GL_STENCIL_BUFFER_BIT;
			return ret;
		}

		void GLRenderer::clear(uint buf)
		{
			GLCall(glClear(getGLRendererBuffer(buf)));
		}

		void GLRenderer::setViewport(uint x, uint y, uint width, uint height)
		{
			GLCall(glViewport(x, y, width, height));
		}

		void GLRenderer::setDepthTesting(bool val)
		{
			if(val) {
				GLCall(glEnable(GL_DEPTH_TEST));
			}
			else {
				GLCall(glDisable(GL_DEPTH_TEST));
			}
		}

		void GLRenderer::setBlend(bool val)
		{
			if(val) {
				GLCall(glEnable(GL_BLEND));
			}
			else {
				GLCall(glDisable(GL_BLEND));
			}
		}
	}
}