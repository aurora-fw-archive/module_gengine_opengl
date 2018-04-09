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

#include <AuroraFW/GEngine/GL/Texture.h>
#include <AuroraFW/Image/STB/Image.h>

namespace AuroraFW::GEngine::API {
	GLTexture::GLTexture(const std::string& path)
		: _id(AFW_NULLVAL)
	{
		_path = path;
		_width = AFW_NULLVAL;
		_height = AFW_NULLVAL;
		_bpp = AFW_NULLVAL;
		_rawbuf = AFW_NULLPTR;

		stbi_set_flip_vertically_on_load(1);
		_rawbuf = stbi_load(_path.c_str(), &_width, &_height, &_bpp, 4);

		GLCall(glGenTextures(1, &_id));
		GLCall(glBindTexture(GL_TEXTURE_2D, _id));

		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _rawbuf));
		unbind();

		if(_rawbuf)
			stbi_image_free(_rawbuf);
	}

	GLTexture::~GLTexture()
	{
		GLCall(glDeleteTextures(1, &_id));
	}

	void GLTexture::bind(uint slot) const
	{
		GLCall(glActiveTexture(GL_TEXTURE0 + slot));
		GLCall(glBindTexture(GL_TEXTURE_2D, _id));
	}

	void GLTexture::unbind(uint slot) const
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	}
}