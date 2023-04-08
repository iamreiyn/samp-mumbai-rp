/*
	@title C-MySQL
	@author Carlton (CarltonTheGG)
	@copyright (2010)
	
	@functions
	native CMySQL_Create(Username[], Password[], bool:md5 = true, ThreadID = -1, extraID = -1);
	native CMySQL_Delete(Username[], ThreadID = -1, extraID = -1);
	native CMySQL_SetInt(Username[], Field[], Value, ThreadID = -1, extraID = -1);
	native CMySQL_CustomDataSet(Username[], Custom[], ThreadID = -1, extraID = -1);
	native CMySQL_Set(Username[], Field[], Value[], bool:md5 = false, ThreadID = -1, extraID = -1);
	native CMySQL_SetFloat(Username[], Field[], Float:Value, ThreadID = -1, extraID = -1);
	native CMySQL_SetBool(Username[], Field[], bool:Value, ThreadID = -1, extraID = -1);
	native CMySQL_Load(Username[], ThreadID = -1, extraID = -1);
	native CMySQL_Exists(Username[]);
	native CMySQL_Int(Username[], Field[], ThreadID = -1, extraID = -1);
	native CMySQL_Get(Username[], Field[], Storage[], ThreadID = -1, extraID = -1);
	native Float:CMySQL_Float(Username[], Field[],ThreadID = -1, extraID = -1);
	native CMySQL_SetPasswordField(FieldName[]);
	native CMySQL_SetUsernameField(FieldName[]);
	native CMySQL_SetAccountTable(TableName[]);
	
	www.volt-host.com
*/
//==================================
#include <a_samp>

#tryinclude <a_mysql>
#if !defined _inc_a_mysql
    #tryinclude <mysql>
    #if !defined _inc_mysql
        #error You must have at least one mysql include!
    #endif
#endif
//==================================
#define MYSQL_PLUGIN // Defined = BlueG's plugin. | Undefined = Strickenkid's plugin.
//==================================
#define ACCOUNT_TABLE "Accounts"
#define USERNAME_FIELD "Username"
#define PASSWORD_FIELD "Password"
//==================================
new
	SQLEscapeX[6][256];

stock Float:CMySQL_Float(Username[], Field[],ThreadID = -1, extraID = -1) {
    mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(Username, SQLEscapeX[2]);
	mysql_real_escape_string(Field, SQLEscapeX[3]);
    if(ThreadID != -1 && extraID != -1) {
	 	format(SQLEscapeX[5], 128, "SELECT %s FROM %s WHERE %s = '%s'", SQLEscapeX[1], SQLEscapeX[0], SQLEscapeX[1], SQLEscapeX[2]);
   		mysql_query(SQLEscapeX[5], ThreadID, extraID);
   		return 0.0;
	}
	format(SQLEscapeX[5], 128, "SELECT %s FROM %s WHERE %s = '%s'", SQLEscapeX[1], SQLEscapeX[0], SQLEscapeX[1], SQLEscapeX[2]);
	mysql_query(SQLEscapeX[5], ThreadID, extraID);
	mysql_store_result();
	new Storage[30];
	#if defined MYSQL_PLUGIN
		mysql_fetch_field_row(Storage, Field);
	#else
	    mysql_fetch_field(Field, Storage);
	#endif
	new Float:StoredResult = floatstr(Storage);
	mysql_free_result();
	return StoredResult;
}
stock CMySQL_Get(Username[], Field[], Storage[], ThreadID = -1, extraID = -1) {
    mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(Username, SQLEscapeX[2]);
	mysql_real_escape_string(Field, SQLEscapeX[3]);
    if(ThreadID != -1 && extraID != -1) {
	 	format(SQLEscapeX[5], 128, "SELECT %s FROM %s WHERE %s = '%s'", SQLEscapeX[3], SQLEscapeX[0], SQLEscapeX[1], SQLEscapeX[2]);
   		mysql_query(SQLEscapeX[5], ThreadID, extraID);
   		return 1;
	}
	format(SQLEscapeX[5], 128, "SELECT %s FROM %s WHERE %s = '%s'", SQLEscapeX[3], SQLEscapeX[0], SQLEscapeX[1], SQLEscapeX[2]);
	mysql_query(SQLEscapeX[5], ThreadID, extraID);
	mysql_store_result();
	#if defined MYSQL_PLUGIN
		if(mysql_retrieve_row()) {
			mysql_fetch_field_row(Storage, Field);
		}
	#else
	    mysql_fetch_string(Storage);
	#endif
	mysql_free_result();
	return 1;
}
stock CMySQL_Int(Username[], Field[], ThreadID = -1, extraID = -1) {
    mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(Username, SQLEscapeX[2]);
	mysql_real_escape_string(Field, SQLEscapeX[3]);
    if(ThreadID != -1 && extraID != -1) {
	 	format(SQLEscapeX[5], 128, "SELECT %s FROM %s WHERE %s = '%s'", SQLEscapeX[3], SQLEscapeX[0], SQLEscapeX[1], SQLEscapeX[2]);
        return mysql_query(SQLEscapeX[5], ThreadID, extraID);
	}
	format(SQLEscapeX[5], 128, "SELECT %s FROM %s WHERE %s = '%s'", SQLEscapeX[3], SQLEscapeX[0], SQLEscapeX[1], SQLEscapeX[2]);
	mysql_query(SQLEscapeX[5], ThreadID, extraID);
	mysql_store_result();
	new ReturnedValue = mysql_fetch_int();
	mysql_free_result();
	return ReturnedValue;
}
stock CMySQL_Exists(Username[]) {
    mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(Username, SQLEscapeX[2]);
	format(SQLEscapeX[5], 128, "SELECT %s FROM %s WHERE %s = '%s'", SQLEscapeX[1], SQLEscapeX[0], SQLEscapeX[1], SQLEscapeX[2]);
	mysql_query(SQLEscapeX[5]);
	mysql_store_result();
	if(mysql_num_rows() == 0) {
	    mysql_free_result();
	    return 0;
	}
	mysql_free_result();
 	return 1;
}
stock CMySQL_Load(Username[], ThreadID = -1, extraID = -1) {
    mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(Username, SQLEscapeX[2]);
	format(SQLEscapeX[5], 128, "SELECT * FROM %s WHERE %s = '%s'",SQLEscapeX[0], SQLEscapeX[1], SQLEscapeX[2]);
	return mysql_query(SQLEscapeX[5], ThreadID, extraID);
}
stock CMySQL_SetBool(Username[], Field[], bool:Value, ThreadID = -1, extraID = -1) {
    mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(Username, SQLEscapeX[2]);
	mysql_real_escape_string(Field, SQLEscapeX[3]);
    switch(Value) {
		case false: format(SQLEscapeX[5], 128, "UPDATE %s SET %s = 'false' WHERE %s = '%s'", SQLEscapeX[0], SQLEscapeX[3], SQLEscapeX[1],  SQLEscapeX[2]);
		case true: format(SQLEscapeX[5], 128, "UPDATE %s SET %s = 'true' WHERE %s = '%s'", SQLEscapeX[0], SQLEscapeX[3], SQLEscapeX[1], SQLEscapeX[2]);
	}
	return mysql_query(SQLEscapeX[5], ThreadID, extraID);
}
stock CMySQL_SetFloat(Username[], Field[], Float:Value, ThreadID = -1, extraID = -1) {
    mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(Username, SQLEscapeX[2]);
	mysql_real_escape_string(Field, SQLEscapeX[3]);
    format(SQLEscapeX[5], 128, "UPDATE %s SET %s = '%f' WHERE %s = '%s'", SQLEscapeX[0], SQLEscapeX[3], Value, SQLEscapeX[1], SQLEscapeX[2]);
	return mysql_query(SQLEscapeX[5], ThreadID, extraID);
}
stock CMySQL_Set(Username[], Field[], Value[], bool:md5 = false, ThreadID = -1, extraID = -1) {
    mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(Username, SQLEscapeX[2]);
	mysql_real_escape_string(Field, SQLEscapeX[3]);
	mysql_real_escape_string(Value, SQLEscapeX[4]);
	switch(md5) {
		case false: format(SQLEscapeX[5], 128, "UPDATE %s SET %s = '%s' WHERE %s = '%s'", SQLEscapeX[0], SQLEscapeX[3], SQLEscapeX[4], SQLEscapeX[1], SQLEscapeX[2]);
		case true: format(SQLEscapeX[5], 128, "UPDATE %s SET %s = md5('%s') WHERE %s = '%s'", SQLEscapeX[0], SQLEscapeX[3], SQLEscapeX[4], SQLEscapeX[1], SQLEscapeX[2]);
	}
	return mysql_query(SQLEscapeX[5], ThreadID, extraID);
}
stock CMySQL_CustomDataSet(Username[], Custom[], ThreadID = -1, extraID = -1) {
    mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(Username, SQLEscapeX[2]);
	mysql_real_escape_string(Custom, SQLEscapeX[3]);
	format(SQLEscapeX[5], 256, "UPDATE %s SET %s WHERE %s = '%s'", SQLEscapeX[0], SQLEscapeX[3], SQLEscapeX[1], SQLEscapeX[2]);
	return mysql_query(SQLEscapeX[5], ThreadID, extraID);
}
stock CMySQL_SetInt(Username[], Field[], Value, ThreadID = -1, extraID = -1) {
    mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(Username, SQLEscapeX[2]);
	mysql_real_escape_string(Field, SQLEscapeX[3]);
	format(SQLEscapeX[5], 128, "UPDATE %s SET %s = %i WHERE %s = '%s'", SQLEscapeX[0], SQLEscapeX[3], Value, SQLEscapeX[1], SQLEscapeX[2]);
	return mysql_query(SQLEscapeX[5], ThreadID, extraID);
}
stock CMySQL_Create(Username[], Password[], bool:md5 = true, ThreadID = -1, extraID = -1) {
	mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(PASSWORD_FIELD, SQLEscapeX[2]);
	mysql_real_escape_string(Username, SQLEscapeX[3]);
	mysql_real_escape_string(Password, SQLEscapeX[4]);
	switch(md5) {
	    case false: {
	        format(SQLEscapeX[5], 128, "INSERT INTO %s (%s, %s) VALUES('%s', '%s')", SQLEscapeX[0], SQLEscapeX[1], SQLEscapeX[2], SQLEscapeX[3], SQLEscapeX[4]);
	    }
	    case true: {
	    	format(SQLEscapeX[5], 128, "INSERT INTO %s (%s, %s) VALUES('%s', md5('%s'))", SQLEscapeX[0], SQLEscapeX[1], SQLEscapeX[2], SQLEscapeX[3], SQLEscapeX[4]);
	    }
	}
	return mysql_query(SQLEscapeX[5], ThreadID, extraID);
}
stock CMySQL_Delete(Username[], ThreadID = -1, extraID = -1) {
    mysql_real_escape_string(ACCOUNT_TABLE, SQLEscapeX[0]);
	mysql_real_escape_string(USERNAME_FIELD, SQLEscapeX[1]);
	mysql_real_escape_string(Username, SQLEscapeX[2]);
	format(SQLEscapeX[5], 128, "DELETE FROM %s WHERE %s = '%s'", SQLEscapeX[0], SQLEscapeX[1], SQLEscapeX[2]);
	return mysql_query(SQLEscapeX[5], ThreadID, extraID);
}
