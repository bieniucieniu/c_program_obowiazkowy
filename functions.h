#define NULL 0

#ifndef __FUNCTIONS__
#define __FUNCTIONS__



void CopeString(char pcSource[], char pcDestination[]) {
    for (short i = 0; pcSource[i] != NULL; i++) {
        pcDestination[i] = pcSource[i];
    }
}


void CopeStringWhile(char pcStr1[], char pcStr2[]) {

    short i = 0;
    do {
        pcStr2[i] = pcStr1[i++];
    } while (pcStr1[i]!=NULL);

    pcStr2[i] = NULL;
}


enum EEquivalent{NOTEQUEL, EQUEL};

enum EEquivalent eCompareStr(char str1[], char str2[]) {
    for (short i = 0; str1[i] != NULL || str2[i] != NULL; i++) {
        if(str1[i] != str2[i]) return NOTEQUEL;
    }
    return EQUEL;
}


void AppendString(char pcSourceStr[], char pcDestinationStr[]) {
    for (short i = 0; pcSourceStr[i] != NULL ; i++) {
        if(pcDestinationStr[i] == NULL){
            pcDestinationStr[i] = pcSourceStr[i];
        }
    }
}


void ReplaceCharactersInString(char str[],char cOldChar,char cNewChar) {
    for(short i = 0; str[i]!=NULL; i++){
        if(str[i] == cOldChar) str[i] = cNewChar;
    }
}

void IntToHexStr(unsigned int uiValue, char pcStr[]) {
    char hexs_numbers[17] = "0123456789ABCDEF";

    for (short i = 2; uiValue != NULL; i++){
        pcStr[i] = hexs_numbers[uiValue & 0b1111];
        uiValue = uiValue >> 4;
    }
    pcStr = pcStr+NULL;
}


void HexStringToUInt(char pcStr[], unsigned int *puiValue) {
    char __hexs_numbers[17] = "0123456789ABCDEF";

    puiValue = 0;
    for (short i = 2; pcStr[i] != NULL; i++) {
        for (short j = 0; __hexs_numbers[j] != NULL; j++) {
            if(pcStr[i] == __hexs_numbers[j]) {
                *puiValue = *puiValue << 4;
                *puiValue = (*puiValue | j);
                break;
            }
        }
    }
}

#endif