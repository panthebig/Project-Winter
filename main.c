#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

    char *inputStream;
    char **words;
    char **sentence;
    char **wordsUnique;
    char **par;
    int wordsCounter = 0;
    int wordsCounterUnique = 0;
    int sentenceCounter = 0;
    int parCounter =0;
    wordsUnique = calloc(1000,sizeof(char*));
    par = calloc(1000,sizeof(char*));



    char funq[5];
    do{
        gets(funq);

        if(strcmp(funq,"ap")== 0)
        {
            wordsCounter = 0;
            sentenceCounter = 0;
            inputStream = malloc(10001*sizeof(char));

            fgets(inputStream,10000,stdin);
            inputStream[strcspn(inputStream,"\0")] = '\0';
            inputStream =(char*) realloc(inputStream,strlen(inputStream)+1);

            par[parCounter]=calloc(10000,sizeof(char));
            strcpy(par[parCounter],inputStream);
            par[parCounter] = realloc(par[parCounter],strlen(par[parCounter])+1);
            printf("\n this is a paragraph : %s",par[parCounter]);
            parCounter++;

            words = calloc(10001,sizeof(char*));
            int startIndex = 0;
            int endIndex ;
            for( endIndex =0;endIndex<=strlen(inputStream);endIndex++)
            {
                if (inputStream[endIndex]==' ' || endIndex == (strlen(inputStream)-1) || inputStream[endIndex]=='.' || inputStream[endIndex]=='!' || inputStream[endIndex]=='?' ||inputStream[endIndex]==';')
                {
                    words[wordsCounter] = calloc(5000,sizeof(char));
                    memcpy(words[wordsCounter],&inputStream[startIndex],(endIndex-startIndex)*sizeof(char));
                    words[wordsCounter][strlen(words[wordsCounter])]='\0';
                    words[wordsCounter] = realloc(words[wordsCounter],strlen(words[wordsCounter])*sizeof(char) + 1);
                    printf("%s\n",words[wordsCounter]);
                    wordsCounter++;
                    do{
                       endIndex++;
                    }while(!((inputStream[endIndex]>='a'&&inputStream[endIndex]<='z')|| (inputStream[endIndex]>='A'&&inputStream[endIndex]<='Z')));
                    startIndex=endIndex;


                }
            }

            printf("num of words %d",wordsCounter);

            words =  realloc(words,wordsCounter*sizeof(char*));
            sentence = calloc(5000,sizeof(char*));
            startIndex = 0;
            for( endIndex =0;endIndex<strlen(inputStream);endIndex++)
            {
                if(inputStream[endIndex]=='.' || inputStream[endIndex]=='!' || inputStream[endIndex]=='?' ||inputStream[endIndex]==';' || endIndex == (strlen(inputStream)-1))
                {
                    sentence[sentenceCounter] = calloc(5000,sizeof(char));
                    strncpy(sentence[sentenceCounter],&inputStream[startIndex],(endIndex-startIndex)*sizeof(char));
                    sentence[sentenceCounter][strlen(sentence[sentenceCounter])] = '\0';
                    sentence[sentenceCounter] = realloc(sentence[sentenceCounter],strlen(sentence[sentenceCounter])*sizeof(char) + 1);
                    printf("%s\n",sentence[sentenceCounter]);
                    sentenceCounter++;
                    do{
                       endIndex++;
                    }while(!((inputStream[endIndex]>='a'&&inputStream[endIndex]<='z')|| (inputStream[endIndex]>='A'&&inputStream[endIndex]<='Z')));
                    startIndex=endIndex;

                }
            }
            sentence = realloc(sentence,sentenceCounter*sizeof(char*));

            printf("num of seentences = %d",sentenceCounter);

            char exist;
            //wordsUnique = malloc((wordsCounter+wordsCounterUnique)*sizeof(char*));
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
            printf("\n%d\n",wordsCounterUnique);

            free(words);
            free(sentence);
            free(inputStream);


        }else if(strcmp(funq,"fw")==0)
        {
            char* fw;
            fw = calloc(1001,sizeof(char));
            fgets(fw,1000,stdin);
            fw = realloc(fw ,sizeof(char)*strlen(fw)+1);
            fw[strcspn(fw,"\n")]='\0';


            for(int i =0;i<wordsCounterUnique;i++)
                if(strstr(wordsUnique[i],fw)!= NULL)
                    printf("%s\n",wordsUnique[i]);

            free(fw);

        }else if(strcmp(funq,"fs")==0)
        {
            char* fs;
            fs = calloc(1001,sizeof(char));
            fgets(fs,1000,stdin);
            fs = realloc(fs ,sizeof(char)*strlen(fs)+1);
            fs[strcspn(fs,"\n")]='\0';

            for(int i =0;i<sentenceCounter;i++)
                if(strstr(sentence[i],fs)!=NULL)
                    printf("%s\n",sentence[i]);

            free(fs);

        }else if(strcmp(funq,"fp")==0)
        {
            char* fp;
            fp = calloc(1001,sizeof(char));
            fgets(fp,1000,stdin);
            fp = realloc(fp ,sizeof(char)*strlen(fp)+1);
            fp[strcspn(fp,"\n")]='\0';

            for(int i =0;i<parCounter;i++)
                if(strstr(par[i],fp)!=NULL)
                    printf("%s",par[i]);

            free(fp);

        }


    }while(strcmp(funq,"qt"));


    //printf("%s",input);

    return 0;

}
