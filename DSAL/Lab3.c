#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float real,img;
} Complex;

void cRead(Complex *c1){
    printf("Enter real and imaginary part: ");
    scanf("%f%f",&c1->real,&c1->img);
}

void cDisp(Complex *c1){
    printf("%.2f + %.2fi\n",c1->real,c1->img);
}

Complex cAdd(Complex *c1,Complex *c2){
    Complex sum;
    sum.real = c1->real + c2->real;
    sum.img = c1->img + c2->img;
    return sum;
}

Complex cSub(Complex *c1,Complex *c2){
    Complex diff;
    diff.real = c1->real - c2->real;
    diff.img = c1->img - c2->img;
    return diff;
}

Complex cMult(Complex *c1,Complex *c2){
    Complex result;
    result.real = c1->real*c2->real - c1->img*c2->img;
    result.img = c1->real*c2->img + c2->real*c1->img;
    return result;
}

typedef struct{
    char name[30];
    int roll;
    float cgpa;
}Student;

void sRead(Student *s1){
    printf("Enter name: ");
    do{
        fgets(s1->name, 30, stdin);
    }
    while(s1->name[0] == '\n');
    s1->name[strlen(s1->name)-1] = '\0';
    printf("Enter roll no.: ");
    scanf("%d",&s1->roll);
    printf("Enter CGPA: ");
    scanf("%f",&s1->cgpa);
}

void sDisp(Student *s1){
    printf("Name: %s\nRoll no.: %d\nCGPA: %.2f\n",s1->name,s1->roll,s1->cgpa);
}

int main(void){
    int q;
    while(1){
        printf("Enter question number: ");
        scanf("%d",&q);

        if(q==1){
            Complex *c1 = malloc(sizeof(Complex));
            Complex *c2 = malloc(sizeof(Complex));
            cRead(c1);
            cRead(c2);
            cDisp(c1);
            cDisp(c2);
            Complex sum = cAdd(c1,c2);
            Complex diff = cSub(c1,c2);
            Complex mult = cMult(c1,c2);
            printf("Addition of the 2 complex numbers = %.2f + i%.2f\n",sum.real,sum.img);
            printf("Subtraction of the 2 complex numbers = %.2f + i%.2f\n",diff.real,diff.img);
            printf("Multiplication of the 2 complex numbers = %.2f + i%.2f\n",mult.real,mult.img);
        }  
        else if(q==2){
            Student *s1 = malloc(sizeof(Student));
            sRead(s1);
            sDisp(s1);
            Student *studs = malloc(3 * sizeof(Student));
            
        }
        else if(q==3){
            
        }
        else if(q==4){

        }
        else{printf("Exitting program");break;}
    }
    return 0;
}