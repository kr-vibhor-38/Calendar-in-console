#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
char c, week[8][10]={"0","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};
int j; //j is the day no. of the week
char month[13][10]={"0","JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST",
                    "SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
void dayof(int,int,int);
void prt_cal(int,int,int,int,int);
int main()
{
    int d,m,y,nodim;
    double totaltime=0;
    clock_t start,end;
    printf("Enter a date to print it's Day of Week and Calendar.\n DD/MM/YYYY\n");
    printf("Enter any Year(1900-2100)(YYYY):");
    yr:
    scanf("%i",&y);
    if (y<1900 || y>2100)
    { printf("Out of range!\nEnter again:");
        fflush(stdin); goto yr; }
    printf("Enter Month Number(1-12)(MM):");
    mm:
    scanf("%i",&m);
    if (m<1 || m>12)
    { printf("Select a valid month!\nEnter Again:");
        fflush(stdin); goto mm;}
    printf("Enter Date of month(DD):");
    dd:
    scanf("%i",&d);
    if(d<1 || d>31)
    {printf("Enter a valid date of month!\nEnter again:"); goto dd;}
    if((d==31)&&(m==2||m==4||m==6||m==9||m==11))
        {printf("It is not 31-days month!\nEnter again:"); goto dd; }
    if((d==30)&&(m==2))
        {printf("It is not 30-days month!\nEnter again:"); goto dd;}
    if((d==29)&&(y%4!=0)&&(m==2))
            {printf("%i is not a leap year!\nEnter again:",y); goto dd;}
    start=clock();
    dayof(d,m,y);
    printf("\nType of Year is: %c\n",c);
    printf("Day of the date is: %s\n",week[j]);
    dayof(1,m,y);
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) nodim=31;
    else if(m==4||m==6||m==9||m==11) nodim=30;
    else if(m==2 && y%4==0) nodim=29;
    else nodim=28;
    if(j<7)
    prt_cal(j+1,nodim,d,m,y);
    else
    prt_cal(1,nodim,d,m,y);
    end=clock();
    totaltime+=((double)(end-start))/CLK_TCK;
    printf("\nTask executed in %f seconds.",totaltime);
    printf("\nPress any key to exit...");
    getch();
    return 0;
}
void dayof(int D,int M,int Y)  //by help of 100-yr calendar table given in back-page of notebook
{int i,start;                 // 1900 to 2000 cases is found by research
 char dt, mtype[14];

    switch (Y)
    {
    case 1900:case 1906:case 1917:case 1923:case 1934:case 1945:case 1951:case 1962:
    case 1973:case 1979:case 1990:case 2001:case 2007:case 2018:case 2029:case 2035:
    case 2046:case 2057:case 2063:case 2074:case 2085:case 2091:{c='A'; break;}

    case 1901:case 1907:case 1918:case 1929:case 1935:case 1946:case 1957:case 1963:
    case 1974:case 1985:case 1991:case 2002:case 2013:case 2019:case 2030:case 2041:
    case 2047:case 2058:case 2069:case 2075:case 2086:case 2097:{c='B'; break;}

    case 1902:case 1913:case 1919:case 1930:case 1941:case 1947:case 1958:case 1969:
    case 1975:case 1986:case 1997:case 2003:case 2014:case 2025:case 2031:case 2042:
    case 2053:case 2059:case 2070:case 2081:case 2087:case 2098:{c='C'; break;}

    case 1903:case 1914:case 1925:case 1931:case 1942:case 1953:case 1959:case 1970:
    case 1981:case 1987:case 1998:case 2009:case 2015:case 2026:case 2037:case 2043:
    case 2054:case 2065:case 2071:case 2082:case 2093:case 2099:{c='D'; break;}

    case 1909:case 1915:case 1926:case 1937:case 1943:case 1954:case 1965:case 1971:
    case 1982:case 1993:case 1999:case 2010:case 2021:case 2027:case 2038:case 2049:
    case 2055:case 2066:case 2077:case 2083:case 2094:case 2100:{c='E'; break;}

    case 1910:case 1921:case 1927:case 1938:case 1949:case 1955:case 1966:case 1977:
    case 1983:case 1994:case 2005:case 2011:case 2022:case 2033:case 2039:case 2050:
    case 2061:case 2067:case 2078:case 2089:case 2095:{c='F'; break;}

    case 1905:case 1911:case 1922:case 1933:case 1939:case 1950:case 1961:case 1967:
    case 1978:case 1989:case 1995:case 2006:case 2017:case 2023:case 2034:case 2045:
    case 2051:case 2062:case 2073:case 2079:case 2090:{c='G';break;}

    case 1912:case 1940:case 1968:case 1996:case 2024:case 2052:case 2080:{c='H'; break;}

    case 1924:case 1952:case 1980:case 2008:case 2036:case 2064:case 2092:{c='I'; break;}

    case 1908:case 1936:case 1964:case 1992:case 2020:case 2048:case 2076:{c='J'; break;}

    case 1920:case 1948:case 1976:case 2004:case 2032:case 2060:case 2088:{c='K'; break;}

    case 1904:case 1932:case 1960:case 1988:case 2016:case 2044:case 2072:{c='L'; break;}

    case 1916:case 1944:case 1972:case 2000:case 2028:case 2056:case 2084:{c='M'; break;}

    case 1928:case 1956:case 1984:case 2012:case 2040:case 2068:case 2096:{c='N'; break;}
    }

    switch (c)
    {
        case 'A':{strcpy(mtype,"0144725736146"); break; }
        case 'B':{strcpy(mtype,"0255136147257"); break; }
        case 'C':{strcpy(mtype,"0366247251361"); break; }
        case 'D':{strcpy(mtype,"0477351362472"); break; }
        case 'E':{strcpy(mtype,"0511462473513"); break; }
        case 'F':{strcpy(mtype,"0622573514624"); break; }
        case 'G':{strcpy(mtype,"0733614625735"); break; }
        case 'H':{strcpy(mtype,"0145136147257"); break; }
        case 'I':{strcpy(mtype,"0256247251361"); break; }
        case 'J':{strcpy(mtype,"0367351362472"); break; }
        case 'K':{strcpy(mtype,"0471462473513"); break; }
        case 'L':{strcpy(mtype,"0512573514624"); break; }
        case 'M':{strcpy(mtype,"0623614625735"); break; }
        case 'N':{strcpy(mtype,"0734725736146"); break; }
    }
    dt=mtype[M];
    switch (dt)
    {
        case '1':{start=1;break;}
        case '2':{start=2;break;}
        case '3':{start=3;break;}
        case '4':{start=4;break;}
        case '5':{start=5;break;}
        case '6':{start=6;break;}
        case '7':{start=7;break;}
    }
    for(i=1,j=start;i<=31;i++,j++)
    {
        if(j==8) j=1;
        if(i==D) break;
    }

}
void prt_cal(int wk,int nod,int sd,int mt,int yr) //1st day,no. of days in month,DD,MM,YYYY
{
    int n,i,r;
    printf("\t%s, %i\n",month[mt],yr);
    printf("%c",201);// double liner blocks
    for(n=0;n<6;n++)
        printf("%c%c%c%c%c",205,205,205,205,203);// double liner blocks
    printf("%c%c%c%c%c\n",205,205,205,205,187);// double liner blocks
    printf("%cSun %cMon %cTue %cWed %cThu %cFri %cSat %c\n",186,186,186,186,186,186,186,186);
    printf("%c",204);// double liner blocks
    for(n=0;n<6;n++)
        printf("%c%c%c%c%c",205,205,205,205,206);// double liner blocks
    printf("%c%c%c%c%c\n",205,205,205,205,185);// double liner blocks
    for(n=wk-(wk-1)*2;n<=nod;)
    {
        printf("%c",179); //single liner blocks
        for(i=1;i<=7;i++,n++)
        {
            if (n >= 1 && n <= nod)
            {
                if(n==sd) printf("%c%2i%c%c",175,n,174,179);//single liner blocks with marker
                else printf(" %2i %c", n, 179);//single liner blocks
            }
            else printf("    %c",179);//single liner blocks
        }
        printf("\n");
        if(n>nod && i>=7)
        { printf("%c",192);
            for(r=1;r<=6;r++)
                printf("%c%c%c%c%c",196,196,196,196,193);//single liner blocks
            printf("%c%c%c%c%c",196,196,196,196,217);//single liner blocks
        }
        else
        {  printf("%c",195);
            for(r=1;r<=6;r++)
                printf("%c%c%c%c%c",196,196,196,196,197);//single liner blocks
            printf("%c%c%c%c%c",196,196,196,196,180);//single liner blocks
        }
        printf("\n");
    }

}