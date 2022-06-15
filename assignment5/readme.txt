Name: Eliut S. Brenlla Reyes
ONID: brenllae

  This program is meant to store values (void*) into a hash table. There is documentation on
what each function does on hash_table.c. You can set up the size of the Hash table by updating
the integer next to MAX_ARRAY to the array size you wish (default is 10). Additionaly there is
a commented line of code (line 168 in test_hash_table.c) that, once undocumented, can show you
the hash table for all 16 items.

Here is the functions and an abridge description of what they do:
ht_create();
print_hash // Prints Hash Array
ht_isempty // Checks is the table is empty
ht_size // Outputs the Size of the Hash Table (number of items)
ht_free // Clears up the Hash table and frees up the memory
ht_hash_func // Function to randomize and output the index that the data is asigned to
ht_insert // takes the Hash table, the data (void*), the key (void*), and a function to convert void* to int
ht_lookup // Looks up the Data in a Hash table based on the key input
ht_remove // Removes the data in a Hash table based on the key input

Know limitations:
 - Key should be able to be converted to an int, no strings support yet
 - It depends on the convert function that it's being passed on test_hash_table
 - It was made at 4am after an almost full day of sleep depravation so there might be a few
   things that could be refined.

 Additional Notes:

 Thankyou for the awesome term! I wish you guys luck on Finals and ond your Engineering quest!

  _____  _                    _                          _ 
|_   _|| |                  | |                        | |
  | |  | |__    __ _  _ __  | | __ _   _   ___   _   _ | |
  | |  | '_ \  / _` || '_ \ | |/ /| | | | / _ \ | | | || |
  | |  | | | || (_| || | | ||   < | |_| || (_) || |_| ||_|
  \_/  |_| |_| \__,_||_| |_||_|\_\ \__, | \___/  \__,_|(_)
                                    __/ |                 
                                   |___/                  