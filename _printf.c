#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    //initialize list variables
    va_list args;

    //initializes args variable
    //to be used with the va_arg and va_end
    va_start(args, format);

    //initialize counter to count number of chars
    int count = 0, num;

    //to get arguement from va_arg
    char ch;

    //while string not equal null
    while (*format)
    {
        //when string is equal to modules
        if (*format == '%')
        {
            //now move to next char
            format++;

            //if the next char of modules also equal to modules
            if (*format == '%')
            {
                //then print modules
                putchar('%');

                //increment the counter which mean this first char in string
                count++;
            }

            //if the format equal to char
            else if (*format == 'c')
            {
                //then get argument which type is int
                ch = va_arg(args, int);

                //print this char
                putchar(ch);

                //increment counter
                count++;
            }

            //if the format is string
            else if (*format == 's')
            {
                //then get string from user
                char *str = va_arg(args, char *);

                //to get the length of string
                while (*str)
                {
                    putchar(*str++);
                    count++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                num = va_arg(args, int);
                count += printf("%d", num);
            }
        }
        //if the format not char or string
        else
        {
            //print it
            putchar(*format);

            //and count it
            count++;
        }

        //increment pointer to next char
        format++;
    }

    //now end the list
    va_end(args);

    //return the number of string
    return count;
}

int main(void)
{
    int len;
    int len2;
    //unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    //ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    //_printf("Unsigned:[%u]\n", ui);
    //printf("Unsigned:[%u]\n", ui);
    //_printf("Unsigned octal:[%o]\n", ui);
    //printf("Unsigned octal:[%o]\n", ui);
    // _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    // printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    //printf("Unknown:[%r]\n");
    return (0);
}
