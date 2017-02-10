#include<string.h>

#define n 1000

void reverse(char *s)
{
    int i,j;
    char tmp;
    for(i=0, j=strlen(s)-1; i<=(strlen(s)-1)/2; i++,j--)
    {
	tmp= s[i];
	s[i]= s[j];
	s[j]= tmp;
    }
}

void add(char *a, char *b, char *c)
{
    int carry=0,k=0,i,d1,d2,s;
    for(i=0; a[i]!='\0' && b[i]!='\0'; i++)
    {
	d1= a[i]-'0';
	d2= b[i]-'0';
	s= d1+d2;
	s+= carry;
	carry= s/10;
	c[k++]= s%10+ '0';
    }
    if(a[i]!='\0')
    {
	while(a[i]!='\0')
	    {
		s=a[i]-'0';
		s+= carry;
		carry= s/10;
		c[k++]= s%10+ '0';
		i++;
	    }
    }
    else
    {
	 while(b[i]!='\0')
	 {
		s=b[i]-'0';
		s+= carry;
		carry= s/10;
		c[k++]= s%10+ '0';
		i++;
	 }
    }
    if(carry!=0)
	c[k++]= carry+ '0';
    c[k++]= '\0';

}

void multiply(char *a, char *b, char *d)
{

    char c[n],e[n],tmp[n];
    int i,j,k,l,d1,d2,p,carry;
    reverse(a);
    reverse(b);
    for(i=0; b[i]!='\0'; i++)
    {
        k=0;  carry=0;
        d1= b[i]- '0';          //storing one digit of b at a time which will be multiplied by a.
        for(j=0; a[j]!='\0'; j++)
        {
            d2= a[j]- '0';      //storing digit of a at a time and multiplying it by d1 and carry is stored
            p= d1*d2;
            p+= carry;
            carry= p/10;
            c[k++]=p%10+ '0';      //storing the partial result in another string c
        }
        if(carry!=0)
            c[k++]=carry+ '0';
        c[k++]= '\0';
        for(j=0;j<i;j++)
            tmp[j]= '0';       //tmp is a string which will denote string c but it will contain concatened required no of zeroes in the end
        for(l=0; l<k; l++)
            tmp[j++]= c[l];
        tmp[j++]= '\0';
        strcpy(c,tmp);         //finall c is modified using tmp. now c contain the partial multiplication result along with required no of zeroes in the end. now c will be added with previous result(of multiplication).
        if(i==0)
            strcpy(d,c);      //for the first time there is no previous multiplication result. so, no need to perform addition.
        else
        {
            add(c,d,e);         // c contain current multiplication result and d contain previous one. both are added.
            strcpy(d,e);        //finally the sum is stored in d which will act as previous sum in next iteration
        }
    }
    reverse(d);                 //finally reverse the string to get the result
}

int main()
{
    int i,k,d,N;
    char a[n],b[n],c[n];
    printf("Enter the nuber : ");
    scanf("%d", &N);
    if(N==0 || N==1)
    {
        printf("1");
        return 0;
    }
    strcpy(a,"1");
    for(i=2;i<=N;i++)
    {
        k=0; d=i;
        while(d>0)
        {
            b[k++]= d%10+ '0';
            d/=10;
        }
        b[k++]= '\0';
        reverse(b);
        multiply(a,b,c);    //the result will be stored in c.
        strcpy(a,c);
    }
    printf("%s",a);
    return 0;
}


