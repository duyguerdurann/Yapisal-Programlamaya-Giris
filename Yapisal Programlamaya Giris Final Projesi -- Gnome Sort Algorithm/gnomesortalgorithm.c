//Tumlesik kutuphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  //clock fonksiyonunu kullanmamizi saglar
#include <locale.h>
#include <windows.h>
#define dMAX 10000
#define tmax 10

// Global Degisken tanimlari
int data_number[tmax]; // girilen sayi adedini tutuyor. 
int times[tmax];
int iter = 0; //kacinci aramada oldugunun bilgisi

//Fonksiyon tanimlari
void gnomesort();
void printHistogram();

void gnomesort()
    {   
        int i,k, temp, array[dMAX],n;
        printf("\t     Siralanacak sayi adedini giriniz:");
        scanf("%d", &n);
        printf("\t     Siralanacak sayilari bosluk birakarak giriniz. :\n");
        printf("\t     ");
        for (i = 0; i < n; i++)
            scanf(" %d", &array[i]);
        i = 0;
        clock_t baslangic = clock(); // gecen süreyi hesaplamak icin islem saatinin baslatiriz. 
        while (i < n)  // Gnome Sort siralama yapilmasi
        {
            if (i == 0 || array[i - 1] <= array[i])
                i++;
            else
            {
                temp = array[i-1];
                array[i - 1] = array[i];
                array[i] = temp;
                i = i - 1;
            }
        }printf(" \t     Gnome Sorted :");
        for (i = 0;i < n;i++)
            printf("%d  ", array[i]); //siralanmis diziyi ekrana yazdirdik
        clock_t bitis= clock(); // islem saatini bitiririz.
        float saniye= ((double)(bitis - baslangic) / CLOCKS_PER_SEC); // Saniyeyi hesaplar degiskene atariz
        int ms= saniye *1000; // histogram için sadelestirme yaptik (optimizasyon). Milisaniyeyi bulup degiskene atadik
        printf(" \n\t     %d milisaniyede islem yapýldý.\n", ms); // milisaniyeyi yazdiririz.	  
		data_number[iter] = n; // tutulacak sayi adetini diziye attik
		times[iter] = ms; // hesaplanan milisaniyeye diziye atildi. 
		iter++; // devamliligi sagladik 
		//Siralanan sayi adetlerini ve Siralanan dizinin sürelerini data_number ve times dizilerinden tuttuk ve her islemde yazdirdik. 
		for(k = 0; k < iter; k++){   
			printf("\n\t     Siralanan sayi adedi [%d] = %d\n", k, data_number[k]);
			printf("\t     Siralanan dizinin süresi [%d] = %d\n", k, times[k]); 
		}	  		
    }
    
void printHistogram() {
	int k,n,t;
    printf("\n");
	printf(" %18s%20s%18s    \n\n", "  \t     Veri adeti (N)   "," \t Çalisma Süresi (MS) ","  \t  Histogram "); // histogram için kullanacagimiz veriler
	int i ;
	for(k=0;k<iter;k++){ //verileri ve  sürelerini sirayla diziden yazdirdik
		printf(" %20u%20d   \t      ---->       ",data_number[k],times[k]);
		//birinci arama isleminin sonucunu digerlerine oranla  *** kodun iyilestirilmesi***
		//(en küçük olan veriyi buluyorum, 1 yildiz veriyorum, digerlerini ona oranliyorum)
	  /*int smallest = times[0];
 
	   for ( i = 1; i < iter; i++) {
	      if (times[i] < smallest) {
	         smallest = times[i];
	      }
	   }
		int divide_result = times[k] / smallest; */
				
		for(t=0; t <  times[k] /* divide_result */; t++){ 
			printf("%c",'*' );
		}
			printf("\n");
	}
}

int main() {

	setlocale(LC_ALL, "Turkish"); 	//Turkcelestirme
    system(" color 0F "); // Tema renk ayari
    
	//Degisken tanimlari
	int islem = 0;
	char tekrar = 'e';
	while (tekrar == 'e') {
		//Islem secimi
		printf(" \n\n       ~~ YAPISAL PROGRAMLAMAYA GÝRÝÞ FÝNAL PROJESÝ --> GNOME SORT ALGORITHM ~~ \n");
		printf( "\n                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		        "                 ~    1- GNOME SORT HESAPLAMA    ~ \n"
		        "                 ~                               ~ \n"
				"                 ~    2- HÝSTOGRAM OLUÞTURMA     ~  \n"
				"                 ~                               ~ \n"
				"                 ~    3- PROGRAMDAN ÇIKMA        ~   "
				"\n                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"
				"\n\t     Yapmak istediginiz iþlemin numarasýný giriniz: ");	
		scanf("%d", &islem);
		switch (islem) {
		case (1):
	        gnomesort();
			break;
		case (2):
			printHistogram();
			break;
		case (3):
			exit(0);
			break;
		default:
			printf("\t     Ýslem seçilmedi.");
		}
		//Tekrarlayim mi?
		tekrar = 'h';
		printf("\n\t     Tekrar islem yapmak istiyor musunuz (e/h)? ");
		scanf(" %c", &tekrar);
	
		//tekrar karakter kontrolu
		while(tekrar != 'e' && tekrar != 'h'){
			printf("\"%c\" geçerli deðildir.\n"
		  "\t     Lütfen geçerli karakter giriniz (e/h): ", tekrar);
			scanf(" %c", &tekrar);
		}
		printf("\n");
	}
	return 0;
}


