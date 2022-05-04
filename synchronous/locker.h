#ifndef LOCKER_H
#define LOCKER_H

#include<exception>
#include<pthread.h>
#include<semaphore>
/*封装信号量*/
class sem{
public:
    /*创建并初始化信号量*/
    sem(){
        if(sem_init(&m_sem,0,0) != 0){
            throw std::exception();
        }
    }
    ~sem(){
        sem_destroy(&m_sem);
    }
private:
    sem_t m_sem;
};