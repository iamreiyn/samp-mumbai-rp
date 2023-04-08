/*
================================================================================
-------------------------------------------------
LuX Administration System v1.0

Data Include
-------------------------------------------------
================================================================================

ORIGINAL DUDB functions By DracoBlue
*/


#if defined _dudb_included
  #endinput
#endif

#define _dudb_included
#pragma library dutils

#include <dutils>
#include <dini>
#define dUser(%1).( udb_User(%1,
#define dUserINT(%1).( udb_UserInt(%1,
#define dUserSet(%1).( udb_UserSet(%1,
#define dUserSetINT(%1).( udb_UserSetInt(%1,
#define dUserSetFLOAT(%1).( udb_UserSetFloat(%1,
#define dUserFLOAT(%1).( udb_UserFloat(%1,

stock udb_hash(buf[]) {
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

stock udb_encode(nickname[]) {
  new tmp[MAX_STRING];
  set(tmp,nickname);
  tmp=strreplace("_","_00",tmp);
  tmp=strreplace(";","_01",tmp);
  tmp=strreplace("!","_02",tmp);
  tmp=strreplace("/","_03",tmp);
  tmp=strreplace("\\","_04",tmp);
  tmp=strreplace("[","_05",tmp);
  tmp=strreplace("]","_06",tmp);
  tmp=strreplace("?","_07",tmp);
  tmp=strreplace(".","_08",tmp);
  tmp=strreplace("*","_09",tmp);
  tmp=strreplace("<","_10",tmp);
  tmp=strreplace(">","_11",tmp);
  tmp=strreplace("{","_12",tmp);
  tmp=strreplace("}","_13",tmp);
  tmp=strreplace(" ","_14",tmp);
  tmp=strreplace("\"","_15",tmp);
  tmp=strreplace(":","_16",tmp);
  tmp=strreplace("|","_17",tmp);
  tmp=strreplace("=","_18",tmp);
  return tmp;
}

stock udb_decode(nickname[]) {
  new tmp[MAX_STRING];
  set(tmp,nickname);
  tmp=strreplace("_01",";",tmp);
  tmp=strreplace("_02","!",tmp);
  tmp=strreplace("_03","/",tmp);
  tmp=strreplace("_04","\\",tmp);
  tmp=strreplace("_05","[",tmp);
  tmp=strreplace("_06","]",tmp);
  tmp=strreplace("_07","?",tmp);
  tmp=strreplace("_08",".",tmp);
  tmp=strreplace("_09","*",tmp);
  tmp=strreplace("_10","<",tmp);
  tmp=strreplace("_11",">",tmp);
  tmp=strreplace("_12","{",tmp);
  tmp=strreplace("_13","}",tmp);
  tmp=strreplace("_14"," ",tmp);
  tmp=strreplace("_15","\"",tmp);
  tmp=strreplace("_16",":",tmp);
  tmp=strreplace("_17","|",tmp);
  tmp=strreplace("_18","=",tmp);
  tmp=strreplace("_00","_",tmp);
  return tmp;
}


stock udb_Exists(nickname[]) {
  new tmp[MAX_STRING];
  format(tmp,sizeof(tmp),"LuxAdmin/Accounts/%s.sav",udb_encode(nickname));
  return fexist(tmp);
}


stock udb_Remove(nickname[]) {
  new tmp[MAX_STRING];
  format(tmp,sizeof(tmp),"LuxAdmin/Accounts/%s.sav",udb_encode(nickname));
  return dini_Remove(tmp);
}

stock udb_UserSetInt(nickname[],key[],value) {
  new fname[MAX_STRING];
  format(fname,sizeof(fname),"LuxAdmin/Accounts/%s.sav",udb_encode(nickname));
  return dini_IntSet(fname,key,value);
}

stock udb_UserSetFloat(nickname[],key[],Float:value) {
  new fname[MAX_STRING];
  format(fname,sizeof(fname),"LuxAdmin/Accounts/%s.sav",udb_encode(nickname));
  return dini_FloatSet(fname,key,value);
}

stock udb_UserSet(nickname[],key[],value[]) {
  new fname[MAX_STRING];
  format(fname,sizeof(fname),"LuxAdmin/Accounts/%s.sav",udb_encode(nickname));
  return dini_Set(fname,key,value);
}

stock udb_User(nickname[],key[]) {
  new fname[MAX_STRING];
  format(fname,sizeof(fname),"LuxAdmin/Accounts/%s.sav",udb_encode(nickname));
  format(fname,sizeof(fname),dini_Get(fname,key));
  return fname;
}

stock Float:udb_UserFloat(nickname[],key[]) {
  new fname[MAX_STRING];
  format(fname,sizeof(fname),"LuxAdmin/Accounts/%s.sav",udb_encode(nickname));
  return dini_Float(fname,key);
}

stock udb_UserInt(nickname[],key[]) {
  new fname[MAX_STRING];
  format(fname,sizeof(fname),"LuxAdmin/Accounts/%s.sav",udb_encode(nickname));
  return dini_Int(fname,key);
}

stock udb_Create(nickname[])
{
  if (udb_Exists(nickname)) return false;
  new fname[MAX_STRING];
  format(fname,sizeof(fname),"LuxAdmin/Accounts/%s.sav",udb_encode(nickname));
  dini_Create(fname);
  return true;
}

stock udb_RenameUser(nickname[],newnick[]) {
  new oldfname[MAX_STRING];
  new newfname[MAX_STRING];
  format(oldfname,sizeof(oldfname),"LuxAdmin/Accounts/%s.sav",udb_encode(nickname));
  format(newfname,sizeof(newfname),"LuxAdmin/Accounts/%s.sav",udb_encode(newnick));
  return frenametextfile(oldfname,newfname);
}

