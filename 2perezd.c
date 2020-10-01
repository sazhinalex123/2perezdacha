#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
int main(void){
double**arr;
int a,b,i,j;
double tmp;
int u;
FILE*input_file;
FILE*output_file;
output_file=fopen("data.res","w");
input_file=fopen("data.dat","r");
if(input_file==NULL){
    return -2;
}
if(output_file==NULL){
    return -3;
}

if(fscanf(input_file,"%d%d",&a,&b)!=2){
    fclose(input_file);
    fclose(output_file);
    return 5;
}
if((a<=0)||(b<=0)){
    fclose(input_file);
    fclose(output_file);
        return 7;
    }
    arr=(double**)malloc(a*sizeof(double*));
    if(arr==NULL){
        return 5;
    }
    for(i=0;i<a;i++){
        arr[i]=(double*)malloc(b*sizeof(double));
        if(arr[i]==NULL){
            for(int m=0;m<i;i++){
                free (arr[m]);
            }
            free(arr);
            fclose(input_file);
            fclose(output_file);
            return 4;
        }
    }
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            if(fscanf(input_file,"%lf",&arr[i][j])!=1){
                for (int q=0;q<a;q++){
                    free(arr[q]);
                }
                free(arr);
                fclose(input_file);
                fclose(output_file);
                return 4;
                
            }
        }
    }
    for(i=0;i<a;i++){
        for(j=0;j<b-1;j++){
            for(u=0;u<b-1;u++){
            if(arr[i][u]>arr[i][u+1]){
                tmp=arr[i][u];
                arr[i][u]=arr[i][u+1];
                arr[i][u+1]=tmp;
            }
        }
    }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            fprintf(output_file,"%lf ",arr[i][j]);
         }
         fprintf(output_file,"\n");
    }
    for(int i=0;i<a;i++){
        free(arr[i]);
    }
    free(arr);
    fclose(output_file);
    fclose(input_file);
    return 0;
}
