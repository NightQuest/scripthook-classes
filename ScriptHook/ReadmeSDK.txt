GTAIV Script Hook 0.3.0 SDK
(C) 2009, Aru <oneforaru at gmail dot com>

== What ==

This code will let you create a custom script thread in C++ and have GTAIV process it
along with its real scripts threads. Additionally, a type-safe manner to access native
functions in GTAIV is provided.

A sample implementation having the following features is included:

  F4 - Teleport to the waypoint marked on your map (in SampleCustomFiber only)
  F5 - Spawn a random car
  F6 - Give player $1000 
  F7 - Spawn a Banshee
  F8 - Change player skin to Johnny
  F9 - Change player skin to random variation of Niko

Another sample called Speedo is included to demonstrate usage of the extensible services
framework ScriptHook 0.3.0+ provides. Press ALT+F10 to bring up a menu in this sample. 

For development, you can choose to use your own ASI loader or use the one provided in 
the DevLoader directory. DevLoader implements a menu interface to loading/unloading
modules to ease development. To use it, copy d3d9.dll and DevLoader.config to your GTAIV 
directory and edit DevLoader.config with a text editor.

== How ==

1. Edit CustomThread.h/.cpp as per your liking
2. Compile
3. Use a dll/asi loader to get the dll loaded into GTAIV.

If you need to use any natives that are not in Scripting.h, find them in 
ScriptingDirty.h, clean it up, and move it to Scripting.h in your project
before using it.

The SampleCustom project presents a sample with a tick-based approach to scripting GTAIV, 
where as the SampleCustomFiber project presents a sample with a linear script based approach 
(new in version 0.2.0 of the Script Hook). It's recommended that you use the SampleCustomFiber 
as a starting point unless you are converting legacy 0.1.x Script Hook code.

== Why ==

Why not... :)

== License ==

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

In addition to this license, usage of this software requires that you comply with the 
following for either development and/or use of any compiled products:

  By the use of this software, you agree not to modify, alter or otherwise circumvent 
  any restrictions programmed into this software for online game play.
