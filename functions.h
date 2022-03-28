
#ifndef __FUNCTIONS__
#define __FUNCTIONS__
#define NULL 0



void CopeString(char pcSource[], char pcDestination[]) {

    unsigned char ucCharCounter;
    for (ucCharCounter = 0; pcSource[ucCharCounter]; ucCharCounter++) {
        pcDestination[ucCharCounter] = pcSource[ucCharCounter];
    }
    pcDestination[ucCharCounter] = pcSource[ucCharCounter];
}


enum EEquivalent{NOTEQUEL, EQUEL};

enum EEquivalent eCompareStr(char str1[], char str2[]) {
    for (unsigned char ucCharCounter = 0; str1[ucCharCounter] || str2[ucCharCounter]; ucCharCounter++) {
        if(str1[ucCharCounter] != str2[ucCharCounter]) return NOTEQUEL;
    }
    return EQUEL;
}


void AppendString(char pcSourceStr[], char pcDestinationStr[]) {
    unsigned char ucCharCounter = 0;
    for (ucCharCounter = 0; pcDestinationStr[ucCharCounter] != NULL ; ucCharCounter++);
    CopeString(pcSourceStr, pcDestinationStr + ucCharCounter);
}


void ReplaceCharactersInString(char str[],char cOldChar,char cNewChar) {
    for(short i = 0; str[i]; i++){
        if(str[i] == cOldChar) str[i] = cNewChar;
    }
}

void UIntToHexStr(unsigned int uiValue, char pcStr[]) {
    pcStr[0] = '0';
    pcStr[1] = 'x';
    pcStr[6] = NULL;

    unsigned char ucBuffer;

    for(char i = 0; i < 4; i++) {
        ucBuffer = uiValue & 0b1111;
        pcStr[5 - i] = ucBuffer < 10 ? '0' + ucBuffer : 'A' + ucBuffer - 10;
    }
}


void eHexStringToUInt(char pcStr[], unsigned int *puiValue) {

}

#endif