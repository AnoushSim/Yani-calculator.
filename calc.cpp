#include <iostream>
#include <string>
#include <cmath>
const int n=40;
int main()
{
  std::string s;
  std::cout<<"Enter the expression you want to calculate: ";
  std::getline(std::cin,s);
  int a[n];
  for(int i=0;i<n;i++) a[i]=0;
  int i;
 int sum;
 int j=0,t=0;
  for(i=0;i<s.size();i++) 
 {
    while(s[i]>=48 && s[i]<=57)
    {
      t++;
      i++;
    }
    while(t--)
              a[j]+=(s[i-t]-'0')*pow(10,t-1);
  if(s[i]==40 || s[i]==41 ||s[i]==42 ||s[i]==43 ||s[i]==45 ||s[i]==47 )
  {
    a[j]=s[i]-'0';
    i++;
  }
  j++;
 }
 if(a[0]<48 || a[0]> 57) 
              std::cout<<"Your calculation form is not correct!";
 for( i=0;i<j;i++)  
 {
   if(a[i]=='(')
  { int op=a[i+2];
   switch(op)
   {
     case '+':
     a[i]=a[i+1]+a[i+3];
     a[i+1]=a[i+2]=a[i+3]=a[i+4]=0;
     break;
     case '-':
     a[i]=a[i+1]-a[i+3];
     a[i+1]=a[i+2]=a[i+3]=a[i+4]=0;
     break;
     case '*':
     a[i]=a[i+1]*a[i+3];
     a[i+1]=a[i+2]=a[i+3]=a[i+4]=0;
     break;
     case '/':
     a[i]=a[i+1]/a[i+3];
     a[i+1]=a[i+2]=a[i+3]=a[i+4]=0;
     break;
     default:
     std::cout<<"Unknown operation"<<std::endl;
     break;
   }
 }
 }
 for( i=0;i<j;i++) 
         if(a[i]=='*')
            {
             a[i-1]=a[i-1]*a[i+1];
             a[i]=a[i+1]=0;
            }
 for( i=0;i<j;i++) 
         if(a[i]=='/')
            {
             a[i-1]=a[i-1]/a[i+1];
             a[i]=a[i+1]=0;
            }
 for( i=0;i<j;i++) 
         if(a[i]=='+')
            {
             a[i-1]=a[i-1]+a[i+1];
             a[i]=a[i+1]=0;
            }
 for( i=0;i<j;i++) 
         if(a[i]=='-')
            {
             a[i-1]=a[i-1]-a[i+1];
             a[i]=a[i+1]=0;
            }
 for( i=0;i<j;i++)
   sum+=a[i];
   for( i=0;i<j;i++)
   std::cout<<"Your calculation result is "<<sum;
 }
  return 0;
}
