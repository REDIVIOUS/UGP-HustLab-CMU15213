/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */


/* We do not support C11 <threads.h>.  */
/* 
 *   lsbZero - set 0 to the least significant bit of x 
 *   Example: lsbZero(0x87654321) = 0x87654320
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 1
 */

/*
实现思路如下：
1.设置一个mask，将最低位为0，其它各位为1。
2.将x和这个mask相与，将x最低位置0
*/
int lsbZero(int x) {
  int mask = (1 << 31) >> 30;
  return x & mask;
}



/* 
 * byteNot - bit-inversion to byte n from word x  
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByteNot(0x12345678,1) = 0x1234A978
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */

/*
实现思路如下：
1.先给定一个mask，是8个1。
2.将n左移三位，等于将n乘以8。将mask左移n乘以8之后的数值，将8个1移动到对应的位置。
3.和1异或相当于翻转，x和2中的结果进行异或实现对应位翻转，并返回。
*/
int byteNot(int x, int n) {
  int mask = 0xff;
  return x ^ (mask << (n << 3));
}



/* 
 *   byteXor - compare the nth byte of x and y, if it is same, return 0, if not, return 1

 *   example: byteXor(0x12345678, 0x87654321, 1) = 1

 *			  byteXor(0x12345678, 0x87344321, 2) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2 
 */

/*
实现思路如下：
1.给定一个mask为0xff(即是8个1)
2.将这8个1放到要比较的位置上（方法和上一个函数相同）
3.分别将x和y与这个函数相与，只留下要比较的8位数值
4.将得到的结果进行异或，若相同，得到的结果为0，若不同得到的结果不为0，再用两个！运算实现不为0的时候输出为1，为0的时候输出为0
*/
int byteXor(int x, int y, int n) {
  int mask = 0xff;
  int xl = x & (mask << (n << 3));
  int yl = y & (mask << (n << 3));
  return !(!(xl ^ yl));
}



/* 
 *   logicalAnd - x && y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */

/*
实现思路：
1.分别取x和y的逻辑非，判断x和y是否为0（若为0逻辑非为1，若为1逻辑非为0）
2.将这两个逻辑非相或，然后再取逻辑非。（德摩根定律）
*/
int logicalAnd(int x, int y) {
  return !((!x) | (!y));
}



/* 
 *   logicalOr - x || y
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */

/*
实现思路：
1.分别取x和y的逻辑非，判断x和y是否为0（若为0逻辑非为1，若为1逻辑非为0）
2.将这两个逻辑非相与，然后再取逻辑非。（德摩根定律）
*/
int logicalOr(int x, int y) {
  return !((!x) & (!y));
}



/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */

/*
实现思路如下：
1.设置一个mask1，将最高n位置1，其余各位置0
2.设置一个mask2，为32-n的值
3.设置一个mask3，低n位为1，其余各位为0
4.取高n位，即将x和mask1相与，右移（32-n）位，和mask3相与，将高n位取到了低n位，其余各位为0，即为highn
5.将x左移n为和highn相或得到结果
*/
int rotateLeft(int x, int n) {
  int mask1 = ((1 << 31) >> n) << 1;
  int mask2 = 32 + (~n) + 1;
  int mask3 = ~((~(0 << 31)) << n);
  int highn = ((x & mask1) >> mask2) & mask3;
  int xl = x << n;
  return highn | xl;
}



/*
 * parityCheck - returns 1 if x contains an odd number of 1's
 *   Examples: parityCheck(5) = 0, parityCheck(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */

/*
实现思路如下：
1.设置一个mask1，使得低16位为1，高16位为0。
2.若有奇数个1，则x每一位异或得到的值为1，否则为0，利用这个结论，且用divide and conquer的思想解决这个问题。
3.将x右移16位和x异或，和mask1相与，完成第一次异或（处理了16次异或），记结果为div16（16位）。
4.将div16右移8位和div16异或，再和0xff相与，完成第二次异或（处理了8次异或），结果为div8（8位）。
5.以此类推，直到最后的结果只剩下一位，即div1，即为输出的结果。
*/
int parityCheck(int x) {
  int mask1 = (0xff << 8) | 0xff; 
  int div16 = ((x >> 16) ^ x) & mask1;
  int div8 = ((div16 >> 8 ) ^ div16) & 0xff;
  int div4 = ((div8 >> 4) ^ div8) & 0x0f;
  int div2 = ((div4 >> 2) ^ div4) & 0x03;
  int div1 = ((div2 >> 1) ^ div2) & 1;
  return div1;
}



/*
 * mul2OK - Determine if can compute 2*x without overflow
 *   Examples: mul2OK(0x30000000) = 1
 *             mul2OK(0x40000000) = 0
 *         
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2
 */

/*
实现思路如下：
1.将1左移31位，使得最高位为1，其余都为0，记这个数为mask1。
2.将x和mask相与，判断x最高位是否为1。若为1则sign1的最高位为1，其余为0；若不为1则sign1全为0.
3.将x乘以2（左移1位之后）和mask1相与，以和2中相同的方式判断结果是否为最高位是否为1，记得到的数为sign2.
3.sign1和sign2若相同，则表示x和2*x的符号为相同，无溢出，否则有溢出。
4.将sign1和sign2异或并左移31位，若sign1和sign2相同，结果为32个0，否则为32个1，将这个结果和1相与，取最低位。最后将此与1进行异或得到结果。
*/
int mul2OK(int x) {
  int mask1 = 1 << 31;
  int sign1 = x & mask1;
  int sign2 = (x << 1) & mask1;
  int s = (((sign1 ^ sign2) >> 31) & 1) ^ 1;
  return s;
}



/*
 * mult3div2 - multiplies by 3/2 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/2),
 *   including overflow behavior.
 *   Examples: mult3div2(11) = 16
 *             mult3div2(-9) = -13
 *             mult3div2(1073741824) = -536870912(overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */

/*
实现思路如下：
1.首先将x乘以3，即3个x相加，记为y。定义一个mask，它的最高位为1，其余各位为0，即1向左移动31位。
2.判断最高位是否为1，若为1就是负数。实现方法是将y和mask相与然后左移31位，若小于0，则为32个1，否则为32个0。
3.将2中移位过后的结果和1相与，记为z，若小于0则z=1，若大于0则z=0。
4.小于0的时候要将y加上1再除以2（因为是负数，向下取整），若是大于0则不用加1，即式子为y+z之后向左边移动一位得到结果。
*/
int mult3div2(int x) {
  int y = x + x + x;
  int mask = 1 << 31;
  int z = ((y & mask) >> 31) & 1;
  int w = (y+z) >> 1;
  return w;
}



/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */

/*
实现思路如下：
1.首先计算x-y，存在变量sum里。
2.设置一个mask，最高位为1，其余各位为0。
3.将x，y，sum分别和mask相与，得到x，y，sum的符号位（存在最高位），分别记为sx，sy，ss。
4.如果被减数和减数的符号不同且被减数和商的符号不同，则会溢出，即将sx和sy相异或然后与上sx和ss的异或。
5.将上述结果取非，得到结果。
*/
int subOK(int x, int y) {
  int sum = x + (~y) + 1;
  int mask = 1 << 31;
  int sx = (x & mask);
  int sy = (y & mask);
  int ss = (sum & mask);
  int of = !((sx ^ sy) & (sx ^ ss));
  return of;
}



/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */

/*
实现思路如下：
1.首先取出符号位。设置一个mask，最高位为1，其余各位为0，将x和这个mask相与，右移31位，记为s。若符号位为1，则s全为1，否则全为0。
2.将s和1相与，取出符号位，记为n。
3.若为负数则x取反加一，若为正数则不变。最方便的方法就是将x和s异或再加上n，得到结果。
*/
int absVal(int x) {
  int mask = 1 << 31;
  int s = (x & mask) >> 31;
  int n = s & 1;
  return (x ^ s) + n;
}



/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */

/*
实现思路如下：
1.我们将uf的最高位置0，即让它和最高位是0其余位为1的数相与，记为z。
2.判断其阶码是否大于255，若大于255，则直接返回uf，否则返回z。
*/
unsigned float_abs(unsigned uf) {
  unsigned mask1 = ~(1<<31); 
  unsigned abs = uf & mask1;
  unsigned jiema = 0xff << 23;
  if(abs > jiema)
  {
    return uf;
  }
  return abs;
}



/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */

/*实现思路如下：
1.首先取尾数，放在低23位，第24位置1，得到数x。
2.取出阶码，放在低8位。
3.若阶码大于158，则得到的整数int整形放不下，会溢出，这时候输出0x80000000
4.若阶码小于127，则证明整数部分是0，输出0。
5.其他情况下，判断阶码是否大于150（因为我们取尾数的时候已经放在了低23位，所以判断127+23=150的阶码）；若大于150，则x向左移动“阶码-150”位；否则向右移动“150-阶码”位，记得到的数为y。
6.判断uf符号位是否为1，若为1，则y取反加1，输出；否则直接输出y。
*/
int float_f2i(unsigned uf) {
  int x = (uf & 0x007fffff) ^ (1 << 23);
  int jiema = (uf & 0x7f800000) >> 23;
  int y,sign;
  if(jiema > 158)
  {
    int overf = 0x80000000;
    return overf;
  }
  else if (jiema < 127)
  {
    int zero = 0;
    return zero;
  }
  else
  {
    if(jiema > 150)
    {
      y = x << (jiema - 150);
    }
    else
    {
      y = x >> (150 - jiema);
    }
    sign = (uf >> 31) & 1;
    if(sign == 1)
    {
      y = ~y + 1;
    }
    return y;
  }
}
