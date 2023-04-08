/*----------------------------------------------------------------------------*-
					====================================
					 y_testing - Run unit tests easilly 
					====================================
Description:
	Runs any functions named as tests when the Testing_Run function is called.
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
		Integrated in to YSI.
	06/08/10:
		First version
-*----------------------------------------------------------------------------*/

#include <YSI\internal\y_version>

#include <YSI\y_scripting>
#include <YSI\y_debug>

#if !defined RUN_TESTS
	#if _DEBUG > 0 || defined _YSI_SPECIAL_DEBUG
		#define RUN_TESTS
		#if defined _YSI_SPECIAL_DEBUG
			#define TP printf
			#define TC(%0); %0
		#else
			#define TP P:1
			#define TC C:1
		#endif
	#else
		#define Tests:%1() stock bool:Tests_@%1()
		#define Test:%1() stock bool:Test_@%1()
		#define TestInit:%1() stock Init_@%1()
		#define TestClose:%1() stock Shut_@%1()
	#endif
#endif

#define TEST_TRUE(%0)  Testing_Test(bool:(%0))
#define TEST_FALSE(%0) Testing_Test(!(%0))
#define TEST_NULL(%0)  Testing_Test((%0) == 0)
#define TEST_N(%0,%1)  Testing_Test((%0) == (%1))

#define TEST_TRUE_EX(%0,%2)  Testing_Test(bool:(%0), (%2))
#define TEST_FALSE_EX(%0,%2) Testing_Test(!(%0), (%2))
#define TEST_NULL_EX(%0,%2)  Testing_Test((%0) == 0, (%2))
#define TEST_N_EX(%0,%1,%2)  Testing_Test((%0) == (%1), (%2))

static stock
	YSI_g_sTests,
	YSI_g_sFails;

stock Testing_Test(bool:x, const str[] = "")
{
	++YSI_g_sTests;
	if (!x)
	{
		++YSI_g_sFails;
		TP("*** Test failed: %s", str);
	}
	TC(else printf("*** Test passed: %s", str););
}

/*----------------------------------------------------------------------------*-
Function:
	Testing_Run
Params:
	&tests - Number of tests run.
	&fails - Number of tests which failed.
	buffer[33] - The name of the first test which failed.
Return:
	Wether all tests were sucessful or not.
Notes:
	-

native Testing_Run(&tests, &fails, buffer[33] = "");

-*----------------------------------------------------------------------------*/

stock bool:Testing_Run(&tests, &fails, lastfail[33] = "", bool:p = false)
{
	#pragma unused p
	#if defined RUN_TESTS
		P:3("Testsing_Run() called");
		new
			idx,
			buffer[32];
		while ((idx = Scripting_GetPublic(idx, buffer, "Test_@")))
		{
			++YSI_g_sTests;
			// Call the setup function if there is one.
			buffer[0] = 'I';
			buffer[1] = 'n';
			buffer[2] = 'i';
			buffer[3] = 't';
			CallLocalFunction(buffer, "");
			// Call the test.
			buffer[0] = 'T';
			buffer[1] = 'e';
			buffer[2] = 's';
			buffer[3] = 't';
			TP("Testsing_Run(): Calling %s", buffer[6]);
			if (!CallLocalFunction(buffer, ""))
			{
				if (YSI_g_sFails)
				{
					++YSI_g_sFails;
				}
				else
				{
					fails = 0;
					// Copy the string over.
					while ((lastfail[fails] = buffer[fails + 6])) ++fails;
					YSI_g_sFails = 1;
				}
				TC(if (p) printf("*** Test failed: %s", buffer[fails + 6]););
			}
			// Call the shutdown function if there is one.
			buffer[0] = 'S';
			buffer[1] = 'h';
			buffer[2] = 'u';
			buffer[3] = 't';
			CallLocalFunction(buffer, "");
		}
		while ((idx = Scripting_GetPublic(idx, buffer, "Tezt_@")))
		{
			//++YSI_g_sTests;
			// Call the setup function if there is one.
			buffer[0] = 'I';
			buffer[1] = 'n';
			buffer[2] = 'i';
			buffer[3] = 't';
			CallLocalFunction(buffer, "");
			// Call the test.
			buffer[0] = 'T';
			buffer[1] = 'e';
			buffer[2] = 'z';
			buffer[3] = 't';
			fails = YSI_g_sFails;
			TP("Testsing_Run(): Calling %s", buffer[6]);
			CallLocalFunction(buffer, "");
			/*if (YSI_g_sFails != fails)
			{
				if (YSI_g_sFails)
				{
					++YSI_g_sFails;
				}
				else
				{
					fails = 0;
					// Copy the string over.
					while ((lastfail[fails] = buffer[fails + 6])) ++fails;
					YSI_g_sFails = 1;
				}
				//C:1(if (p) printf("*** Test failed: %s", buffer[fails + 6]););
			}*/
			// Call the shutdown function if there is one.
			buffer[0] = 'S';
			buffer[1] = 'h';
			buffer[2] = 'u';
			buffer[3] = 't';
			CallLocalFunction(buffer, "");
		}
		tests = YSI_g_sTests;
		fails = YSI_g_sFails;
		return fails == 0;
	#else
		#pragma unused tests, fails, lastfail
		return true;
	#endif
}

#if defined RUN_TESTS
	#define Tests:%1() forward bool:Tezt_@%1(); public bool:Tezt_@%1()
	#define Test:%1() forward bool:Test_@%1(); public bool:Test_@%1()
	#define TestInit:%1() forward Init_@%1(); public Init_@%1()
	#define TestClose:%1() forward Shut_@%1(); public Shut_@%1()
	#if _DEBUG > 0 || defined _YSI_SPECIAL_DEBUG
		#if !defined FILTERSCRIPT
			// Hook main in gamemodes.
			main()
			{
				new
					tests,
					fails;
				Testing_Run(tests, fails, _, true);
				printf("*** Tests: %d, Fails: %d", tests, fails);
				Testing_main();
			}
			
			#define main Testing_main
		#endif
	#endif
#endif
