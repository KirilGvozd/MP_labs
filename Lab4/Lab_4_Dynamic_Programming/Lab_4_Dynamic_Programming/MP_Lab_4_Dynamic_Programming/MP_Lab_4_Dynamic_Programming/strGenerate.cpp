#include "strGenerate.h"
#include <cstdlib>
#include <ctime>
namespace strGenerate
{
	char* strGenerate(int length)
	{
       
        char* str = new char[length + 1];
        
        for (int i = 0; i < length; i++) {
            int symbol_cod = (int)(((double)rand() / (double)RAND_MAX) * (122. - 65.) + 65.);
            if (symbol_cod > 90 && symbol_cod < 97)
            {
                i--;
                continue;
            }
            str[i] = (char)symbol_cod;
        }
        str[length] = '\0';
        return str;
	}
}

