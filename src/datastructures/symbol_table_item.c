#include "symbol_table/symboltable.h"
#include <stdlib.h>
#include <stdio.h>

node_item createNewItem(char* val){
  node_item itm;
  itm.name=val;
  return itm;
}
