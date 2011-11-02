#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"
extern struct stQueue qhead;
void menu();
int main(int argc, char **argv)
{
    menu();
	return 0;
}
void menu()
{
    int iSelect = 0,k=0;
    while(1){
        system("cls");
        vfnprintqueue();
        printf("1.enqueue \n2.dequeue\n3.replace element\n4.checkqueue\n5.show queue\n6.quit\n");
        scanf("%d",&iSelect);
        switch(iSelect)
        {
            case 1:
                vfnenqueue();
                break;
            case 2:
                vfndequeue();
                break;
            case 3:
                printf("replace number ?\n");
                scanf("%d",&k);
                vfnreplace(k);
                break;
            case 4:
                vfncheckqueue();
                break;
            case 5:
                //vfnprintqueue();
                break;
            case 6:
                printf("bye bye!!");
                exit(0);
            default:
                printf("please select 1-5\n");
                continue;
        }
    }
}
