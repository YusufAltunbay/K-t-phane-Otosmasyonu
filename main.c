#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Kitap {

	char KitapIsmi[30];
	char YazarIsmi[30];
	char KitapCesidi[30];
	int kitapSayfasi;
	int kitapNumarasi;
	int stokSayisi;
} kitap ;
typedef struct Kullanicilar {

	char adSoyad[30];
	char telefon [30];
	char uyelikTarihi[30];
	int kullaniciNumarasi;
	int durum;
} Kullanicilar ;
typedef struct Emanet {

	int kullaniciNumarasi;
    int kitapNu;
    int kullanacagiGunSayisi;
    time_t teslimTarihi ;
    int kullandigiGunSayisi;
	time_t iadeTarihi ;
	int gecikmeGunSayisi;
    int durum1;
    int stok;
} emanet ;
int menu()
{
	int j;
	int secim;
	printf("\n\t YUSUF ALTUNBAY KUTUPHANE OTOMASYON SISTEMINE HOSGELDINIZ \n\t\t LUTFEN YAPACAGINIZ ISLEMI SECINIZ\n") ;
	for( j=1;j<70;j++)
    {
        printf("=");
    }
    printf("\n");

	printf("\t1- KITAP ISLEMLERI \n");
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("\t2- KULLANICI ISLEMLERI \n");
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("\t3- EMANET KITAP ISLEMLERI \n");
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("\t0- PROGRAMI KAPAT \n");
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("\tLUTFEN YAPMAK ISTEDIGINIZ ISLEMIN KODUNU GIRINIZ : ");  	scanf("%d", &secim);
	return secim;
}
int main()
{
	int secim= menu();

	while( secim != 0 )
	{
		switch(secim )
		{
			case 1: kitapIslemleri(); break;
			case 2: kullaniciIslemleri(); break;
			case 3: emanetKitapIslemleri(); break;
			case 0: break;
			default : printf("YAPTIGINIZ SECIM HATALIDIR!! \n");
		}
		secim= menu();
	}

	printf("PROGRAMI KAPATTINIZ ") ;
	return 0;
}
void kitapIslemleri()
{
	int j;
	system("cls");
	printf("#KITAP ISLEMLERI EKRANI# \n") ;
    for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	int secim;
	printf("1-KITAP EKLE\n");
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("2-KITAP SIL\n");
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("3-KITAP LISTELE\n");
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("4-KITAPLARDA ARAMA YAPMA\n");
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("5-KITAP GUNCELLEME\n");
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("0-ANA MENUYE DON\n");
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("LUTFEN YAPMAK ISTEDIGINIZ ISLEMIN KODUNU GIRINIZ :");  scanf("%d", &secim);

	switch(secim )
	{
		case 1: kitapEkle(); break;
		case 2: kitapSil(); break;
		case 3: kitapListele(); break;
		case 4: kitapAra(); break;
		case 5: kitapGuncelle(); break;
		case 0: break;
		default: printf("YAPTIGINIZ SECIM HATALI,ANA MENUYE YONLENDIRILIYORSUNUZ \n") ; break;
	}
}
void kitapEkle()
{
    int j;
	system("cls");
	printf("#KITAP EKLEME EKRANI#\n") ;
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
    kitap k1;
	printf("KITAP ADINI GIRINIZ:") ; scanf(" %[^\n]s", k1.KitapIsmi );
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("YAZAR ADINI GIRINIZ:") ; scanf(" %[^\n]s", k1.YazarIsmi );
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("KITAP TURUNU GIRINIZ: ") ; scanf(" %[^\n]s", k1.KitapCesidi );
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
    printf("KITAP SAYFASINI GIRINIZ: ") ; scanf("%d",&k1.kitapSayfasi);
    for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
	printf("KAC ADET KITAP EKLEYECEKSINIZ: ") ; scanf(" %d", &k1.stokSayisi );
	for( j=1;j<40;j++)
    {
        printf("=");
    }

	srand((unsigned int)time(NULL));
    k1.kitapNumarasi = rand()%1000;

	FILE * ptr= fopen("kitaplar.txt", "a+b");
	fwrite( &k1, sizeof(kitap), 1, ptr );
	fclose(ptr);
	printf("\nKITAP KAYDI BASARIYLA KAYDEDILMISTIR\n");
	for( j=1;j<40;j++)
    {
        printf("=");
    }

}
void kitapSil()
{
    int j;
	system("cls");
	printf("#KITAP SILME EKRANI#\n") ;
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");

	kitap k1;
	int kitapNo, sonuc=0;

	printf("SILMEK ISTEDIGINIZ KITAP NUMARASINI GIRINIZ:") ; scanf(" %d", &kitapNo);
	for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");

	FILE * ptr= fopen("kitaplar.txt", "r+b");
	FILE * yptr= fopen("yedek.txt", "w+b");


	while( fread( &k1, sizeof(kitap), 1, ptr ) != NULL   )
	{
		if( kitapNo != k1.kitapNumarasi  )
		fwrite ( &k1, sizeof(kitap), 1, yptr ) ;
		else
		sonuc= 1;
	}

	fclose(ptr);
	fclose(yptr);
	if(sonuc==0)
	{
		printf("%d NUMARALI KITAP ENVANTERIMIZDE YOKTUR \n", kitapNo );
		for( j=1;j<40;j++){printf("=");}printf("\n");

	}
	else
	{
		remove("kitaplar.txt");
		rename("yedek.txt", "kitaplar.txt");
		printf("%d  NUMARALI KITAP BASARIYLA SILINMISTIR \n", kitapNo );
		for( j=1;j<40;j++){printf("=");}printf("\n");
	}
}
void kitapListele()
{
    int j;
	system("cls");
	printf("#KITAP LISTELEME EKRANI#\n") ;
	for( j=1;j<140;j++)
    {
        printf("=");
    }
    printf("\n");

	kitap k1;
	int kitapSayisi=0;
	FILE * ptr= fopen("kitaplar.txt", "r+b");

	printf("%-20s%-30s%-30s%-30d%-30s%-20s\n", "KITAP NUMARASI", "KITAP-ADI", "YAZAR-ADI","KITAP SAYFASI", "KITAP-TURU", "STOK" ) ;
	for( j=1;j<160;j++)
    {
        printf("=");
    }
    printf("\n");


	while( fread( &k1, sizeof(kitap), 1, ptr ) != NULL   )
	{
	printf("%-20d%-30s%-30s%-30d%-30s%-20d\n", k1.kitapNumarasi, k1.KitapIsmi,k1.YazarIsmi,k1.kitapSayfasi,k1.KitapCesidi,k1.stokSayisi );
	for( j=1;j<160;j++)
    {
        printf("=");
    }
    printf("\n");
	kitapSayisi += k1.stokSayisi ;
	}

	fclose(ptr);


	printf("\nTOPLAM KITAP SAYISI : %d \n", kitapSayisi );
	for( j=1;j<160;j++)
    {
        printf("=");
    }
    printf("\n");
}

void kitapGuncelle() {
    int j;
    int guncellenecekNumara;
    printf("GUNCELLEMEK ISTEDIGINIZ KITABIN NUMARASINI GIRINIZ: ");
    scanf("%d", &guncellenecekNumara);
    for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");

    FILE *dosya = fopen("kitaplar.txt", "r+b");
    if (dosya == NULL) {
        printf("!!DOSYA ACILAMADI!!\n");
        for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
        return;
    }

    kitap k;

    int bulundu = 0;

    while (fread(&k, sizeof(kitap), 1, dosya) == 1) {
        if (k.kitapNumarasi == guncellenecekNumara) {
            printf("KITABIN YENI BILGILERINI GIRINIZ:\n");
            for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
            printf("KITAP ADI: "); scanf(" %[^\n]s", k.KitapIsmi);
            for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
            printf("YAZAR ADI: "); scanf(" %[^\n]s", k.YazarIsmi);
            for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
            printf("KITAP TURU: "); scanf(" %[^\n]s", k.KitapCesidi);
            for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
            printf("KITAP SAYFASI: "); scanf("%d", &k.kitapSayfasi);
            for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");

            fseek(dosya, -sizeof(kitap), SEEK_CUR);
            fwrite(&k, sizeof(kitap), 1, dosya);

            bulundu = 1;
            break;
        }
    }

    fclose(dosya);

    if (!bulundu) {
        printf("!!KITAP BULUNAMADI!!\n");
        for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
    } else {
        printf("KITAP BASARIYLA GUNCELLENDI\n");
        for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
    }
}
void kitapAra() {
    int j;
    int arananKNumara;
    printf("ARAMAK ISTEDIGINIZ KITABIN NUMARASINI GIRINIZ: ");
    scanf("%d", &arananKNumara);for( j=1;j<40;j++){printf("=");} printf("\n");


    FILE *dosya = fopen("kitaplar.txt", "r+b");
    if (dosya == NULL) {
        printf("!!DOSYA ACILAMADI!!\n");for( j=1;j<40;j++){printf("=");} printf("\n");

        return;
    }

    kitap k;
    int bulundu = 0;

    while (fread(&k, sizeof(kitap), 1, dosya) == 1) {
        if (k.kitapNumarasi == arananKNumara) {
            printf("KITAP NUMARASI: %d\n", k.kitapNumarasi);for( j=1;j<40;j++){printf("=");} printf("\n");

            printf("KITAP ADI: %s\n", k.KitapIsmi);for( j=1;j<40;j++){printf("=");} printf("\n");
            printf("YAZAR ADI: %s\n", k.YazarIsmi);for( j=1;j<40;j++){printf("=");} printf("\n");
            printf("KITAP TURU: %s\n", k.KitapCesidi);for( j=1;j<40;j++){printf("=");} printf("\n");
            printf("KITAP SAYFASI: %d\n", k.kitapSayfasi);for( j=1;j<40;j++){printf("=");} printf("\n");


            bulundu = 1;
            break;
        }
    }

    fclose(dosya);

    if (!bulundu) {
        printf("!!KITAP BULUNAMADI!!\n");
           for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");
    }

}
void kullaniciIslemleri()
{
	int j;
	system("cls");
	printf("##KULLANICI ISLEMLERI EKRANI##\n") ;
	   for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");


	int secim;

	printf("1-KULLANICI EKLE\n");
	   for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");

	printf("2-KULLANICI SIL \n");
	   for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");

	printf("3-KULLANICI LISTELE \n");
	   for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");

	printf("4-KULLANICI ARAMA\n");
	   for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");

	printf("5-KULLANICI GUNCELLE\n");
	   for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");

	printf("0-ANA MENUYE DON \n");
	   for( j=1;j<40;j++)
    {
        printf("=");
    }
    printf("\n");

	printf("YAPACAGINIZ ISLEMIN KODUNU GIRINIZ: ");  scanf("%d", &secim);
	   for( j=1;j<40;j++){printf("=");} printf("\n");


	switch(secim )
	{
		case 1: kullaniciEkle(); break;
		case 2: kullaniciSil(); break;
		case 3: kullaniciListele(); break;
		case 4: kullaniciAra(); break;
		case 5: kullaniciguncelle(); break;
		case 0: break;
		default: printf("Hatali secim yaptiniz, ana menuye yonlendiriliyorsunuz... \n") ; break;
	}
}
void kullaniciEkle()
{
    int j;
	system("cls");
	printf("UYE EKLEME EKRANI\n") ;
	 for( j=1;j<40;j++){printf("=");} printf("\n");


	Kullanicilar k2;


	printf("AD-SOYAD: ") ; scanf(" %[^\n]s", k2.adSoyad )  ;
     for( j=1;j<40;j++){printf("=");} printf("\n");


	printf("TELEFON NUMARASI: ") ; scanf(" %[^\n]s",k2.telefon )  ;
	 for( j=1;j<40;j++){printf("=");} printf("\n");


	printf("UYELIK TARIHI:") ; scanf(" %[^\n]s", k2.uyelikTarihi )  ;
	 for( j=1;j<40;j++){printf("=");} printf("\n");


	srand((unsigned int)time(NULL));
    k2.kullaniciNumarasi = rand()%1000;

	k2.durum= 0;
	FILE * ptr= fopen("kullanicilar.txt", "a+b");
	fwrite( &k2, sizeof(Kullanicilar), 1, ptr );
	fclose(ptr);
	printf("YENI KULLANICI BASARI ILE KAYDEDILDI\n");
	 for( j=1;j<40;j++){printf("=");} printf("\n");


}
void kullaniciSil()
{
    int j;
	system("cls");
	printf("UYE SILME EKRANI\n") ;
	 for( j=1;j<40;j++){printf("=");} printf("\n");


	Kullanicilar k2;
	int sonuc=0;
	int uyeNuma;

	printf("SILMEK ISTEDIGINIZ KULLANICIN NUMARASINI GIRINIZ: ") ; scanf(" %d", &uyeNuma );
	 for( j=1;j<40;j++){printf("=");} printf("\n");


	FILE * ptr= fopen("kullanicilar.txt", "r+b");
	FILE * yptr= fopen("yedek.txt", "w+b");


	while( fread( &k2, sizeof(Kullanicilar ), 1, ptr ) != NULL   )
	{
		if(   uyeNuma !=  k2.kullaniciNumarasi   )
		fwrite ( &k2, sizeof(Kullanicilar), 1, yptr ) ;
		else
		sonuc= 1;
	}

	fclose(ptr);
	fclose(yptr);
	if(sonuc==0)
	{
		printf("%d KULLANICI NUMARALI KISI BULUNAMADI\n", uyeNuma  );
		 for( j=1;j<40;j++){printf("=");} printf("\n");

	}
	else
	{
		remove("kullanicilar.txt");
		rename("yedek.txt", "kullanicilar.txt");
		printf("%d KULLANICI NUMARALI KISI BASARI ILE SILINDI\n", uyeNuma);
		 for( j=1;j<40;j++){printf("=");} printf("\n");

	}
}
void kullaniciListele()
{
    int j;
	system("cls");
	printf("UYE LISTELEME EKRANI\n") ;
	 for( j=1;j<140;j++){printf("=");} printf("\n");


	Kullanicilar k2;
	int kisiSayisi=0;
	FILE * ptr= fopen("kullanicilar.txt", "r+b");

	printf("%-20s%-30s%-20s%-20s\n", "KULLANICI NUMARASI", "AD-SOYAD", "TELEFON",  "UYELIK-TARIH");
	 for( j=1;j<120;j++){printf("=");} printf("\n");


	while( fread( &k2, sizeof(Kullanicilar ), 1, ptr ) != NULL   )
	{
	printf("%-20d%-30s%-20s%-20s\n", k2.kullaniciNumarasi, k2.adSoyad, k2.telefon, k2.uyelikTarihi);
	 for( j=1;j<120;j++){printf("=");} printf("\n");


	kisiSayisi++ ;
	}

	fclose(ptr);
	printf("\nTOPLAM KULLANICI SAYISI: %d \n",kisiSayisi );
	 for( j=1;j<140;j++){printf("=");} printf("\n");

}
void kullaniciguncelle() {
    int j;
    int guncellenecekNumara;
    printf("GUNCELLEMEK ISTEDIGINIZ KISININ KULLANICI NUMARASINI GIRINIZ: ");
    scanf("%d", &guncellenecekNumara);
     for( j=1;j<40;j++){printf("=");} printf("\n");


    FILE *dosya = fopen("kullanicilar.txt", "r+b");
    if (dosya == NULL) {
        printf("!!DOSYA ACILAMADI!!\n");
         for( j=1;j<40;j++){printf("=");} printf("\n");

        return;
    }

    Kullanicilar k2;

    int bulundu = 0;

    while (fread(&k2, sizeof(Kullanicilar), 1, dosya) == 1) {
        if (k2.kullaniciNumarasi == guncellenecekNumara) {
            printf("YENI UYE BILGILERINI GIRINIZ:\n");
             for( j=1;j<40;j++){printf("=");} printf("\n");

            printf("AD-SOYAD: "); scanf(" %[^\n]s", k2.adSoyad);
             for( j=1;j<40;j++){printf("=");} printf("\n");

            printf("TELEFON MUMARASI : "); scanf(" %[^\n]s", k2.telefon);
             for( j=1;j<40;j++){printf("=");} printf("\n");

            printf("UYELIK TARIHI: "); scanf(" %[^\n]s", k2.uyelikTarihi);
             for( j=1;j<40;j++){printf("=");} printf("\n");


            fseek(dosya, -sizeof(Kullanicilar), SEEK_CUR);
            fwrite(&k2, sizeof(Kullanicilar), 1, dosya);

            bulundu = 1;
            break;
        }
    }

    fclose(dosya);

    if (!bulundu) {
        printf("KULLANICI BULUNAMADI\n");
         for( j=1;j<40;j++){printf("=");} printf("\n");

    } else {
        printf("KULLANICI BASARI ILE GUNCELLENDI\n");
         for( j=1;j<40;j++){printf("=");} printf("\n");

    }
}
void kullaniciAra() {
    int j;
    int arananNumara;
    printf("ARAMAK ISTEDIGINIZ KULLANICININ  NUMARASINI GIRINIZ: ");
    scanf("%d", &arananNumara);
     for( j=1;j<40;j++){printf("=");} printf("\n");



    FILE *dosya = fopen("kullanicilar.txt", "rb");
    if (dosya == NULL) {
        printf("!!DOSYA ACILAMADI!!\n");
         for( j=1;j<40;j++){printf("=");} printf("\n");

        return;
    }

    Kullanicilar k2;
    int bulundu = 0;

    while (fread(&k2, sizeof(Kullanicilar), 1, dosya) == 1) {
        if (k2.kullaniciNumarasi == arananNumara) {
            printf("KULLANICI NUMARASINI GIRINIZ: %d\n", k2.kullaniciNumarasi);
             for( j=1;j<40;j++){printf("=");} printf("\n");

            printf("AD-SOYAD: %s\n",k2.adSoyad);for( j=1;j<40;j++){printf("=");} printf("\n");
            printf("TELEFON NUMARASI: %s\n",k2.telefon);for( j=1;j<40;j++){printf("=");} printf("\n");
            printf("UYELIK TARIHI: %s\n",k2.uyelikTarihi);for( j=1;j<40;j++){printf("=");} printf("\n");



            bulundu = 1;
            break;
        }
    }

    fclose(dosya);

    if (!bulundu) {
        printf("KULLANICI BULUNAMADI\n");
         for( j=1;j<40;j++){printf("=");} printf("\n");

    }
}
void emanetKitapIslemleri()
{
    int j;
	system("cls");
	printf("EMANET KITAP ISLEMLERI EKRANI\n") ;
	 for( j=1;j<40;j++){printf("=");} printf("\n");


	int secim;
	printf("1-EMANET KITAP ALMA\n");
	 for( j=1;j<40;j++){printf("=");} printf("\n");

	printf("2-EMANET KITABI IADE ETME\n");
	 for( j=1;j<40;j++){printf("=");} printf("\n");



	printf("0-ANA MENUYE DON\n");
	 for( j=1;j<40;j++){printf("=");} printf("\n");

	printf("LUTFEN YAPMAK ISTEDIGINIZ ISLEMIN KODUNU GIRINIZ: ");  scanf("%d", &secim);
	 for( j=1;j<40;j++){printf("=");} printf("\n");


	switch(secim )
	{
		case 1: emanetKitapVer(); break;
		case 2: emanetKitabiIadeAl(); break;

		case 0: break;
		default: printf("HATALI SECIM YAPTINIZ,ANA MENUYE YONLENDIRILIYORSUNUZ\n") ; break;
	}
}
void stokGuncelle( int kitapNo, int sayi  )
{
    int j;
	kitap k1;
	emanet e1;
	int sayac=0;
	FILE * ptr= fopen("kitaplar.txt", "r+b");
	while( fread( &k1, sizeof(kitap), 1, ptr ) != NULL   )
	{
		if( kitapNo == k1.kitapNumarasi  )
		break;
		sayac++;
	}
	while( fread( &e1, sizeof(emanet), 1, ptr ) != NULL   )
	{
		if( kitapNo == k1.kitapNumarasi  )
		break;
		sayac++;
	}


	rewind(ptr) ;

	fseek ( ptr, (sayac) * sizeof(kitap), 0 ) ;

	k1.stokSayisi += sayi;
	fwrite ( &k1, sizeof(kitap), 1, ptr ) ;
	fclose(ptr);
	printf("STOK BASARIYLA GUNCELLENDI\n");
	 for( j=1;j<40;j++){printf("=");} printf("\n");

}

void emanetKitapVer()
{
    int j;
	system("cls");
	printf("EMANET KITAP VERME EKRANI\n");
	 for( j=1;j<40;j++){printf("=");} printf("\n");

	emanet e1;
	Kullanicilar k2;
	kitap k1;
	int usonuc=0, ksonuc=0;

	printf("KULLANICI NUMARANIZI GIRERMISINIZ: "); scanf(" %d", &e1.kullaniciNumarasi );
	 for( j=1;j<40;j++){printf("=");} printf("\n");

	printf("EMANET ALMAK ISTEDIGINIZ KITABIN NUMARASINI GIRERMISINIZ : "); scanf("%d", &e1.kitapNu );
	 for( j=1;j<40;j++){printf("=");} printf("\n");

	FILE * uptr= fopen("kullanicilar.txt", "r+b");
	while( fread( &k2, sizeof(Kullanicilar ), 1, uptr ) != NULL  )
	{
		if( e1.kullaniciNumarasi==k2.kullaniciNumarasi )
		{
			usonuc=1;
			break;
		}
	}
	fclose(uptr);
	if(usonuc==0)
	{
		printf("%s KULLANICI NUMARALI UYE YOKTUR,ANA MENUYE YONLENDIRILIYORSUNUZ\n", e1.kullaniciNumarasi );
		 for( j=1;j<40;j++){printf("=");} printf("\n");

		return ;
	}


	FILE * kptr= fopen("kitaplar.txt", "r+b");
	while( fread( &k1, sizeof(kitap ), 1, kptr ) != NULL  )
	{
		if(  e1.kitapNu== k1.kitapNumarasi )
		{
			ksonuc=1;
			break;
		}
	}
	fclose(kptr);
	if(ksonuc==0)
	{
		printf("%d NUMARALI KITAP KAYDI YOKTUR,ANA MENUYE YONLENDIRILIYORSUNUZ\n", e1.kitapNu );
		 for( j=1;j<40;j++){printf("=");} printf("\n");

		return ;
	}
	if( k1.stokSayisi < 1 )
	{
		printf("%d NUMARALI KITAP ENVANTERDE YOKTUR! ,ANA MENUYE YONLENDIRILIYORSUNUZ\n", e1.kitapNu );
		 for( j=1;j<40;j++){printf("=");} printf("\n");

		return ;
	}
    FILE *ptr = fopen("emanetler.txt", "a+b");
    printf("KAC GUNLUGUNE EMANET ALACAKSINIZ: ");
    scanf(" %d", &e1.kullanacagiGunSayisi);
     for( j=1;j<40;j++){printf("=");} printf("\n");

    e1.teslimTarihi = time(0);
    fwrite(&e1, sizeof(emanet), 1, ptr);
    fclose(ptr);
    printf("EMANET KAYDI BASARI ILE TAMAMLANMISTIR\n");
     for( j=1;j<40;j++){printf("=");} printf("\n");

    stokGuncelle(e1.kitapNu, -1);

}
void kullaniciGuncelle( char *kullaniciNumarasiPtr  )
{
    int j;
	Kullanicilar k2;
	int sonuc=0, sayac=0;

	FILE * ptr= fopen("kullanicilar.txt", "r+b");

	while( fread( &k2, sizeof(Kullanicilar ), 1, ptr ) != NULL   )
	{
		if(  strcmp( kullaniciNumarasiPtr, k2.kullaniciNumarasi ) ==0  )
		{
			sonuc=1;
			break;
		}
		sayac++;
	}
	if( sonuc == 1 )
	{
	rewind(ptr);
	fseek ( ptr, (sayac)*  sizeof(Kullanicilar), 0  ) ;
	k2.durum=-1;
	fwrite ( &k2, sizeof(Kullanicilar), 1, ptr ) ;
	printf("UYE DURUMU BASARI ILE GUNCELLLENDI\n");
	 for( j=1;j<40;j++){printf("=");} printf("\n");

	}
	fclose(ptr);
}

void emanetKitabiIadeAl()
{
    int j;
	system("cls");
	printf("EMANET KITAP IADE ISLEMLERI EKRANI\n");
	 for( j=1;j<40;j++){printf("=");} printf("\n");

	emanet e1;
	Kullanicilar k2;
	kitap k1;
	int sonuc=0, sayac=0 ;
	int uyeNum;
	int kitapNum;

	printf("KULLANICI NUMARANIZI GIRINIZ: "); scanf(" %d", &uyeNum ); for( j=1;j<40;j++){printf("=");} printf("\n");
	printf("KITAP NUMARASINI GIRINIZ: "); scanf("%d", &kitapNum ); for( j=1;j<40;j++){printf("=");} printf("\n");
	FILE * ptr= fopen("emanetler.txt", "r+b");
	while( fread( &e1, sizeof( emanet ), 1, ptr ) != NULL  )
	{
		if(  e1.kullaniciNumarasi ==  uyeNum     && kitapNum == e1.kitapNu   )
		{
			sonuc=1;
			break;
		}
		sayac++;
	}

	if(sonuc==0)
	{
		fclose(ptr);
		printf("%s KULLANICI NUMARALI %d KITAP NUMARALI KAYIT BULUNAMADI !\n\n", uyeNum, kitapNum );
		 for( j=1;j<40;j++){printf("=");} printf("\n");

		return ;
	}
	else
	{
		rewind(ptr);
	e1.iadeTarihi = time(0);
	float saniye, dakika, saat, gun;
	saniye= difftime( e1.iadeTarihi, e1.teslimTarihi ) ;
	dakika= saniye/60;
	saat= dakika/60;
	gun= saat/24;
	e1.kullandigiGunSayisi =     gun;

	printf("KULLANDIGINIZ SAAT :  %.2f\n", saat )	;
	 for( j=1;j<40;j++){printf("=");} printf("\n");

	printf("KULLANDIGINIZ GUN:  %.2f\n", gun)	;
	 for( j=1;j<40;j++){printf("=");} printf("\n");


	e1.gecikmeGunSayisi = e1.kullanacagiGunSayisi- e1.kullandigiGunSayisi;


	if( e1.gecikmeGunSayisi > 10  )
		e1.durum1= -1;
	else
	e1.durum1= 1;

	fseek ( ptr,(sayac) *sizeof(emanet ), 0 ) ;
	fwrite ( &e1, sizeof(emanet ), 1, ptr ) ;
	fclose(ptr);
	printf("IADE ISLEMI BASARI ILE TAMAMLANMISTIR\n");
	 for( j=1;j<40;j++){printf("=");} printf("\n");



	stokGuncelle( e1.kitapNu, 1 );

	if(e1.durum1==-1 )
	kullaniciGuncelle(uyeNum);

	}

}
