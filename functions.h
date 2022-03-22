#define NULL 0

#ifndef __FUNCTIONS__
#define __FUNCTIONS__



void CopeString(char input_str[], char output_str[]) {

    short i;
    for (i = 0; input_str[i] != NULL; i++) {
        output_str[i] = input_str[i];
    }
    output_str[i] = NULL;
}


void CopeStringWhile(char input_str[], char output_str[]) {

    short i = 0;
    do {
        output_str[i] = input_str[i++];
    } while (input_str[i]!=NULL);

    output_str[i] = NULL;
}


enum EEquivalent{NOTEQUEL, EQUEL};

enum EEquivalent CompareStr(char str1[], char str2[]) {
    short i;
    for (i = 0; str1[i] != NULL; i++) {
        if(str1[i] != str2[i]) return NOTEQUEL;
    }
    if(str1[i] != str2[i]) return NOTEQUEL;

    return EQUEL;
}


void AppendString(char source_str[], char destination_str[]) {
    for (short i = 0; source_str[i] != NULL ; i++) {
        if(destination_str[i] == NULL){
            destination_str[i] = source_str[i];
        }
    }
}


void ReplaceCharactersInString(char str[],char old_char,char new_char) {
    for(short i = 0; str[i]!=NULL; i++){
        if(str[i] == old_char) str[i] = new_char;
    }
}

void IntToHexStr(unsigned int value, char output_str[]) {
    char hex_numbers[17] = "0123456789ABCDEF";

    for (short i = 2; value != NULL;){
        output_str[i++] = hex_numbers[value & 0b1111];
        value = value >> 4;
    }
    output_str = output_str+NULL;
}


void HexStringToUInt(char str[], unsigned int *output_num) {
    char hex_numbers[17] = "0123456789ABCDEF";

    output_num = 0;
    for (short i = 2; str[i] != NULL; i++) {
        for (short j = 0; hex_numbers[j] != NULL; j++) {
            if(str[i] == hex_numbers[j]) {
                *output_num = *output_num << 4;
                *output_num = (*output_num | j);
                break;
            }
        }
    }
}

#endif