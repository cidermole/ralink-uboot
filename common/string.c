// TODO: copied a few relevant routines from original u-boot: lib_bootstrap/string.c, this should be integrated there, where it belongs...

#include <linux/types.h>
#include <linux/string.h>
#include <linux/ctype.h>
#include <malloc.h>


/**
 * strcat - Append one %NUL-terminated string to another
 * @dest: The string to be appended to
 * @src: The string to append to it
 */
char * strcat(char * dest, const char * src)
{
   char *tmp = dest;

   while (*dest)
      dest++;
   while ((*dest++ = *src++) != '\0')
      ;

   return tmp;
}

/**
 * strncat - Append a length-limited, %NUL-terminated string to another
 * @dest: The string to be appended to
 * @src: The string to append to it
 * @count: The maximum numbers of bytes to copy
 *
 * Note that in contrast to strncpy, strncat ensures the result is
 * terminated.
 */
char * strncat(char *dest, const char *src, size_t count)
{
   char *tmp = dest;

   if (count) {
      while (*dest)
         dest++;
      while ((*dest++ = *src++)) {
         if (--count == 0) {
            *dest = '\0';
            break;
         }
      }
   }

   return tmp;
}

char * strdup(const char *s)
{
   char *new;

   if ((s == NULL)   ||
       ((new = malloc (strlen(s) + 1)) == NULL) ) {
      return NULL;
   }

   strcpy (new, s);
   return new;
}