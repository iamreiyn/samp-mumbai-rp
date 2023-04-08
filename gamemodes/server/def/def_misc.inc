
#define percent(%0,%1)  floatround((float((%0)) / 100) * (%1))
#define Random(%0,%1)   (random((%1) - (%0)) + (%0))
#define mysql_new_query(%0,%1,%2,%3,"%4"%5) \
		mysql_tquery(%0,%1,%3,#%4%5)
#undef INVALID_3DTEXT_ID
#define INVALID_3DTEXT_ID (Text3D:0xFFFF)

#define SCM 				SendClientMessage
#define MaterialRes Dialog_Show(playerid, TextureResources, DIALOG_STYLE_LIST, "Texture Category:", "Material Colors\nPrinted Fabrics\nWooden\nTiles\nBuilding\nMetals\nPaintings\nWallpapers\nMisc", "Select", "Exit");

#define IPI                 INVALID_PLAYER_ID
#define SendInfoMessage(%0,%1)   SendClientMessageEx((%0), COLOR_WHITE, ""%1)
#define SendSyntaxMessage(%0,%1) SendClientMessageEx((%0), COLOR_GREY, "Usage: "%1)
#define SendErrorMessage(%0,%1)  ShowPlayerFooter((%0), "~r~ERROR:~w~ "%1)
// ---------------------------------------
#define HOLDING(%0) \
	((newkeys & (%0)) == (%0))
#define RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#define func%0(%1)    \
        forward%0(%1); \
        public%0(%1)
#define SendServerMessage(%0,%1) \
	SendClientMessageEx(%0, COLOR_WHITE, "[SERVER]:{FFFFFF} "%1)