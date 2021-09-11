// Binary Search Tree - insert, search, tech
#include <stdio.h>
#include <stdlib.h>

struct binTree{
    int var; 
    struct binTree *binLeft;
    struct binTree *binRight;
};

struct binTree* createBin(int var){

    struct binTree* newBin = (struct binTree*)malloc(sizeof(struct binTree));

    newBin->var = var;
    newBin->binLeft = NULL;
    newBin->binRight = NULL;

    return newBin;

};

struct binTree* search(int var, struct binTree* origBin) {
    if (!(origBin)) {
        printf("original binary tree does not exist/ var does not exist: var is %d \n",var);
        return origBin;
    }
    else {
        if(origBin->var < var ) {
            return search(var, origBin->binRight);
        }
        else if (origBin->var > var) {
            return search(var, origBin->binLeft);
        }
        else {
            printf("found\n");
            return origBin;
        }
    }
}

struct binTree* insertBin(int var,struct binTree* origBin){

    //printf("empty? : %s \n",((origBin->binLeft)==NULL? "true":"false"));
    //printf("variable: %d \n",(origBin->binLeft)->var);
    if (!origBin){
        printf("original binary tree does not exist/ var does not exist %d \n",var);
        return createBin(var);
    }else{
        if(origBin->var > var){ // right bin 
            origBin->binLeft = insertBin(var,origBin->binLeft);
        }else{
            origBin->binRight = insertBin(var,origBin->binRight);
        }
        return origBin;
    }
};

struct binTree* checkRightBin(int var,struct binTree* origBin){

    //checking right side of the treeeee
    if (!origBin){
        printf("original binary tree does not exist/ end of the tree %x \n",origBin);
        return origBin;
    }else{
        if(origBin->var > var){ // right bin 
            printf("error: smaller value appeared \n");
        }else if (origBin->var < var){
            if(!origBin->binRight){
                printf("end of tree \n");
            }else{
                checkRightBin(var,origBin->binRight);
            }
        }else{
            printf("binary tree node %x, var %d \n",origBin,var);
            if(!origBin->binRight){
                printf("end of tree \n");
            }else{
                var = origBin->binRight->var;
                checkRightBin(var,origBin->binRight);
            }
        }
        return origBin;
    }
};

struct binTree* checkLeftBin(int var,struct binTree* origBin){

    //checking left side of the treeeee
    if (!origBin){
        printf("original binary tree does not exist/ end of the tree %x \n",origBin);
        return origBin;
    }else{
        if(origBin->var < var){ // left bin 
            printf("error: bigger value appeared \n");
        }else if (origBin->var > var){
            if(!origBin->binLeft){
                printf("end of tree \n");
            }else{
            checkLeftBin(var,origBin->binLeft);
            }
        }else{
            printf("binary tree node %x, var %d \n",origBin,var);
            if (!origBin->binLeft){
                printf("end of tree \n");
            }else{
                var = origBin->binLeft->var;
                checkLeftBin(var,origBin->binLeft);
            }
        }
        return origBin;
    }
};

int main(){

    //create the root bin tree first
    struct binTree* root= createBin(10);
    
    //insert values and create tree - currently only have right roots 
    printf("root: %x \n",root);

    for (int i =9;i>0;i--){
        insertBin(i,root);
    }
    printf("root: %x \n",root);

    //search for the specific values
    for (int i = 0;i<11;i++){
        printf("search for %d \n",i);
        search(i,root);
    }

    checkRightBin(1,root);
    checkLeftBin(10,root);

    


    printf("%s","hellllllo");
}