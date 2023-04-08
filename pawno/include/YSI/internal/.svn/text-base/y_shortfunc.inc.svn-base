/*----------------------------------------------------------------------------*-
                              ====================
                               YSI - Master Funcs
                              ====================
Description:
	Defines new names for native functions.
Legal:
	Version: MPL 1.1
	
	The contents of this file are subject to the Mozilla Public License Version 
	1.1 (the "License"); you may not use this file except in compliance with 
	the License. You may obtain a copy of the License at 
	http://www.mozilla.org/MPL/
	
	Software distributed under the License is distributed on an "AS IS" basis,
	WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
	for the specific language governing rights and limitations under the
	License.
	
	The Original Code is the SA:MP script information include.
	
	The Initial Developer of the Original Code is Alex "Y_Less" Cole.
	Portions created by the Initial Developer are Copyright (C) 2008
	the Initial Developer. All Rights Reserved.
	
	Contributors:
		ZeeX, koolk
	
	Thanks:
		Peter, Cam - Support.
		ZeeX - Very productive conversations.
		koolk - IsPlayerinAreaEx code.
		TheAlpha - Danish translation.
		breadfish - German translation.
		Fireburn - Dutch translation.
		yom - French translation.
		50p - Polish translation.
		Zamaroht - Spanish translation.
		Dracoblue, sintax, mabako, Xtreme, other coders - Producing other modes
			for me to strive to better.
		Pixels^ - Running XScripters where the idea was born.
		Matite - Pestering me to release it and using it.
	
	Very special thanks to:
		Thiadmer - PAWN.
		Kye/Kalcor - SA:MP.
		SA:MP Team past, present and future - SA:MP.
Version:
	0.2
Changelog:
	21/10/10:
		Split in to y_shortfunc.
Functions:
	Public:
		-
	Core:
		-
	Stock:
		-
	Static:
		-
	Inline:
		-
	API:
		-
	Hooks:
		-
Callbacks:
	-
Definitions:
	-
Enums:
	-
Macros:
	-
Tags:
	-
Variables:
	Global:
		-
	Static:
		-
Commands:
	-
Compile options:
	-
Operators:
	-
Natives:
	W@ - Renaming of CallRemoteFunction for size reasons.
	V@ - Renaming of getproperty for size reasons.
	S@ - Renaming of setproperty for size reasons.
	P@ - Renaming of CallLocalFunction for size reasons.
-*----------------------------------------------------------------------------*/

native U@(id=0, const name[]="", value=cellmin, const string[]="") = setproperty;
native V@(id=0, const name[]="", value=cellmin, string[]="") = getproperty;
// Define this command with basically every strong tag in existance to avoid
// tag mismatch warnings with remote functions with strong tag parameters.
native W@(const function[], const format[], {Float, File, Bit, PlayerText3D, Text, Text3D, Menu, DB, DBResult, Style, XML, Bintree, Group, _}:...) = CallRemoteFunction;
native P@(const function[], const format[], {Float, File, Bit, PlayerText3D, Text, Text3D, Menu, DB, DBResult, Style, XML, Bintree, Group, _}:...) = CallLocalFunction;
native O@(const function[], time, repeat, const format[], {Float, File, Bit, PlayerText3D, Text, Text3D, Menu, DB, DBResult, Style, XML, Bintree, Group, _}:...) = SetTimerEx;

// Consume trailing spaces.  Despite being a common letter, this is unlkely to
// ever be matched due to the unusual series of operators after it.  If anyone
// else tries to define "x" however they may have a slight problem (they can't).
//#define x,), x),
// Changed as x,): was also needed (for ?:).
#define x,) x)

// This is for getting excess parameters on non-strings.
#define _:%0,) %0)
