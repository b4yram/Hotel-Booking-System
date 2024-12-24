#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void add();
void list();
void edit();
void delete1();
void search();


void login()
{

	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="admin";
    do
{
	system("cls");

    printf("\n  =============  LOGIN FORM  =============  ");
    printf(" \n        KULLANICI ADI:-");
	scanf("%s", &uname);
	printf(" \n        SIFRE:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       GIRIS BASARILI!!!");

	break;
	}
	else
	{
		printf("\n        GIRIS BASARISIZ!!!");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\n ARD ARDA YANLIS SIFRE GIRDINIZ!!!");

		getch();

		}
		system("cls");
}

struct CustomerDetails   //STRUCT VERI YAPILARI
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;

int main(){
	int i=0;

	time_t t;
	time(&t);
	char customername;
	char choice;

	system("cls");
	printf("\t\t|       ----------------------------        |\n");
	printf("\t\t|         OTEL REZERVASYON SISTEMI          |\n");
	printf("\t\t|       ----------------------------        |\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\n TARIH VE SAAT : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
	printf(" \n Devam etmek icin herhangi bir tusa basiniz:");

	getch();
    system("cls");
    login();
    system("cls");
	while (1)
	{
		system("cls");

        for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t\t|ANA MENU|  \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\t\t ISLEM SECINIZ:");
		printf("\n\n");
		printf(" \n 1 Oda Rezervi");
		printf(" \n 2 Musteri Detayi");
		printf(" \n 3 Musteri Silme");
		printf(" \n 4 Kayit Sorusturma");
		printf(" \n 5 Kayit Guncelleme");
		printf(" \n 6 Cikis");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\n Tarih : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);
		switch(choice)
		{
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				edit();break;
			case '6':
				system("cls");
				printf("\n\n\t BIZI TERCIH ETTIGINIZ ICIN");
				printf("\n\t ******TESEKKURLER******");
			//	Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Hatali Giris");
				printf("\n Devam etmek icin bir tusa basiniz");
				getch();
		}
	}
}

void add()
{
	FILE *f;
	char test;
	f=fopen("cus.txt","a+");
	if(f==0)
	{   f=fopen("cus.txt","w+");
		system("cls");
		printf("\n Islem basarili devam etmek icin bir tusa basiniz!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Musteri Bilgisi Giriniz:");
		printf("\n**************************");
		printf("\n Oda Numarasi:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Ad:\n");
		scanf("%s",s.name);
		printf("Adres Giriniz:\n");
		scanf("%s",s.address);
		printf("Telefon Numarasi Giriniz:\n");
		scanf("%s",s.phonenumber);
		printf("Email:\n");
		scanf(" %s",s.email);
		printf("Rezervasyon Suresi(\'x\'Gun):\n");
		scanf("%s",&s.period);
		printf("Giris Tarihi(gg\\ay\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Oda Basariyla Rezerve Edildi!!");
		printf("\n Cikmak icin esc tusuna basiniz,  yeni musteri bilgizsi icin herhangi bir tusa basiniz:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}

void list()
{
	FILE *f;
	int i;
	if((f=fopen("cus.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("ODA    ");
	printf("ISIM\t ");
	printf("\tADDRES ");
	printf("\tTELEFON NUMARASI ");
	printf("\tEMAIL ");
	printf("\t\t  SURE ");
	printf("\t GIRIS TARIHI \n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{

		printf("\n%s \t%s \t\t%s \t\t%s \t%s  \t%s  \t     %s  \t  %s",s.roomnumber, s.name , s.address , s.phonenumber ,s.email,s.period,  s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("cus.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Sistemden Musteri Silmek Icin Oda Numarasi Giriniz: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{
		printf("\n\n Odaya ait musteri girisi bulunamadi!!");

		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("cus.txt");
	rename("temp.txt","cus.txt");
	printf("\n\nMusteri bilgisi basariyla silindi....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("cus.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Musteri Bilgisi Görmek İcin Oda Numarasi Giriniz: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tKayit Bulundu\n ");
			printf("\nOda Numarası:\t%s",s.roomnumber);
			printf("\nIsim:\t%s",s.name);
			printf("\nAddres:\t%s",s.address);
			printf("\nTelefon Numarası:\t%s",s.phonenumber);
			printf("\nEmail:\t%s",s.email);
			printf("\nSure:\t%s",s.period);
			printf("\nGiris Tarihi:\t%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tIstenilen Kullanici Bulunamadi!");
	}
	getch();
	fclose(f);
}

void edit()
{
	FILE *f;
	int k=1;
	char roomnumber[20];
	long int size=sizeof(s);
	if((f=fopen("cus.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Musteri Bilgisi Duzenlemek Icin Oda Numarasi Giriniz:\n\n");
	scanf("%[^\n]",roomnumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{
			k=0;
			printf("\nOda Numarasi Giriniz     :");
			gets(s.roomnumber);
			printf("\nIsim Giriniz    :");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nAdres Giriniz        :");
			scanf("%s",&s.address);
			printf("\nTelefon Numarasi Giriniz :");
			scanf("%f",&s.phonenumber);
			printf("\nEmail Giriniz :");
			scanf("%s",&s.email);
			printf("\nSure Giriniz :");
			scanf("%s",&s.period);
			printf("\nGiris Tarihi Giriniz :");
			scanf("%s",&s.arrivaldate);
			fseek(f,size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nBOYLE BIR KAYIT BULUNMAMAKTADIR!!!!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tKAYIT BASARIYLA DUZENLENDI!!!");
	getch();
}
}
