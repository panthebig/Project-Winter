#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

    char *inputStream;
    char **words;
    char **sentence;
    char **wordsUnique;
    int wordsCounter = 0;
    int sentenceCounter = 0;
    inputStream = malloc(10001*sizeof(char));


    char funq[5];
    do{
        gets(funq);

        if(strcmp(funq,"ap")== 0)
        {
            fgets(inputStream,10000,stdin);
            inputStream[strcspn(inputStream,"\0")] = '\0';
            inputStream =(char*) realloc(inputStream,strlen(inputStream)+1);
            words = calloc(10001,sizeof(char*));
            int startIndex = 0;
            for(int endIndex =0;endIndex<=strlen(inputStream);endIndex++)
            {
                if (inputStream[endIndex]==' ' || endIndex == (strlen(inputStream)-1) || inputStream[endIndex]=='.' || inputStream[endIndex]=='!' || inputStream[endIndex]=='?' ||inputStream[endIndex]==';')
                {
                    words[wordsCounter] = calloc(5000,sizeof(char));
                    memcpy(words[wordsCounter],&inputStream[startIndex],(endIndex-startIndex)*sizeof(char));
                    words[wordsCounter][strlen(words[wordsCounter])]='\0';
                    words[wordsCounter] = realloc(words[wordsCounter],strlen(words[wordsCounter])*sizeof(char) + 1);
                    printf("%s\n",words[wordsCounter]);
                    wordsCounter++;
                    startIndex = endIndex + 1;

                }
            }

            printf("num of words %d",wordsCounter);

            words =  realloc(words,wordsCounter*sizeof(char*));
            sentence = calloc(5000,sizeof(char*));
            startIndex = 0;
            for(int endIndex =0;endIndex<strlen(inputStream);endIndex++)
            {
                if(inputStream[endIndex]=='.' || inputStream[endIndex]=='!' || inputStream[endIndex]=='?' ||inputStream[endIndex]==';' || endIndex == (strlen(inputStream)-1))
                {
                    sentence[sentenceCounter] = calloc(5000,sizeof(char));
                    strncpy(sentence[sentenceCounter],&inputStream[startIndex],(endIndex-startIndex)*sizeof(char));
                    sentence[sentenceCounter][strlen(sentence[sentenceCounter])] = '\0';
                    sentence[sentenceCounter] = realloc(sentence[sentenceCounter],strlen(sentence[sentenceCounter])*sizeof(char) + 1);
                    printf("%s\n",sentence[sentenceCounter]);
                    sentenceCounter++;
                    startIndex = endIndex+1;

                }
            }
            sentence = realloc(sentence,sentenceCounter*sizeof(char*));

            printf("num of seentences = %d",sentenceCounter);

        }else if(strcmp(funq,"fw")==0)
        {
            int wordsCounterUnique = 0;
            char exist;
            wordsUnique = calloc(wordsCounter,sizeof(char*));
            for(int i =0;i<wordsCounter;i++)
            {
                exist=0;
                for(int j = 0;j < wordsCounterUnique && !(exist);j++)
                {
                    if(strcmp(words[i],wordsUnique[j])==0)
                    {
                        exist = 1;
                    }
                }
                if(!(exist))
                {
                    wordsUnique[wordsCounterUnique] = calloc(strlen(words[i]),sizeof(char));
                    memcpy(wordsUnique[wordsCounterUnique],words[i],strlen(words[i])+1);
                    wordsCounterUnique++;
                }

            }
            printf("%d",wordsCounterUnique);
            for(int i =0;i<wordsCounterUnique;i++)
                printf("\n%s",wordsUnique[i]);
        }


    }while(strcmp(funq,"qt"));


    //printf("%s",input);

    return 0;

}
