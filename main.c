//
//  main.c
//  OS X build checker
//
//  Created by Paulo A. Nascimento  on 15/08/2015.
//  Copyright (c) 2015 noOrg. All rights reserved.
//  paulo.nascimento@icloud.com
//

#include <stdio.h>
#include <string.h>

#define kTableRows 51   // number of Apple OS X public known builds so far...
#define kTableCols 2    // it's a 2 column simple table

/* ******************************************************************************************************** */
void toUpperStr(char s[255])
{                                           // vamos converter todos os caracteres minusculos em maiusculos...
    for (int i=0; i<strlen(s); i++)
        if ( s[i]>='a' && s[i]<='z' )
            s[i]=(s[i]-32);
}
/* ******************************************************************************************************** */

int main(int argc, const char * argv[])
{
    char s[15];
    char *tabela[kTableRows][kTableCols]=
    {
        // List of build numbers from Apple
        // per https://support.apple.com/en-us/HT201260
        
        
        // El Capitan
        "15AAA","Mac OS X v10.11 El Capitan",
        
        // Yosemite
        "14F27", "Mac OS X v10.10.5 Yosemite",
        "14E46", "Mac OS X v10.10.4 Yosemite",
        "14D136", "Mac OS X v10.10.3 with supplemental update, Yosemite",
        "14C109", "Mac OS X v10.10.2 Yosemite",
        "14B25", "Mac OS X v10.10.1 Yosemite",
        "14A389", "Mac OS X v10.10 Yosemite",
        
        // Mavericks
        "13F34", "Mac OS X v10.9.5 Mavericks",
        "13E28", "Mac OS X v10.9.4 Mavericks",
        "13D65", "Mac OS X v10.9.3 Mavericks",
        "13C64", "Mac OS X v10.9.2 Mavericks",
        "13B42", "Mac OS X v10.9.1 Mavericks",
        "13A603", "Mac OS X v10.9 Mavericks",
        
        // Mountain Lion
        "12F37", "Mac OS X v10.8.5 Mountain Lion",
        "12F45", "Mac OS X v10.8.5 Mountain Lion",
        "12F2029", "Mac OS X v10.8.5 Mountain Lion",
        "12E55", "Mac OS X v10.8.4 Mountain Lion",
        "12D78", "Mac OS X v10.8.3 Mountain Lion",
        "12C54", "Mac OS X v10.8.2 Mountain Lion",
        "12C60", "Mac OS X v10.8.2 Mountain Lion",
        "12C2034", "Mac OS X v10.8.2 Mountain Lion",
        "12B19", "Mac OS X v10.8.1 Mountain Lion",
        "12A269", "Mac OS X Mountain Lion",
        
        // Lion
        "11G56", "Mac OS X v10.7.5 Lion",
        "11G63", "Mac OS X v10.7.5 Lion",
        "11A511", "Mac OS X v10.7 Lion",
        
        // Snow Leopard
        "10K540", "Mac OS X v10.6.8 Snow Leopard",
        "10K549", "Mac OS X v10.6.8 Snow Leopard",
        "10D575", "Mac OS X v10.6.3 Snow Leopard Install DVD",
        "10A433", "Mac OS X Server v10.6 Snow Leopard Install DVD",
        "10A432", "Mac OS X v10.6 Snow Leopard Install DVD",
        
        // Leopard
        "9L30", "Mac OS X v10.5.8 Leopard",
        "9L34", "Mac OS X Server 10.5.8 v1.1 Leopard",
        "9G66", "Mac OS X v10.5.6 Leopard Install DVD",
        "9A581","Mac OS X v10.5 Leopard Install DVD",
        
        // Tiger
        "8S165", "Mac OS X v10.4.11 Tiger",
        "8A428", "Mac OS X v10.4 Tiger installation disc",
        
        // Panther
        "7W98","Mac OS X v10.3.9 Panther",
        "7D28","Mac OS X v10.3.2 Panther installation disc",
        "7B85","Mac OS X v10.3 Panther installation disc",
        
        // Jaguar
        "6R65","Mac OS X v10.2.8 Jaguar",
        "6R73","Mac OS X v10.2.8 Jaguar",
        "6G37","Mac OS X v10.2.3 Jaguar installation disc",
        "6G35","Mac OS X Server v10.2.3 Jaguar installation disc",
        "6C115","Mac OS X v10.2 Jaguar installation disc",
        
        // Puma
        "5S66","Mac OS X v10.1.5 Puma with Networking Update 1.0",
        "5S60","Mac OS X v10.1.5 Puma",
        "5L17B","Mac OS X v10.1 Puma installation disc with  Security Update 10-19-01", // actually is 5L17b, not to compromise algorithm
        "5L14","Mac OS X v10.1 Puma installation disc with  Security Update 10-19-01",
        "5G64","Mac OS X v10.1 Puma installation disc",
        
        //Cheetah
        "4K78", "Mac OS X v10.0 Cheetah installation disc"
    };
    
    if ( argc < 2)  // não foram passados argumentos na invocação do comando desde o OS...
    {
        printf("OSX build# or 'osxbc build#' next time you run this tool: ");
        scanf("%s",s);
        toUpperStr(s);
    }
    else    // ele há argumentos na invocação da ferramenta...
    {
        strcpy(s, argv[1]);
        toUpperStr(s);
    }
    
    if ( strcmp(s,"DUMP")==0 )      // because everything is uppercased...
    {
        for (int i=0;i<kTableRows;i++)
            printf("%s\t%s\n", tabela[i][0], tabela[i][1]);
    }
    
    for (int i=0 ; ; i++)                   // clever search & print... to be returned... 1 result only through inconditional loop
    {
        if ( i >= kTableRows )          // stay within matrix/array boundaries...
        {
            if ( strcmp(s,"DUMP")!=0 )  // thus not echoing below msg when issuing "osxbc dump" command.... aestehtics :-)
                printf("No such Mac OS X build!\n");
            break;
        }
        
        if ( strcmp(tabela[i][0],s)==0 )    // found!
        {
            printf("%s\n", tabela[i][1] );
            break;
        }
    }
    
    return 0;
}

/*
 
KNOWN BUGS:
 
a) Missing "sysctl -a | grep kern.osxversion" proper system call through execve...
 
*/
