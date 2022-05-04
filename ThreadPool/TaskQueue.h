/*
 * @Author: P1glet 
 * @Date: 2022-05-03 10:05:05 
 * @Last Modified by: P1glet
 * @Last Modified time: 2022-05-03 15:08:09
 */
#ifndef THREADPOOL_TASKQUEUE_H
#define THREADPOOL_TASKQUEUE_H

#include<queue>
#include<functional>
#include<mutex>
#include<future>
#include<iostream>

class TaskQueue{
public:
    using Task = std::function<void()>;  //任务类，将所有任务函数类型封装为无返回值无参数类型
    template<typename F,typename ...Args>
    auto addTask(F &f,Args && ... args) -> std::future<decltype(f(args...))>; //增加任务
    Task takeTask();            //取出任务
    bool empty(){ return taskQueue.empty(); }
private:
    std::mutex taskQueueMutex;  //任务队列互斥锁
    std::queue<Task> taskQueue; //任务队列
};

template<typename F,typename... Args>
auto TaskQueue::addTask(F &f,Args && ... args) -> std::future<decltype(f(args...))>{
    using RetType = decltype(f(args...));  // 获取函数返回值类型
    auto task = std::make_shared<std::packaged_task<RetType()>>(std::bind(f, std::forward<Args>(args)...)); 
    std::lock_guard<std::mutex> lockGuard(taskQueueMutex);
    taskQueue.emplace([task]{(*task)();});      
    return task->get_future();
}



#endif  // THREADPOOL_TASKQUEUE_H