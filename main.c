#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* AP();

int main()
{

    char *inputStream;
    char **words;
    char **sentence;
    int wordsCounter = 0;
    int sentenceCounter = 0;
    inputStream = malloc(10001*sizeof(char));


    char funq[5];
    do{
        gets(funq);

        if(strcmp(funq,"ap")== 0)
        {
            gets(inputStream);
            printf("%s",inputStream);
            inputStream =(char*) realloc(inputStream,strlen(inputStream)+1);
            words = malloc(10001*sizeof(char*));
            int startIndex = 0;
            for(int endIndex =0;endIndex<=strlen(inputStream);endIndex++)
            {
                if (inputStream[endIndex]==' ' || inputStream[endIndex]=='\0' || inputStream[endIndex]=='.' || inputStream[endIndex]=='!' || inputStream[endIndex]=='?' ||inputStream[endIndex]==';')
                {
                    words[wordsCounter] = malloc(5000*sizeof(char));
                    memcpy(words[wordsCounter],&inputStream[startIndex],(endIndex-startIndex)*sizeof(char));
                    words[wordsCounter][strlen(words[wordsCounter])]='\0';
                    //words[wordsCounter] = realloc(words[wordsCounter],strlen(words[wordsCounter])*sizeof(char) + 1);
                    printf("%s\n",words[wordsCounter]);
                    wordsCounter++;
                    startIndex = endIndex;

                }
            }
            words =  realloc(words,wordsCounter*sizeof(char*));
            sentence = malloc(10001*sizeof(char*));
            startIndex = 0;
            for(int endIndex =0;endIndex<strlen(inputStream);endIndex++)
            {
                if(inputStream[endIndex]=='.' || inputStream[endIndex]=='!' || inputStream[endIndex]=='?' ||inputStream[endIndex]==';')
                {
                    sentence[sentenceCounter] = malloc(10001*sizeof(char));
                    strncpy(sentence[sentenceCounter],&inputStream[startIndex],(endIndex-startIndex)*sizeof(char));
                    sentence[sentenceCounter][strlen(sentence[sentenceCounter])] = '\0';
                    sentence[sentenceCounter] = realloc(sentence[sentenceCounter],strlen(sentence[sentenceCounter])*sizeof(char) + 1);
                    printf("%s\n",sentence[sentenceCounter]);
                    sentenceCounter++;
                    startIndex = endIndex+1;

                }
            }
            sentence = realloc(sentence,sentenceCounter*sizeof(char*));
        }


    }while(strcmp(funq,"qt"));


    //printf("%s",input);

    return 0;

}
/*char* AP()
{
    return inputStream;

}
*/