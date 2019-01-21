#include <stdio.h>
#include <windows.h>

void menu();
void admin();

/*enum perKM{
	Traverse Town=4, Radiant Garden=7, Hollow Bastion=15
};*/

struct driver{
	int nomor;
	char nama[100];
	char id[100];
	char pass[100];
};

struct car{
	int nomor;
	char mobil[100];
	int harga;
	//enum perKM list[100];
}temp, m;

struct customer{
	int nomor;
	char nama[100];
	char pass[100];
};

struct kilo{
	char nama[100];
	int km;
};

struct snack{
	char nama[100];
	int harga;
};

int main(){          
	logo();
	menu();
	return 0;
}

void logo(){
	int i;
	for(i=0;i<3;i++){
		if(i==0){
			printf("\n   Loading. ");
		} else if(i==1){
			printf("\n   Loading..");
		} else {
			printf("\n   Loading...");
		}
		Sleep(900);
		system("cls");
	}
	printf("\n");
	printf(" ================================================================================\n");
	printf("   aginIm  inIma       inIma       gin           nImag      inImag  nImag   maginI\n");
	printf("   pmagin  aginI       aginI      Imagi         aginImagin  aginIm  ginIm   nImagi\n");   
	printf("    nIma     agin      Ima        inIma        nIma  nIma    magi    aginI   inIm\n");
	printf("     inI     Imagi    ginI       maginI       agin    inI     Ima    Imagin  agi\n");
	printf("    mag      inIma    m gi       nIm gin      Ima            gin     inImagi Ima\n");
	printf("     Ima     aginIm  in ma      aginImagi     inI             agi    aginIma inI\n");
	printf("     in      Im ginI ag nI      ImaginIma     agi   aginIm    Im     Ima inImagi\n");
	printf("     ag      in  aginI  gin    ginI   inIm     ma    magin    in     inI aginIma\n");
	printf("    nIma     agi  mag  Imag    mag     gin     nIm   nIma    magi    agi  maginI\n");
	printf("   aginIm  inImag  I  ginIma ginIma   Imagin    inImagin    inImag  nImag  Imagi\n");
	printf("   ImaginI  ginIm    maginI  maginI   inImag     ginIma    aginImag inIma  nImagi\n");
	printf(" ================================================================================\n");
	Sleep(1500);
	system("cls");    
}

void menu(){
	int i,n;
	FILE *fo = fopen("harga.txt","r+");//harga mobil
	FILE *fk = fopen("priceperkm.txt","r+");//price per km + destinasi
	FILE *fu = fopen("DB_User.txt","r+");//user
	FILE *fp = fopen("DB_Driver.txt","r+");//driver
	struct customer user[100];
	struct car data[100];
	struct driver list[100];
	struct kilo price[100];
	char str1[]="* * *   M a i n M e n u   * * *";
	char str2[]=" ";
	char str3[]=" M A G I N   T A X I";
	char str4[]=" T H R E E   W A Y   L A N E ";
	do{
		printf(" ");
		for(i=0;i<100;i++){
			printf("/");
		}
		printf("\n /%+65s%-33s/",str1,str2);
		printf("\n /%+98s/",str2);
		printf("\n /%+59s%-39s/",str3,str2);
		printf("\n /%+98s/",str2);
		printf("\n /%+64s%-34s/",str4,str2);
		printf("\n /%+98s/\n",str2);
		printf(" ");
		for(i=0;i<100;i++){
			printf("/");
		}
		printf("\n /%+98s/",str2);
		printf("\n /  1. Login as Admin%+79s/",str2);
		printf("\n /  2. Login as User%+80s/",str2);
		printf("\n /%+98s/\n",str2);
		printf(" ");
		for(i=0;i<100;i++){
			printf("/");
		}
		printf("\n Please enter number to execute action: "); scanf("%d",&n);
		if(n==1){
			system("cls");
			admin(fo,fp,data,list);
		} else if(n==2){
			system("cls");
			pengguna(fo,fp,fu,fk,user,data,list,price);
		}	
	} while(n!=3);

}
/*********************************
	USER
**********************************/
void pengguna(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[]){
	story();
	int pilih;
	int n=0,i=0;
	while(!feof(fu)){
		fscanf(fu,"%3d#%[^#]#%[^\n]\n",&user[i].nomor,user[i].nama,user[i].pass);
		//printf("   %03d\t\t%-20s\t\t%s\n",user[i].nomor,user[i].nama,user[i].pass);
		i++;
		n=i;
	}
	//printf("n=%d\n",n);
	//getch();
	do {
		printf("\n  Taksi version 1.0.1\n");
		printf("  Copyright 2017 IMAGIN\n");
		printf("  Released under ALPEM Last Project.\n");
		printf("\n   1. Login User \n");
		printf("   2. Register User\n");
		printf("   3. Help Desk User\n");
		printf("   4. Exit\n");
		printf("\n Enter option [1-3, 4 to quit] : "); scanf("%d",&pilih);
		if(pilih==1){
			system("cls");
			loginUser(fo,fp,fu,fk,user,data,list,price,n);
		} else if(pilih==2){
			system("cls");
			registerUser(fu,user,n);
			n++;
		} else if(pilih==3){
			system("cls");
		//	helpDeskUser(fp,list,n);
		}
	} while (pilih!=4);
	getch();
	system("cls");
	fclose(fu);
}
/*********************************
	USER > REGISTER USER
**********************************/
void registerUser(FILE *fu, struct customer user[],int n){
	int i;
	for(i=0;i<n;i++){
		fscanf(fu,"%3d#%[^#]#%[^\n]\n",&user[i].nomor,user[i].nama,user[i].pass);
		printf("   %03d\t\t%-20s\t\t%s\n",user[i].nomor,user[i].nama,user[i].pass);
	}
	//printf("n=%d\n",n);
	//getch();
	fflush(stdin);
	printf("\n   \tMasukkan Nama Anda\t: "); scanf("%[^\n]",user[n].nama);
	fflush(stdin);
	printf("\n   \tMasukkan Passwod Driver 	: "); scanf("%[^\n]",user[n].pass);
	user[n].nomor=n+1;
	fprintf(fu,"\n%03d#%s#%s",user[n].nomor,user[n].nama,user[n].pass);
	printf("\n   \t\t DONE.\n\n");
	getch();
	system("cls");
	fclose(fu);
}
/*********************************
	USER > LOGIN USER
**********************************/
void loginUser(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[],int n){
	char usr[100];
	char password[100];
	int a=0,i;
	for(i=0;i<n;i++){
		fscanf(fu,"%3d#%[^#]#%[^\n]\n",&user[i].nomor,user[i].nama,user[i].pass);
		printf("   %03d\t\t%-20s\t\t%s\n",user[i].nomor,user[i].nama,user[i].pass);
	}
	//printf("n=%d",n);
	//getch();
	do {
		printf("\n\n");
		fflush(stdin);
		printf("   User ID  : "); scanf("%[^\n]",usr);
		fflush(stdin);
		printf("   Password : "); scanf("%[^\n]",password);
		if(strcmp(usr,user[0].nama)==0||strcmp(password,user[0].pass)){
			printf("\n   Login Successful...\n");
			system("pause");
			system("cls");
			break;
		} else {
			printf("   Error\n");
			getch();
		}
		system("cls");
		a++;
	} while(a!=3);
	fclose(fu);
	pesanTaxi(fo,fp,fu,fk,user,data,list,price,n);
}
/*********************************
	USER > LOGIN USER > PESAN TAXI
**********************************/
void pesanTaxi(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[], int n){
	int pilih;
	do {
		printf("\n  Taksi version 1.0.1\n");
		printf("  Copyright 2017 IMAGIN\n");
		printf("  Released under ALPEM Last Project.\n");
		printf("\n   1. Pesan Taxi \n");
		printf("   2. Exit\n");
		printf("\n Enter option [1 & 2 to quit] : "); scanf("%d",&pilih);
		if(pilih==1){
			system("cls");
			waitTaxi(fo,fp,fu,fk,user,data,list,price,n);
		} 
	} while (pilih!=2);
	getch();
	system("cls");
}
/*********************************
	USER > LOGIN USER > PESAN TAXI > WAIT TAXI
**********************************/
void waitTaxi(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[], int n){
	int i,j;
	char satu[]="              .----' `-----.";
	char dua[]="             //^^^^;;^^^^^^`\\ ";
	char tiga[]="     _______//_____||_____()_\\________";
	char empat[]="    /826    :      :                  `\\";
	char lima[]="   |>   ____;      ;  IMAGIN   ____   _<)";
	char enam[]="  {____/    \\_________________/    \\____}";
	char tujuh[]="       \\ '' /                 \\ '' /";
	char delapan[]="        '--'                   '--'";
	char sembilan[]=" ";
	char spasi[]="  ";
	j=0;
	n=5;
	do{
		for(i=0;i<n;i++){
			if(i==1){
				strcpy(spasi,"    ");
			} else if(i==2){
				strcpy(spasi,"          ");
			} else if(i==3){
				strcpy(spasi,"                    ");
			} else if(i==4){
				strcpy(spasi,"                                        ");
			}
			if(i%2==0){
				printf("\n%s%s\n",spasi,satu);
				printf("%s%s\n",spasi,dua);
				printf("%s%s\n",spasi,tiga);
				printf("%s%s\n",spasi,empat);
				printf("%s%s\n",spasi,lima);
				printf("%s%s\n",spasi,enam);
				printf("%s%s\n",spasi,tujuh);
				printf("%s%s\n",spasi,delapan);
				printf("%s%s\n",spasi,sembilan);
			} else {
				printf("\n%s%s\n",spasi,satu);
				printf("%s%s\n",spasi,dua);
				printf("%s%s\n",spasi,tiga);
				printf("%s%s\n",spasi,empat);
				printf("%s%s\n",spasi,lima);
				printf("%s%s\n",spasi,enam);
				printf("%s%s\n",spasi,tujuh);
				printf("%s%s\n",spasi,delapan);
				printf("%s%s\n",spasi,sembilan);
			}
			Sleep(300);
			system("cls");
		}
		j++;	
	} while(j!=3);
	pilihanTaksi(fo,fp,fu,fk,user,data,list,price,n);
}
/*********************************
	USER > LOGIN USER > PESAN TAXI > WAIT TAXI > PILIH
**********************************/
void pilihanTaksi(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[], int n){
	char str1[]="	   _-----_";
	char str2[]="       |       |";
	char str3[]="       |--(o)--|";
	char str4[]="      `---------'";
	char str5[]="       ( ^'U'^ )";
	char str6[]="       /___A___\\";
	char str7[]="        |  ~  |";
	char str8[]="      __'.___.'__";
	char str9[]="    /   `  | ^'I` \\";
	char str3p1[]="     .-----------------------------------.";
	char str4p1[]="    |  Hello, Nama saya ";
	char str5p1[]="     |  Silahkan naik :D                 |";
	char str6p1[]="     '-----------------------------------'";
	//printf("n=%d",n);
	//getch();
	int i, x, pilih;
	for(i=0;i<n;i++){//driver
		fscanf(fp,"%3d#%[^#]#%[^#]#%[^\n]\n",&list[i].nomor,list[i].nama,list[i].id,list[i].pass);
		//printf("   %03d\t\t%-20s\t\t%-20s\t%s\n",list[i].nomor,list[i].nama,list[i].id,list[i].pass);
	}
	for(i=0;i<n;i++){//harga
		fscanf(fo,"%03d#%[^#]#%d\n",&data[i].nomor,data[i].mobil,&data[i].harga);//---
	}
	/*printf("      Nomor\tMobil\t\tHarga\n");
	for(i=0;i<n;i++){
		printf("      %03d \t%-15s %d\n",data[i].nomor,data[i].mobil,data[i].harga);
	}*/
	for(i=0;i<n;i++){//price per km
		fscanf(fk,"%[^#]#%d\n",price[i].nama,&price[i].km);
		//printf("   %s %d\n",price[i].nama,price[i].km);
	}
	i=0;
	do {
		printf("\n\n");
		printf("   %s\n",str1);
		printf("   %s\n",str2);
		printf("   %s%s\n",str3,str3p1);
		printf("   %s%s%-16s|\n",str4,str4p1,list[2].nama);
		printf("   %s%s\n",str5,str5p1);
		printf("   %s%s\n",str6,str6p1);
		printf("   %s\n",str7);
		printf("   %s\n",str8);
		printf("   %s\n",str9);
		printf("\n   Anda mendapatkan driver dengan nama %s dengan nomor %03d semoga perjalan anda menyenangkan.\n",list[2].nama,list[2].nomor);
		printf("   [?]Dimanakah tempat yang anda ingin pergi?\n");
		printf("    1. %s (%d)\n",price[0].nama,price[0].km);
		printf("    2. %s (%d)\n",price[1].nama,price[1].km);
		printf("    3. %s  (%d)\n",price[2].nama,price[2].km);
		printf("\n    Enter option [1-3] : "); scanf("%d",&pilih);
		if(pilih==1){
			x=0;
			system("cls");
			result(fo,fp,fu,fk,user,data,list,price,n,x);
		} else if(pilih==2){
			x=1;
			system("cls");
			result(fo,fp,fu,fk,user,data,list,price,n,x);
		} else if(pilih==3){
			x=2;
			system("cls");
			result(fo,fp,fu,fk,user,data,list,price,n,x);
		}
		pilih=4;
	} while (pilih!=4);
	getch();
	system("cls");
}
/*********************************
	USER > LOGIN USER > PESAN TAXI > WAIT TAXI > PILIH > RESULT
**********************************/
void result(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[], int n, int x){
	char str1[]="	   _-----_";
	char str2[]="       |       |";
	char str3[]="       |--(o)--|";
	char str4[]="      `---------'";
	char str5[]="       ( ^'U'^ )";
	char str6[]="       /___A___\\";
	char str7[]="        |  ~  |";
	char str8[]="      __'.___.'__";
	char str9[]="    /   `  | ^'I` \\";
	char str3p1[]="     .-----------------------------------.";
	char str4p1[]="    |  Destinasi anda ";
	char str5p1[]="     |  dengan bayaran ";
	char str6p1[]="     '-----------------------------------'";
	int i,pilih,nilai=0;
	//printf("x=%d",x);
	//getch();
	for(i=0;i<n;i++){//driver
		fscanf(fp,"%3d#%[^#]#%[^#]#%[^\n]\n",&list[i].nomor,list[i].nama,list[i].id,list[i].pass);
	}
	for(i=0;i<n;i++){//harga
		fscanf(fo,"%03d#%[^#]#%d\n",&data[i].nomor,data[i].mobil,&data[i].harga);//---
	}
	for(i=0;i<n;i++){//price per km
		fscanf(fk,"%[^#]#%d\n",price[i].nama,&price[i].km);
	}
	nilai+=data[x].harga*price[x].km;
	//printf("nilai=%d",nilai);
	//getch();
	do {
		printf("\n\n");
		printf("   %s\n",str1);
		printf("   %s\n",str2);
		printf("   %s%s\n",str3,str3p1);
		printf("   %s%s%-18s|\n",str4,str4p1,price[x].nama);
		printf("   %s%s%-18d|\n",str5,str5p1,nilai);
		printf("   %s%s\n",str6,str6p1);
		printf("   %s\n",str7);
		printf("   %s\n",str8);
		printf("   %s\n",str9);
		printf("\n   Anda sudah menentukan destinasi %s dengan mobil %s akan dikenakan harga %d dan akan dikali %d per km\n",price[x].nama,data[x].mobil,data[x].harga,price[x].km);
		printf("    1. Lanjutkan Perjalanan\n");
		printf("    2. Kembali\n");
		printf("\n    Enter option [1-2] : "); scanf("%d",&pilih);
		if(pilih==1){
			system("cls");
			perjalanan(fo,fp,fu,fk,user,data,list,price,n,x,nilai);
			system("cls");
			
		} else if(pilih==2){
			system("cls");
		} pilih=3;
	} while (pilih!=3);
	getch();
	system("cls");
}
/*********************************
	USER > LOGIN USER > PESAN TAXI > WAIT TAXI > PILIH > RESULT || ANIMASI PERJALANAN
**********************************/
void perjalanan(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[], int n, int x, int nilai){
	int i,j;
	char satu[]="              .----' `-----.";
	char dua[]="             //^^^^;;^^^^^^`\\ ";
	char tiga[]="     _______//_____||_____()_\\________";
	char empat[]="    /826    :      :                  `\\";
	char lima[]="   |>   ____;      ;  IMAGIN   ____   _<)";
	char enam[]="  {____/    \\_________________/    \\____}";
	char tujuh[]="       \\ '' /                 \\ '' /";
	char delapan[]="        '--'                   '--'";
	char sembilan[]=" ";
	char spasi[]="  ";
	j=0;
	n=5;
	do{
		for(i=0;i<n;i++){
			if(i==1){
				strcpy(spasi,"    ");
			} else if(i==2){
				strcpy(spasi,"          ");
			} else if(i==3){
				strcpy(spasi,"                    ");
			} else if(i==4){
				strcpy(spasi,"                                        ");
			}
			if(i%2==0){
				printf("\n%s%s\n",spasi,satu);
				printf("%s%s\n",spasi,dua);
				printf("%s%s\n",spasi,tiga);
				printf("%s%s\n",spasi,empat);
				printf("%s%s\n",spasi,lima);
				printf("%s%s\n",spasi,enam);
				printf("%s%s\n",spasi,tujuh);
				printf("%s%s\n",spasi,delapan);
				printf("%s%s\n",spasi,sembilan);
			} else {
				printf("\n%s%s\n",spasi,satu);
				printf("%s%s\n",spasi,dua);
				printf("%s%s\n",spasi,tiga);
				printf("%s%s\n",spasi,empat);
				printf("%s%s\n",spasi,lima);
				printf("%s%s\n",spasi,enam);
				printf("%s%s\n",spasi,tujuh);
				printf("%s%s\n",spasi,delapan);
				printf("%s%s\n",spasi,sembilan);
			}
			Sleep(300);
			system("cls");
		}
		j++;	
	} while(j!=1);
	tengahPerjalanan(fo,fp,fu,fk,user,data,list,price,n,x,nilai);
}
/*********************************
	USER > LOGIN USER > PESAN TAXI > WAIT TAXI > PILIH > RESULT > TENGAH PERJALANAN
**********************************/
void tengahPerjalanan(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[], int n, int x, int nilai){
	char str1[]="	   _-----_";
	char str2[]="       |       |";
	char str3[]="       |--(o)--|";
	char str4[]="      `---------'";
	char str5[]="       ( ^'U'^ )";
	char str6[]="       /___A___\\";
	char str7[]="        |  ~  |";
	char str8[]="      __'.___.'__";
	char str9[]="    /   `  | ^'I` \\";
	char str3p1[]="     .-----------------------------------.";
	char str4p1[]="    |  Nikmati Perjalanan Anda          | ";
	char str5p1[]="     |  dengan bayaran |";
	char str6p1[]="     '-----------------------------------'";
	int i,pilih;
	char code[100];
	FILE *snk = fopen("snack.txt","r");
	struct snack cemilan[100];
	for(i=0;i<n;i++){//cemilan
		fscanf(snk,"%[^#]#%d\n",cemilan[i].nama,&cemilan[i].harga);
	}
	for(i=0;i<n;i++){//driver
		fscanf(fp,"%3d#%[^#]#%[^#]#%[^\n]\n",&list[i].nomor,list[i].nama,list[i].id,list[i].pass);
	}
	for(i=0;i<n;i++){//harga
		fscanf(fo,"%03d#%[^#]#%d\n",&data[i].nomor,data[i].mobil,&data[i].harga);//---
	}
	for(i=0;i<n;i++){//price per km
		fscanf(fk,"%[^#]#%d\n",price[i].nama,&price[i].km);
	}
	printf("nilai=%d",nilai);
	getch();
	do {
		printf("\n\n");
		printf("   %s\n",str1);
		printf("   %s\n",str2);
		printf("   %s%s\n",str3,str3p1);
		printf("   %s%s\n",str4,str4p1);
		printf("   %s%s\n",str5,str6p1);
		printf("   %s\n",str6);
		printf("   %s\n",str7);
		printf("   %s\n",str8);
		printf("   %s\n",str9);
		printf("\n   Anda sudah menentukan destinasi %s dengan mobil %s akan dikenakan harga %d dan akan dikali %d per km\n",price[x].nama,data[x].mobil,data[x].harga,price[x].km);
		printf("   Harus Beli!! kata supir sambil merekomendasi beng-beng\n");
		printf("    1. %s (%d)\n",cemilan[0].nama,cemilan[0].harga);
		printf("    2. %s (%d)\n",cemilan[1].nama,cemilan[1].harga);
		printf("    3. %s (%d)\n",cemilan[2].nama,cemilan[2].harga);
		printf("    4. Cheat\n");
		//printf("    4. Exit(Mobil)"); DLC
		printf("\n    Enter option [1-4] : "); scanf("%d",&pilih);
		if(pilih==1){
			system("cls");
			nilai+=cemilan[0].harga;
			printf("    Perjalanan akan terasa lama...");
			getch();
			system("cls");
			akhirPerjalanan(fo,fp,fu,fk,user,data,list,price,n,x,nilai);
		} else if(pilih==2){
			nilai+=cemilan[1].harga;
			printf("    Perjalanan akan terasa lama...");
			getch();
			system("cls");
			akhirPerjalanan(fo,fp,fu,fk,user,data,list,price,n,x,nilai);
		} else if(pilih==3){
			nilai+=cemilan[2].harga;
			printf("    Perjalanan akan terasa lama...");
			getch();
			system("cls");
			akhirPerjalanan(fo,fp,fu,fk,user,data,list,price,n,x,nilai);
		} else if(pilih==4){
			/*end();DLC
			pilih=5;*/
			printf("\n     code> "); scanf("%s",code);
			if(strcmpi(code,"ripazha")==0){
				printf("    CHEAT ENABLED  \n");
				getch();
				system("cls");
				flyingCar(fo,fp,fu,fk,user,data,list,price,n,x,nilai);
			} else if(strcmpi(code,"bubblecars")==0){
				printf("    CHEAT ENABLED  \n");
				getch();
				system("cls");
				submarine(fo,fp,fu,fk,user,data,list,price,n,x,nilai);
			} else {
				printf("    Error Cheat\n");
			}
		}
		pilih=5;
	} while (pilih!=5);
	getch();
	system("cls");
}

void submarine(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[], int n, int x, int nilai){
	int i,j;
	char satu[]="     ___     ___     ___";
	char dua[]=" ____\\  \\____\\  \\____\\  \\______";
	char tiga[]=" \\ : : : : : : : : : : : : =  /";
	char empat[]="  ============================";
	char lima[]="  ";
	char spasi[]="  ";
	j=0;
	n=5;
	do{
		for(i=0;i<n;i++){
			if(i==1){
				strcpy(spasi,"    ");
			} else if(i==2){
				strcpy(spasi,"          ");
			} else if(i==3){
				strcpy(spasi,"                    ");
			} else if(i==4){
				strcpy(spasi,"                                        ");
			}
			if(i%2==0){
				printf("\n%s%s\n",spasi,satu);
				printf("%s%s\n",spasi,dua);
				printf("%s%s\n",spasi,tiga);
				printf("%s%s\n",spasi,empat);
				printf("%s%s\n",spasi,lima);
			} else {
				printf("\n%s%s\n",spasi,satu);
				printf("%s%s\n",spasi,dua);
				printf("%s%s\n",spasi,tiga);
				printf("%s%s\n",spasi,empat);
				printf("%s%s\n",spasi,lima);
			}
			Sleep(300);
			system("cls");
		}
		j++;	
	} while(j!=1);
	done(fo,fp,fu,fk,user,data,list,price,n,x,nilai);	
}
/*********************************
	USER > LOGIN USER > PESAN TAXI > WAIT TAXI > PILIH > RESULT > TENGAH PERJALANAN > AKHIR PERJALANAN || ANIMASI CHEAT
**********************************/
void flyingCar(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[], int n, int x, int nilai){
	int i,j;
	char satu[]="   /\\";
	char dua[]="   \\ \\";
	char tiga[]="    \\ \\";
	char empat[]="    /  \\";
	char lima[]="   <===>\\";
	char enam[]="   <    )>";
	char tujuh[]="   <===>/";
	char delapan[]="    \\  /";
	char sembilan[]="    / /";
	char sepuluh[]="   / /";
	char sebelas[]="   \\/";
	char duabelas[]=" ";
	char spasi[]="  ";
	j=0;
	n=5;
	do{
		for(i=0;i<n;i++){
			if(i==1){
				strcpy(spasi,"    ");
			} else if(i==2){
				strcpy(spasi,"          ");
			} else if(i==3){
				strcpy(spasi,"                    ");
			} else if(i==4){
				strcpy(spasi,"                                        ");
			}
			if(i%2==0){
				printf("\n%s%s\n",spasi,satu);
				printf("%s%s\n",spasi,dua);
				printf("%s%s\n",spasi,tiga);
				printf("%s%s\n",spasi,empat);
				printf("%s%s\n",spasi,lima);
				printf("%s%s\n",spasi,enam);
				printf("%s%s\n",spasi,tujuh);
				printf("%s%s\n",spasi,delapan);
				printf("%s%s\n",spasi,sembilan);
				printf("%s%s\n",spasi,sepuluh);
				printf("%s%s\n",spasi,sebelas);
				printf("%s%s\n",spasi,duabelas);
			} else {
				printf("\n%s%s\n",spasi,satu);
				printf("%s%s\n",spasi,dua);
				printf("%s%s\n",spasi,tiga);
				printf("%s%s\n",spasi,empat);
				printf("%s%s\n",spasi,lima);
				printf("%s%s\n",spasi,enam);
				printf("%s%s\n",spasi,tujuh);
				printf("%s%s\n",spasi,delapan);
				printf("%s%s\n",spasi,sembilan);
				printf("%s%s\n",spasi,sepuluh);
				printf("%s%s\n",spasi,sebelas);
				printf("%s%s\n",spasi,duabelas);
			}
			Sleep(300);
			system("cls");
		}
		j++;	
	} while(j!=1);
	done(fo,fp,fu,fk,user,data,list,price,n,x,nilai);	
}
/*********************************
	USER > LOGIN USER > PESAN TAXI > WAIT TAXI > PILIH > RESULT > TENGAH PERJALANAN > AKHIR PERJALANAN || ANIMASI
**********************************/
void akhirPerjalanan(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[], int n, int x, int nilai){
	int i,j;
	char satu[]="              .----' `-----.";
	char dua[]="             //^^^^;;^^^^^^`\\ ";
	char tiga[]="     _______//_____||_____()_\\________";
	char empat[]="    /826    :      :                  `\\";
	char lima[]="   |>   ____;      ;  IMAGIN   ____   _<)";
	char enam[]="  {____/    \\_________________/    \\____}";
	char tujuh[]="       \\ '' /                 \\ '' /";
	char delapan[]="        '--'                   '--'";
	char sembilan[]=" ";
	char spasi[]="  ";
	j=0;
	n=5;
	do{
		for(i=0;i<n;i++){
			if(i==1){
				strcpy(spasi,"    ");
			} else if(i==2){
				strcpy(spasi,"          ");
			} else if(i==3){
				strcpy(spasi,"                    ");
			} else if(i==4){
				strcpy(spasi,"                                        ");
			}
			if(i%2==0){
				printf("\n%s%s\n",spasi,satu);
				printf("%s%s\n",spasi,dua);
				printf("%s%s\n",spasi,tiga);
				printf("%s%s\n",spasi,empat);
				printf("%s%s\n",spasi,lima);
				printf("%s%s\n",spasi,enam);
				printf("%s%s\n",spasi,tujuh);
				printf("%s%s\n",spasi,delapan);
				printf("%s%s\n",spasi,sembilan);
			} else {
				printf("\n%s%s\n",spasi,satu);
				printf("%s%s\n",spasi,dua);
				printf("%s%s\n",spasi,tiga);
				printf("%s%s\n",spasi,empat);
				printf("%s%s\n",spasi,lima);
				printf("%s%s\n",spasi,enam);
				printf("%s%s\n",spasi,tujuh);
				printf("%s%s\n",spasi,delapan);
				printf("%s%s\n",spasi,sembilan);
			}
			Sleep(300);
			system("cls");
		}
		j++;	
	} while(j!=1);
	done(fo,fp,fu,fk,user,data,list,price,n,x,nilai);
}
/*********************************
	USER > LOGIN USER > PESAN TAXI > WAIT TAXI > PILIH > RESULT > TENGAH PERJALANAN > AKHIR PERJALANAN > SAMPAI TUJUAN
**********************************/
void done(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[], int n, int x, int nilai){
	char str1[]="	   _-----_";
	char str2[]="       |       |";
	char str3[]="       |--(o)--|";
	char str4[]="      `---------'";
	char str5[]="       ( ^'U'^ )";
	char str6[]="       /___A___\\";
	char str7[]="        |  ~  |";
	char str8[]="      __'.___.'__";
	char str9[]="    /   `  | ^'I` \\";
	char str3p1[]="     .------------------------------------------.";
	char str4p1[]="    |  Kita sudah sampai di ";
	char str5p1[]="     |  Jangan lupa raiting ya :D               |";
	char str6p1[]="     '------------------------------------------'";
	int i,pilih;
	//printf("x=%d",x);
	//getch();
	for(i=0;i<n;i++){//driver
		fscanf(fp,"%3d#%[^#]#%[^#]#%[^\n]\n",&list[i].nomor,list[i].nama,list[i].id,list[i].pass);
	}
	for(i=0;i<n;i++){//harga
		fscanf(fo,"%03d#%[^#]#%d\n",&data[i].nomor,data[i].mobil,&data[i].harga);//---
	}
	for(i=0;i<n;i++){//price per km
		fscanf(fk,"%[^#]#%d\n",price[i].nama,&price[i].km);
	}
	do {
		printf("\n\n");
		printf("   %s\n",str1);
		printf("   %s\n",str2);
		printf("   %s%s\n",str3,str3p1);
		printf("   %s%s%-19s|\n",str4,str4p1,price[x].nama);
		printf("   %s%s%\n",str5,str5p1);
		printf("   %s%s\n",str6,str6p1);
		printf("   %s\n",str7);
		printf("   %s\n",str8);
		printf("   %s\n",str9);
		printf("\n   Anda sudah sampai dengan selamat di %s dengan bayaran %d\n",price[x].nama, nilai);
		printf("    1. Cetak Struk\n");
		printf("    2. Exit\n");
		printf("\n    Enter option [1-2] : "); scanf("%d",&pilih);
		if(pilih==1){
			cetakStruk(fo,fp,fu,fk,user,data,list,price,n,x,nilai);
		} else if(pilih==2){
			system("cls");
			pilih=3;
		} 
	} while (pilih!=3);
	getch();
	system("cls");
}

void cetakStruk(FILE *fo, FILE *fp, FILE *fu, FILE *fk, struct customer user[], struct car data[], struct driver list[],struct kilo price[], int n, int x, int nilai){
	int i;
	FILE *fs = fopen("struk.txt","w");
	for(i=0;i<n;i++){//driver
		fscanf(fp,"%3d#%[^#]#%[^#]#%[^\n]\n",&list[i].nomor,list[i].nama,list[i].id,list[i].pass);
	}
	for(i=0;i<n;i++){//harga
		fscanf(fo,"%03d#%[^#]#%d\n",&data[i].nomor,data[i].mobil,&data[i].harga);
	}
	for(i=0;i<n;i++){//price per km
		fscanf(fk,"%[^#]#%d\n",price[i].nama,&price[i].km);
	}
	for(i=0;i<n;i++){//user
		fscanf(fu,"%03d#%[^#]#%[^\n]\n",&user[i].nomor,user[i].nama,user[i].pass);
	}
	fprintf(fs,"=======================================\n");
	fprintf(fs,"\tRincian Pembayaran\n");
	fprintf(fs,"=======================================\n");
	fprintf(fs,"\t%s\t%d\n",price[x].nama,nilai);
	fprintf(fs,"\tDriver %s \n\tMobil %s\n",list[2].nama,data[2].mobil);
	fprintf(fs,"=======================================\n");
	fclose(fs);
	printf("   Struk Tercetak!");
	getch();
	system("cls");
}
/*DLC
void end(){
	system("cls");
	printf("\n   Anda ditelantarkan di jalan raya...\n");
}*/

/*********************************
	USER STORY
**********************************/
void story(){
	printf("\n\n   Dahulu kala, ada 1 kota besar yang bernama Twilight Town.  \n");
	Sleep(500);
	printf("   Namun, quadro penguasa keji bernama Efrajaya, Ketan, Natpri, dan EvaKy \n   merusak ketengan itu semua dengan mencoba menaklukkan semua kota.  \n");
	Sleep(500);
	printf("   Semua penduduk melawan, dan kerusuhan 21 mei terjadi. Setelah beberapa lama, terjadilah peace treaty. \n");
	Sleep(500);
	printf("   Sebuah perjanjian yang memecah kota menjadi 3 bagian, Radiant Garden, Hollow Bastion, dan Traverse Town.  \n");
	Sleep(500);
	printf("   Akses diantara kota ini dibutuhkan CTOD (Certified Taxi Owner and Driver). Tanpa itu, kota tidak akan bisa diakses.\n\n");
	system("pause");
	system("cls");
}

/*********************************
	ADMIN
**********************************/
void admin(FILE *fo, FILE *fp, struct car data[], struct driver list[]){
	int pilih,n=0;
	do {
		printf("\n  Taksi version 1.0.1\n");
		printf("  Copyright 2017 IMAGIN\n");
		printf("  Released under ALPEM Last Project.\n");
		printf("\n   1. Login Owner \n");
		printf("   2. Login Driver\n");
		printf("   3. Help Desk Driver\n");
		printf("   4. Exit\n");
		printf("\n Enter option [1-3, 4 to quit] : "); scanf("%d",&pilih);
		if(pilih==1){
			system("cls");
			owner(fp,fo,list,data,&n);
		} else if(pilih==2){
			system("cls");
			loginDriver(fp,list);
		} else if(pilih==3){
			system("cls");
			helpDeskDriver(fp,list,n);
		}
	} while (pilih!=4);
	getch();
	system("cls");
}

/*********************************
	ADMIN > HELP DESK
**********************************/
void helpDeskDriver(FILE *fp, struct driver list[], int n){
	printf("THIS STILL UNDER CONSTRUCTION\n");
	printf("Berisikan hasil report dari inputan user dari helpdesk user\n");
	getch();
	system("cls");
}

/*********************************
	ADMIN > LOGIN DRIVER
**********************************/
void loginDriver(FILE *fp, struct driver list[]){
	int x=1;
	login(fp,list,x);
	printf("THIS STILL UNDER CONSTRUCTION\n");
	printf("Berisikan Gaji, raiting, user yang diantar\n");
	getch();
	system("cls");
	
}

/*********************************
	ADMIN > LOGIN AS DRIVER & OWNER
**********************************/
void login(FILE *fp, struct driver list[], int x){
	//printf("x=%d",x);
	//getch();
	char user[100];
	char password[100];
	int a=0,i,j=0;
	if(x==1){
		//i=0;
		printf("   Driver Login\n");
		x=6;
		for(i=1;i<x;i++){
			fscanf(fp,"%3d#%[^#]#%[^#]#%[^\n]\n",&list[i].nomor,list[i].nama,list[i].id,list[i].pass);
			//printf("   %03d\t\t%-20s\t\t%-20s\t%s\n",list[i].nomor,list[i].nama,list[i].id,list[i].pass);
		}
		j=2;
	} else {
		printf("   Owner Login\n");
		x=1;
		for(i=0;i<x;i++){
			fscanf(fp,"%3d#%[^#]#%[^#]#%[^\n]\n",&list[i].nomor,list[i].nama,list[i].id,list[i].pass);
			//printf("   %03d\t\t%-20s\t\t%-20s\t%s\n",list[i].nomor,list[i].nama,list[i].id,list[i].pass);
		}
		j=0;
	}
	do {
		printf("\n\n");
		fflush(stdin);
		printf("   User ID  : "); scanf("%[^\n]",user);
		fflush(stdin);
		printf("   Password : "); scanf("%[^\n]",password);
		if(strcmp(user,list[j].id)==0||strcmp(user,list[3].id)==0||strcmp(user,list[4].id)==0||strcmp(user,list[5].id)==0/*||strcmp(user,list[6].id)==0*/){
			printf("\n   Login Successful...\n");
			system("pause");
			system("cls");
			break;
		} else {
			printf("   Error\n");
			getch();
		}
		system("cls");
		a++;
	} while(a!=3);
}

/*********************************
	ADMIN > OWNER
**********************************/
void owner(FILE *fp, FILE *fo, struct driver list[], struct car data[], int *n){
	int i,pilih,x;
	i=0;
	x=0;
	login(fp,list,x);
	while(!feof(fp)){
		fscanf(fp,"%3d#%[^#]#%[^#]#%[^\n]\n",&list[i].nomor,list[i].nama,list[i].id,list[i].pass);
		i++;
		(*n)=i;
	}
	//printf("n=%d",*n);
	//getch();
	//(*n)++;
	do {
		printf("\n  Taksi version 1.0.1\n");
		printf("  Copyright 2017 IMAGIN\n");
		printf("  Released under ALPEM Last Project.\n");
		printf("\n   1. Register Driver \n");
		printf("   2. Sort Driver\n");
		printf("   3. Price\n");
		printf("   4. Search Driver\n");
		printf("   5. Exit\n");
		printf("\n Enter option [1-4, 5 to quit] : "); scanf("%d",&pilih);
		if(pilih==1){
			system("cls");
			registerDriver(fp,list,*n);
			(*n)++;
		} else if(pilih==2){
			sortDriver(fp,list,*n);
		} else if(pilih==3){
			system("cls");
			harga(fo,data);
		} else if(pilih==4){
			//search();
		}
	} while (pilih!=5);
	system("cls");
	getch();
}

/*********************************
	ADMIN > OWNER > REGISTER
**********************************/
void registerDriver(FILE *fp, struct driver list[], int n){
	//printf("n=%d\n",n);
	fflush(stdin);
	printf("\n   \tMasukkan Nama Driver\t: "); scanf("%[^\n]",list[n].nama);
	fflush(stdin);
	printf("\n   \tMasukkan ID Driver\t: "); scanf("%[^\n]",list[n].id);
	fflush(stdin);
	printf("\n   \tMasukkan Passwod Driver 	: "); scanf("%[^\n]",list[n].pass);
	list[n].nomor=n;
	fprintf(fp,"\n%03d#%s#%s#%s",list[n+1].nomor,list[n].nama,list[n].id,list[n].pass);
	printf("\n   \t\t DONE.\n\n");
	getch();
	system("cls");
	fclose(fp);
}

/*********************************
	ADMIN > OWNER > SORT DRIVER
**********************************/
void sortDriver(FILE *fp, struct driver list[], int n){
	int i;
	printf("   Nomor\tNama\t\t\t\tID\t\t\tPassword\n");
	printf("   ================================================================================\n");
	for(i=0;i<n;i++){
		printf("   %03d\t\t%-20s\t\t%-20s\t%s\n",list[i].nomor,list[i].nama,list[i].id,list[i].pass);
	}
	getch();
	system("cls");
	fclose(fp);
}

void bubble(struct car data[],int n){
    int i=1,j,k;
	for (i = 1; i < n; i++){//baris
	    for (j = 0; j < n - i; j++) {//kolom
	        if (data[j].harga > data[j + 1].harga) {
	        	temp = data[j];
	            data[j] = data[j + 1];
	            data[j + 1] = temp;
	        }
	    }
	}
}

void insertion(struct car data[], int n){
	int i,j;
	for(i=1;i<=n-1;i++){
    	j=i;
		while(j>0&&data[j].nomor < data[j-1].nomor){
      		temp=data[j];
      		data[j]=data[j-1];
      		data[j-1] = temp; 
      		j--;
    	}
  	}
}

void selection(struct car data[], int n){
	int i, j, temp;
	for(i=0;i<n-1;i++){
		temp=i;
		for(j=i+1;j<n;j++){
			if(strcmp(data[j].mobil , data[temp].mobil)<0){
				temp = j;
			}
		}
		//swap(&arr[temp], &arr[i]);
      	m=data[temp];
      	data[temp]=data[i];
      	data[i] = m; 
	}
}

/*********************************
	ADMIN > OWNER > PRICE
**********************************/
void harga(FILE *fo, struct car data[]){
	int i,n=0,pilih;
	do {
		printf("\n\n");
		printf("   1. Sort Harga(bubble)\n");
		printf("   2. Sort Nomor(insertion)\n");
		printf("   3. Sort Mobil(selection)\n");
		printf("   4. Input Mobil\n");
		printf("   5. List Mobil\n");
		printf("   6. Exit\n");
		printf("\n   Enter option [1-5, 6 to quit] : "); scanf("%d",&pilih);
		if(pilih==6){
			break;
		}
		printf("\n   Berapa List : "); scanf("%d",&n);
		if(pilih==1){
			bubble(data,n);
			printf("   Sorted.\n");
			getch();
			system("cls");
			//for(i=0;i<n;i++){
			//	printf("      %03d \t%-15s %d\n",data[i].nomor,data[i].mobil,data[i].harga);
			//}
		} else if(pilih==2){
			insertion(data,n);
			printf("   Sorted.\n");
			getch();
			system("cls");
		} else if(pilih==3){
			selection(data,n);
			printf("   Sorted.\n");
			getch();
			system("cls");
		} else if(pilih==4){
			inputMobil(fo,data,n);
		} else if(pilih==5){
			//printf("\n   Berapa List : "); scanf("%d",&n);
			listMobil(fo,data,n);
		}	
	} while(pilih!=6);
	getch();
	system("cls");
	fclose(fo);
}

/*********************************
	ADMIN > OWNER > PRICE > INPUT MOBIL
**********************************/
void inputMobil(FILE *fo, struct car data[], int n){
	int i;
	//printf("n=%d",n);
	for(i=0;i<n;i++){
		printf("   Nomor mobil  : "); scanf("%d",&data[i].nomor);
		fflush(stdin);
		printf("   Jenis Mobil  : "); scanf("%[^\n]",data[i].mobil);
		printf("   Harga		: "); scanf("%d",&data[i].harga);
		fprintf(fo,"\n%03d#%s#%d\n",data[i].nomor,data[i].mobil,data[i].harga);
	}
	fclose(fo);
	getch();
	system("cls");
}

/*********************************
	ADMIN > OWNER > PRICE > LIST MOBIL
**********************************/
void listMobil(FILE *fo,struct car data[],int n){
	int i=0;
	//printf("n=%d",n);
	//getch();
	for(i=0;i<n;i++){
		fscanf(fo,"\n%03d#%[^#]#%d\n",&data[i].nomor,data[i].mobil,&data[i].harga);
	}
	printf("      Nomor\tMobil\t\tHarga\n");
	for(i=0;i<n;i++){
		printf("      %03d \t%-15s %d\n",data[i].nomor,data[i].mobil,data[i].harga);
	}
	getch();
	system("cls");
}

/*****************************************************
Sumber 
http://ascii.co.uk/art/taxi
ttps://i.stack.imgur.com/0xe1L.png
http://ezh.sourceforge.net/
https://www.reddit.com/r/PowerShell/comments/4y4oet/module_for_building_cli_menus/
http://www.asciiworld.com/-Planes-.html
http://www.asciiartfarts.com/20121130.html
http://ascii.co.uk/art/submarine
http://ascii.co.uk/art/ships
*****************************************************/
