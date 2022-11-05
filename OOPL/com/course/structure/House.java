package com.course.structure;

public class House extends Building{
    private int bedR,bathR;

    void setBedR(int x){
        bedR = x;
    }
    void setBathR(int x){
        bathR = x;
    }
    int getBedR(){
        return bedR;
    }
    int getBathR(){
        return bathR;
    }
}
