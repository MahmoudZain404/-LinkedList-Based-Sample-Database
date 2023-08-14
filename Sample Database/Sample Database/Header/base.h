/*
 * base.h
 *
 * Created: 8/11/2023 11:15:48 PM
 *  Author: Mahmoud Zain Salah
 */


#ifndef BASE_H
#define BASE_H



#define COURSES_NUM (3)

typedef enum boolean
{
    TRUE = 1,
    FALSE = 0
} boolean;

typedef struct Course
{
    int course_ID;
    int course_grade;
} Course;

typedef struct student
{
    int index;
    int student_ID;
    int student_year;
    Course courses[COURSES_NUM];
    struct student* nextnode;

} student;

void Add_Student(void);

int Sort_list(struct student** head);

void Delete_student();

struct student* Search_ID();

struct student* get_middle(struct student* start, struct student* end);

struct student* swap(struct student* ptr1, struct student* ptr2);

int list_lingth(void);

#endif // BASE_H
