#include <stdio.h>
#include <stdlib.h>

struct binTree{
    int var; 
    struct binTree *binLeft;
    struct binTree *binRight;
};

struct binTree* createBin(int var){

    struct binTree* newBin = (struct binTree*)malloc(sizeof(struct binTree));

    newBin -> var = var;
    newBin -> binLeft = NULL;
    newBin -> binRight = NULL;

    return newBin;

};
struct binTree* insertBin(int var,struct binTree* origBin){

    printf("empty? : %s \n",((origBin->binLeft)==NULL? "true":"false"));
    //printf("variable: %d \n",(origBin->binLeft)->var);
    if (!(origBin->var)){
        printf("original binary tree does not exist/ var does not exist");
        return createBin(var);
    }else{
        if(origBin->var > var){ // right bin 
            if (origBin->binRight){
            printf("original binary alredy have right branch filled \n");
            return origBin;
            }else{
                return origBin;
            }

        }else{
            if (origBin->binLeft){
            printf("original binary alredy have left branch filled \n");
            return origBin;
            }else{
                return origBin;
            }

        }
    }

    

};

int main(){

    struct binTree* root= createBin(1);
    //root->binLeft = createBin(2);
    
    //for (int i =2;i<10;i++){
    insertBin(2,root);
    //}
    printf("%d \n",root->binRight);

    printf("%s","hellllllo");
}