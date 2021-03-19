#include <windows.h>
#include<stdlib.h>
#include "mmsystem.h"
#include <iostream>
#include <fstream>
#define DASH "-"
#define DOT "."
#define DASH "_"
#define space " "
#include<string.h>
using namespace std;
char c[10];

char* finddotdash(char ch)
{
   	ifstream fi("mc.txt");
   	char intext[15];
   	if(!fi)
   	  cout<<"file ended";
   	int flag =0;
   	
    
   	while(!fi.eof())
   	{
   		
   		fi>>intext;	
   		strcpy(c,intext);
		  	
   		if(intext[0]==ch)
   		{  
   		     flag=1;
		     fi>>intext;
			  break;
		}	
    }
    fi.close();
    if(flag ==0)
        {
		    strcpy(intext,"/");
		    strcpy(c,"SPACE");
	    }
	return intext; 
	
	
}
char uni[100];
void encode(char code[100])
{
	char *ptr=code;
	int i;
	char encoded[20];
	while(*ptr!='\0')
	{
		
	    strcpy(encoded,finddotdash(*ptr));
	    cout<<"\n string back from dotdash is "<<c<<" : "<<encoded;
	    ofstream fo("final.txt",ios::app);
	    fo<<encoded;
	    fo<<" ";
	    fo.close();
	    for(i=0;encoded[i]!='\0';i++)
	    {
	    	if(encoded[i]=='.')
	    	   {
				 PlaySound("1 sec beep", NULL, SND_SYNC);Sleep(100);
			   }
			else if(encoded[i]=='-')
			   {
				 PlaySound("3 sec beep", NULL, SND_SYNC);Sleep(100);	
			   }	
		}
	    if(encoded[0]=='/') 
			      Sleep(600);//100+600    
	    else 
		          Sleep(200);//200+100
	
		ptr++;
	}	
}
void findchar(char che[20])
{
	ifstream fi;
	char ch=' ';
	char intext[20];
	fi.open("mc.txt");
	int flag =0;
	while(!fi.eof())
	{
			
		fi>>ch;
		fi>>intext;	
	 
		if(strcmp(intext,che)==0)
		  {
			  cout<<ch;flag=1;
		}
		   
	  	
	}
	
	fi.close();
	if(flag==0)
	   cout<<space;
}
void decode(char code[100])
{
	char ch;
	char input[20];
	char intext[20];
	ofstream fo("input.txt");
	fo<<code;
	fo.close();
	ifstream f2("input.txt");
	while(!f2.eof())
	{
	
		f2>>input;
		findchar(input);
	  	
	}
	f2.close();
	
}
int main() 
{
    
	char code[100];
	cout<<"\n \n \n \t \t \t \t \t  MORSE CODE TRANSLATOR\n ";
	cout<<"--TYPE SOMETHING--->";
	gets(code);
	for(int i=0;code[i]!='\0';i++)
	   code[i]=toupper(code[i]);
	   
	if(code[0]=='.'||code[0]=='-')
	    decode(code);
	else 
	    encode(code);
	ifstream fi("final.txt");
	char line[100];
	cout<<"\n final message :";
	
	while(!fi.eof())
	{
        fi.getline(line,80);
		cout<<line;				
	}
	fi.close(); 
	system("pause"); 
	  
	ofstream fo("final.txt",ios::trunc);
    fo.close();
	 
		 
	return 0;
}
