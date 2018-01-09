#Coraline Plugin Development Skeleton Generator

This is a skeleton/generator used to create a basic Coraline plugin. The files included may serve as simple samples, but they are really templates used to setup new projects, thanks to the magic of cmake.


Requirements
============

 * [CMake /CPack](https://cmake.org/)
 * [Coraline plugin dev package](https://coraline.psychogenic.com/developer/plugins)
 * [Coraline](https://coraline.psychogenic.com/downloads), assuming you want to test your creation.


USAGE
=====

Setup a project, by converting the templates to a usable project with a CMakeLists.txt file etc.


Generation
==========

1) SETUP: Generate a project

From the top-level dir, here, do:

	mkdir gen; cd gen
	cmake -DPLUGIN_CLASS=SuperDuper ..
	cd .. ; ls

The 'superduper' (lowercase of your class name) directory will now hold the skeleton for a Coraline plugin project.

Optional arguments.  In addition to defining PLUGIN_CLASS, as shown above, you may also define:

 * _PLUGIN_SHORTNAME_, the name used to reference the module in JS, e.g. "BLE" or 
   "Notifications", by setting -DPLUGIN_SHORTNAME=Notifications
 * _PLUGIN_FULLNAME_, the cordova name used in config xml <plugin /> tags, e.g.
   cordova-plugin-dialogs, by setting -DPLUGIN_FULLNAME=cordova-plugin-dialogs



Build your project
==================


2) BUILD the generated project (here called 'superduper' as per instructions above):

	cd superduper
	mkdir build; cd build
	cmake ..
	make package

You will find a compiled plugin, as well as deb/rpm/zip file (assuming you have debuild/alien/tools to generate packages). Hurray.

Customize
=========

The sample code has all the boilerplate you need to get going, but it's not a very interesting plugin: it has one method, _hello_ which may be triggered from JS using your "shortname".  In this sample it would be something like
	
	var sup = new SuperDuper();
	sup.hello(function(val) { console.log("got hello back: " + val.message); });


Short version: any exposed callback must have the same signature as the hello() example, and needs to be exposed in the registerAllMethods() call, as is shown for hello.

Finally, callbacks need support on the JS side, using the standard cordova.exec calling convertions (with all arguments passed to the C++ side callback in a single array, as the final argument).  See the generated _init.js_ file for an example.


License
=======

This skeleton/plugin code generator is 

	Copyright (C) 2017,2018 Pat Deegan, https://psychogenic.com/

and release under the terms and conditions of the Apache License, v2.0.  See the included LICENSE file for details.
