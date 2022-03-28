
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


enum CompResult {NOTEQUEL, EQUEL};

enum CompResult eCompareStr(char str1[], char str2[]) {
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

    for(char ucCharCounter = 0; ucCharCounter < 4; ucCharCounter++) {
        ucBuffer = uiValue & 0b1111;
        pcStr[5 - ucCharCounter] = ucBuffer < 10 ? '0' + ucBuffer : 'A' + ucBuffer - 10;
    }
}
enum Result { OK, ERROR };

enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue) {
    unsigned char ucBuffer;
    if ((pcStr[0] != '0' && pcStr[1] != 'x') || pcStr[2] != NULL) return ERROR;

    for (int i = 2; pcStr[i]; i++) {
        ucBuffer = pcStr[i];

        if(i > 6 || ((ucBuffer >= '0') && (ucBuffer <= '9')) || ((ucBuffer >= 'A') && (ucBuffer <= 'F'))) return ERROR;

        *puiValue = *puiValue << 4;
        *puiValue = ucBuffer < 'A' ? *puiValue = *puiValue | (ucBuffer - '0') : *puiValue | (pcStr[i] - 'A' + 10);
    }
    return OK;
    
}

#endif