#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    // File pointers to handle input and output files
    FILE *f1, *f2, *f3, *f4;

    // Character arrays to store labels, opcodes, and operands
    char s[100], lab[30], opcode[30], opa[30], opcode1[30], opa1[30];

    // Integer variables for location counter and flag
    int locctr, x = 0;

    // Open files for reading and writing
    f1 = fopen("input.txt", "r");          // Source code file
    f2 = fopen("opcode.txt", "r");         // Opcode table
    f3 = fopen("intermediate.txt", "w");   // Intermediate file
    f4 = fopen("symtab.txt", "w");         // Symbol table

    // Read each line from input file until EOF
    while (fscanf(f1, "%s%s%s", lab, opcode, opa) != EOF)
    {
        // Check if the line has no label
        if (strcmp(lab, "**") == 0)
        {
            // If opcode is "START", initialize location counter
            if (strcmp(opcode, "START") == 0)
            {
                locctr = atoi(opa); // Set location counter to starting address
                fprintf(f3, "%s %s %s", lab, opcode, opa);  // Write to intermediate file
                printf("%s %s %s\n", lab, opcode, opa);     // Print to console
            }
            else
            {
                rewind(f2); // Rewind opcode file
                x = 0;

                // Search for opcode in the opcode table
                while (fscanf(f2, "%s%s", opcode1, opa1) != EOF)
                {
                    if (strcmp(opcode, opcode1) == 0)
                    {
                        x = 1; // Set flag if opcode found
                        break;
                    }
                }

                // If opcode found, write to intermediate file and increment location counter
                if (x == 1)
                {
                    fprintf(f3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                    printf("%d %s %s %s\n", locctr, lab, opcode, opa); // Print to console
                    locctr += 3; // Increment locctr by 3 for a typical instruction
                }
            }
        }
        else
        {
            // Handle assembler directives or data allocation

            if (strcmp(opcode, "RESW") == 0)  // Reserve Words (3 bytes each)
            {
                fprintf(f3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                fprintf(f4, "\n%d %s", locctr, lab);  // Write to symbol table
                printf("%d %s %s %s\n", locctr, lab, opcode, opa); // Print to console
                locctr += 3 * atoi(opa); // Increment locctr by 3 * operand value
            }
            else if (strcmp(opcode, "WORD") == 0) // Define a word (3 bytes)
            {
                fprintf(f3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                fprintf(f4, "\n%d %s", locctr, lab);  // Write to symbol table
                printf("%d %s %s %s\n", locctr, lab, opcode, opa); // Print to console
                locctr += 3; // Increment locctr by 3 bytes
            }
            else if (strcmp(opcode, "BYTE") == 0) // Define a byte
            {
                fprintf(f3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                fprintf(f4, "\n%d %s", locctr, lab);  // Write to symbol table
                printf("%d %s %s %s\n", locctr, lab, opcode, opa); // Print to console
                locctr += 1; // Increment locctr by 1 byte
            }
            else if (strcmp(opcode, "RESB") == 0) // Reserve Bytes
            {
                fprintf(f3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                fprintf(f4, "\n%d %s", locctr, lab);  // Write to symbol table
                printf("%d %s %s %s\n", locctr, lab, opcode, opa); // Print to console
                locctr += atoi(opa); // Increment locctr by the operand value
            }
            else
            {
                // Default case: treat as machine instruction
                fprintf(f3, "\n%d %s %s %s", locctr, lab, opcode, opa);
                fprintf(f4, "\n%d %s", locctr, lab);  // Write to symbol table
                printf("%d %s %s %s\n", locctr, lab, opcode, opa); // Print to console
                locctr += 3; // Increment locctr by 3 for machine instruction
            }
        }
    }

    // Close all files
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
}
