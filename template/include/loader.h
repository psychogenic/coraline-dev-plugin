/*
 * loader.h
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

#ifndef INCLUDE_@PLUGIN_CLASS_ASUPPER@_LOADER_H_
#define INCLUDE_@PLUGIN_CLASS_ASUPPER@_LOADER_H_

#include "@PLUGIN_CLASS_ASLOWER@_globals.h"

#ifdef __cplusplus
extern "C" {
#endif

bool supports_driver(const Coraline::Version & v);

Coraline::Version object_version();

Coraline::Plugin::Plugin * create_object(const Coraline::Plugin::Context & ctx);

void destroy_object(Coraline::Plugin::Plugin * object );

#ifdef __cplusplus
}
#endif





#endif /* INCLUDE_LOADER_H_ */
