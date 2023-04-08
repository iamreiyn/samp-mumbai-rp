native XML:xml_open(const filename[]);
native xml_close(XML:handle);
native bool:xml_get_bool(XML:handle, const xpath[]);
native xml_get_int(XML:handle, const xpath[]);
native Float:xml_get_float(XML:handle, const xpath[]);
native xml_get_string(XML:handle, const xpath[], result[], size = sizeof result);