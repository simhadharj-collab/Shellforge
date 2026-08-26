#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "history.h"

int main(void)
{
    printf("=====================================\n");
    printf("          Shellforge\n");
    printf("     A Unix Style Shell in C\n");
    printf("=====================================\n");

    using_history();

    char *line;

    while (1)
    {
        line = readline("shellforge$ ");

        if (line == NULL)
        {
            printf("\nGoodbye!\n");
            break;
        }

        if (strlen(line) == 0)
        {
            free(line);
            continue;
        }

        /* Display command history */
        if (strcmp(line, "history") == 0)
        {
            print_history();
            free(line);
            continue;
        }

        /* Add command to history */
        add_history(line);

        printf("YOU ENTERED : %s\n", line);

        /* Exit shell */
        if (strcmp(line, "exit") == 0)
        {
            free(line);
            printf("Exiting...\n");
            break;
        }

        free(line);
    }

    return 0;
}
