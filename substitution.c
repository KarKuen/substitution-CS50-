#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    else
    {
        for (int x = 0, i = strlen(argv[1]); x < i; x++)
        {
            if ((!(argv[1][x] >= 65 && argv[1][x] <= 90)) && (!(argv[1][x] >= 97 && argv[1][x] <= 122)))
            {
                printf("Key must contain alphabets\n");
                return 1;
            }
            else
            {
                char unique[strlen(argv[1])];
                for (int y = 0, j = strlen(argv[1]); y < j; y++)
                {
                    unique[y] = argv[1][y];
                }
                for (int z = 0, k = strlen(argv[1]); z < k; z++)
                {
                    int counter = 0;
                    for (int a = 0, b = strlen(argv[1]); a < b; a++)
                    {
                        if (argv[1][z] == unique[a])
                        {
                            counter = counter + 1;
                            if (counter > 1)
                            {
                                printf("Key must contain unique alphabets\n");
                                return 1;
                            }

                        }
                    }
                }
            }
        }
    }
    //check if its an alphabet
    //check if each letter only appears once

    string plain = get_string("plaintext: ");


    for (int x = 0, i = strlen(plain); x < i; x++)
    {
        if (plain[x] >= 65 && plain[x] <= 90)
        {
            plain[x] = toupper(argv[1][(plain[x] - 65)]);
        }

        else if (plain[x] >= 97 && plain[x] <= 122)
        {
            plain[x] = tolower(argv[1][(plain[x] - 97)]);
        }
        else
        {
            plain[x] = plain[x];
        }
    }

    printf("ciphertext: %s\n", plain);
    return 0;
}


