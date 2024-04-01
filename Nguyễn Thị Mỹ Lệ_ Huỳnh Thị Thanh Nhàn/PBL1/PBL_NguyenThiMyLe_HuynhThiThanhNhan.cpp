#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char b[] = "0123456789ABCDEF";
void title();
void menu();
void chuong_trinh();
int kiem_tra(char *a,int q);
char* so_am(char *a, char *c);
unsigned long long nhan(char *a, int dau);
void ket_qua(int i,int a, int sau ,int d[]);
void he_hai(int d[],char *c);
int thap_phan(char *a);
void dau_cach(int d[]);

int main() {
	char tt;
	title();
	while(1){
    menu();
    chuong_trinh();
	}
}

void title()
{
 	printf("\n\t******************************************WELCOME********************************************");
	printf("\n\t*                                                                                           *");
    printf("\n\t*                                                                                           *");
	printf("\n\t*                                                                                           *");
	printf("\n\t*                                         DE TAI                                            *");
	printf("\n\t*                               UNG DUNG CHUYEN DOI CO SO                                   *");
    printf("\n\t*                        Thanh vien :                                                       *");
	printf("\n\t*            Nguyen Thi My Le        102220238   22T_DT5                                    *");
	printf("\n\t*            Huynh Thi Thanh Nhan    102220243   22T_DT5                                    *");
	printf("\n\t*                                                                                           *");
	printf("\n\t*                                                                                           *");
	printf("\n\t*                                                                                           *");
    printf("\n\t******************************************WELCOME********************************************");
}

void menu()
{
	printf("\n\n*****************************CHAO MUNG CAC BAN DEN VOI UNG DUNG***********************************************\n\n");
	printf("=====================================CHUYEN DOI CO SO DEM=====================================================\n");
	printf("=\t\t          1. Doi tu he thap phan sang he nhi phan.                                            =\n");
	printf("=\t\t          2. Doi tu he thap phan sang he bat phan.                                            =\n");
	printf("=\t\t          3. Doi tu he thap phan sang he thap luc phan.                                       =\n");
	printf("=\t\t          4. Doi tu he nhi phan sang he thap phan.                                            =\n");
	printf("=\t\t          5. Doi tu he bat phan sang he thap phan.                                            =\n");
	printf("=\t\t          6. Doi tu he thap luc phan sang he thap phan.                                       =\n");
	printf("=\t\t          7. Doi tu he nhi phan sang he thap luc phan.                                        =\n");
	printf("=\t\t          8. Doi tu he nhi phan sang he bat phan.                                             =\n");
	printf("=\t\t          9. Doi tu he bat phan sang he nhi phan.                                             =\n");
	printf("=\t\t          10. Doi tu he thap luc phan sang he nhi phan.                                       =\n");
	printf("=\t\t          11. Thoat.         :>                                                               =\n");
	printf("==============================================================================================================\n");
}

int kiem_tra(char *a,int q)
{
	int i=0;
	int len = strlen(a);
        if((q==1)||(q==2)||(q==3)){
        	while(i<len)
        	{
        		if ((a[i] >= '0' && a[i] <= '9')|| a[i]=='.') i++;
        		else return 0;
			} return 1;
	    } 
    
        else if((q==4)||(q==7)||(q==8)){
            while(i<len)
        	{
        		if ((a[i] == '0' || a[i] == '1')||a[i]=='.')  i++;
        		else return 0;
			} return 1;
	    } 
	    
	    else if((q==5)||(q==9) ){
            while(i<len)
        	{
        		if ((a[i] >= '0' && a[i] <= '7')|| a[i]=='.') i++;
        		else return 0;
			} return 1;
     	}
     	
		else {
            while(i<len)
        	{
        		if ((a[i] >= '0' && a[i] <= 'F')|| a[i]=='.') i++;
        		else return 0;
			} return 1;
     	}
	return 0;
}

char * so_am(char *a, char *c)
{
    if(c[0]=='-')
	{
		for(int i=1;i<strlen(c);i++)  a[i-1]=c[i];
    }
    
  	else 
	{
	  	for(int i=0;i<strlen(c);i++)  a[i]=c[i];
	}	
}

int thap_phan(char *a)
{
    for (int i = 0; i < strlen(a); i++) 
	{
        if (a[i] == '.')  return i;
    }
    return -1;
}

unsigned long long  nhan (char *a, int dau) 
{
    unsigned long long  muoi = 0;
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        int m = 0;
        
        if (a[i] >= '0' && a[i] <= '9')      m = a[i] - '0';
        else if (a[i] >= 'A' && a[i] <= 'F') m = a[i] - 'A' + 10;
        else  return -1;
        
        muoi += m * pow(dau , len - i - 1);
    }
	return muoi;
}

void ket_qua(int i,int a, int sau ,int d[])
{
    int nguyen = a / sau;
    int du = a % sau;
    if (nguyen > 0)  	ket_qua(i+1,nguyen, sau,d); 
    if(sau==2 ) d[i]= du;
    else printf("%c", b[du]);
}

void dao_bit_cong_1(int d[],char *c)
{
	if(c[0]=='-')
	{
		for(int i=31 ;i>=0;i--)
	    {
		    d[i]=!d[i];	
	    } 
	
	    for(int i=0;i<32;i++)
    	{
		    if(d[i]==0)
		    {
			    d[i]=1;
			    break;
     	    }
     	    else d[i]=0;
    	}
	}
}

void dau_cach(int d[])
{	
	for(int i=31;i>=0;i--) 
	{
		printf("%d", d[i]);
		if (i%4==0) printf(" ");
	}
}

void chuong_trinh()
{
	int q,dau,sau;
	char a[50],u[50];
    int d[32];
    unsigned long long  muoi;
    for(int i=0;i<32;i++)  d[i]=0;
    
	printf("\n Moi chon MENU:\t\t");	
	memset(u,0,sizeof(u));
	scanf("%s",&u);	
	
	q=nhan(u,10);
	while((q!=1)&&(q!=2)&&(q!=3)&&(q!=4)&&(q!=5)&&(q!=6)&&(q!=7)&&(q!=8)&&(q!=9)&&(q!=10)&&(q!=11))
	{
    	printf("\n Khong co trong MENU \n Moi chon lai MENU:\t\t");
        memset(u,0,sizeof(u));
	    scanf("%s",&u);	
	    q=nhan(u,10);
	}
    switch(q)
	{
        case 1 : dau=10 , sau=2  ; break;
        case 2 : dau=10 , sau=8  ; break;
        case 3 : dau=10 , sau=16 ; break;
		case 4 : dau=2  , sau=10 ; break;
		case 5 : dau=8  , sau=10 ; break;	
		case 6 : dau=16 , sau=10 ; break;
		case 7 : dau=2  , sau=16 ; break;  
		case 8 : dau=2  , sau=8  ; break;
		case 9 : dau=8  , sau=2  ; break;
		case 10: dau=16 , sau=2  ; break;
		case 11: 
		{
		system ("color 0");
    	printf("\n\n\n\n\t\t\t\t **   TAM BIET   **     \n\n");
    	printf("\t\t\t\t***  HEN GAP LAI ! ***   \n");
	    exit(1);
		}
	}
	
	printf("\n\t\t\tNhap so:\t ");
	char c[50];
	memset(c,0,sizeof(c));
	scanf("%s", c);
	
	memset(a,0,sizeof(a));
    so_am(a,c);
    
    while (!kiem_tra(a,q))
	{
        printf("\n So khong hop le! \n\t\t\tNhap lai so:\t");
        memset(c,0,sizeof(c));
    	scanf("%s", c);
    	
    	memset(a,0,sizeof(a));
        so_am(a,c);
    }
    
    int o=thap_phan(a);
    
    if(o>0)
    {
    	int s1=0;
		float s2=0;
        for (int k = 0; k < o; k++)
        {
        	s1 += (a[k] - '0') * pow(dau, o - k - 1);
		}
    
        for (int l = o + 1; l < strlen(a ); l++)
        {
        	s2 += (a[l] - '0') * pow(dau, o - l);
		}
    
    	if((sau==2))
    	{
    		printf("\t\t\tKet qua: \t");
    		ket_qua(0,s1,sau,d);
		    dao_bit_cong_1(d,c);
		    dau_cach(d);
		}

        else if((sau!=2)&&(c[0]=='-'))
        {
        	printf("\t\t\tKet qua: \t -");
    	    ket_qua(1,s1,sau,d);
		}
		
        else 
		{
		    printf("\t\t\tKet qua: \t");
            ket_qua(1,s1,sau,d);
		}
		
    printf(".");
    
    int m=1;
        do
        {
        	s2 *= sau;
            printf("%c", b[(int) s2]);
            s2 = fmod(s2, 1);
            if(m%4==0) printf(" ");
            m++;
		}while (s2 > 0);
    }
    
    else
    {
    	muoi = nhan (a, dau);
    	
        if (muoi != -1)
        {
        	if((sau==2))
        	{
        		printf("\t\t\tKet qua: \t");
        		ket_qua(0,muoi,sau,d);
	    	    dao_bit_cong_1(d,c);
	    	    dau_cach(d);
	    	}
	   
    	    else if((sau!=2)&&(c[0]=='-'))
    	    {
    	    	printf("\t\t\tKet qua: \t -");
    	        ket_qua(1,muoi,sau,d);
			}
            else
            {
            	printf("\t\t\tKet qua: \t");
                ket_qua(1,muoi,sau,d);
			}
		}
    }
    
printf("\nBam phim bat ky de tiep tuc ...");
getch();
}
