package com.course.structure;

public class School extends Building{
    private int classR;
    private String grade;
    void setClassR(int x){
        classR = x;
    }
    void setGrade(String x){
        grade = x;
    }
    int getClassR(){
        return classR;
    }
    String getGrade(){
        return grade;
    }
}
