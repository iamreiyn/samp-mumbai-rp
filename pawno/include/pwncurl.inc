/**
 *            pwncurl 0.1
 *       (c) Copyright 2009 by DracoBlue
 *
 * @author    : DracoBlue (http://dracoblue.com)
 * @date      : 7th April 2009
 * @update    : 7th April 2009
 *
 * This file is provided as is (no warranties).
 *
 * It's released under the terms of MIT.
 *
 * Feel free to use it, a little message in
 * about box is honouring thing, isn't it?
 *
 */
 

#if defined _pwncurl_included
  #endinput
#endif

#define _pwncurl_included
#pragma library pwncurl

/**
 * @param url the url to fetch the content for
 * @param buf Buffer to save the content
 * @param buflen Size of the buffer to save the content
 *
 * @example
 * <code>
 *    new my_uri="http://dracoblue.net/test.php"
 *    new buf[255];
 *    printf("Content was: %s", pwncurl_get(my_uri, buf, 255));
 * </code>
 */
native pwncurl_get(url[],buf[],buflen);