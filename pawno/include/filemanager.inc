native file_move(file[],destination[]); // Moves a file
native file_delete(file[]); // Deletes a file
native file_create(file[]); // Creates a file
native file_write(file[],text[],mode[] = "a"); // Writes in append mode to a file, option to set write mode, append mode is default
native file_read(file[],storage[], size = sizeof(storage)); // Saves to the specified string
native file_log(); // Adding this will enable logging
native file_exists(file[]); // Check if a file exists
native dir_create(directory[]); // Creates a new directory
native dir_delete(directory[]); // Deletes a directory (Directory MUST be empty!)
native dir_exists(directory[]); // Check if a directory exists (Returns 0 if it doesn't, 1 if it does and 2 if it's a file)