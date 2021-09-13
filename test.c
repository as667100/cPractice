#include "binSearch.c"

int main(){

    //for testing purpose: create the file and write the inputs
    FILE *fp;

    fp = fopen("test.txt", "w");
    
    
    //create the root bin tree first
    struct binTree* root =NULL;
    int rN;
    //insert values and create tree - currently only have right roots 
    printf("root: %x \n",root);

    for (int i =100000;i>0;i--){
        rN = rand() % 100000;
        printf("%d ",rN);
        root = insertBin(rN,root);
    }
    printf("\nroot: %x \n",root);

    // //create the root bin tree first
    // struct binTree* root2= createBin(0);
    
    // //insert values and create tree - currently only have right roots 
    // printf("root: %x \n",root2);

    // for (int i =1;i<10;i++){
    //     insertBin(i,root2);
    // }
    // printf("root: %x \n",root2);

    // //search for the specific values
    // for (int i = 0;i<11;i++){
    //     printf("search for %d \n",i);
    //     search(i,root);
    // }

    checkRightBin(root->var,root);
    checkLeftBin(root->var,root);
    // checkRightBin(0,root2);
    // checkLeftBin(0,root2);

    // int testVal;
    // if(root->binLeft->var){
    //     testVal = root->binRight->var;
    // }
    // else{
    //     testVal = root->binLeft->var;
    // }

    
    for (int i =100000;i>0;i--){
        //printf("test value is %d\n",root->var);
        fprintf(fp,"%d ",root->var);
        root = deleteBin(root,root->var);
        //printf("new root value is %d\n",root?root->var:-898);
    }
    printf("max: %d\n",treeMinMax(root,false)?treeMinMax(root,false)->var:-898);
    printf("min: %d\n",treeMinMax(root,true)?treeMinMax(root,true)->var:-898);
    
    fclose(fp);
    

    printf("%s","\nend of main");
}