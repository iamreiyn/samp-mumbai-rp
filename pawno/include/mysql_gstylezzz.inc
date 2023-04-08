/**
*
*			MySQL Native Functions
*	More information about the function usage at mysql.com
*
**/

#if defined mysql_included
	#endinput
#endif
#define mysql_included

//Definitions

#define mysql_fetch_row(%1) mysql_fetch_row_format(%1,"|")
#define mysql_get_field(%1,%2) mysql_fetch_field_row(%2,%1)

//Native functions

native mysql_affected_rows(connectionHandle = 1);
native mysql_close(connectionHandle = 1);
native mysql_connect(const host[],const user[],const database[],const password[]);
native mysql_debug(enable = 1);
native mysql_errno(connectionHandle = 1);
native mysql_fetch_int(connectionHandle = 1);
native mysql_fetch_field(number,dest[],connectionHandle = 1);
native mysql_fetch_field_row(string[],const fieldname[],connectionHandle = 1);
native mysql_fetch_float(&Float:result,connectionHandle = 1);
native mysql_fetch_row_format(string[],const delimiter[] = "|",connectionHandle = 1);
native mysql_field_count(connectionHandle = 1);
native mysql_free_result(connectionHandle = 1);
native mysql_get_charset(destination[],connectionHandle = 1);
native mysql_insert_id(connectionHandle = 1);
native mysql_num_rows(connectionHandle = 1);
native mysql_num_fields(connectionHandle = 1);
native mysql_ping(connectionHandle = 1);
native mysql_query(query[],resultid = (-1),extraid = (-1),connectionHandle = 1);
native mysql_real_escape_string(const source[],destination[],connectionHandle = 1);
native mysql_reconnect(connectionHandle = 1);
native mysql_reload(connectionHandle = 1) = mysql_reconnect;
native mysql_retrieve_row(connectionHandle = 1);
native mysql_set_charset(charset[],connectionHandle = 1);
native mysql_stat(const destination[],connectionHandle = 1);
native mysql_store_result(connectionHandle = 1);
native mysql_warning_count(connectionHandle = 1);

//Callback

forward OnQueryFinish(query[], resultid, extraid, connectionHandle);