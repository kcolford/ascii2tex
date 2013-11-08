/* This is a program that translates ascii text into plain TeX
   output. */

/* 
Copyright (C) 2013 Kieran Colford

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#include <stdio.h>

int main ()
{
  register char c;

  puts ("{\\tt");                     /* Use typewriter font. */
  puts ("\\noindent");

  while ((c = getchar ()) != EOF)
    {
      switch (c)
	{
	case ' ':
	  printf ("{\\kern0.500em}");
	  break;
	case '\t':
	  printf ("{\\kern4.000em}"); /* A tab is 8 spaces wide. */
	  break;
	case '\n':
	  puts ("\\hfill\n");
	  puts ("\\noindent");
	  break;
	  /* We type all of these cases out because it gives the
	     compiler a chance to generate a "switch table" which is
	     much more efficient than doing some sort search. */
	case '\\':
	case '$':
	case '&':                    
	case '{':
	case '}':
	case '#':
	case '~':
	case '`':
	case '_':
	case '^':
	case '"':
	case '%':
	  /* Certain characters aren't printed directly in TeX, so we
	     tell TeX to print them according to their ascii code. */
	  printf ("{\\char%d}", c); 
	  break;
	default:
	  putchar (c);
	  break; 
	}
    }

  puts ("}");

  return 0;
}
