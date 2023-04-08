#include <a_samp>
#include <dutils>

#if defined _dof_included
	#endinput
#endif
#define _dof_included

#if !defined isnull
	#define isnull(%1) \
		((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#if !defined strcpy
	#define strcpy(%0,%1,%2) \
		strcat((%0[0] = '\0', %0), %1, %2)
#endif

#define MAX_ENTRIES 128 // Eintraege zum lesen
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 256
#define MAX_FILE_SIZE 64

#define USER_FILE_PATH "Accounts/%s.dudb.sav"

//#define DOF_DEBUG
//#define DUDB_CONVERT
//#define DINI_CONVERT

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

static LoadedFile[MAX_FILE_SIZE+1];
static LoadedEntries;
static FileChanged=false;
static Keys[MAX_ENTRIES][MAX_KEY_SIZE+1];
static KeyHashes[MAX_ENTRIES];
static Values[MAX_ENTRIES][MAX_VALUE_SIZE+1];

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

/*
native DOF_SetFile(file[]);
native DOF_LoadFile();
native DOF_SaveFile();
native DOF_PrintFile(comment[]="");
native DOF_GetString(file[],key[],bool:hashcmp=true);
native DOF_GetStringEx(file[],key[],result[],len,bool:hashcmp=true);
native DOF_GetFloat(file[],key[],bool:hashcmp=true);
native DOF_GetInt(file[],key[],bool:hashcmp=true);
native DOF_GetBool(file[],key[],bool:hashcmp=true);
native DOF_SetString(file[],key[],value[],bool:hashcmp=true);
native DOF_SetFloat(file[],key[],Float:value,bool:hashcmp=true);
native DOF_SetInt(file[],key[],value,bool:hashcmp=true);
native DOF_SetBool(file[],key[],bool:value,bool:hashcmp=true);
native DOF_IsSet(file[],key[],bool:hashcmp=true);
native DOF_Unset(file[],key[],bool:hashcmp=true);
native DOF_FileExists(file[]);
native DOF_RemoveFile(file[]);
native DOF_CreateFile(file[],password[]="");
native DOF_RenameFile(oldfile[],newfile[]);
native DOF_RenameKey(file[],oldkey[],newkey[],bool:hashcmp=true);
native DOF_CopyFile(filetocopy[],newfile[]);
native DOF_CheckLogin(file[],password[]);
native DOF_GetHashCols();
native DOF_File(user[]);
*/

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

DOF_Exit()//Bei OnGameModeExit:
{
	DOF_SaveFile();
}

stock DOF_SetFile(file[])
{
	if(!isnull(file))
	    return strcpy(LoadedFile,file,sizeof(LoadedFile));
	return 0;
}

stock DOF_LoadFile()
{
	if(!isnull(LoadedFile))
	{
	    LoadedEntries=0;
		new File:f=fopen(LoadedFile,io_read),string[MAX_VALUE_SIZE+MAX_KEY_SIZE+5],pos,pos2;
		while(fread(f,string,sizeof(string)) && LoadedEntries<MAX_ENTRIES)
		{
			StripNewLine(string);
			if(!isnull(string) && string[0]!=';')//;This is a comment^^
			{
			    pos=0;
			    while(string[pos]!='=' && string[pos])
			    {
			        if(pos<MAX_KEY_SIZE)
			        	Keys[LoadedEntries][pos]=string[pos];
					pos++;
			    }
			    if(pos<MAX_KEY_SIZE)
					Keys[LoadedEntries][pos]='\0';
			    KeyHashes[LoadedEntries]=DOF_bernstein(Keys[LoadedEntries]);
			    
			    pos++;
			    pos2=pos;
			    while(string[pos2] && (pos2-pos)<MAX_VALUE_SIZE)
			    {
			        Values[LoadedEntries][pos2-pos]=string[pos2];
			        pos2++;
			    }
			    if((pos2-pos)<MAX_VALUE_SIZE)
			    	Values[LoadedEntries][pos2-pos]='\0';
			    LoadedEntries++;
			}
		}
		fclose(f);
		return LoadedEntries;
	}
	return 0;
}

stock DOF_SaveFile()
{
    if(!isnull(LoadedFile))
	{
	    #if defined DOF_DEBUG
			//DOF_PrintFile();
			printf("[DOF] Schreibe Datei ('%s') neu!",LoadedFile);
	    #endif
	    fremove(LoadedFile);
	    new File:f=fopen(LoadedFile,io_append),string[MAX_VALUE_SIZE+MAX_KEY_SIZE+5];
	    for(new i=0;i<LoadedEntries;i++)
	    {
	        format(string,sizeof(string),"%s=%s\r\n",Keys[i],Values[i]);
	        fwrite(f,string);
	    }
		FileChanged=false;
	    return fclose(f);
	}
	return 0;
}

stock DOF_PrintFile(comment[]="")
{
	if(!isnull(LoadedFile))
	{
	    printf("[DOF] Geladene Datei: '%s'",LoadedFile);
	    for(new i=0;i<LoadedEntries;i++)
	        printf("%s=%s",Keys[i],Values[i]);
		printf("(%d Eintraege)",LoadedEntries);
		if(!isnull(comment))
		    printf("* Kommentar: %s",comment);
		return 1;
	}
	
	print("[DOF] Keine Datei geladen!");
	return 0;
}

stock DOF_GetString(file[],key[],bool:hashcmp=true)
{
	new result[MAX_VALUE_SIZE];
	if(!isnull(file) && !isnull(key))
	{
	    if(DOF_FileExists(file))
	    {
			if(isnull(LoadedFile) || strcmp(file,LoadedFile,false))//Neue Datei laden.
			{
			    if(FileChanged)
					DOF_SaveFile();
			    #if defined DOF_DEBUG
			        printf("[DOF] Alte Datei ('%s') gespeichert, lade neue ('%s')!",LoadedFile,file);
			    #endif
			    DOF_SetFile(file);
			    DOF_LoadFile();
			}

			if(hashcmp)
			{
			    for(new i=0, h=DOF_bernstein(key);i<LoadedEntries;i++)
				{
				    if(h==KeyHashes[i] && !strcmp(Keys[i],key,true))
				    {
						strcpy(result,Values[i],sizeof(result));
						return result;
					}
				}
			}
			else
			{
				for(new i=0;i<LoadedEntries;i++)
				{
				    if(!strcmp(Keys[i],key,true))
				    {
						strcpy(result,Values[i],sizeof(result));
						return result;
					}
				}
			}
		}
	}
	return result;
}

stock DOF_GetStringEx(file[],key[],result[],len,bool:hashcmp=true)
{
    if(!isnull(file) && !isnull(key))
	{
	    if(DOF_FileExists(file))
	    {
			if(isnull(LoadedFile) || strcmp(file,LoadedFile,false))//Neue Datei laden.
			{
			    if(FileChanged)
					DOF_SaveFile();
			    #if defined DOF_DEBUG
			        printf("[DOF] Alte Datei ('%s') gespeichert, lade neue ('%s')!",LoadedFile,file);
			    #endif
			    DOF_SetFile(file);
			    DOF_LoadFile();
			}

			if(hashcmp)
			{
				for(new i=0, h=DOF_bernstein(key);i<LoadedEntries;i++)
				    if(h==KeyHashes[i] && !strcmp(Keys[i],key,true))
				        return strcpy(result,Values[i],len);
			}
			else
			{
				for(new i=0;i<LoadedEntries;i++)
				    if(!strcmp(Keys[i],key,true))
				        return strcpy(result,Values[i],len);
			}
		}
	}
	return 0;
}

stock Float:DOF_GetFloat(file[],key[],bool:hashcmp=true)
	return floatstr(DOF_GetString(file,key,hashcmp));
	
stock DOF_GetInt(file[],key[],bool:hashcmp=true)
	return strval(DOF_GetString(file,key,hashcmp));
	
stock bool:DOF_GetBool(file[],key[],bool:hashcmp=true)
{
	if(strval(DOF_GetString(file,key,hashcmp)))
	    return (bool:1);
	return (bool:0);
}

stock DOF_SetString(file[],key[],value[],bool:hashcmp=true)
{
    if(!isnull(file) && !isnull(key))
	{
	    if(DOF_FileExists(file))
	    {
			if(isnull(LoadedFile) || strcmp(file,LoadedFile,false))//Neue Datei laden.
			{
			    if(FileChanged)
					DOF_SaveFile();
			    #if defined DOF_DEBUG
			        printf("[DOF] Alte Datei ('%s') gespeichert, lade neue ('%s')!",LoadedFile,file);
			    #endif
			    DOF_SetFile(file);
			    DOF_LoadFile();
			}

            FileChanged=true;
            if(hashcmp)
            {
                for(new i=0, h=DOF_bernstein(key);i<LoadedEntries;i++)
				    if(h==KeyHashes[i] && !strcmp(Keys[i],key,true))
				        return strcpy(Values[i],value,MAX_VALUE_SIZE);
            }
            else
            {
				for(new i=0;i<LoadedEntries;i++)
				    if(!strcmp(Keys[i],key,true))
			        	return strcpy(Values[i],value,MAX_VALUE_SIZE);
			}

			//Key existiert nicht:
			if(LoadedEntries<MAX_ENTRIES)
			{
			    strcpy(Keys[LoadedEntries],key,MAX_KEY_SIZE);
				KeyHashes[LoadedEntries]=DOF_bernstein(Keys[LoadedEntries]);
			    strcpy(Values[LoadedEntries],value,MAX_VALUE_SIZE);
			    LoadedEntries++;
			    return 1;
			}
		}
	}
	return 0;
}

stock DOF_IsSet(file[],key[],bool:hashcmp=true)
{
	if(!isnull(file) && !isnull(key))
	{
	    if(DOF_FileExists(file))
	    {
			if(isnull(LoadedFile) || strcmp(file,LoadedFile,false))//Neue Datei laden.
			{
			    if(FileChanged)
					DOF_SaveFile();
			    #if defined DOF_DEBUG
			        printf("[DOF] Alte Datei ('%s') gespeichert, lade neue ('%s')!",LoadedFile,file);
			    #endif
			    DOF_SetFile(file);
			    DOF_LoadFile();
			}

			if(hashcmp)
			{
			    for(new i=0, h=DOF_bernstein(key);i<LoadedEntries;i++)
				    if(h==KeyHashes[i] && !strcmp(Keys[i],key,true))
				        return 1;
			}
			else
			{
				for(new i=0;i<LoadedEntries;i++)
				    if(!strcmp(Keys[i],key,true))
						return 1;
			}
		}
	}
	return 0;
}

stock DOF_Unset(file[],key[],bool:hashcmp=true)
{
    if(!isnull(file) && !isnull(key))
	{
	    if(DOF_FileExists(file))
	    {
			if(isnull(LoadedFile) || strcmp(file,LoadedFile,false))//Neue Datei laden.
			{
			    if(FileChanged)
					DOF_SaveFile();
			    #if defined DOF_DEBUG
			        printf("[DOF] Alte Datei ('%s') gespeichert, lade neue ('%s')!",LoadedFile,file);
			    #endif
			    DOF_SetFile(file);
			    DOF_LoadFile();
			}

			if(hashcmp)
			{
			    for(new i=0, h=DOF_bernstein(key);i<LoadedEntries;i++)
			    {
				    if(h==KeyHashes[i] && !strcmp(Keys[i],key,true))
				    {
				        FileChanged=true;
				        LoadedEntries--;
				        Keys[i]=Keys[LoadedEntries];
				        KeyHashes[i]=KeyHashes[LoadedEntries];
				        Values[i]=Values[LoadedEntries];
			        	return 1;
					}
				}
			}
			else
			{
				for(new i=0;i<LoadedEntries;i++)
				{
				    if(!strcmp(Keys[i],key,true))
				    {
				        FileChanged=true;
				        LoadedEntries--;
				        Keys[i]=Keys[LoadedEntries];
				        KeyHashes[i]=KeyHashes[LoadedEntries];
				        Values[i]=Values[LoadedEntries];
			        	return 1;
					}
				}
			}
		}
	}
	return 0;
}

stock DOF_SetFloat(file[],key[],Float:value,bool:hashcmp=true)
{
	new fvalue[MAX_VALUE_SIZE];
	format(fvalue,sizeof(fvalue),"%.8f",value);
	return DOF_SetString(file,key,fvalue,hashcmp);
}

stock DOF_SetInt(file[],key[],value,bool:hashcmp=true)
{
	new ivalue[MAX_VALUE_SIZE];
	//valstr(ivalue,value);//This is bullshit!!! Freezing server when using valstr(ivalue,2000000000);
	format(ivalue,sizeof(ivalue),"%d",value);
	return DOF_SetString(file,key,ivalue,hashcmp);
}

stock DOF_SetBool(file[],key[],bool:value,bool:hashcmp=true)
{
	if(value)
	    return DOF_SetString(file,key,"1",hashcmp);
	return DOF_SetString(file,key,"0",hashcmp);
}

stock DOF_FileExists(file[])
	return fexist(file);
	
stock DOF_RemoveFile(file[])
{
	if(!isnull(file))
	{
	    if(!isnull(LoadedFile) && !strcmp(file,LoadedFile,false))//Gespeicherte Datei löschen, falls die gespeicherte Datei die ist, welche gelöscht werden soll.
	    {
			LoadedFile[0]='\0';
			LoadedEntries=0;
		}
		return fremove(file);
	}
	return 0;
}

stock DOF_CreateFile(file[],password[]="")
{
	if(!isnull(file))
	{
	    if(!DOF_FileExists(file))
	    {
            DOF_SaveFile();
            #if defined DOF_DEBUG
		        printf("[DOF] Alte Datei ('%s') gespeichert, lade neue ('%s')!",LoadedFile,file);
		    #endif
            new File:f=fopen(file,io_append);
            fclose(f);
            DOF_SetFile(file);
            LoadedEntries=0;
            if(!isnull(password))
				DOF_SetInt(file,"password_hash",num_hash(password));
            return DOF_SaveFile();
	    }
	}
	return 0;
}

stock DOF_RenameFile(oldfile[],newfile[])
{
	if(!isnull(oldfile) && !isnull(newfile))
	{
	    if(DOF_FileExists(oldfile) && !DOF_FileExists(newfile))
	    {
	        if(FileChanged)
				DOF_SaveFile();//Derzeitige Datei speichern
	        DOF_SetFile(oldfile);
	        DOF_LoadFile();
	        fremove(oldfile);
	        DOF_SetFile(newfile);
	        return DOF_SaveFile();
	    }
	}
	return 0;
}

stock DOF_RenameKey(file[],oldkey[],newkey[],bool:hashcmp=true)
{
    if(!isnull(file) && !isnull(oldkey) && !isnull(newkey))
	{
	    if(DOF_FileExists(file))
	    {
			if(isnull(LoadedFile) || strcmp(file,LoadedFile,false))//Neue Datei laden.
			{
			    if(FileChanged)
					DOF_SaveFile();
			    #if defined DOF_DEBUG
			        printf("[DOF] Alte Datei ('%s') gespeichert, lade neue ('%s')!",LoadedFile,file);
			    #endif
			    DOF_SetFile(file);
			    DOF_LoadFile();
			}

			if(hashcmp)
			{
			    for(new i=0, h=DOF_bernstein(oldkey);i<LoadedEntries;i++)
			    {
				    if(h==KeyHashes[i] && !strcmp(Keys[i],oldkey,true))
				    {
				        FileChanged=true;
				        strcpy(Keys[i],newkey,MAX_KEY_SIZE);
				        KeyHashes[i]=DOF_bernstein(Keys[i]);
			        	return 1;
					}
				}
			}
			else
			{
				for(new i=0;i<LoadedEntries;i++)
				{
				    if(!strcmp(Keys[i],oldkey,true))
				    {
				        FileChanged=true;
				        strcpy(Keys[i],newkey,MAX_KEY_SIZE);
				        KeyHashes[i]=DOF_bernstein(Keys[i]);
			        	return 1;
					}
				}
			}
		}
	}
	return 0;
}

stock DOF_CopyFile(filetocopy[],newfile[])
{
    if(!isnull(filetocopy) && !isnull(newfile))
	{
	    if(DOF_FileExists(filetocopy) && !DOF_FileExists(newfile))
	    {
	        if(FileChanged)
				DOF_SaveFile();//Derzeitige Datei speichern
	        DOF_SetFile(filetocopy);
	        DOF_LoadFile();
	        DOF_SetFile(newfile);
	        return DOF_SaveFile();
	    }
	}
	return 0;
}

stock DOF_CheckLogin(file[],password[])
{
	if(!isnull(file) && !isnull(password))
	    if(num_hash(password)==DOF_GetInt(file,"password_hash"))
			return 1;
	return 0;
}

stock DOF_GetHashCols()
{
	new c;
	for(new i=0;i<LoadedEntries;i++)
	{
	    for(new j=(i+1);j<LoadedEntries;j++)
	    {
	        if(KeyHashes[i]==KeyHashes[j] && strcmp(Keys[i],Keys[j],true))
	        {
	            printf("[DOF] Hash-Kollision: '%s' (%d) mit '%s' (%d)",Keys[i],KeyHashes[i],Keys[j],KeyHashes[j]);
	        	c++;
			}
	    }
	}
	return c;
}

stock DOF_File(user[])
{
	new newfile[MAX_FILE_SIZE];
	format(newfile,sizeof(newfile),USER_FILE_PATH,DOF_udb_encode(user));
	return newfile;
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//DUDB (DracoBlue)

stock DOF_udb_encode(nickname[]) {
	new tmp[255];
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

stock DOF_udb_decode(nickname[]) {
	new tmp[255];
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

//YSI_misc.own (Y_Less)

stock DOF_bernstein(string[])
{
	new
		h = -1,
		i,
		j;
	while ((j = string[i++]))
	{
		h = h * 33 + j;
	}
	return h;
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#if defined DUDB_CONVERT

	#define dUser(%0).( 			DOF_GetString(DOF_File(%0),
	#define dUserSet(%0).( 			DOF_SetString(DOF_File(%0),
	#define dUserINT(%0).( 			DOF_GetInt(DOF_File(%0),
	#define dUserSetINT(%0).( 		DOF_SetInt(DOF_File(%0),
	#define dUserFLOAT(%0).( 		DOF_GetFloat(DOF_File(%0),
	#define dUserSetFLOAT(%0).( 	DOF_SetFloat(DOF_File(%0),
	#define udb_Create(%0,%1)		DOF_CreateFile(DOF_File(%0),%1)
	#define udb_RenameUser(%0,%1)   DOF_RenameFile(DOF_File(%0),DOF_File(%1))
	#define udb_Exists(%0)          DOF_FileExists(DOF_File(%0))
	#define udb_Remove(%0)          DOF_RemoveFile(DOF_File(%0))
	#define udb_CheckLogin(%0,%1)   DOF_CheckLogin(DOF_File(%0),%1)
	#define udb_hash            	num_hash
	#define udb_encode              DOF_udb_encode
	#define udb_decode              DOF_udb_decode
	
	#if !defined _dudb_included
		#define _dudb_included
	#endif
#endif

#if defined DINI_CONVERT

	#define dini_Exists		        DOF_FileExists
	#define dini_Remove         	DOF_RemoveFile
	#define dini_Create         	DOF_CreateFile
	#define dini_Set			    DOF_SetString
	#define dini_Get         		DOF_GetString
	#define dini_IntSet   			DOF_SetInt
	#define dini_Int         		DOF_GetInt
	#define dini_BoolSet            DOF_SetBool
	#define dini_Bool               DOF_GetBool
	#define dini_FloatSet 			DOF_SetFloat
	#define dini_Float      		DOF_GetFloat
	#define dini_Unset       		DOF_Unset
	#define dini_Isset       		DOF_IsSet
	
	#if !defined _dini_included
		#define _dini_included
	#endif
#endif
