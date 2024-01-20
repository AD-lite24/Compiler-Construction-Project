# Compliler Construction

C code for the compiler project

## Overview of a compiler

<img width="654" alt="Screenshot 2024-01-20 at 3 05 52 PM" src="https://github.com/AD-lite24/Compiler-Construction-Project/assets/96363931/3699e52c-5de3-4309-b023-febd37651dc6">

## Language Specs

### Sample code

_Function Defintion_

```
% Program1.txt
_statistics input parameter list [int c2dbc,int d7,int b2d567] output parameter list [real d2, real c3bcd];
type real: c3 : global; c3 <---3;
d2 <--- (c2dbc + d7 + b2d567)/c3;
c3bcd <--- d2*3.23;
return [d2,c3bcd];
end
```

_Function Call_
```
type real : c4;
type real : d3cd6 ;
[c4, d3cd6] <--- call _statistics with parameters [2,3,5];
```



### Variable Identifiers

Variable Identifiers
The identifiers are the names with the following pattern.
[b-d] [2-7][b-d] * [2-7] *
The identifier can be of any length of size varying in the range from 2 to 20.
A sample list of valid identifiers is d2bbbb54, b5cdbcdbcd7654, c6dcdcbcc7722.
The list of invalid identifiers is d2bdcbdcb5c, 2cdc765 and so on.
An identifier cannot be declared multiple times in the same scope and it should be declared before its use.
Also, an identifier declared globally cannot be declared anywhere else in function definitions.

### Function Identifiers

Function identifier name starts with an underscore and must have the following pattern
_[a-z|A-Z] [a-z|A-Z] * [0-9] *
i.e. a function name can have one or more number of English alphabet following the underscore. Also any
number of digits can follow towards the trail. A function identifier is of maximum size of 30

### Data Types

The language supports the following types
* **Integer type**: The keyword used for representing integer data type is int and will be supported by the
underlying architecture. A statically available number of the pattern [0-9][0-9]*
is of integer type.

* **Real type**: The keyword used for representing integer data type is real and will be supported by the
underlying architecture. A statically available real number has the pattern [0-9][0-9]*
[.][0-9][0-9] and is of type real. The language also supports exponent and mantissa form of real number representation. The
regular expression for the same is [0-9][0-9]* [.][0-9][0-9] [E] [+|-| ∈] [0-9][0-9] restricting to exactly two
digits in the exponent part.

* **Record type**: This isthe constructed data type of the form of the Cartesian product of types of its constituent
fields. For example the following record is defined to be of type 'finance' and its actual type is <int , real ,
int> preserving the types and sequence of fields appearing in the record type definition.

```
record #finance
type int: value;
type real:rate;
type int: interest;
endrecord
```

A record type must have at least two fields in it, while there can be any more fields as well.
A variable identifier of type finance is declared as follows

```
type record #finance : d5bb45;
```

The names of fields start with any alphabet and can have names as words of English alphabet (only small
case). The fields are accessed using a dot in an expression as follows

```
d5bb45.value <--- 30;
d5bb45.rate <--- 30.5;
```

and so on. The types of these constructed names using variable name and record fields are same as field
types defined in the record type definition correspondingly. Nested record definitions are supported in this
language. However, the definition of the record type in nested positions cannot be used as standalone
definitions.
A test case handling addition operation on two records and use of record variables in parameters list is
depicted below. The record type #book declared in _main function is also visible in function _recordDemo1.
The language supports name equivalence and not structural equivalence, which means that similar
structured record definitions are treated different. For example, #new and #book are the two record types
with similar structure (sequence and type of variables) but different names.


