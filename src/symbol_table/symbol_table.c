#include "../../include/symbol_table/symbol_table.h"
#include <stdio.h>
#include <stdlib.h>

node_item createNewItem(char *name) {
    node_item itm;
    itm.name = name;
    return itm;
}