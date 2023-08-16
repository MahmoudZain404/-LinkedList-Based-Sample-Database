/*
 * base.h
 *
 * Created: 8/11/2023 11:15:48 PM
 *  Author: Mahmoud Zain Salah
 */


#ifndef BASE_H
#define BASE_H



#define COURSES_NUM (3)


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

void Delete_student(void);

struct student* Search_ID(void);

struct student* get_middle(struct student* start, struct student* end);

struct student* swap(struct student* prev, struct student* next);

int list_length(void);

#endif // BASE_H
