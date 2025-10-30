#include<stdio.h>
#include<stdlib.h>
char str[50],pat[20],rep[20],ans[50];
int c=0,m=0,i=0,j=0,k,flag=0;
void stringmatch()
{
    while(str[c]!='\0')
    {
        if(str[m]==pat[i])
        {
            i++;
            m++;
            if(pat[i]=='\0')
            {
                flag=1;
                for(k=0;rep[k]!='\0';k++)
                    ans[k]=rep[k];
        i=0;
        c=m;
            }
        }
        else
        {
            ans[k]=str[c];
            k++;
            c++;
            m=c;
            k=0;
        }
    }
    ans[k]='\0';

}
void main()
{
    printf("\n Enter main string: ");
    fgets(str,50,stdin);
    printf("\n Enter pat string: ");
    fgets(pat,20,stdin);
    printf("\n Enter replace string:");
    fgets(rep,20,stdin);
    stringmatch();
    if(flag==1)
        printf("\n Resultant string is %s",ans);
    else
        printf("\n Pattern string is not found");
}
