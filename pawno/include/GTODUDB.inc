
/*
//  DUDB GTO 1.2.01 Mod
*/

/*
 *            DUDB 1.2
 *       (c) Copyright 2006 by DracoBlue
 *
 * @author    : DracoBlue (http://dracoblue.com)
 * @date      : 8th May 2006
 * @update    : 31st July 2006
 * @require   : DUtils 1.3
 *
 * This file is provided as is (no warranties).
 *
 * Feel free to use it, a little message in 
 * about box is honouring thing, isn't it?
 *
 */

/*
//
//  Modification information:
//
//                          Author: 	Roach
//                          Date:       14.08.06
//
//                          Notes:      
//
//										I needed file/db saving, modding DracoBlue's
//                                      DUDB to do what I want is just quicker and already tested.
//                                      Thanks go to DracoBlue.
//
//
//
*/

#if defined _gtodudb_included
  #endinput
#endif

#define _gtodudb_included
#pragma library dutils

#include <dutils>

#define MAX_DBSTRING 255 // sending a single string to write whole db is a prolly bad way to do it, but i dont know how else i can send as many values as i need without hardcoding. feel free to advise me :/

public udb_hash(buf[]) {
	new length=strlen(buf);
    new s1 = 1;
    new s2 = 0;
    new n;
    for (n=0; n<length; n++)
    {
       s1 = (s1 + buf[n]) % 65521;
       s2 = (s2 + s1)     % 65521;
    }
    return (s2 << 16) + s1;
}

public udb_encode(nickname[])
{
  new tmp[MAX_STRING];
  set(tmp,nickname);


  tmp=strreplace("_"," 00",tmp);
  tmp=strreplace(";"," 01",tmp);
  tmp=strreplace("!"," 02",tmp);
  tmp=strreplace("/"," 03",tmp);
  tmp=strreplace("\\"," 04",tmp);
  tmp=strreplace("["," 05",tmp);
  tmp=strreplace("]"," 06",tmp);
  tmp=strreplace("?"," 07",tmp);
  //tmp=strreplace("."," 08",tmp);
  tmp=strreplace("*"," 09",tmp);
  tmp=strreplace("<"," 10",tmp);
  tmp=strreplace(">"," 11",tmp);
  tmp=strreplace("{"," 12",tmp);
  tmp=strreplace("}"," 13",tmp);
  tmp=strreplace("|","14",tmp);

  return tmp;
}

public udb_decode(nickname[]) {
  new tmp[MAX_STRING];
  set(tmp,nickname);


  tmp=strreplace(" 01",";",tmp);
  tmp=strreplace(" 02","!",tmp);
  tmp=strreplace(" 03","/",tmp);
  tmp=strreplace(" 04","\\",tmp);
  tmp=strreplace(" 05","[",tmp);
  tmp=strreplace(" 06","]",tmp);
  tmp=strreplace(" 07","?",tmp);
  tmp=strreplace(" 08",".",tmp);
  tmp=strreplace(" 09","*",tmp);
  tmp=strreplace(" 10","<",tmp);
  tmp=strreplace(" 11",">",tmp);
  tmp=strreplace(" 12","{",tmp);
  tmp=strreplace(" 13","}",tmp);
  tmp=strreplace(" 14","|",tmp);
  tmp=strreplace(" 00","_",tmp);

  return tmp;
}

public udb_Exists(filename[]) {
  new tmp[MAX_STRING];
  new tmp2[MAX_STRING];
  set(tmp2,udb_encode(filename));
  set(tmp,tmp2);
  strcat(tmp,".GTO.DB.1.sav");
  if (fexist(tmp)) return true;
  set(tmp,tmp2);
  strcat(tmp,".GTO.DB.2.sav");
  if (fexist(tmp)) return true;
  set(tmp,tmp2);
  strcat(tmp,".GTO.DB.3.sav");
  if (fexist(tmp)) return true;
  return false;
}


public udb_Remove(filename[]) {
  new tmp[MAX_STRING];
  new tmp2[MAX_STRING];
  if (!udb_Exists(filename)) return false;
  set(tmp2,udb_encode(filename));
  set(tmp,tmp2);
  strcat(tmp,".GTO.DB.1.sav");
  fremove(tmp);
  set(tmp,tmp2);
  strcat(tmp,".GTO.DB.2.sav");
  fremove(tmp);
  set(tmp,tmp2);
  strcat(tmp,".GTO.DB.3.sav");
  fremove(tmp);
  return true;
}

public udp_PRIVATE_clearbroken(filename[]) {
  new tmp2[MAX_STRING];
  new tmp_a[MAX_STRING];
  new tmp_b[MAX_STRING];
  set(tmp2,filename);
  set(tmp_a,tmp2);strcat(tmp_a,".GTO.DB.1.sav");
  set(tmp_b,tmp2);strcat(tmp_b,".GTO.DB.2.sav");
  if ((fexist(tmp_a))&&(fexist(tmp_b))) {
	 fremove(tmp_b);
  } else {
    set(tmp_a,tmp2);strcat(tmp_a,".GTO.DB.2.sav");
    set(tmp_b,tmp2);strcat(tmp_b,".GTO.DB.3.sav");
    if ((fexist(tmp_a))&&(fexist(tmp_b))) {
  	   fremove(tmp_b);
    } else {
       set(tmp_a,tmp2);strcat(tmp_a,".GTO.DB.3.sav");
       set(tmp_b,tmp2);strcat(tmp_b,".GTO.DB.1.sav");
       if ((fexist(tmp_a))&&(fexist(tmp_b))) {
         fremove(tmp_b);
       } else {

       }
    }
  }
}

public udb_Savefile(filename[], dbstring[]) {
  new File:fhnd;
  new name[MAX_STRING];
  new tmp_a[MAX_STRING];
  new tmp_b[MAX_STRING];
  set(name,udb_encode(filename));
  udp_PRIVATE_clearbroken(name);
  set(tmp_a,name);strcat(tmp_a,".GTO.DB.1.sav");
  set(tmp_b,name);strcat(tmp_b,".GTO.DB.2.sav");
  if ((fexist(tmp_a))) {
	 fhnd=fopen(tmp_b,io_write);
	 fwrite(fhnd,dbstring);
	 fclose(fhnd);
	 fremove(tmp_a);
     return true;
  }

  set(tmp_a,name);strcat(tmp_a,".GTO.DB.2.sav");
  set(tmp_b,name);strcat(tmp_b,".GTO.DB.3.sav");
  if ((fexist(tmp_a))) {
	 fhnd=fopen(tmp_b,io_write);
	 fwrite(fhnd,dbstring);
	 fclose(fhnd);
	 fremove(tmp_a);
     return true;
  }

  set(tmp_a,name);strcat(tmp_a,".GTO.DB.3.sav");
  set(tmp_b,name);strcat(tmp_b,".GTO.DB.1.sav");
  if ((fexist(tmp_a))) {
	 fhnd=fopen(tmp_b,io_write);
	 fwrite(fhnd,dbstring);
	 fclose(fhnd);
	 fremove(tmp_a);
     return true;
  }
	 fhnd=fopen(tmp_b,io_write);
	 fwrite(fhnd,dbstring);
	 fclose(fhnd);
  return false;
}

public udb_Loadfile(filename[]) {
  new tmpres[MAX_DBSTRING];
  tmpres[0]=0;
  new File:fhnd;
  new name[MAX_STRING];
  new tmp_a[MAX_STRING];
  set(name,udb_encode(filename));
  udp_PRIVATE_clearbroken(name);
  set(tmp_a,name);strcat(tmp_a,".GTO.DB.1.sav");
  if ((fexist(tmp_a))) {
	 fhnd=fopen(tmp_a,io_read);
	 fread(fhnd,tmpres);
	 fclose(fhnd);
  }
  set(tmp_a,name);strcat(tmp_a,".GTO.DB.2.sav");
  if ((fexist(tmp_a))) {
	 fhnd=fopen(tmp_a,io_read);
	 fread(fhnd,tmpres);
	 fclose(fhnd);
  }
  set(tmp_a,name);strcat(tmp_a,".GTO.DB.3.sav");
  if ((fexist(tmp_a))) {
	 fhnd=fopen(tmp_a,io_read);
	 fread(fhnd,tmpres);
	 fclose(fhnd);
  }
  StripNewLine(tmpres);
  return tmpres;
}

public udb_Create(filename[],dbstring[]) {
  if (udb_Exists(filename)) return false;
  udb_Savefile(filename,dbstring);
  return true;
}
