#include<stdio.h>

int main()

{

    char s[100];
    char s1[] ={"Hello, World!"};

    int arr1[3] = {1,2,3};
    int arr2[3] = {1,2,3};
    int arr3[3] = *arr1;

    arr3[2] = 10;
    printf("%s",arr3);


    scanf("%[^\n]%*c", s); 
    printf("%s",s1);
    printf("\n");
    printf("%s",s);

    return 0;

}