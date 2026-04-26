#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
FILE *fp = fopen("input.txt", "r");
FILE *inter = fopen("intermediate.txt", "w");
char line[100], label[20], opcode[20],operand[20];
char sym[20][20];
int addr[20], symcount = 0;
int locctr = 0, start = 0, count, length;
printf("PASS 1:\n");
while (fgets(line, sizeof(line), fp)) {
    count = sscanf(line, "%s %s %[^\n]", label, opcode, operand);
    if (count == 1) {
        strcpy(opcode, label);
        strcpy(label, "-");
        strcpy(operand, "-");
    } else if (count == 2) {
        strcpy(operand, opcode);
        strcpy(opcode, label);
        strcpy(label, "-");
    }
    if (strcmp(opcode, "START") == 0) {
        start = (int)strtol(operand, NULL, 16);
        locctr = start;
        length = 0;
        fprintf(inter, "%X %d %s %s %s\n",locctr, length, label, opcode, operand);
        continue;
    }
    if (!strcmp(opcode, "END")) {
        length = 0;
        fprintf(inter, "%X %d %s %s %s\n",
        locctr, length, label, opcode, operand);
        break;
    }
    if (strcmp(label, "-") != 0) {
        int found = 0;
        for (int i = 0; i < symcount; i++)
            if (!strcmp(sym[i], label)) found = 1;
        if (found)
        printf("ERROR: Duplicate symbol %s\n", label);
        else {
            strcpy(sym[symcount], label);
            addr[symcount++] = locctr;
        }
    }
    
    if (!strcmp(opcode,"LDA")|| !strcmp(opcode,"STA") ||!strcmp(opcode,"ADD")|| !strcmp(opcode,"SUB") ||!strcmp(opcode,"RSUB")) {
        length = 3;
    }
    else if (!strcmp(opcode,"WORD")) {
        length = 3;
    }
    else if (!strcmp(opcode,"RESW")) {
        length = 3 * atoi(operand);
    }
    else if (!strcmp(opcode,"RESB")) {
        length = atoi(operand);
    }
    else if (!strcmp(opcode,"BYTE")) {
        if (operand[0] == 'C')
            length = strlen(operand) - 3;
        else
            length = (strlen(operand) - 3) / 2;
    }
    else {
        printf("ERROR: Invalid opcode %s\n",
        opcode);
        length = 0;
    }
    fprintf(inter, "%X %d %s %s %s\n", locctr,length, label, opcode, operand);
    locctr += length;
}
printf("\nProgram Length = %X\n", locctr -start);
printf("\nSYMTAB:\n");
FILE *symfile = fopen("symtab.txt", "w");
for (int i = 0; i < symcount; i++) {
    printf("%s\t%X\n", sym[i], addr[i]);
    fprintf(symfile, "%s %X\n", sym[i],addr[i]);
}
fclose(symfile);
fclose(fp);
fclose(inter);
return 0;
}