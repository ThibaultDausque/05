#include "bsq.h"

int ft_atoi(char *line)
{
    int    i;
    int    result;

    i = 0;
    while (line[i] && line[i] >= '0' && line[i] <= '9')
    {
        result = line[i] - '0';
        result *= 10;
        i++;
    }
    return result;
}

int ft_strlen(char *line)
{
    int     i;

    i = 0;
    while (line[i])
        i++;
    return i;
}

char*   ft_strcat(char *line, int start, int end)
{
    char    *result;
    int        len;
    int         i;


    len = end - start;

    result = (char *)malloc(len * sizeof(char));
    if (!result)
        return NULL;
    i = 0;
    while (start < end)
    {
        result[i] = line[i];
        start++;
        i++;
    }
    result[i] = '\0';
    return result;
}