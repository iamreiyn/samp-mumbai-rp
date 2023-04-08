/**
 *       SA:MP MySQL Functions     
 *  (c) Copyright 2010, <__Ethan__>
 *
 **/

#if defined _mysql_included
	#endinput
#endif
#define _mysql_included
#pragma library mysql

// defines

#define INVALID_MYSQL_ID (-1)


#define LOG_OFF           (0)
#define LOG_ALL           (1)
#define LOG_ONLY_ERRORS   (2)

// plugin callbacks

forward OnMysqlQuery(resultid, MySQL:connection);
forward OnMysqlError(error[], errorid, MySQL:connection);

// plugin natives

native mysql_log(logtype, windowerrors = 1, MySQL:handle = MySQL:0);
native MySQL:mysql_connect(const host[], const user[], const pass[], const db[], auto_reconnect = 0);
native mysql_close(MySQL:handle = MySQL:0);
native mysql_reload(MySQL:handle = MySQL:0);
native mysql_select_db(const db[], MySQL:handle = MySQL:0);
native mysql_query(const query[], resultid = (-1), MySQL:handle = MySQL:0);
native mysql_store_result(MySQL:handle = MySQL:0);
native mysql_free_result(MySQL:handle = MySQL:0);
native mysql_result_stored(MySQL:handle = MySQL:0);
native mysql_fetch_field(const fieldname[], dest[], MySQL:handle = MySQL:0);
native mysql_fetch_field_num(fieldnum, dest[], MySQL:handle = MySQL:0);
native mysql_fetch_row(dest[], const splitter[] = "|", MySQL:handle = MySQL:0);
native mysql_fetch_row_data(MySQL:handle = MySQL:0);
native mysql_real_escape_string(const string[], dest[], MySQL:handle = MySQL:0);
native mysql_num_rows(MySQL:handle = MySQL:0);
native mysql_num_fields(MySQL:handle = MySQL:0);
native mysql_affected_rows(MySQL:handle = MySQL:0);
native mysql_insert_id(MySQL:handle = MySQL:0);
native mysql_ping(MySQL:handle = MySQL:0);
native mysql_error(dest[], MySQL:handle = MySQL:0);
native mysql_errno(MySQL:handle = MySQL:0);
native mysql_warning_count(MySQL:handle = MySQL:0);
native mysql_info(dest[], MySQL:handle = MySQL:0);
native mysql_stat(dest[], MySQL:handle = MySQL:0);
native mysql_get_server_info(dest[], MySQL:handle = MySQL:0);
native mysql_get_host_info(dest[], MySQL:handle = MySQL:0);
native mysql_data_seek(rownum, MySQL:handle = MySQL:0);
native mysql_set_character_set(const csname[], MySQL:handle = MySQL:0);
native mysql_fetch_int(MySQL:handle = MySQL:0);
native Float:mysql_fetch_float(MySQL:handle = MySQL:0);
native mysql_fetch_string(dest[], MySQL:handle = MySQL:0);

// split function - thanks to Blacklite
stock split(const strsrc[], strdest[][], delimiter = '|')
{
	new i, li, aNum, len, srclen = strlen(strsrc);
	while(i <= srclen)
	{
		if (strsrc[i] == delimiter || i == srclen)
		{
			len = strmid(strdest[aNum], strsrc, li, i, 128);
			strdest[aNum][len] = 0;
			li = i + 1;
			aNum++;
		}
		i++;
	}
}