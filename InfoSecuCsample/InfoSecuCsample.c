#include "InfoSecuCsample.h"

int main()
{
    FILE* fptr;
    int ctr;
    struct bookInfo books[3];
    for (ctr = 0; ctr < 3; ctr++)
    {
        printf("å #%d�� �̸���?\n", (ctr + 1));
        gets(books[ctr].title);
        puts("å�� ���ڴ�?");
        gets(books[ctr].author);
        puts("å�� ������?");
        scanf_s("%f", &books[ctr].price);
        puts("å�� ����������?");
        scanf_s("%d", &books[ctr].pages);
        getchar();
    }

    fptr = fopen("c:\\aa\\cdata.txt", "w");
    if (fptr == 0)
    {
        printf("����-������ ������ �ʾ���.\n");
        exit(1);
    }
    fprintf(fptr, "\n\nå�� �÷��� ����: \n");
    for (ctr = 0; ctr < 3; ctr++)
    {
        fprintf(fptr, "#%d: %s ���ڴ� %s", (ctr + 1), books[ctr].title, books[ctr].author);
        fprintf(fptr, "\n%d �������� ������ $%.2f", books[ctr].pages, books[ctr].price);

        fprintf(fptr, "\n\n");
    }

    fclose(fptr);
    return 0;

}