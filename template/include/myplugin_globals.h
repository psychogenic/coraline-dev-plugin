/*
 * myplugin_globals.h
 *
 *  Created on: Dec 2, 2017
 *
 *        Copyright (C) 2017 Pat Deegan, https://psychogenic.com
 *
 *  This file is a supporting component of the
 *  Coraline [https://coraline.psychogenic.com/] plugin
 *  skeleton/code generator [https://github.com/psychogenic/coraline-dev-plugin]
 *
 *  It is released under the terms and conditions of the
 *  Apache License, v2.0.  See the included LICENSE file
 *  for details.
 *
 */

#ifndef INCLUDE_@PLUGIN_CLASS_ASUPPER@_GLOBALS_H_
#define INCLUDE_@PLUGIN_CLASS_ASUPPER@_GLOBALS_H_

#include <coraline/plugins/pluginDev.h>

#define @PLUGIN_CLASS_ASUPPER@_VERSION_MAJOR     0
#define @PLUGIN_CLASS_ASUPPER@_VERSION_MINOR     0
#define @PLUGIN_CLASS_ASUPPER@_VERSION_PATCH     1

//define @PLUGIN_CLASS_ASUPPER@_ENABLE_DEBUG

#ifdef @PLUGIN_CLASS_ASUPPER@_ENABLE_DEBUG
#include <iostream>
#define @PLUGIN_CLASS_ASUPPER@_DEBUG(...)		std::cerr << __VA_ARGS__
#define @PLUGIN_CLASS_ASUPPER@_DEBUGLN(...)		std::cerr << __VA_ARGS__ << std::endl;
#else
#define @PLUGIN_CLASS_ASUPPER@_DEBUG(...)
#define @PLUGIN_CLASS_ASUPPER@_DEBUGLN(...)
#endif





#endif /* INCLUDE_@PLUGIN_CLASS_ASUPPER@_GLOBALS_H_ */
