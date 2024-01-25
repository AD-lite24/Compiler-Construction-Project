#include "datastructures/symbol_table_item.h"
#include <stdlib.h>
#include <stdio.h>

node_item createNewItem(char* val){
  node_item itm;
  itm.val=val;
  return itm;
}
