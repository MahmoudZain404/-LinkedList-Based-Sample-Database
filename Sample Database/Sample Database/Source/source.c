/*
 * source.c
 *
 * Created: 8/11/2023 11:15:48 PM
 *  Author: Mahmoud Zain Salah
 */




#include <stdio.h>
#include <stdlib.h>
#include "../Header/base.h"




 static student* head = NULL;





 static int list_lingth()
 {
     student* current = head;

     int count = 0;

     while (current != NULL)
     {
         count++;
         current = current->nextnode;
     }
     return count;
 }


 static struct student* get_middle(struct student* start, struct student* end)
 {
     if (start == NULL)
         return NULL;

     struct student* mid = start;
     struct student* advhead = start->nextnode;

     while (advhead != end)
     {
         advhead = advhead->nextnode;
         if (advhead != end)
         {
             mid = mid->nextnode;
             advhead = advhead->nextnode;
         }
     }

     return mid;
 }


 static struct student* Search_ID()
 {
     int ID = 0;

     printf("\nPlease Enter Student ID You Look For: ");

     scanf_s("%d", &ID);

     struct student* h = head;
     struct student* start = head;
     struct student* end = NULL;

      while (end == NULL || end != start)
     {
         struct student* mid = get_middle(start, end);

         if (mid == NULL)
             return NULL;

         if (mid->student_ID == ID)
         {
             printf("\n-------------------ID: %d is Available------------------------\n", ID);
             printf("student ID: %d\n", mid->student_ID);
             printf("student year: %d\n\n", mid->student_year);
             for (int j = 0; j < COURSES_NUM; j++)
             {
                 printf("%d- Course ID: %d Grade: %d    ", j + 1, mid->courses[j].course_ID, mid->courses[j].course_grade);
             }
             printf("\n--------------------------------------------------------------\n");

             return mid;
         }
         else if (mid->student_ID < ID)
         {
             start = mid->nextnode;
         }
         else
         {
             end = mid;
         }
     }
      printf("Student ID Unavailable!");
     return NULL;
 }


 static struct student* swap(struct student* prev, struct student* next)
 {
     struct student* temp = next->nextnode;
     next->nextnode = prev;
     prev->nextnode = temp;
     return next;
 }


 static int Sort_list(struct student** head)
 {
     int count = list_lingth();

     struct student** current;
     int i, j, swapped;

     for (i = 0; i <= count; i++) 
     {

         current = head;
         swapped = 0;

         for (j = 0; j < count - i - 1; j++) 
         {

             struct student* prev = *current;
             struct student* next = prev->nextnode;

             if (prev->student_ID > next->student_ID) 
             {

                 *current = swap(prev, next);
                 swapped = 1;
             }

             current = &(*current)->nextnode;
         }

         if (swapped == 0)
         {
             break;
         }
     }
 }


static void Add_Student()
{
    int i = 0;
    int j = 0;
    int x = 0;
    int student_ID = 0;
    int student_year = 0;
    Course courses[] = { {1,2}, {1,2} , {1,2} };

    printf("\nPlease Enter Student ID: ");
    scanf_s("%d", &student_ID);
    printf("Please Enter student year: ");
    scanf_s("%d", &student_year);

    for (j = 0; j < COURSES_NUM; j++)
    {
        printf("Please Enter The Student %d Course ID: ", j + 1);
        scanf_s("%d", &courses[j].course_ID);

        printf("Please Enter The Student %d Course Grade: ", j + 1);
        scanf_s("%d", &courses[j].course_grade);
    }
    printf("\n");
   
    if (head == NULL) 
    {
        head = (student*)malloc(sizeof(student));

        head->student_ID = student_ID;

        head->student_year = student_year;

        for (x = 0; x < COURSES_NUM; x++)
        {
            head->courses[x] = courses[x];
        }
        head->nextnode = NULL;
    }
    else 
    {
        student* current = head;

        while (current->nextnode != NULL)
        {
            current = current->nextnode;
        }

        current->nextnode = (student*)malloc(sizeof(student));

        current->nextnode->student_ID = student_ID;

        current->nextnode->student_year = student_year;

        for (i = 0; i < COURSES_NUM; i++) 
        {
        current->nextnode->courses[i] = courses[i];
        }

        current->nextnode->nextnode = NULL;
    }
    Sort_list(&head);
}




static void Delete_student()
{
    int ID = 0;

    printf("\nPlease Enter Student ID To Be Deleted: ");

    scanf_s("%d", &ID);

    student* prev = head;

    if (head->student_ID == ID) {
    
        head = head->nextnode; 
        
        free(prev); 
    }
    else 
    {
        while (prev->nextnode->student_ID != ID)
        {
                if (prev->nextnode->nextnode == NULL && prev->nextnode->student_ID != ID)
                {
                    printf("\nID NOT FOUND!\n");
                    return 0;
                }
                else
                {
                    prev = prev->nextnode;
                }
        }
         student *tobedeleted = prev->nextnode;
         if (prev->nextnode->nextnode != NULL)
         {
                prev->nextnode = prev->nextnode->nextnode;
         }
         else
         {
                prev->nextnode = NULL;
         }

         free(tobedeleted);
    }
   


}


static void PrintList()
{
    int i = 0;
    int j= 0;
    student* current = head;

    while (current != NULL)
    {
        printf("\n-------------------%d------------------------\n", i+1);
        printf("%d- student ID: %d\n", i+1 ,current->student_ID);
        printf("%d- student year: %d\n\n", i+1 ,current->student_year);
        for (j = 0; j < COURSES_NUM; j++)
        {
            printf("%d- Course ID: %d Grade: %d    ", j + 1, current->courses[j].course_ID, current->courses[j].course_grade);
        }
        printf("\n---------------------------------------------\n");
        current = current->nextnode;
        i++;
    }
    i = 0;
}
