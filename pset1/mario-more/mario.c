#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pyramidSize = get_int("Define a pyramid height between 1 and 8 \n");
    while (pyramidSize < 1 || pyramidSize > 8)
    {
        pyramidSize =
            get_int("Define a pyramid height. IT MUST BE BETWEEN 1 AND 8"); // Wait for valid number
    }

    for (int i = 1; i <= pyramidSize; i++)
    {
        int line_size =
            i * 2 + 2; // The size of the line is dynamic - it depends on the position we are.

        if (i != pyramidSize)
        {
            for (int k = 0; k < pyramidSize - i; k++)
            {
                printf(" "); // Printing necessary spaces if not on last line.
            }
        }
        for (int j = 0; j < line_size; j++)
        {
            if (j == (i) || j == (i + 1))
            {
                printf(" "); // i is the middle of the string.
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    };
}
