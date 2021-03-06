/* This file is part of KDevelop
   Copyright 2012 Olivier de Gaalon <olivier.jg@gmail.com>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include <stdarg.h>

class A {};

int last(int argc, ...)
{
  va_start(vl,argc);
  // "type" : { "toString" : "int" }
  int one = va_arg(vl, int);
  // "type" : { "toString" : "int" }
  auto two = va_arg(vl, int);
  // "type" : { "toString" : "A" }
  A three = va_arg(vl, A);
  // "type" : { "toString" : "A" }
  auto four = va_arg(vl, A);
  // "type" : { "toString" : "char*" }
  char *five = va_arg(vl, char *);
  // "type" : { "toString" : "char*" }
  auto six = va_arg(vl, char *);
  va_end(vl);
  return va_arg(vl, int);
}
