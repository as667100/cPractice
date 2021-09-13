// Binary Search Tree - insert, search, tech
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct binTree{
    int var; 
    struct binTree *binLeft;
    struct binTree *binRight;
    struct binTree *binParent;
    
};

struct binTree* createBin(int var){

    struct binTree* newBin = (struct binTree*)malloc(sizeof(struct binTree));

    newBin->var = var;
    newBin->binLeft = NULL;
    newBin->binRight = NULL;
    newBin->binParent = NULL;

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

struct binTree* treeMinMax(struct binTree* origBin,bool status)
{
    if(!origBin){
        printf("error: the binTree does not exist\n");
        return NULL;
    }
    else{
        //true = min, false = max
        if (status){
            if (origBin->binLeft){
                return treeMinMax(origBin->binLeft,status);
            }
            else{
                //printf("min: %d\n",origBin->var);
                return origBin;
            }
        }
        else{
            if (origBin->binRight){
                return treeMinMax(origBin->binRight,status);
            }
            else{
                //printf("max: %d\n",origBin->var);
                return origBin;
            }
        }
    }
}

struct binTree* deleteBin(struct binTree* origBin,int key)
{
    struct binTree* newOrig;
    struct binTree* successor;
    // if node is found right away
    if(origBin == NULL){
        return origBin;
    }
    if (key == origBin->var){
        
        // best case: the key node does not have left or right -> implement the exist one to replace the original
        if (!(origBin->binLeft)){
            newOrig =origBin->binRight;
            //printf("original bin pointers: left - %x right - %x\n",origBin->binLeft,origBin->binRight);
            free(origBin);
            //printf("new: original bin pointers: left - %x right - %x\n",origBin->binLeft,origBin->binRight);
            return newOrig;
        } 
        else if (!(origBin->binRight)){
            newOrig =origBin->binLeft;
            free(origBin);
            return newOrig;
        }
        // worst case: the key node has left and right -> get the minimum from the right hand side (successor of the key)
        // replace the key of the original with the successor and delete successor one    
        else{
            successor = treeMinMax(origBin->binRight,true);
            origBin->var = successor->var;
            origBin->binRight = deleteBin(origBin->binRight,successor->var);
        }
        
    }
    //if key is smaller than the curreny key
    else if (key < origBin->var){
        origBin->binLeft = deleteBin(origBin->binLeft,key);
    }
    //if key is bigger than the curreny key
    else if (key > origBin->var){
        origBin->binRight = deleteBin(origBin->binRight,key);
    }
    return origBin;
    
};


struct binTree* insertBin(int var,struct binTree* origBin){

    //printf("empty? : %s \n",((origBin->binLeft)==NULL? "true":"false"));
    //printf("variable: %d \n",(origBin->binLeft)->var);

    struct binTree* res;

    if (!origBin){
        //printf("original binary tree does not exist/ var does not exist %d \n",var);
        return createBin(var);
    }else{
        if(origBin->var > var){ // right bin 
            res = insertBin(var,origBin->binLeft);
            origBin->binLeft = res;
            res->binParent = origBin;

        }else{
            res = insertBin(var,origBin->binRight);
            origBin->binRight = res;
            res->binParent = origBin;
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
            //printf("binary tree node %x, var %d \n",origBin,var);
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
            //printf("binary tree node %x, var %d \n",origBin,var);
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

