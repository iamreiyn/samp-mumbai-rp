/*----------------------------------------------------------------------------*-
					========================================
					 y_stringhash - Fast string comparisons 
					========================================
Description:
	Allows you to hash strings at compile time to use them in a switch.
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
	1.0
Changelog:
	25/10/10:
		Updated comments.
		Added to YSI 1.0.
		Added FNV1 and FNV1a hashes to avoid collisions.
	19/08/10:
		First version.
Functions:
	stock:
		YHash - Generate a string hash at run time.
Definitions:
	_H - Generate a string hash at compile time.
	_I - Generate a case insensitive string hash at compile time.
-*----------------------------------------------------------------------------*/

#include <YSI\internal\y_version>

// ================
//  Case sensitive
// ================

// These are the default values
#define HASH(%0,%1) HASH@%0(%1)

#define _H(%0) HASH(bernstein,%0)

#define _H@b HASH@bernstein
#define _H@f HASH@fnv1
#define _H@a HASH@fnv1a

// ================
//  Bernstein hash
// ================

// Signify the end with two "@" symbols.
#define HASH@bernstein(%0) _REHASH@b(%0,@,@)

// Internal call.
#define _REHASH@b(%0,%1) _HASH@b_%0(%1)

// The bit that actually does the work.
#define _DOHASH@b(%0,%1,%2) (_HASH@b_%1(%2)*33+%0)

// Space.
#define _HASH@b_(%0) _DOHASH@b(32,%0)

// Numbers.
#define _HASH@b_0(%0) _DOHASH@b(48,%0)
#define _HASH@b_1(%0) _DOHASH@b(49,%0)
#define _HASH@b_2(%0) _DOHASH@b(50,%0)
#define _HASH@b_3(%0) _DOHASH@b(51,%0)
#define _HASH@b_4(%0) _DOHASH@b(52,%0)
#define _HASH@b_5(%0) _DOHASH@b(53,%0)
#define _HASH@b_6(%0) _DOHASH@b(54,%0)
#define _HASH@b_7(%0) _DOHASH@b(55,%0)
#define _HASH@b_8(%0) _DOHASH@b(56,%0)
#define _HASH@b_9(%0) _DOHASH@b(57,%0)

// Upper case letters.
#define _HASH@b_A(%0) _DOHASH@b(65,%0)
#define _HASH@b_B(%0) _DOHASH@b(66,%0)
#define _HASH@b_C(%0) _DOHASH@b(67,%0)
#define _HASH@b_D(%0) _DOHASH@b(68,%0)
#define _HASH@b_E(%0) _DOHASH@b(69,%0)
#define _HASH@b_F(%0) _DOHASH@b(70,%0)
#define _HASH@b_G(%0) _DOHASH@b(71,%0)
#define _HASH@b_H(%0) _DOHASH@b(72,%0)
#define _HASH@b_I(%0) _DOHASH@b(73,%0)
#define _HASH@b_J(%0) _DOHASH@b(74,%0)
#define _HASH@b_K(%0) _DOHASH@b(75,%0)
#define _HASH@b_L(%0) _DOHASH@b(76,%0)
#define _HASH@b_M(%0) _DOHASH@b(77,%0)
#define _HASH@b_N(%0) _DOHASH@b(78,%0)
#define _HASH@b_O(%0) _DOHASH@b(79,%0)
#define _HASH@b_P(%0) _DOHASH@b(80,%0)
#define _HASH@b_Q(%0) _DOHASH@b(81,%0)
#define _HASH@b_R(%0) _DOHASH@b(82,%0)
#define _HASH@b_S(%0) _DOHASH@b(83,%0)
#define _HASH@b_T(%0) _DOHASH@b(84,%0)
#define _HASH@b_U(%0) _DOHASH@b(85,%0)
#define _HASH@b_V(%0) _DOHASH@b(86,%0)
#define _HASH@b_W(%0) _DOHASH@b(87,%0)
#define _HASH@b_X(%0) _DOHASH@b(88,%0)
#define _HASH@b_Y(%0) _DOHASH@b(89,%0)
#define _HASH@b_Z(%0) _DOHASH@b(90,%0)

// Underscore.
#define _HASH@b__(%0) _DOHASH@b(95,%0)

// Lower case letters.
#define _HASH@b_a(%0) _DOHASH@b(97,%0)
#define _HASH@b_b(%0) _DOHASH@b(98,%0)
#define _HASH@b_c(%0) _DOHASH@b(99,%0)
#define _HASH@b_d(%0) _DOHASH@b(100,%0)
#define _HASH@b_e(%0) _DOHASH@b(101,%0)
#define _HASH@b_f(%0) _DOHASH@b(102,%0)
#define _HASH@b_g(%0) _DOHASH@b(103,%0)
#define _HASH@b_h(%0) _DOHASH@b(104,%0)
#define _HASH@b_i(%0) _DOHASH@b(105,%0)
#define _HASH@b_j(%0) _DOHASH@b(106,%0)
#define _HASH@b_k(%0) _DOHASH@b(107,%0)
#define _HASH@b_l(%0) _DOHASH@b(108,%0)
#define _HASH@b_m(%0) _DOHASH@b(109,%0)
#define _HASH@b_n(%0) _DOHASH@b(110,%0)
#define _HASH@b_o(%0) _DOHASH@b(111,%0)
#define _HASH@b_p(%0) _DOHASH@b(112,%0)
#define _HASH@b_q(%0) _DOHASH@b(113,%0)
#define _HASH@b_r(%0) _DOHASH@b(114,%0)
#define _HASH@b_s(%0) _DOHASH@b(115,%0)
#define _HASH@b_t(%0) _DOHASH@b(116,%0)
#define _HASH@b_u(%0) _DOHASH@b(117,%0)
#define _HASH@b_v(%0) _DOHASH@b(118,%0)
#define _HASH@b_w(%0) _DOHASH@b(119,%0)
#define _HASH@b_x(%0) _DOHASH@b(120,%0)
#define _HASH@b_y(%0) _DOHASH@b(121,%0)
#define _HASH@b_z(%0) _DOHASH@b(122,%0)

// String end.
#define _HASH@b_@(%0) -1

// ===========
//  FNV1 hash
// ===========

// Signify the end with two "@" symbols.
#define HASH@fnv1(%0) _REHASH@f(%0,@,@)

// Internal call.
#define _REHASH@f(%0,%1) _HASH@f_%0(%1)

// The bit that actually does the work.
#define _DOHASH@f(%0,%1,%2) (_HASH@f_%1(%2)*16777619^%0)

// Space.
#define _HASH@f_(%0) _DOHASH@f(32,%0)

// Numbers.
#define _HASH@f_0(%0) _DOHASH@f(48,%0)
#define _HASH@f_1(%0) _DOHASH@f(49,%0)
#define _HASH@f_2(%0) _DOHASH@f(50,%0)
#define _HASH@f_3(%0) _DOHASH@f(51,%0)
#define _HASH@f_4(%0) _DOHASH@f(52,%0)
#define _HASH@f_5(%0) _DOHASH@f(53,%0)
#define _HASH@f_6(%0) _DOHASH@f(54,%0)
#define _HASH@f_7(%0) _DOHASH@f(55,%0)
#define _HASH@f_8(%0) _DOHASH@f(56,%0)
#define _HASH@f_9(%0) _DOHASH@f(57,%0)

// Upper case letters.
#define _HASH@f_A(%0) _DOHASH@f(65,%0)
#define _HASH@f_B(%0) _DOHASH@f(66,%0)
#define _HASH@f_C(%0) _DOHASH@f(67,%0)
#define _HASH@f_D(%0) _DOHASH@f(68,%0)
#define _HASH@f_E(%0) _DOHASH@f(69,%0)
#define _HASH@f_F(%0) _DOHASH@f(70,%0)
#define _HASH@f_G(%0) _DOHASH@f(71,%0)
#define _HASH@f_H(%0) _DOHASH@f(72,%0)
#define _HASH@f_I(%0) _DOHASH@f(73,%0)
#define _HASH@f_J(%0) _DOHASH@f(74,%0)
#define _HASH@f_K(%0) _DOHASH@f(75,%0)
#define _HASH@f_L(%0) _DOHASH@f(76,%0)
#define _HASH@f_M(%0) _DOHASH@f(77,%0)
#define _HASH@f_N(%0) _DOHASH@f(78,%0)
#define _HASH@f_O(%0) _DOHASH@f(79,%0)
#define _HASH@f_P(%0) _DOHASH@f(80,%0)
#define _HASH@f_Q(%0) _DOHASH@f(81,%0)
#define _HASH@f_R(%0) _DOHASH@f(82,%0)
#define _HASH@f_S(%0) _DOHASH@f(83,%0)
#define _HASH@f_T(%0) _DOHASH@f(84,%0)
#define _HASH@f_U(%0) _DOHASH@f(85,%0)
#define _HASH@f_V(%0) _DOHASH@f(86,%0)
#define _HASH@f_W(%0) _DOHASH@f(87,%0)
#define _HASH@f_X(%0) _DOHASH@f(88,%0)
#define _HASH@f_Y(%0) _DOHASH@f(89,%0)
#define _HASH@f_Z(%0) _DOHASH@f(90,%0)

// Underscore.
#define _HASH@f__(%0) _DOHASH@f(95,%0)

// Lower case letters.
#define _HASH@f_a(%0) _DOHASH@f(97,%0)
#define _HASH@f_b(%0) _DOHASH@f(98,%0)
#define _HASH@f_c(%0) _DOHASH@f(99,%0)
#define _HASH@f_d(%0) _DOHASH@f(100,%0)
#define _HASH@f_e(%0) _DOHASH@f(101,%0)
#define _HASH@f_f(%0) _DOHASH@f(102,%0)
#define _HASH@f_g(%0) _DOHASH@f(103,%0)
#define _HASH@f_h(%0) _DOHASH@f(104,%0)
#define _HASH@f_i(%0) _DOHASH@f(105,%0)
#define _HASH@f_j(%0) _DOHASH@f(106,%0)
#define _HASH@f_k(%0) _DOHASH@f(107,%0)
#define _HASH@f_l(%0) _DOHASH@f(108,%0)
#define _HASH@f_m(%0) _DOHASH@f(109,%0)
#define _HASH@f_n(%0) _DOHASH@f(110,%0)
#define _HASH@f_o(%0) _DOHASH@f(111,%0)
#define _HASH@f_p(%0) _DOHASH@f(112,%0)
#define _HASH@f_q(%0) _DOHASH@f(113,%0)
#define _HASH@f_r(%0) _DOHASH@f(114,%0)
#define _HASH@f_s(%0) _DOHASH@f(115,%0)
#define _HASH@f_t(%0) _DOHASH@f(116,%0)
#define _HASH@f_u(%0) _DOHASH@f(117,%0)
#define _HASH@f_v(%0) _DOHASH@f(118,%0)
#define _HASH@f_w(%0) _DOHASH@f(119,%0)
#define _HASH@f_x(%0) _DOHASH@f(120,%0)
#define _HASH@f_y(%0) _DOHASH@f(121,%0)
#define _HASH@f_z(%0) _DOHASH@f(122,%0)

// String end.
#define _HASH@f_@(%0) 2166136261

// ============
//  FNV1a hash
// ============

// Signify the end with two "@" symbols.
#define HASH@fnv1a(%0) _REHASH@a(%0,@,@)

// Internal call.
#define _REHASH@a(%0,%1) _HASH@a_%0(%1)

// The bit that actually does the work.
#define _DOHASH@a(%0,%1,%2) ((_HASH@a_%1(%2)^%0)*16777619)

// Space.
#define _HASH@a_(%0) _DOHASH@a(32,%0)

// Numbers.
#define _HASH@a_0(%0) _DOHASH@a(48,%0)
#define _HASH@a_1(%0) _DOHASH@a(49,%0)
#define _HASH@a_2(%0) _DOHASH@a(50,%0)
#define _HASH@a_3(%0) _DOHASH@a(51,%0)
#define _HASH@a_4(%0) _DOHASH@a(52,%0)
#define _HASH@a_5(%0) _DOHASH@a(53,%0)
#define _HASH@a_6(%0) _DOHASH@a(54,%0)
#define _HASH@a_7(%0) _DOHASH@a(55,%0)
#define _HASH@a_8(%0) _DOHASH@a(56,%0)
#define _HASH@a_9(%0) _DOHASH@a(57,%0)

// Upper case letters.
#define _HASH@a_A(%0) _DOHASH@a(65,%0)
#define _HASH@a_B(%0) _DOHASH@a(66,%0)
#define _HASH@a_C(%0) _DOHASH@a(67,%0)
#define _HASH@a_D(%0) _DOHASH@a(68,%0)
#define _HASH@a_E(%0) _DOHASH@a(69,%0)
#define _HASH@a_F(%0) _DOHASH@a(70,%0)
#define _HASH@a_G(%0) _DOHASH@a(71,%0)
#define _HASH@a_H(%0) _DOHASH@a(72,%0)
#define _HASH@a_I(%0) _DOHASH@a(73,%0)
#define _HASH@a_J(%0) _DOHASH@a(74,%0)
#define _HASH@a_K(%0) _DOHASH@a(75,%0)
#define _HASH@a_L(%0) _DOHASH@a(76,%0)
#define _HASH@a_M(%0) _DOHASH@a(77,%0)
#define _HASH@a_N(%0) _DOHASH@a(78,%0)
#define _HASH@a_O(%0) _DOHASH@a(79,%0)
#define _HASH@a_P(%0) _DOHASH@a(80,%0)
#define _HASH@a_Q(%0) _DOHASH@a(81,%0)
#define _HASH@a_R(%0) _DOHASH@a(82,%0)
#define _HASH@a_S(%0) _DOHASH@a(83,%0)
#define _HASH@a_T(%0) _DOHASH@a(84,%0)
#define _HASH@a_U(%0) _DOHASH@a(85,%0)
#define _HASH@a_V(%0) _DOHASH@a(86,%0)
#define _HASH@a_W(%0) _DOHASH@a(87,%0)
#define _HASH@a_X(%0) _DOHASH@a(88,%0)
#define _HASH@a_Y(%0) _DOHASH@a(89,%0)
#define _HASH@a_Z(%0) _DOHASH@a(90,%0)

// Underscore.
#define _HASH@a__(%0) _DOHASH@a(95,%0)

// Lower case letters.
#define _HASH@a_a(%0) _DOHASH@a(97,%0)
#define _HASH@a_b(%0) _DOHASH@a(98,%0)
#define _HASH@a_c(%0) _DOHASH@a(99,%0)
#define _HASH@a_d(%0) _DOHASH@a(100,%0)
#define _HASH@a_e(%0) _DOHASH@a(101,%0)
#define _HASH@a_f(%0) _DOHASH@a(102,%0)
#define _HASH@a_g(%0) _DOHASH@a(103,%0)
#define _HASH@a_h(%0) _DOHASH@a(104,%0)
#define _HASH@a_i(%0) _DOHASH@a(105,%0)
#define _HASH@a_j(%0) _DOHASH@a(106,%0)
#define _HASH@a_k(%0) _DOHASH@a(107,%0)
#define _HASH@a_l(%0) _DOHASH@a(108,%0)
#define _HASH@a_m(%0) _DOHASH@a(109,%0)
#define _HASH@a_n(%0) _DOHASH@a(110,%0)
#define _HASH@a_o(%0) _DOHASH@a(111,%0)
#define _HASH@a_p(%0) _DOHASH@a(112,%0)
#define _HASH@a_q(%0) _DOHASH@a(113,%0)
#define _HASH@a_r(%0) _DOHASH@a(114,%0)
#define _HASH@a_s(%0) _DOHASH@a(115,%0)
#define _HASH@a_t(%0) _DOHASH@a(116,%0)
#define _HASH@a_u(%0) _DOHASH@a(117,%0)
#define _HASH@a_v(%0) _DOHASH@a(118,%0)
#define _HASH@a_w(%0) _DOHASH@a(119,%0)
#define _HASH@a_x(%0) _DOHASH@a(120,%0)
#define _HASH@a_y(%0) _DOHASH@a(121,%0)
#define _HASH@a_z(%0) _DOHASH@a(122,%0)

// String end.
#define _HASH@a_@(%0) 2166136261

// ==================
//  Case insensitive
// ==================

// These are the default values
#define HASHi(%0,%1) HASHi@%0(%1)

//#define _I(%0) _REHASib(%0,@,@)
#define _I(%0) HASHi(bernstein,%0)

#define _I@b HASHi@bernstein
#define _I@f HASHi@fnv1
#define _I@a HASHi@fnv1a

// ================
//  Bernstein hash
// ================

// Signify the end with two "@" symbols.
#define HASHi@bernstein(%0) _REHASH@ib(%0,@,@)

// Internal call.
#define _REHASH@ib(%0,%1) _HASH@ib_%0(%1)

// The bit that actually does the work.
#define _DOHASH@ib(%0,%1,%2) (_HASH@ib_%1(%2)*33+%0)

// Space.
#define _HASH@ib_(%0) _DOHASH@ib(32,%0)

// Numbers.
#define _HASH@ib_0(%0) _DOHASH@ib(48,%0)
#define _HASH@ib_1(%0) _DOHASH@ib(49,%0)
#define _HASH@ib_2(%0) _DOHASH@ib(50,%0)
#define _HASH@ib_3(%0) _DOHASH@ib(51,%0)
#define _HASH@ib_4(%0) _DOHASH@ib(52,%0)
#define _HASH@ib_5(%0) _DOHASH@ib(53,%0)
#define _HASH@ib_6(%0) _DOHASH@ib(54,%0)
#define _HASH@ib_7(%0) _DOHASH@ib(55,%0)
#define _HASH@ib_8(%0) _DOHASH@ib(56,%0)
#define _HASH@ib_9(%0) _DOHASH@ib(57,%0)

// Upper case letters.
#define _HASH@ib_A(%0) _DOHASH@ib(65,%0)
#define _HASH@ib_B(%0) _DOHASH@ib(66,%0)
#define _HASH@ib_C(%0) _DOHASH@ib(67,%0)
#define _HASH@ib_D(%0) _DOHASH@ib(68,%0)
#define _HASH@ib_E(%0) _DOHASH@ib(69,%0)
#define _HASH@ib_F(%0) _DOHASH@ib(70,%0)
#define _HASH@ib_G(%0) _DOHASH@ib(71,%0)
#define _HASH@ib_H(%0) _DOHASH@ib(72,%0)
#define _HASH@ib_I(%0) _DOHASH@ib(73,%0)
#define _HASH@ib_J(%0) _DOHASH@ib(74,%0)
#define _HASH@ib_K(%0) _DOHASH@ib(75,%0)
#define _HASH@ib_L(%0) _DOHASH@ib(76,%0)
#define _HASH@ib_M(%0) _DOHASH@ib(77,%0)
#define _HASH@ib_N(%0) _DOHASH@ib(78,%0)
#define _HASH@ib_O(%0) _DOHASH@ib(79,%0)
#define _HASH@ib_P(%0) _DOHASH@ib(80,%0)
#define _HASH@ib_Q(%0) _DOHASH@ib(81,%0)
#define _HASH@ib_R(%0) _DOHASH@ib(82,%0)
#define _HASH@ib_S(%0) _DOHASH@ib(83,%0)
#define _HASH@ib_T(%0) _DOHASH@ib(84,%0)
#define _HASH@ib_U(%0) _DOHASH@ib(85,%0)
#define _HASH@ib_V(%0) _DOHASH@ib(86,%0)
#define _HASH@ib_W(%0) _DOHASH@ib(87,%0)
#define _HASH@ib_X(%0) _DOHASH@ib(88,%0)
#define _HASH@ib_Y(%0) _DOHASH@ib(89,%0)
#define _HASH@ib_Z(%0) _DOHASH@ib(90,%0)

// Underscore.
#define _HASH@ib__(%0) _DOHASH@ib(95,%0)

// Lower case letters.
#define _HASH@ib_a(%0) _DOHASH@ib(65,%0)
#define _HASH@ib_b(%0) _DOHASH@ib(66,%0)
#define _HASH@ib_c(%0) _DOHASH@ib(67,%0)
#define _HASH@ib_d(%0) _DOHASH@ib(68,%0)
#define _HASH@ib_e(%0) _DOHASH@ib(69,%0)
#define _HASH@ib_f(%0) _DOHASH@ib(70,%0)
#define _HASH@ib_g(%0) _DOHASH@ib(71,%0)
#define _HASH@ib_h(%0) _DOHASH@ib(72,%0)
#define _HASH@ib_i(%0) _DOHASH@ib(73,%0)
#define _HASH@ib_j(%0) _DOHASH@ib(74,%0)
#define _HASH@ib_k(%0) _DOHASH@ib(75,%0)
#define _HASH@ib_l(%0) _DOHASH@ib(76,%0)
#define _HASH@ib_m(%0) _DOHASH@ib(77,%0)
#define _HASH@ib_n(%0) _DOHASH@ib(78,%0)
#define _HASH@ib_o(%0) _DOHASH@ib(79,%0)
#define _HASH@ib_p(%0) _DOHASH@ib(80,%0)
#define _HASH@ib_q(%0) _DOHASH@ib(81,%0)
#define _HASH@ib_r(%0) _DOHASH@ib(82,%0)
#define _HASH@ib_s(%0) _DOHASH@ib(83,%0)
#define _HASH@ib_t(%0) _DOHASH@ib(84,%0)
#define _HASH@ib_u(%0) _DOHASH@ib(85,%0)
#define _HASH@ib_v(%0) _DOHASH@ib(86,%0)
#define _HASH@ib_w(%0) _DOHASH@ib(87,%0)
#define _HASH@ib_x(%0) _DOHASH@ib(88,%0)
#define _HASH@ib_y(%0) _DOHASH@ib(89,%0)
#define _HASH@ib_z(%0) _DOHASH@ib(90,%0)

// String end.
#define _HASH@ib_@(%0) -1

// ===========
//  FNV1 hash
// ===========

// Signify the end with two "@" symbols.
#define HASHi@fnv1(%0) _REHASH@if(%0,@,@)

// Internal call.
#define _REHASH@if(%0,%1) _HASH@if_%0(%1)

// The bit that actually does the work.
#define _DOHASH@if(%0,%1,%2) (_HASH@if_%1(%2)*16777619^%0)

// Space.
#define _HASH@if_(%0) _DOHASH@if(32,%0)

// Numbers.
#define _HASH@if_0(%0) _DOHASH@if(48,%0)
#define _HASH@if_1(%0) _DOHASH@if(49,%0)
#define _HASH@if_2(%0) _DOHASH@if(50,%0)
#define _HASH@if_3(%0) _DOHASH@if(51,%0)
#define _HASH@if_4(%0) _DOHASH@if(52,%0)
#define _HASH@if_5(%0) _DOHASH@if(53,%0)
#define _HASH@if_6(%0) _DOHASH@if(54,%0)
#define _HASH@if_7(%0) _DOHASH@if(55,%0)
#define _HASH@if_8(%0) _DOHASH@if(56,%0)
#define _HASH@if_9(%0) _DOHASH@if(57,%0)

// Upper case letters.
#define _HASH@if_A(%0) _DOHASH@if(65,%0)
#define _HASH@if_B(%0) _DOHASH@if(66,%0)
#define _HASH@if_C(%0) _DOHASH@if(67,%0)
#define _HASH@if_D(%0) _DOHASH@if(68,%0)
#define _HASH@if_E(%0) _DOHASH@if(69,%0)
#define _HASH@if_F(%0) _DOHASH@if(70,%0)
#define _HASH@if_G(%0) _DOHASH@if(71,%0)
#define _HASH@if_H(%0) _DOHASH@if(72,%0)
#define _HASH@if_I(%0) _DOHASH@if(73,%0)
#define _HASH@if_J(%0) _DOHASH@if(74,%0)
#define _HASH@if_K(%0) _DOHASH@if(75,%0)
#define _HASH@if_L(%0) _DOHASH@if(76,%0)
#define _HASH@if_M(%0) _DOHASH@if(77,%0)
#define _HASH@if_N(%0) _DOHASH@if(78,%0)
#define _HASH@if_O(%0) _DOHASH@if(79,%0)
#define _HASH@if_P(%0) _DOHASH@if(80,%0)
#define _HASH@if_Q(%0) _DOHASH@if(81,%0)
#define _HASH@if_R(%0) _DOHASH@if(82,%0)
#define _HASH@if_S(%0) _DOHASH@if(83,%0)
#define _HASH@if_T(%0) _DOHASH@if(84,%0)
#define _HASH@if_U(%0) _DOHASH@if(85,%0)
#define _HASH@if_V(%0) _DOHASH@if(86,%0)
#define _HASH@if_W(%0) _DOHASH@if(87,%0)
#define _HASH@if_X(%0) _DOHASH@if(88,%0)
#define _HASH@if_Y(%0) _DOHASH@if(89,%0)
#define _HASH@if_Z(%0) _DOHASH@if(90,%0)

// Underscore.
#define _HASH@if__(%0) _DOHASH@if(95,%0)

// Lower case letters.
#define _HASH@if_a(%0) _DOHASH@if(65,%0)
#define _HASH@if_b(%0) _DOHASH@if(66,%0)
#define _HASH@if_c(%0) _DOHASH@if(67,%0)
#define _HASH@if_d(%0) _DOHASH@if(68,%0)
#define _HASH@if_e(%0) _DOHASH@if(69,%0)
#define _HASH@if_f(%0) _DOHASH@if(70,%0)
#define _HASH@if_g(%0) _DOHASH@if(71,%0)
#define _HASH@if_h(%0) _DOHASH@if(72,%0)
#define _HASH@if_i(%0) _DOHASH@if(73,%0)
#define _HASH@if_j(%0) _DOHASH@if(74,%0)
#define _HASH@if_k(%0) _DOHASH@if(75,%0)
#define _HASH@if_l(%0) _DOHASH@if(76,%0)
#define _HASH@if_m(%0) _DOHASH@if(77,%0)
#define _HASH@if_n(%0) _DOHASH@if(78,%0)
#define _HASH@if_o(%0) _DOHASH@if(79,%0)
#define _HASH@if_p(%0) _DOHASH@if(80,%0)
#define _HASH@if_q(%0) _DOHASH@if(81,%0)
#define _HASH@if_r(%0) _DOHASH@if(82,%0)
#define _HASH@if_s(%0) _DOHASH@if(83,%0)
#define _HASH@if_t(%0) _DOHASH@if(84,%0)
#define _HASH@if_u(%0) _DOHASH@if(85,%0)
#define _HASH@if_v(%0) _DOHASH@if(86,%0)
#define _HASH@if_w(%0) _DOHASH@if(87,%0)
#define _HASH@if_x(%0) _DOHASH@if(88,%0)
#define _HASH@if_y(%0) _DOHASH@if(89,%0)
#define _HASH@if_z(%0) _DOHASH@if(90,%0)

// String end.
#define _HASH@if_@(%0) 2166136261

// ============
//  FNV1a hash
// ============

// Signify the end with two "@" symbols.
#define HASHi@fnv1a(%0) _REHASH@ia(%0,@,@)

// Internal call.
#define _REHASH@ia(%0,%1) _HASH@ia_%0(%1)

// The bit that actually does the work.
#define _DOHASH@ia(%0,%1,%2) ((_HASH@ia_%1(%2)^%0)*16777619)

// Space.
#define _HASH@ia_(%0) _DOHASH@ia(32,%0)

// Numbers.
#define _HASH@ia_0(%0) _DOHASH@ia(48,%0)
#define _HASH@ia_1(%0) _DOHASH@ia(49,%0)
#define _HASH@ia_2(%0) _DOHASH@ia(50,%0)
#define _HASH@ia_3(%0) _DOHASH@ia(51,%0)
#define _HASH@ia_4(%0) _DOHASH@ia(52,%0)
#define _HASH@ia_5(%0) _DOHASH@ia(53,%0)
#define _HASH@ia_6(%0) _DOHASH@ia(54,%0)
#define _HASH@ia_7(%0) _DOHASH@ia(55,%0)
#define _HASH@ia_8(%0) _DOHASH@ia(56,%0)
#define _HASH@ia_9(%0) _DOHASH@ia(57,%0)

// Upper case letters.
#define _HASH@ia_A(%0) _DOHASH@ia(65,%0)
#define _HASH@ia_B(%0) _DOHASH@ia(66,%0)
#define _HASH@ia_C(%0) _DOHASH@ia(67,%0)
#define _HASH@ia_D(%0) _DOHASH@ia(68,%0)
#define _HASH@ia_E(%0) _DOHASH@ia(69,%0)
#define _HASH@ia_F(%0) _DOHASH@ia(70,%0)
#define _HASH@ia_G(%0) _DOHASH@ia(71,%0)
#define _HASH@ia_H(%0) _DOHASH@ia(72,%0)
#define _HASH@ia_I(%0) _DOHASH@ia(73,%0)
#define _HASH@ia_J(%0) _DOHASH@ia(74,%0)
#define _HASH@ia_K(%0) _DOHASH@ia(75,%0)
#define _HASH@ia_L(%0) _DOHASH@ia(76,%0)
#define _HASH@ia_M(%0) _DOHASH@ia(77,%0)
#define _HASH@ia_N(%0) _DOHASH@ia(78,%0)
#define _HASH@ia_O(%0) _DOHASH@ia(79,%0)
#define _HASH@ia_P(%0) _DOHASH@ia(80,%0)
#define _HASH@ia_Q(%0) _DOHASH@ia(81,%0)
#define _HASH@ia_R(%0) _DOHASH@ia(82,%0)
#define _HASH@ia_S(%0) _DOHASH@ia(83,%0)
#define _HASH@ia_T(%0) _DOHASH@ia(84,%0)
#define _HASH@ia_U(%0) _DOHASH@ia(85,%0)
#define _HASH@ia_V(%0) _DOHASH@ia(86,%0)
#define _HASH@ia_W(%0) _DOHASH@ia(87,%0)
#define _HASH@ia_X(%0) _DOHASH@ia(88,%0)
#define _HASH@ia_Y(%0) _DOHASH@ia(89,%0)
#define _HASH@ia_Z(%0) _DOHASH@ia(90,%0)

// Underscore.
#define _HASH@ia__(%0) _DOHASH@ia(95,%0)

// Lower case letters.
#define _HASH@ia_a(%0) _DOHASH@ia(65,%0)
#define _HASH@ia_b(%0) _DOHASH@ia(66,%0)
#define _HASH@ia_c(%0) _DOHASH@ia(67,%0)
#define _HASH@ia_d(%0) _DOHASH@ia(68,%0)
#define _HASH@ia_e(%0) _DOHASH@ia(69,%0)
#define _HASH@ia_f(%0) _DOHASH@ia(70,%0)
#define _HASH@ia_g(%0) _DOHASH@ia(71,%0)
#define _HASH@ia_h(%0) _DOHASH@ia(72,%0)
#define _HASH@ia_i(%0) _DOHASH@ia(73,%0)
#define _HASH@ia_j(%0) _DOHASH@ia(74,%0)
#define _HASH@ia_k(%0) _DOHASH@ia(75,%0)
#define _HASH@ia_l(%0) _DOHASH@ia(76,%0)
#define _HASH@ia_m(%0) _DOHASH@ia(77,%0)
#define _HASH@ia_n(%0) _DOHASH@ia(78,%0)
#define _HASH@ia_o(%0) _DOHASH@ia(79,%0)
#define _HASH@ia_p(%0) _DOHASH@ia(80,%0)
#define _HASH@ia_q(%0) _DOHASH@ia(81,%0)
#define _HASH@ia_r(%0) _DOHASH@ia(82,%0)
#define _HASH@ia_s(%0) _DOHASH@ia(83,%0)
#define _HASH@ia_t(%0) _DOHASH@ia(84,%0)
#define _HASH@ia_u(%0) _DOHASH@ia(85,%0)
#define _HASH@ia_v(%0) _DOHASH@ia(86,%0)
#define _HASH@ia_w(%0) _DOHASH@ia(87,%0)
#define _HASH@ia_x(%0) _DOHASH@ia(88,%0)
#define _HASH@ia_y(%0) _DOHASH@ia(89,%0)
#define _HASH@ia_z(%0) _DOHASH@ia(90,%0)

// String end.
#define _HASH@ia_@(%0) 2166136261

enum e_HASH_TYPE
{
	hash_bernstein,
	hash_fnv1,
	hash_fnv1a
}

/*----------------------------------------------------------------------------*-
Function:
	Hash
Params:
	str - The string to hash.
	sensitive - Wether the hash is case sensitive or not.
Return:
	The reverse Bernstein hash of the string.
Notes:
	Based on Bernstein hash, but backwards to match the macros.  The only
	characters which can be used in the compile time version of this code are:
	a-z, A-Z, 0-9, _ and space.

native Hash(str[]);

-*----------------------------------------------------------------------------*/

stock YHash(const str[], bool:sensitive = true, e_HASH_TYPE:type = hash_bernstein, len = -1)
{
	if (len == -1)
	{
		len = strlen(str);
	}
	switch (type)
	{
		case hash_bernstein:
		{
			new
				hash = -1;
			if (sensitive)
			{
				while (len--)
				{
					hash = hash * 33 + str[len];
				}
			}
			else
			{
				while (len--)
				{
					new
						ch = str[len];
					if (ch >= 'a' && ch <= 'z')
					{
						ch &= ~0x20;
					}
					hash = hash * 33 + ch;
				}
			}
			return hash;
		}
		case hash_fnv1:
		{
			new
				hash = 2166136261;
			if (sensitive)
			{
				while (len--)
				{
					hash = hash * 16777619 ^ str[len];
				}
			}
			else
			{
				while (len--)
				{
					new
						ch = str[len];
					if (ch >= 'a' && ch <= 'z')
					{
						ch &= ~0x20;
					}
					hash = hash * 16777619 ^ ch;
				}
			}
			return hash;
		}
		case hash_fnv1a:
		{
			new
				hash = 2166136261;
			if (sensitive)
			{
				while (len--)
				{
					hash = (hash ^ str[len]) * 16777619;
				}
			}
			else
			{
				while (len--)
				{
					new
						ch = str[len];
					if (ch >= 'a' && ch <= 'z')
					{
						ch &= ~0x20;
					}
					hash = (hash ^ ch) * 16777619;
				}
			}
			return hash;
		}
	}
	return -1;
}
