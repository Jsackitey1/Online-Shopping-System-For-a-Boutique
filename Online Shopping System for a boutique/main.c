#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showshops(void);
void showDetails(int arrayIndex);
void showClothes(void);
void showClothesDetails(int arrayIndex);
void addClothing(void);

struct clothing
{
    int clothcode;
    int clothyear;

    struct shopselling
{
    char shopname;
    unsigned long long int theirphonenumber;
}shopselling;

struct price
{
  char currency;
  int amount;
}price;

union size
{
int digit;
char letter;
char word[30];
}size;
int sizetype;

};

struct shopselling allshops[20];
struct clothing allcloths[20];
 int shopcount=0;
 int clothcount=0;



int main()

{
   struct shopselling shop1 =  {.shopname="zen fields",.theirphonenumber= 233593935047};
   struct shopselling shop2 ={.shopname="kwame enterprise",.theirphonenumber= 233248097466};
   allshops[0]=shop1;
   allshops[1]=shop2;
   shopcount=2;

   struct clothing cloth1 ={.clothcode=11183,.clothyear=2001,.sizetype=3,.size.digit=4,.size.letter='L',.size.word="Jeans",.price.currency='$',.price.amount = 70,.shopselling.shopname= shop1.shopname,.shopselling.theirphonenumber = shop1.theirphonenumber,};
   struct clothing cloth2 ={.clothcode=1222,.clothyear=2014,.sizetype=3,.size.digit=5,.size.letter='M',.size.word="Shorts",.price.currency='$',.price.amount = 90,.shopselling.shopname=shop1.shopname,.shopselling.theirphonenumber=shop2.theirphonenumber,};
   struct clothing cloth3 ={.clothcode=4545,.clothyear=1965,.sizetype=3,.size.digit=6,.size.letter='s',.size.word="Jeans",.price.currency='$',.price.amount = 45,.shopselling.shopname=shop1.shopname,.shopselling.theirphonenumber=shop1.theirphonenumber,};
   struct clothing cloth4 ={.clothcode=5545,.clothyear=2023,.sizetype=3,.size.digit=7,.size.letter='L',.size.word="Jeans",.price.currency='$',.price.amount = 45,.shopselling.shopname=shop2.shopname,.shopselling.theirphonenumber=shop1.theirphonenumber,};

   allcloths[0]= cloth1;
   allcloths[1]= cloth2;
   allcloths[2]= cloth3;
   allcloths[3]= cloth4;

 int looping=0;
 do{

 printf("CLOTHING MALL\n1.Visit Shop\t2.Add Clothing\t3.Exit\n");
 int option;
 scanf(" %d", &looping);

 switch(looping)
 {
 case 1:
     showShops();

     scanf(" %d", &option);
     showDetails(option-1);
     showClothes();
     scanf(" %d", &option);
     ShowClothesDetails(option - 1);
     break;

 case 2:
     addClothing();


     break;
 case 3:
     looping = 0;
     printf("Thanks for shopping :)");
     break;

 default:
     printf("Invalid choice\n");

     break;
 }

 }
 while(looping>0);

    return 0;
}

void showShops(void){
printf("Available Shops\n1.Shop 1\n2.Shop 2 ");
printf("Added shops by user.\n");
printf("3. User shop 1\n4. User shop 2\n5. User shop 3\n6. User shop 3\n7. User shop 4\n");
}

void showDetails(int arrayIndex)
{
 printf("Shop name is %s\nShop Mobile Number is %11u\n",allshops[arrayIndex].shopname,allshops[arrayIndex].theirphonenumber);

}

void showClothes(void)
{
    printf("\nAvailable are \n");
    printf("1. Clothe 1\n2. Clothe 2\n3. Clothe 3\n4. Clothe 4");

}

void ShowClothesDetails(int arrayIndex)
{
   printf("\nClothe Details\n");
   printf("Clothe is %S\n",allcloths[arrayIndex].size.word);
   printf("Available size is %c\n",allcloths[arrayIndex].size.letter);
//   printf("Currently available at %s\nShops phone number is %11u ",allcloths[arrayIndex].shopselling.shopname,allcloths.shopselling.theirphonenumber);
   printf("Code for cloth %u\nYear cloth was made %u",allcloths[arrayIndex].clothcode,allcloths[arrayIndex].clothyear);
   printf("Accepted Currency %s\nPrice of item is %2f",allcloths[arrayIndex].price.currency,allcloths[arrayIndex].price.amount);


}

void addClothing(void)
{
    int userClothescount=0;
    printf("Add your Own clothes.\n");
    printf("How many clothes will you want to add?");
    scanf("%d",&userClothescount);
    for(int i=0;i<userClothescount;++i){

        struct shopselling userShop;
        struct clothing userAddedClothe;

        fflush(stdin);
        printf("Add your clothes to the new shop or chose an existing shop.\n");

        gets(userShop.shopname);

        if (strcmp(userShop.shopname,"shop2")==0)
        {
            strcpy(userShop.shopname,allshops[0].shopname);
        userShop.theirphonenumber=allshops[0].theirphonenumber;
        allshops[i+2]= userShop;
        }
        else if((strcmp(userShop.shopname,"shop 2")== 0))
        {
         strcpy(userShop.shopname,allshops[1].shopname);
         userShop.theirphonenumber=allshops[1].theirphonenumber;
         allshops[i+2]=userShop;
         }

         else
        {
            printf("Add your shop's phone number\n");
            scanf("%11u",userShop.theirphonenumber);
            allshops[i+2]=userShop;
         }
         fflush(stdin);
         printf("Add the name of the clothe.eg: X JEANS\n");
         gets(userAddedClothe.size.word);
         printf("Add the unique code for the clothe.\n");
         scanf(" %u", &userAddedClothe.clothcode);
         printf("Add the year the clothe was made.\n");
         scanf(" %u", &userAddedClothe.clothyear);
         printf("Add the accepted currency.\n");
         scanf(" %s", userAddedClothe.price.currency);
         printf("Add the cost of the clothe.\n");
         scanf(" %f", &userAddedClothe.price.amount);
         strcpy(userAddedClothe.shopselling.shopname,userShop.shopname);
         userAddedClothe.shopselling.theirphonenumber = userShop.theirphonenumber;

         allcloths[i+4]=userAddedClothe;
    }


}
