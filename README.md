# Compliler Construction

C code for the compiler project

## Table of contents:

1. [Overview of Compiler]()
2. [Sample Code]()
3. [Language Specs]()
  - [Variable Identifiers]()
  - [Function Identifiers]()
  - [Data Types]()
      - [Integer]()
      - [Real]()
      - [Record]()
      - [Union]()
      - [Global]()
      - [Type Definitions]()
  - [Functions]()

## Overview of a compiler

<img width="654" alt="Screenshot 2024-01-20 at 3 05 52 PM" src="https://github.com/AD-lite24/Compiler-Construction-Project/assets/96363931/3699e52c-5de3-4309-b023-febd37651dc6">

## Sample code

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

## Language Specs

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
#### **Integer type**: 
The keyword used for representing integer data type is int and will be supported by the
underlying architecture. A statically available number of the pattern [0-9][0-9]*
is of integer type.

#### **Real type**: 
The keyword used for representing integer data type is real and will be supported by the
underlying architecture. A statically available real number has the pattern [0-9][0-9]*
[.][0-9][0-9] and is of type real. The language also supports exponent and mantissa form of real number representation. The
regular expression for the same is [0-9][0-9]* [.][0-9][0-9] [E] [+|-| ∈] [0-9][0-9] restricting to exactly two
digits in the exponent part.

#### **Record type**: 
This isthe constructed data type of the form of the Cartesian product of types of its constituent
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

An assignment statement with variables from two different record types is not allowed in the language.
Also, once a record type is defined, its re-occurrence anywhere in the program is not allowed and is treated
as an error.
A variable of record type can only be multiplied or divided by a scalar (integer or real) i.e. two record type
variables cannot be multiplied together nor can be divided by the other. Two operands (variables) of record
type can be added, subtracted from one provided the types of the operands match and both the operands are of record type. An addition/subtraction means addition/subtraction of corresponding field values, for
Example :
```
type record #finance : d5;
type record #finance : c4;
type record #finance : c3;
c3 <--- c4 + d5;
```

#### Union Type: 

A union type is similar to record structure in its lexical formations other than the union
keyword used. For example

```
union #student
type int: rollno;
type real:marks;
type int: age;
endunion
```

As usual, the union data type refers to maximum of all fields memory allocation to the variables. Based on
your understanding of unions, it is understood that the static type checking is not possible and it leads to
spurious data access. In order to prevent the users from this situation, tagged union is supported in this
language where the tag is computed at run time. The tag is part of the variant record following the same
syntax as that of the record defining the (a) variant field as the union data type and (b) the fixed field of the
tag. The tag can be of any primitive type integer or real.

```
definetype union #student as #newname;
record #taggedunionexample
type int: tagvalue;
type newname: field;
endrecord
```

The tagged union variable is defined in the similar way as other variables are. For example

```
type record #taggedunionexample b7bc34;
```
The variable b7bc34 of type #taggedunionexample which is a variant record has a fixed field tagvalue of
integer type and the variant field of union type newname. The tagvalue field is used as

```
b7bc34.tagvalue = 1;
b7bc34. field.rollno = 23;
write(b7bc34. field.rollno); //No type error
write(b7bc34. field.marks); // Compiler reports the type error – dynamic type checking
b7bc34.tagvalue = 2;
b7bc34. field.marks = 97.5;
b7bc34.tagvalue = 3;
b7bc34. field.age = 21;
```

#### Global: 
This defines the scope of the variable as global and the variable specified as global is visible
anywhere in the code. The syntax for specifying a variable of any type to be global is as follows
`type int: c5d2: global;`

#### Type definition (Aliases): 
The language supports type redefinition using the keyword definetype for record
and union data type. For example
```
definetype union #student as #newname;
definetype record #book as #newbook;
```
Since record and union type definitions are visible anywhere in the program, their type definitions
representing equivalent names are also visible anywhere in the program. Hence, the type definition for other
records or unions cannot be type defined similar to the ones already defined.

### Functions 


