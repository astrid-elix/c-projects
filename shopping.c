#include<stdio.h>
#include<stdlib.h>
int page=0 ,pchanged=0,exit1=0;

int changepass(int ogpass)
{
    int newpass,prepass,orignalpass;
    FILE *pass;

printf("Enter previous password :");
scanf("%d",&prepass);


if (ogpass==prepass)
{
    pchanged=1;
    pass=fopen("pass.txt","w");
   printf("Enter new Password :");
scanf("%d",&newpass);
fprintf(pass,"%d",newpass);
fclose(pass);

}
else{
    printf("worng previos password");
}

}
int Nextpage(int total ,int orignalpass)
{
    
    system("clear");
    int opt,qty=1;  
 printf("6.Chips : 11rs\n");
  printf("7.Maggi : 12rs\n");
  printf("8.Previous page\n");
   printf("9.change password\n");
    printf("10.Exit the program\n");
scanf("%d",&opt);
switch (opt)
{
case 6:
    printf("Total chips qty (default value is 1):");
    scanf("%d",&qty);
    total=11*qty;
    
    return total;
    break;
case 7:
    printf("Total chips qty (default value is 1):");
    scanf("%d",&qty);
    total+=12*qty;
      return total;
    break;
    case 8:
    page=-1;
    break;
     case 9:
    changepass(orignalpass);
    
    break;
case 10:
exit1 =1;
    break;
}
}
int main()
{
int pass,orignalpass,option,total=0,quantity=1;
int addbuy;
    FILE *passw;

    start:

    passw=fopen("pass.txt","r");

printf("Enter login pass :");
scanf("%d",&pass);
fscanf(passw,"%d",&orignalpass);
fclose(passw);
if (pass==orignalpass)
{
   printf("correct pass word :)\n");
}
else
{
    printf("wrong password !!!!\n");
    goto start;
}
buy:

system("clear");
printf("Buying Options :\n");
printf("1.Apple :20rs\n");
printf("2.Bannana :10rs\n");
printf("3.Chocolate :15rs\n");
printf("4.Orange :25rs\n");
printf("5.Next page\n");
scanf("%d",&option);
switch (option)
{
case 1:
printf("Total apple quantity (by default is 1): ");
scanf("%d",&quantity);
    total+=20*quantity;
    printf("total ammount is : %d\n",total);
printf("Want to buy womething else (1 for yes and other for no): ");
scanf("%d",&addbuy);
switch (addbuy)
{
case 1:
    goto buy;
    break;
default:
goto bill;
break;
}
    break;
case 2:
printf("Total bannana quantity (by default is 1): ");
scanf("%d",&quantity);
    total+=10*quantity;
    printf("total ammount is : %d\n",total);
    printf("Want to buy womething else (1 for yes and other for no): ");
scanf("%d",&addbuy);
switch (addbuy)
{
case 1:
    goto buy;
    break;
default:
goto bill;
break;
}
    break;
    case 3:
printf("Total Chocolate quantity (by default is 1): ");
scanf("%d",&quantity);
    total+=15*quantity;
    printf("total ammount is : %d\n",total);
    printf("Want to buy womething else (1 for yes and other for no): ");
scanf("%d",&addbuy);
switch (addbuy)
{
case 1:
    goto buy;
    break;
default:
goto bill;
break;
}
    break;
    case 4:
printf("Total bannana quantity (by default is 1): ");
scanf("%d",&quantity);
    total+=25*quantity;
    printf("total ammount is : %d\n",total);

    printf("Want to buy womething else (1 for yes and other for no): ");
scanf("%d",&addbuy);
switch (addbuy)
{
case 1:
    goto buy;
    break;
default:
goto bill;
break;
}
    break;
    case 5:
    total+=Nextpage(total,orignalpass);
   if (exit1==1)
   {
    goto exit;
   }
   


if (total>0)
{
   printf("Total amount :%d",total);
}

   if (page==-1)
   {
    goto buy;
   }
   if(total>0){
   printf("\nWant to buy womething else (1 for yes and other for no): ");
scanf("%d",&addbuy);
switch (addbuy)
{
case 1:
    goto buy;
    break;
default:
goto bill;
break;
}
   }
    break;
default:
printf("Wrong number Reselect the choice\n");
goto buy;
    break;
}
if (pchanged==1)
{
    goto start;
}


bill:
printf("Your bill is of total amount is :%d",total);
exit:
    return 0;
}